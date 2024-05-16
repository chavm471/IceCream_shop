/*Marcos Chavez, CS302 In-person , Karla Fant, For program 3 we are creating
a program that helps with a ice cream shop and i need the program to help with 
sales of the different product. At the end of the month, i need the total sales,
for all products together. My class is going to be called dessert and I will offer 
3 types of dessert. I will offer IcecreamCake, MilkShake , and a WaffleCone.
*/
#include<iostream>
#include<string>
#include<memory>
#include<vector>

using namespace std;

//this is the base class
class Dessert
{
    public:
    Dessert();
    ~Dessert();
    
    private:
        string name;
        double price;
        int quantitySold;
};

class IceCreamCake : public Dessert
{
    public:
        IceCreamCake();
        ~IceCreamCake();
        virtual int displayProduct();
        virtual double updateSales();
        virtual string chooseSize();

    private:
        string size;
        int numLayers;
};

class MilkShake : public Dessert
{
    public:
        Milkshake();
        ~Milkshake();
        virtual int displayProduct();
        virtual double updateSales();
        virtual int chooseSize();

    private:
        int volume;
};

class WaffleCone : public Dessert
{
    public:
        WaffleCone();
        WaffleCone(const string & src_cone_type,vector
        ~WaffleCone();
        virtual int displayProduct();
        virtual double updateSales();
        virtual string chooseSize();

    private:
        string coneType;
        vector<string> toppings;
};
