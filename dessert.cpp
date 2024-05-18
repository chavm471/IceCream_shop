/*
The purpose of this program is to implement the base class member functions such as the
constructor and destructor. I have implemented the virtual function displayProduct but not 
the chooseSize or addOn function because they are pure virtual functions. Ive also 

*/

#include "dessert.h"

//default contructor
Dessert::Dessert() : productNum(0), totalSales(0.0)
{}

//initizationlist

//destructor has to be virtual to call the correct derived class destructor
Dessert::~Dessert()
{}

int Dessert::displayProduct() const
{
    return 0;
}

//this function updates the sales for how many obejects is made.
//calculates total.
double Dessert::updateSales()
{

    return 0;
}
        
//constructor of IceCreamCake class
IceCreamCake::IceCreamCake() : size("empty") , numLayers(0)
{}

/*
IceCreamCake::IceCreamCake(const int prodNum,const double srcSales,vector<string> srcTopping 
    ,const string & srcSize, const int srcLayers) 
    : size("empty") , numLayers(0)
*/
/*
IceCreamCake::IceCreamCake(const Dessert & src,const string & srcSize, const int srcLayers) :
    Dessert(src), size(srcSize), numLayers(srcLayers)
{}*/

//destructor of IceCreamCake class
IceCreamCake::~IceCreamCake()
{

}

//virtual functions
int IceCreamCake::displayProduct() const
{

}

string IceCreamCake::chooseSize() // large only
{
    return "Large";
}
double IceCreamCake::addOns()
{

}
//end of virtual functions
int IceCreamCake::pickLayers()
{


}

MilkShake::MilkShake()
{

}

MilkShake::~MilkShake()
{

}

//virtual functions
int MilkShake::displayProduct() const
{

}
double MilkShake::addOns()
{

    return 0.0;
}
// changes to int to store in volume in data member
string MilkShake::chooseSize()
{

}
//end of virtual functions,// glass, foam
string MilkShake::chooseContainer()
{

}

//costructor of Wafflecone class
WaffleCone::WaffleCone() : coneSize("empty")
{}

//initialization list of WaffleCone
WaffleCone::WaffleCone(const string & src_coneSize, vector<string> & srcToppings)
{}

//Destructor of WaffleCone
WaffleCone::~WaffleCone()
{

}

//virtual function
int WaffleCone::displayProduct() const
{
    return 0;
}

//
string WaffleCone::chooseSize()
{
    return "hello";
}

double WaffleCone::addOns()
{
    return 0.0;
}

//end of virtual functions
string WaffleCone::chooseCone()
{
    return "string";
}
