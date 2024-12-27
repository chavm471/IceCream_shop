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

        //functions to manage keys
        bool is_full() const;//check if the node has 3 keys

        shared_ptr<Dessert> get_key(int index) const;
        void set_key(int index, shared_ptr<Dessert> value);

        shared_ptr<Node> get_child(int index) const;
        void set_child(int index,shared_ptr<Node> val);

        int get_size() const;
        void set_size(int s);

        int add_key(shared_ptr<Dessert> new_data);
        //void remove_key(int index);
        //int set_data(int index);
        
    private:
        int size_n;//current number of keys
        vector<shared_ptr<Dessert>> keys;//data
        vector<node_ptr_type> children;//Fixed size of 4
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
        int insert_dessert(Dessert *& to_add);
        //wrapper function for display
        int displayAll() const;
        int removeAll();
        //int removeItem(int to_remove);

    private:
        node_ptr root;
        //this is the recursive calls
        int insert_dessert(node_ptr & root,Dessert *& to_add);
        void split_node(node_ptr & to_split,node_ptr & parent,int child_index);
        //recursive call for the display all function
        int displayAll(const node_ptr & current) const;
        int removeAll(node_ptr & current);
        //int removeItem(node_ptr & current,int to_remove);
};
