/*
The purpose of this file is to serve as the implementation file for my 
data structure that is a Btree.
*/

const int MAX_KEYS = 3;

#include"btree.h"
using namespace std;

//default constructor
Node::Node(int num) : size_n(0), children(4)
{
    int size = num;

    //initialize each index to null
    for(int i =0;i < size;++i)
    {
        children[i] = nullptr;
    }
}

//destructor 
Node::~Node()
{
}
        
//check if the node has 3 keys
bool Node::is_full() const
{
    return size_n == MAX_KEYS;
}

//this function inserts the dessert object in the correct node
//
int Node::add_key(shared_ptr<Dessert> new_data)
{
    if(is_full()) return -1;

    //insert in sorted order
    auto it = keys.begin();
    //loop through the keys to insert in sorted order.
    while(it != keys.end() && **it < *new_data){
        ++it;
    }
    keys.insert(it,move(new_data));
    size_n++;
    return 0;
}

/*void Node::remove_key(int index)
{
    if(index < 0 || index >= static_cast<int>(keys.size()))
    {
        //escape from function nothing to do.
        return;
    }
    keys.erase(keys.begin() + index);
    size_n--;
}*/

shared_ptr<Dessert> Node::get_key(int index) const{
    //return the the key value
    return keys[index];
}

void Node::set_key(int index, shared_ptr<Dessert> value){
    keys[index] = value;
}

//gets child and returns the child type shared_ptr (NODE)
shared_ptr<Node> Node::get_child(int index) const{
    //returnd the child of current node
    return children[index];
}

void Node::set_child(int index,shared_ptr<Node> val){
    children[index] = val;
}

int Node::get_size() const{
    return size_n;
}

void Node::set_size(int s){
    size_n = s;
}

//constructor
Btree::Btree(): root(nullptr)
{}

//destructor
Btree::~Btree()
{
    //removeAll();
}
        
void Btree::split_node(node_ptr & to_split,node_ptr & parent,int child_index){
    //create two nodes for the split
    auto left = make_shared<Node>();
    auto right = make_shared<Node>();
    
    //middle key to be promoted
    auto middle_key = to_split->get_key(1);//assuming keys are{0,1,2,3}

    //left child gets the first key and the first two children
    left->add_key(to_split->get_key(0));
    left->set_child(0,to_split->get_child(0));
    left->set_child(1,to_split->get_child(1));

    //right child gets the last key and the last two children
    right->add_key(to_split->get_key(2));
    right->set_child(0,to_split->get_child(2));
    right->set_child(1,to_split->get_child(3));

    //promote the middle key to the parent node
    parent->add_key(middle_key);

    //shift parent's children to make space for the new
    //right child
    for(int i = parent->get_size(); i > child_index + 1;i--){
        parent->set_child(i,parent->get_child(i - 1));
    }

    //update parent's children
    parent->set_child(child_index,left);
    parent->set_child((child_index + 1),right);

    //clear the original
    to_split.reset();
}

//wrapper function for insert
int Btree::insert_dessert(Dessert *& to_add)
{
    //if b-tree is empty
    if(!root){
        //allocate a root node
        root = make_shared<Node>();
        //insert the Dessert
        //root->add_key(make_shared<auto>(*to_add));
        root->add_key(to_add->clone());
        return 0;
    }

    //if the root is full, split the root
    if(root->is_full()){
        //create a new root
        auto new_root = make_shared<Node>();
        new_root->set_child(0,root);

        //split the old root and promote its middle key
        split_node(root,new_root,0);
        
        //update the root pointer
        root = new_root;
    }
    
    //recursive function call
    return insert_dessert(root,to_add);
}

//recursive function for insert
int Btree::insert_dessert(node_ptr & root,Dessert *& to_add)
{
    //base case
    if(!root)
    {
        return -1;
    }

    //if the current node is a leaf,add the key directly
    if(root->get_child(0) == nullptr){
        root->add_key(to_add->clone());
        return 0;
    }

    //find the correct child to descend into
    int i = 0;
    while(i < root->get_size() && *(root->get_key(i)) < *to_add){
        ++i;
    }
    
    auto child = root->get_child(i);
    //if the selected child is full,split it first
    if(child && child->is_full()){
        split_node(child,root,i);
        
        //after splitting,recheck which child to descend into
        if(*root->get_key(i) < *to_add){
            ++i;
        }
    }
    //get child again after potential split
    child = root->get_child(i);

    return insert_dessert(child,to_add);
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
int Btree::displayAll(const node_ptr & current) const
{
    if(!current)
    {
        return -1;
    }
    
    //store how many keys are in this node
    int numKeys = current->get_size();

    //traverse children/keys from left to right
    for(int i = 0; i < numKeys; ++i){
        //1.if child[i] exists,visit it first
        if(auto leftChild = current->get_child(i))
        {
            displayAll(leftChild);
        }

        //2.Display the i-th key in this node
        auto key = current->get_key(i);
        if(key)
        {
            key->displayProduct();   
        }
    }

    //3. traverse the last child if it exists
    if(auto rightChild = current->get_child(numKeys)){
        displayAll(rightChild);
    }

    return 1;
}

//wrapper fucntion for remove all function
/*int Btree::removeItem(int to_remove)
{
    if(!root)
    {
        return -1;
    }

    return removeItem(root,to_remove);
}

//recursive call for remove all
int Btree::removeItem(node_ptr & current,int to_remove)
{
    if(!current)
    {
        return -1;
    }

    int numKeys = current->get_size();

    for(int i = 0; i < numKeys; ++i)
    {
        //fetch the shared_ptr<Dessert> at index i
        auto treat = current->get_key(i);

        if(treat && (*treat == to_remove))
        {
            current->remove_key(i);
        }
    }

    //if its a leaf node, its simply not found
    if(!current->get_child(0))
    {
        return -1;
    }

    //otherwise, we figure out which child to search
    int j = 0;
    while(j < numKeys && *current->get_key(j) < to_remove)
    {
        ++j;
    }
    auto child = current->get_child(j);

    //recursively call removeItem on that child
    return removeItem(child,to_remove);
}*/

int Btree::removeAll(){
    return 0;
}

int Btree::removeAll(node_ptr & current){
    return 0;
}
