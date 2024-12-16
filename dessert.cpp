/*
The purpose of this program is to implement the base class member functions such as the
constructor and destructor. I have implemented the virtual function displayProduct but not 
the chooseSize or addOn function because they are pure virtual functions. Ive also 

*/
#include "dessert.h"

const int IDNUM_MAX = 4000;

//default contructor
Dessert::Dessert() : productNum(0), totalSales(0.0)
{
    productNum = randNum(IDNUM_MAX);
}

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
    cout<<"Product Number is:" << productNum <<endl;
    cout<<"Total sale is:" << totalSales <<endl;
    cout<<"Flavors:";
    //for loop to iterate through vector to print all flavors
    for(string x: iceCream)
    {
        cout << x << ", ";
    }

    return 1;
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
    string temp = "";
    double charge {ADDFLAV};
    bool flag = true;
    
    //this do while loop allows the user to pick flavors
    do{
        cout <<"what flavor do you want?\n";
        cout <<"1. STRAWBERRY\n";
        cout <<"2. VANILLA\n";
        cout <<"3. CHOCOLATE\n";
        cout <<"4. MINT\n";
        cout <<"5. QUIT\n";
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
                break;
            case 4:
                temp = "MINT";
                break;
            case 5:
                cout <<"Back to the Dessert Menu!\n";
                flag = false;
                break;
            default:
                flag = false;
                break;
        }
        //push onto vector of icecream
        iceCream.push_back(temp);

        //charge the user for the flavor
        updateSales(charge);

        //dont really need this printing flavors twice
        /*cout<<"Your flavors are:\n";
        for(string x: iceCream)
        {
            cout << x << endl;
        }*/
        cout << endl;
    }while(flag);

    return charge;
}

//this function updates the sales for how many obejects is made.
//calculates total.
double Dessert::updateSales(double & srcAdd)
{
    totalSales += srcAdd;
    return 1.0;
}

//compares less_than_or_equal
bool Dessert::less_than_or_equal(const Dessert * to_comp)
{
    return (to_comp->productNum < productNum);
}

//this function compares for greater than on prod num
bool Dessert::greater_than(const Dessert * new_data)
{
    return(new_data->productNum > productNum);
}

