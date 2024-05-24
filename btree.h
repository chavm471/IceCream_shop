/*
the purpose of this file is to declare the node class and the Btree class
The Node class is not derived from a base class or derived class. In the 
private section I declared Dessert as a pointer. The Btree class handles 
the Btree operations.
*/
#include"dessert.h"
#include<memory>
using std::unique_ptr;

class Node
{
    public:
        //typedef unique_ptr<Node> node_ptr_type;
        Node();
        Node(const Node & src);
        ~Node();
        Node *& get_left();
        Node *& get_right();
        int set_data();
        
    private:
        unique_ptr<Dessert> data;
        Node * left;
        Node * right;
};

//implementing a regular tree first then a balance tree
class Btree
{
    public:
        //typedef Node node_type;
        //typedef unique_ptr<Node> node_ptr;
        //constructor
        Btree();
        //destructor
        ~Btree();
        //wrapper function for insert
        int insert(unique_ptr<Dessert> to_add);
        //wrapper function for display
        int display() const;

    private:
        Node * root;
        //
        int insert(Node *& root,unique_ptr<Dessert> to_add);
        int display(const Node *& root) const;
};
