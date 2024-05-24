/*Marcos Chavez, CS302 In-person , Karla Fant, For program 3 we are creating
a program that helps with a ice cream shop and i need the program to help with 
sales of the different product. At the end of the month, i need the total sales,
for all products together. My class is going to be called dessert and I will offer 
3 types of dessert. I will offer IcecreamCake, MilkShake , and a WaffleCone.
The function AddOns() adds differnt add ons for each type. The chooseSize() is going
to set a size (which is different for each type)
*/
#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<random>

const double CAKE_BASE_PRICE = 25;
const double SHAKE_BASE_PRICE = 7.99;
const double WAFFLECONE_BASE_PRICE = 5.99;

using namespace std;
enum class Toppings
{
    CHERRY,
    NUTS,
    COCONUT,
    FUDGE,
    CARAMEL,
    OREO
};

enum class Flavors
{
    STRAWBERRY,
    VANILLA,
    CHOCOLATE,
    MINT
};

///Can make an option to change size

//this is the base class
class Dessert
{
    public:
    //default contructor
    Dessert();
    //copy constructor
    Dessert(const Dessert & to_copy);
    //destructor has to be virtual to call the correct derived class destructor
    virtual ~Dessert();
    virtual int displayProduct() const;
    virtual string chooseSize() = 0;
    virtual double addOns() = 0;
    int randNum(int limit);
    double chooseFlavor();
    double updateSales();
    friend bool operator == (const Dessert & src,const Dessert &);
    friend bool operator == (const Dessert & src,const int & pNum);
    friend bool operator == (const int & pNum,const Dessert & src);
    
    private:
        int productNum;
        double totalSales;
        vector<string> iceCream;
};

class IceCreamCake : public Dessert
{
    public:
        IceCreamCake();
        ~IceCreamCake();
        IceCreamCake(const Dessert & src,const string & srcSize, const int srcLayers);
        //virtual functions
        int displayProduct() const;
        string chooseSize(); // large only
        double addOns();
        //end of virtual functions
        int pickLayers();

    private:
        string size;
        int numLayers;
};

class MilkShake : public Dessert
{
    public:
        MilkShake();
        MilkShake(const Dessert & src,const int srcVolume,const string & srcContainer);
        ~MilkShake();
        //virtual functions
        int displayProduct() const ;
        double addOns();
        string chooseSize(); // changes to int to store in volume in data member
        //end of virtual functions
        string chooseContainer();// glass, foam

    private:
        int volume;
        string container;
};

class WaffleCone : public Dessert
{
    public:
        WaffleCone();
        WaffleCone(const Dessert & src,const string & src_coneSize, vector<string> & srcToppings);
        ~WaffleCone();
        //virtual function
        int displayProduct() const;
        string chooseSize();
        double addOns();
        //end of virtual functions
        string chooseCone();

    private:
        string coneSize;
        vector<string> toppings;
};

