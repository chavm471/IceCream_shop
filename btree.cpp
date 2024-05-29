/*
The purpose of this file is to serve as the implementation file for my 
data structure that is a Btree.
*/

#include"btree.h"
using namespace std;

//default constructor
Node::Node(int num) : left(nullptr),mleft(nullptr),mright(nullptr),right(nullptr)
{
    size = num;
    data = new Dessert * [size];
    //initialize each index to null
    for(int i =0;i < size;++i)
    {
        data[i] = nullptr;
    }
}

//destructor 
Node::~Node()
{
    for (int i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
}

//This function return pointer to most left
Node::node_ptr_type & Node::get_left()
{
    return left;
}
//this function returns middle left node
Node::node_ptr_type & Node::get_mleft()
{
    return mleft;
}
//this function gets the middle right node
Node::node_ptr_type & Node::get_mright()
{
    return mright;
}
//this function returns most right now
Node::node_ptr_type & Node::get_right()
{
    return right;
}

//this function allows us to transfer ownership of unique ptr
int Node::set_data(int index)
{
    //check if index is greater than 0 and index is less than max size
    if(index >= 0 && index < size)
    {
        //transfer ownership over to the index
        //data[index] = move(to_add);
        return 1;
    }
    return 0;
}

bool Node::less_than_or_equal(const Dessert * new_data)
{
    for(int i = 0; i < size; ++i){
        if(data[i] != nullptr)
        {
            return data[0]->less_than_or_equal(new_data);
        }
    }
    return false;
}

bool Node::greater_than(const Dessert * new_data)
{
    for(int i = 0; i < size; ++i){
        if(data[i] != nullptr)
        {
            return data[0]->greater_than(new_data);
        }
    }
    return false;

}

//display the data 
int Node::displayData()
{
    //i think i need a for loop to go through array of each node
    for(int i =0; i < size;++i)
    {
        //check if theres data
        if(data[i])
        {
            //display
            data[i]->displayProduct();
            return 1;
        }
    }
    return 0;
}

//constructor
Btree::Btree(): root(nullptr)
{}

//destructor
Btree::~Btree()
{
    removeAll();
}

//wrapper function for insert
int Btree::insert(const Dessert * to_add)
{
    return insert(root,move(to_add));
}

//recursive function for insert
int Btree::insert(node_ptr & root,const Dessert * to_add)
{
    if(!root)
    {
        //make new Node with array of unique ptrs size 4
        //root = new Node(4);
        //transfer ownership of the unique_ptr to the index
        //root->set_data(to_add,0);
        return 1;
    }

    if(root->greater_than(to_add))
    {
        insert(root->get_left(),to_add);
    }

    return 0;
}

//wrapper function for display
int Btree::displayAll() const
{
    if(!root)
    {
        return 0;
    }
    return displayAll(root);
}

//recursive call for the display all function
int Btree::displayAll(const node_ptr & root) const
//int Btree::displayAll(const Node *& root) const
{
    if(!root)
    {
        return 0;
    }

    //traverse the 2-3-4 tree
    //recursive calls for the data on the left side
    displayAll(root->get_left());
    displayAll(root->get_mleft());

    //display the data
    root->displayData();
    //recursive calls for data on the right side
    displayAll(root->get_mright());
    displayAll(root->get_right());

    return 1;
}

//wrapper fucntion for remove all function
int Btree::removeAll()
{
    if(root)
    {
        if(deleteAll(root))
        {
            cout<<"Everything has been removed\n";
            return 1;
        }
    }

    //this serves an else
    cout<<"There was no data saved\n";
    return 0;
}

//recursive call for remove all
int Btree::deleteAll(node_ptr & current)
    //int Btree::deleteAll(shared_ptr<Node> & current)
{
    //tree is empty
    if(!current) return 0;

    //delete all left
    if(current->get_left()){
        deleteAll(current->get_left());
    }
    //delete all mleft
    if(current->get_mleft()){
        deleteAll(current->get_mleft());
    }
    //delete all middle right nodes
    if(current->get_mright()){
        deleteAll(current->get_mright());
    }
    //delete all right nodes
    if(current->get_right()){
        deleteAll(current->get_right());
    }

    //clean up memory
    //other shared_ptr references it
    current.reset();
    return 1;
}
