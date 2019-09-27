/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <istream>

#define SIZE 500
using namespace std;

struct shipment{
    int product;
    int quantity;
    int customer;
    int day;
    int month;
    int year;
    bool confirmed;
    bool urgent;
};

struct customer{
    char name[SIZE];
    char streetAddress[SIZE];
    char city[SIZE];
    char state[10];
    int zip;
    char phone[20];
};

void printMenu ()
{
  cout<<"Please choose an option below:" <<endl;
  cout<<"1. Create a new shipment." <<endl;
  cout<<"2. Print a shipment list." << endl;
  cout<<"3. Cancel a shipment." << endl;
  cout<<"4. Add a new customer." <<endl;
  cout<<"5. Print a customer list." << endl;
  cout<<"6. Delete a customer." << endl;
  
}

void printCust(int custCount, customer custList)
{
    int i; 
    for (i=0; i<=custCount; i++)
    {
        cout << endl << (i+1)<< ". " << custList.name << " " << custList.streetAddress;
        cout <<  " " << custList.city <<  " " << custList.state;
        cout << " " <<  custList. zip <<  " " << custList.phone << endl;
    }
}

customer editCust (customer editCust){
    int choice;
    customer tempCust;
    cout << "What would you like to edit?" << endl;
    cout << "1. Name." << endl << "2. Address." << endl << "3. Phone." << endl;
    cin >> choice;
    switch (choice)
    {
        case 1:
        {
            cout<<"Please enter the customer's full name: " << endl;
            gets(tempCust.name); //consume newline
            cin.getline (tempCust.name,SIZE);
            break;
        }
        case 2:
        {
            cout<<"Please enter the customer's street address: " << endl;
            gets(tempCust.name); //consume newline
            cin.getline (tempCust.streetAddress,SIZE);
            cout<<"Please enter the customer's city: " << endl;
            cin.getline (tempCust.city,SIZE);
            cout<<"Please enter the customer's state using 2 characters: ";
            cout<<"(example Indiana = IN)" << endl;
            cin.getline (tempCust.state,10);
            cout<<"Please enter the customer's zip code: " << endl;
            cin >> editCust.zip;
            break;
        }
        case 3: 
        {
            cout<<"Please enter the customer's telephone number using the ";
            cout<<"following format 310-867-5309";
            gets(tempCust.name); //consume newline
            cin.getline (tempCust.phone,12);
            break;
        }
        
    }
    
}

customer getCust()
{
    customer newCust;
    char choice ='n';
    int choice2;
    cout<<"Please enter the customer's full name: " << endl;
    gets(newCust.name); //consume newline
    cin.getline (newCust.name,SIZE);
    cout<<"Please enter the customer's street address: " << endl;
    cin.getline (newCust.streetAddress,SIZE);
    cout<<"Please enter the customer's city: " << endl;
    cin.getline (newCust.city,SIZE);
    cout<<"Please enter the customer's state using 2 characters: ";
    cout<<"(example Indiana = IN)" << endl;
    cin.getline (newCust.state,10);
    cout<<"Please enter the customer's zip code: " << endl;
    cin >> newCust.zip;
    gets(newCust.name); //consume newline
    cout<<"Please enter the customer's telephone number using the ";
    cout<<"following format 310-867-5309";
    cin.getline (newCust.phone,20);

    while (choice != 'y')
    {
        cout<<"You entered:";
        gets(newCust.name); //consume newline
        printCust(0, newCust);
        cout<< "Is this correct (y or n)" << endl;
        cin >> choice;
        if (choice =='n')
        newCust = editCust(newCust);
    }
    
    return newCust;
}


int main()
{
    int choice, customerCount;
    customer myCust[SIZE];
    customerCount = 0;
    
    cout<<"Welcome to the shipping editor." << endl;
    printMenu();
    cin>>choice;
    switch(choice)
    {
        case 1:
            if (customerCount ==0)
                cout << "Error: you have no customers. Enter a customer first" << endl;
            
            break;
        case 4:
        {
            myCust[customerCount]=getCust();
            cout << myCust[0].name;
        }
    }
    return 0;
}
