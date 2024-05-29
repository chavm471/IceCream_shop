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
        typedef shared_ptr<Node> node_ptr_type;
        Node(int num = 4);
        ~Node();
        node_ptr_type & get_left();
        node_ptr_type & get_mleft();
        node_ptr_type & get_mright();
        node_ptr_type & get_right();
        bool less_than_or_equal(const Dessert * new_data);
        bool greater_than(const Dessert * new_data);
        int set_data(int index);
        int displayData();
        
    private:
        int size;
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
        typedef shared_ptr<Node> node_ptr;
        //constructor
        Btree();
        //destructor
        ~Btree();
        //wrapper function for insert
        int insert(const Dessert * to_add);
        //wrapper function for display
        int displayAll() const;
        //wrapper fucntion for remove all function
        int removeAll();

    private:
        node_ptr root;
        //this is the recursive calls
        int insert(node_ptr & root,const Dessert * to_add);
        //recursive call for the display all function
        int displayAll(const node_ptr & root) const;
        //recursive call for remove all
        int deleteAll(node_ptr & current);
};
