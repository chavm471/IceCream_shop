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
{}

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

//constructor
Btree::Btree(): root(nullptr)
{}

//destructor
Btree::~Btree()
{}

//wrapper function for insert
int Btree::insert(const Dessert * to_add)
{
    return insert(root,move(to_add));
}


int Btree::insert(Node *& root,const Dessert * to_add)
{
    if(!root)
    {
        //make new Node with array of unique ptrs size 4
        //root = new Node(4);
        //transfer ownership of the unique_ptr to the index
        //root->set_data(to_add,0);
        return 1;
    }

    return 0;
}

//wrapper function for display
int Btree::display() const
{
    return 0;
}
