/* Marcos Chavez, CS302, Karla Fant in person, the purpose of this 
file is to serve as the application of the program where the user
can use the program.
*/

#include "btree.h"

int main()
{
    //data structure
    Btree myStore;
    int choice {0};
    int main_choice {1};
    string srcSize = "";

    cout<<"Dessert Shop Menu!\n";
    cout<<"1. Put an order\n";
    cout<<"2. Display order\n";
    cout<<"3. \n";
    cout<<"4. Quit\n";

    cin >> choice;
    cin.ignore(100,'\n');

    do{
        //this first if statement allows for input
        if(choice == 1)
        {
            int option {0};
            //gather data
            cout<<"What dessert do you want to buy?\n";
            cout<<"1. IceCream cake\n";
            cout<<"2. Milkshake\n";
            cout<<"3. WaffleCone\n";
            cout<<"4. Go Back to Dessert Shop menu\n";
            cin >> option;
            cin.ignore(100,'\n');
            
            //This inserts a IceCreamCake object
            if(option == 1)
            {
                Dessert * temp = new IceCreamCake();

                //ice cream class just has size and numLayer. num layers is based on size.
                cout<<"What size cake do you want";
                temp->chooseFlavor();
                temp->chooseSize();
                temp->addOns();

                cout <<"The cake is this:"<< temp->displayProduct() <<endl;
                myStore.insert(temp);
                
                //clean up memory 
                delete temp;
            }

            //This inserts a Milkshake object
            if(option == 2)
            {
                Dessert * temp = new MilkShake();
                
                //Milk shake class just has volume and container. 
                //num layers is based on size.
                cout<<"What size cake do you want";
                temp->chooseSize();

                //use rtti to be able to access choose container here
                MilkShake * milkshakePtr = dynamic_cast<MilkShake*>(temp);
                //check if its pointing at something
                if(milkshakePtr)
                {
                    milkshakePtr->chooseContainer();
                }
                else
                {
                    cerr<< "failed to downcast to Milkshake\n";
                }

                cout <<"The cake is this:"<< temp->displayProduct() <<endl;
                myStore.insert(temp);
                
                //clean up memory 
                delete temp;
                delete milkshakePtr;
            }
            
            //This inserts a Wafflecone object
            if(option == 3)
            {
                Dessert * temp = new WaffleCone();
                
                //WaffleCone class just has coneSize and toppings.
                cout<<"What size cake do you want";
                temp->chooseFlavor();
                temp->chooseSize();

                cout <<"The cake is this:"<< temp->displayProduct() <<endl;
                myStore.insert(temp);
                
                //clean up memory 
                delete temp;
            }

            //go back to 
            if(option == 4)
            {
                choice = 4;
            }
        }

        //display the order
        if(choice == 2)
        {

        }
    }
    while(main_choice == 1);
}
