/*
The purpose of this file is to serve as the implementation file for my 
data structure that is a Btree.
*/

#include"btree.h"
using namespace std;

Node::Node() : data(nullptr),left(nullptr),right(nullptr)
{}

//copy constructor
Node::Node(const Node & src) : left(nullptr),right(nullptr)
{
    //check if there data
    /*if(src.data)
    {
        data = new Dessert(*src.data);
    }
    else
    {
        data = nullptr;
    }*/
}

//destructor 
Node::~Node()
{}

Node *& Node::get_left()
{
    return left;
}

Node *& Node::get_right()
{
    return right;
}



//constructor
Btree::Btree(): root(nullptr)
{}

//destructor
Btree::~Btree()
{}

//wrapper function for insert
int Btree::insert(unique_ptr<Dessert> to_add)
{
    //return insert(root,to_add);
    return 0;
}


int Btree::insert(Node *& root,unique_ptr<Dessert> to_add)
{
    if(!root)
    {
        //create new node
        //add to the tree
        
    }
    return 0;
}

//wrapper function for display
int Btree::display() const
{
    return 0;
}
