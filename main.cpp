/* Marcos Chavez, CS302, Karla Fant in person, the purpose of this 
   file is to serve as the application of the program where the user
   can use the program.
 */

#include "btree.h"

int main()
{
    //data structure
    Btree myOrder;
    int shopChoice {0};
    bool shopKeepgoing = true;
    string srcSize = "";

    //do while loop for shop menu
    do{
        cout<<"Dessert Shop Menu!\n";
        cout<<"1. Put an order\n";
        cout<<"2. Display order\n";
        cout<<"3. Remove item from order\n";
        cout<<"4. Quit\n";

        cin >> shopChoice;
        cin.ignore(100,'\n');

        //this first if statement allows for input
        if(shopChoice == 1)
        {
            //variables for menu
            bool keepGoing = true;
            //do while loop
            do{
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

                    //ice cream class just has size and numLayer.
                    //num layers is based on size.
                    temp->chooseFlavor();
                    temp->chooseSize();
                    temp->addOns();
                    
                    //
                    //cout <<"IceCream summary\n";
                    //cout <<"The cake is this:\n"<< temp->displayProduct() <<endl;
                    myOrder.insert_dessert(temp);

                    //clean up memory 
                    delete temp;
                }

                //This inserts a Milkshake object
                if(option == 2)
                {
                    Dessert * temp = new MilkShake();

                    //Milk shake class just has volume and container. 
                    //num layers is based on size.
                    temp->chooseFlavor();
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
                        exit(EXIT_FAILURE);
                    }
                    
                    //
                    milkshakePtr->addOns();
                    
                    //add to the btree
                    myOrder.insert_dessert(temp);
                }

                //This inserts a Wafflecone object
                if(option == 3)
                {
                    Dessert * temp = new WaffleCone();

                    //WaffleCone class just has coneSize and toppings.
                    temp->chooseFlavor();
                    temp->chooseSize();

                    myOrder.insert_dessert(temp);

                    //clean up memory 
                    delete temp;
                }

                //go back to the menu
                if(option == 4)
                {
                    keepGoing = false;
                }

            }while(keepGoing == true);
        }

        //display the order
        if(shopChoice == 2)
        {
            myOrder.displayAll();
        }
        
        //remove items from order
        /*if(shopChoice == 3){
            
        }*/
        //quit the menu
        if(shopChoice == 4)
        {
            shopKeepgoing = false;
        }

    }
    while(shopKeepgoing == true);
}
