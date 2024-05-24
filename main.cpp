#include "btree.h"

int main()
{
    Dessert * dessert;    
    //data structure
    Btree myStore;
    int choice {0};    
    string srcSize = "";

    cout <<"1. Put an order\n";
    cout <<"2. Display order\n";
    cout <<"3. Quit\n";

    cin >> choice;
    cin.ignore(100,'\n');

    if(choice == 1)
    {
        int option {0};
        //gather data
        cout<<"What dessert do you want to buy?\n";
        cout<<"1. IceCream cake\n";
        cout<<"2. Milkshake\n";
        cout<<"3. WaffleCone\n";
        cin >> option;
        cin.ignore(100,'\n');

        if(option == 1)
        {
            IceCreamCake obj1;
            //dessert is a pointer of the base class
            dessert = &obj1;

            cout<<"What flavor do you want the base to be?\n";

            //ice cream class just has size and numLayer. num layers is based on size.
            cout<<"What size cake do you want";
            dessert->chooseFlavor();
            cout<<"Medium or Large";
            cin>> srcSize;
            cin.ignore(100, '\n');

            //myStore.insert(data);
        }
        if(option == 2)
        {
            MilkShake obj2;
        }
        if(option == 3)
        {
            WaffleCone obj3;
        }
    }
}
