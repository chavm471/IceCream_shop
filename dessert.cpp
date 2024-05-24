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
Dessert::Dessert(const Dessert & to_copy) 
    : productNum(to_copy.productNum),totalSales(to_copy.totalSales),iceCream(to_copy.iceCream)
{}

//destructor has to be virtual to call the correct derived class destructor
Dessert::~Dessert()
{}

int Dessert::displayProduct() const
{
    //display data
    cout << productNum <<endl;
    cout << totalSales <<endl;

    return 0;
}


int Dessert::randNum(int limit)
{
    random_device rd; 

    mt19937 gen(rd());

    //uniform distribution
    uniform_int_distribution<> dis(1,limit);

    return dis(gen);
}

//this function sets the flavor and adds to the vector.
double Dessert::chooseFlavor()
{
    int choice =0;
    bool keepGoing {true};
    string temp = "";

    do{
        cout <<"what flavor do you want?\n";
        cout <<"1. STRAWBERRY\n";
        cout <<"2. VANILLA\n";
        cout <<"3. CHOCOLATE\n";
        cout <<"4. MINT\n";
        cin>> choice;
        cin.ignore(100,'\n');

        switch(choice)
        {
            case 1:
                temp = "STRAWBERRY";
                break;
            case 2:
                temp = "VANILLA";
                break;
            case 3: 
                temp = "CHOCOLATE";
            default:
                break;
        }

        cout <<"Do you want to keep going?\n";
        cout<<"Enter 1 to keep going\n";
        cout<< "Or enter any number not 1 to stop\n";
        cin >>keepGoing;
        cin.ignore(100, '\n');

    }while(keepGoing == 1);
    //push onto vector of icecream
    iceCream.push_back(temp);

}

//this function updates the sales for how many obejects is made.
//calculates total.
double Dessert::updateSales()
{
    //check what dessert they have
    //if(
    return 0;
}

//constructor of IceCreamCake class
IceCreamCake::IceCreamCake() : size("empty") , numLayers(0)
{}


IceCreamCake::IceCreamCake(const Dessert & src,const string & srcSize, const int srcLayers) :
    Dessert(src), size(srcSize), numLayers(srcLayers)
{}

//destructor of IceCreamCake class
IceCreamCake::~IceCreamCake()
{
    //remove data
    size = "";
    numLayers =0;
}

//virtual functions
int IceCreamCake::displayProduct() const
{

    return 1;
}

string IceCreamCake::chooseSize() // large only
{
    return "Large";
}
double IceCreamCake::addOns()
{

    return 1.0;
}
//end of virtual functions
int IceCreamCake::pickLayers()
{

    return 0;
}

//constructor for milkshake
MilkShake::MilkShake() : volume(0),container("empty")
{}

//initialization list
MilkShake::MilkShake(const Dessert & src,const int srcVolume,const string & srcContainer)
    :Dessert(src),volume(srcVolume),container(srcContainer)
{}

MilkShake::~MilkShake()
{
    volume = 0;
    container = "";
}

//virtual functions
int MilkShake::displayProduct() const
{
    return 0;
}
double MilkShake::addOns()
{

    return 0.0;
}
// changes to int to store in volume in data member
string MilkShake::chooseSize()
{
    return "hello";
}
//end of virtual functions,// glass, foam
string MilkShake::chooseContainer()
{
    int choice {0};
    cout << "what container do you want to use\n";
    cout << "1.Glass\n";
    cout << "2.Plastic\n";

    cin >> choice;
    cin.ignore(100,'\n');

    if(choice == 1)
    {
        return "GLASS";
    }
    return "fail";
}

//costructor of Wafflecone class
WaffleCone::WaffleCone() : coneSize("empty") ,toppings()
{}

//initialization list of WaffleCone
WaffleCone::WaffleCone(const Dessert & src,const string & src_coneSize, vector<string> & srcToppings)
    : Dessert(src),coneSize(src_coneSize),toppings(srcToppings)
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