bool operator == (const Dessert & src,const Dessert & obj2)
{
    if(src.productNum == obj2.productNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator == (const Dessert & src,const int & pNum)
{
    if(src.productNum == pNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool operator == (const int & pNum,const Dessert & src)
{
    if(pNum == src.productNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//constructor of IceCreamCake class
IceCreamCake::IceCreamCake() : size("empty") , numLayers(0)
{}

//initialization list
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
    Dessert::displayProduct();
    cout <<"The size of the cake is:" << size << endl;
    cout<<"The num of Layers is :" << numLayers << endl;
    return 1;
}


//This function allows the user to choose a size for the icecream
string IceCreamCake::chooseSize() // large only
{
    string cakeSize = "";
    int sizeChoice {0};
    double charge {0};

    //prompt the user what size they want
    cout<<"What size cake do you want?\n";
    cout<<"Enter 1 for MEDIUM\n";
    cout<<"Enter 2 for LARGE\n";
    cin>> sizeChoice;
    cin.ignore(100,'\n');

    if(sizeChoice == 1)
    {
        size = "MEDIUM";
        cakeSize = "MEDIUM";
        //charge them for the size
        charge = MEDCAKE;
        updateSales(charge);
    }
    else
    {
        size = "LARGE";
        cakeSize = "LARGE";
        charge = LARGCAKE;
        updateSales(charge);
    }

    return cakeSize;
}

//this function adds on toppings to cake
double IceCreamCake::addOns()
{

    int choice =0;
    double temp {0};

    //prompt the user if they want to expdite the cake making process
    cout <<"what you like to pay extra to finish the cake faster?\n";
    cout <<"It would be another 10.99 to expedite the cake\n";
    cout <<"1. YES\n";
    cout <<"2. NO\n";

    cin>> choice;
    cin.ignore(100,'\n');

    if(choice == 1)
    {
        temp = EXPEDITE;
        updateSales(temp);
        return temp;
    }
    else{
        return 0.0;
    }
}
//end of virtual functions
int IceCreamCake::pickLayers()
{
    int layers {0};
    double charge {0.0};

    cout<<"How many layers do you want to have on the cake\n";
    cin >> layers;
    cin.ignore(100,'\n');

    numLayers = layers;

    //if 0 means theres only 1 layer
    if(layers == 0)
    {
        return 0;
    }

    //update sales
    charge = EXTRLAYERS * static_cast<double>(layers); 
    updateSales(charge);

    return 1;
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
    //call the base class displayproduct
    Dessert::displayProduct();
    cout<< "The size of container is:"<< volume <<"oz\n";
    cout<< "The container type is:" <<container << endl;

    //iterate through the vector
    for(string y: toppings)
    {
        cout << y << ", ";
    }

    return 1;
}
double MilkShake::addOns()
{

    int choice =0;
    int keepGoing {1};
    string temp = "";
    double charge {ADDTOP};

    //this do while loop allows the user to pick toppings
    do{
        cout <<"what flavor do you want?\n";
        cout <<"1. CHERRIES\n";
        cout <<"2. NUTS\n";
        cout <<"3. COCONUT\n";
        cout <<"4. FUDGE\n";
        cout <<"5. CARAMEL\n";
        cout <<"6. OREO\n";
        cout <<"7. QUIT\n"; 
        cin>> choice;
        cin.ignore(100,'\n');

        switch(choice)
        {
            case 1:
                temp = "CHERRIES";
                break;
            case 2:
                temp = "NUTS";
                break;
            case 3: 
                temp = "COCONUT";
                break;
            case 4:
                temp = "FUDGE";
                break;
            case 5:
                temp = "CARAMEL";
                break;
            case 6:
                temp = "OREO";
                break;
            case 7:
                cout <<"Back to the Dessert Menu!\n";
                keepGoing = 99;
                break;
            default:
                break;
        }
        //push onto vector of toppings
        toppings.push_back(temp);

        //charge the user for the flavor
        updateSales(charge);
    }while(keepGoing == 1);
    return 0.0;
}
// changes to int to store in volume in data member
string MilkShake::chooseSize()
{
    string tempVolume = "";
    int option {0};
    double charge {0};

    cout<<"What size cup do you want\n";
    cout<<"1. 8oz\n";
    cout<<"2. 12oz\n";
    cout<<"3. 16oz\n";

    cin >> option;
    cin.ignore(100,'\n');

    //option 8oz
    if(option == 1)
    {
        volume = 8;
        tempVolume = "8oz";
        charge = SMALLSHAKE;
        updateSales(charge);
    }
    //option 12oz
    if(option == 2)
    {
        volume = 12;
        tempVolume = "12oz";
        charge = MEDSHAKE;
        updateSales(charge);
    }

    // option 16oz
    if(option == 3)
    {
        volume = 16;
        tempVolume = "16oz";
        charge = LARGESHAKE;
        updateSales(charge);
    }

    return tempVolume;
}
//end of virtual functions,// glass, foam
//allows user to select container
//user is not charged
string MilkShake::chooseContainer()
{
    int choice {0};
    string tcontain= "";
    cout << "what container do you want to use\n";
    cout << "You won't be charged for this option\n";
    cout << "1.Glass\n";
    cout << "2.Plastic\n";

    cin >> choice;
    cin.ignore(100,'\n');

    if(choice == 1)
    {
        container = "GLASS";
        tcontain = "GLASS";
    }
    else
    {
        container = "PLASTIC";
        tcontain = "PLASTIC";
    }
    return tcontain;
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
    coneSize = "empty";

}

//virtual function
int WaffleCone::displayProduct() const
{
    //call the base class diplay first
    Dessert::displayProduct();
    cout<<"The cone size is: "<< coneSize <<endl;
    cout<<"The toppings include: ";

    //iterate through the vector
    for(string y: toppings)
    {
        cout << y << ", ";
    }
    return 1;
}

//choose cone size for waffle cone
string WaffleCone::chooseSize()
{
    int option {0};
    string temp = "";
    double charge {0};

    cout<<"What waffle cone size would you like\n";
    cout<<"1. SMALL\n";
    cout<<"2. MEDIUM\n";
    cout<<"3. LARGE\n";

    cin>> option;
    cin.ignore(100,'\n');

    if(option == 1)
    {
        temp = "SMALL";
        coneSize = "SMALL";
        //charge the user
        charge = SMALLCONE;
        updateSales(charge);
    }
    if(option == 2)
    {
        temp = "MEDIUM";
        coneSize = "MEDIUM";
        //charge the user
        charge = MEDCONE;
        updateSales(charge);
    }
    if(option == 3)
    {
        temp = "LARGE";
        coneSize = "LARGE";
        //charge the user
        charge = LARGCONE;
        updateSales(charge);
    }

    return temp;
}

double WaffleCone::addOns()
{
    int choice =0;
    int keepGoing {1};
    string temp = "";
    double charge {ADDTOP};

    //this do while loop allows the user to pick toppings
    do{
        cout <<"what flavor do you want?\n";
        cout <<"1. CHERRIES\n";
        cout <<"2. NUTS\n";
        cout <<"3. COCONUT\n";
        cout <<"4. FUDGE\n";
        cout <<"5. CARAMEL\n";
        cout <<"6. OREO\n";
        cout <<"7. QUIT\n"; 
        cin>> choice;
        cin.ignore(100,'\n');

        switch(choice)
        {
            case 1:
                temp = "CHERRIES";
                break;
            case 2:
                temp = "NUTS";
                break;
            case 3: 
                temp = "COCONUT";
                break;
            case 4:
                temp = "FUDGE";
                break;
            case 5:
                temp = "CARAMEL";
                break;
            case 6:
                temp = "OREO";
                break;
            case 7:
                cout <<"Back to the Dessert Menu!\n";
                keepGoing = 99;
                break;
            default:
                break;
        }
        //push onto vector of toppings
        toppings.push_back(temp);

        //charge the user for the flavor
        updateSales(charge);
    }while(keepGoing == 1);

    return 1.1;
}

//end of virtual functions
string WaffleCone::chooseCone()
{
    return "string";
}

