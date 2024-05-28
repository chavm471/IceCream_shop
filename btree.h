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
        typedef unique_ptr<Node> node_ptr_type;
        Node(int num = 4);
        ~Node();
        node_ptr_type & get_left();
        node_ptr_type & get_mleft();
        node_ptr_type & get_mright();
        node_ptr_type & get_right();
        int set_data(int index);
        
    private:
        int size;
        //shared_ptr<shared_ptr<Dessert>[]> data;
        //vector<shared_ptr<Dessert>> data;
        Dessert ** data;
        node_ptr_type left;
        node_ptr_type mleft;
        node_ptr_type mright;
        node_ptr_type right;
};

//implementing a regular tree first then a balance tree
class Btree
{
    public:
        //constructor
        Btree();
        //destructor
        ~Btree();
        //wrapper function for insert
        int insert(const Dessert * to_add);
        //wrapper function for display
        int display() const;

    private:
        Node * root;
        //this is the recursive calls
        int insert(Node *& root,const Dessert * to_add);
        int display(const Node *& root) const;
};
