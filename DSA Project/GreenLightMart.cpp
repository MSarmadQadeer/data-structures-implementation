#include <iostream>
#include <fstream>

using namespace std;

int main();

string checkedInputThroughStringForMain(string checkingString)
{
    for (int i = 0; true; i++)
    {
        string val;
        cout << "Choose : ";
        cin >> val;
        int index = checkingString.find(val);
        if (index != -1)
        {
            return val;
        }
        else if (i == 3)
        {
            exit(0);
        }
        else
        {
            cout << "\nKINDLY THE RIGHT VALUE" << endl;
            cout << "You have ";
            cout << 3 - i;
            cout << " more Chances Left" << endl;
        }
    }
}

string checkedInputThroughString(string checkingString)
{
    for (int i = 0; true; i++)
    {
        string val;
        cout << "Choose : ";
        cin >> val;
        int index = checkingString.find(val);
        if (index != -1)
        {
            return val;
        }
        else if (i == 3)
        {
            main();
            exit(0);
        }
        else
        {
            cout << "\nKINDLY THE RIGHT VALUE" << endl;
            cout << "You have ";
            cout << 3 - i;
            cout << " more Chances Left" << endl;
        }
    }
}

struct Item
{
    string name;
    int totalQuantity;
    double price;
    Item *next = NULL;
    Item *previous = NULL;
};

Item *first = NULL;
Item *last = NULL;

void readItems()
{
    fstream productsFile;
    productsFile.open("products.txt", ios::in);
    if (!productsFile)
    {
        return;
    }
    while (!productsFile.eof())
    {
        Item *current = new Item();
        productsFile >> current->name;
        productsFile >> current->totalQuantity;
        productsFile >> current->price;
        if (first == NULL)
        {
            first = last = current;
        }
        else
        {
            last->next = current;
            current->previous = last;
            last = current;
        }
    }
    productsFile.close();
}

void writeItems()
{
    Item *p = first;
    fstream productsFile;
    productsFile.open("products.txt", ios::out);
    while (p)
    {
        productsFile << "\n"
                     << p->name << " " << p->totalQuantity << " " << p->price;
        p = p->next;
    }
}

void sellItem()
{
    int quantity;
    double price;
    string name;
    cout << "Enter Product Name : ";
    cin >> name;
    bool match = false;
    Item *p = first;
    while (p)
    {
        if (p->name == name)
        {
            match = true;
            break;
        }
        p = p->next;
    }
    if (match)
    {
        cout << "Enter Quantity : ";
        cin >> quantity;
        p->totalQuantity += quantity;
    }
    if (!match)
    {
        cout << "Enter Quantity : ";
        cin >> quantity;
        cout << "Enter Price : ";
        cin >> price;
        Item *current = new Item();
        current->name = name;
        current->totalQuantity = quantity;
        current->price = price;
        if (first == NULL)
        {
            first = last = current;
        }
        else
        {
            last->next = current;
            current->previous = last;
            last = current;
        }
    }
}

void displayItems()
{
    if (first == NULL)
        readItems();
    Item *p = first;
    cout << "\n\n<--- List of Items --->\n\n";
    if (!p)
    {
        cout << "\nNo Products Registered Yet" << endl;
        return;
    }
    while (p)
    {
        printf("%-16s | %5.2f\n", (p->name).c_str(), p->price);
        p = p->next;
    }
}

Item *findItem(string name)
{
    if (first == NULL)
        readItems();
    Item *p = first;
    while (p)
    {
        if (p->name == name)
            return p;
        p = p->next;
    }
    return NULL;
}

bool signIn()
{
    bool verified = false;
    string username;
    string password;
    string fusername;
    string fpassword;
    fstream seller;
    seller.open("sellers.txt", ios::in);
    if (!seller)
    {
        cout << "\nNo seller Registered Yet" << endl;
        return verified;
    }
    cout << "Enter Username : ";
    cin >> username;
    while (!seller.eof())
    {
        seller >> fusername;
        seller >> fpassword;
        if (username == fusername)
            break;
    }
    seller.close();
    if (username == fusername)
    {
        cout << "Enter Password : ";
        cin >> password;
        if (password == fpassword)
        {
            verified = true;
        }
    }
    else
    {
        cout << "\nSeller of this Name is not Registered Yet" << endl;
    }
    return verified;
}

void signUp()
{
    string username;
    string password;
    string cpassword;
    fstream seller;
    seller.open("sellers.txt", ios::out | ios::app);
    cout << "Enter Username : ";
    cin >> username;
    cout << "Enter Password : ";
    cin >> password;
    cout << "Confirm Password : ";
    cin >> cpassword;
    seller << "\n"
           << username << " " << password;
    seller.close();
}

void sellerPerformFunctionality()
{
    if (first == NULL)
        readItems();

    while (true)
    {
        std::cout << "\n<---    Welcome To Sellers Room    --->" << std::endl;
        std::cout << "--------------------------------------\n"
                  << std::endl;
        std::cout << "(1) Sign in  (2) Sign up  (0) Move Back " << std::endl;
        std::string sellerSigningOption = checkedInputThroughString(" 0 1 2 ");
        if (sellerSigningOption == "1")
        {
            if (signIn())
            {
                while (true)
                {
                    cout << "\nPRESS 1 TO SELL" << endl;
                    cout << "PRESS 0 TO MOVE BACK" << endl;
                    string sellerMenuOption = checkedInputThroughString(" 0 1 ");
                    if (sellerMenuOption == "1")
                    {
                        sellItem();
                        writeItems();
                    }
                    else if (sellerMenuOption == "0")
                    {
                        break;
                    }
                }
            }
        }
        else if (sellerSigningOption == "2")
        {
            signUp();
        }
        else if (sellerSigningOption == "0")
        {
            main();
            exit(0);
        }
    }
}

double bill = 0; // for calculating customer bill

void customerPerformFunctionality()
{
    while (true)
    {
        cout << "\n<---   Welcome To Customer Room   --->" << endl;
        cout << "--------------------------------------\n"
             << endl;
        cout << "(1) To view Items List" << endl;
        cout << "(2) To Buy" << endl;
        cout << "(3) To Checkout" << endl;
        cout << "(0) To MOVE BACK" << endl;
        string choose = checkedInputThroughString(" 0 1 2 3 ");
        Item P;
        if (choose == "1")
        {
            displayItems();
        }
        else if (choose == "2")
        {
            string name;
            int quantity;
            cout << "Enter Product Name : ";
            cin >> name;
            Item *searchedItem = findItem(name);
            if (searchedItem)
            {
                if (searchedItem->totalQuantity == 0)
                {
                    cout << "\nThis Product is out of stock" << endl;
                }
                else
                {
                    cout << "Enter Quantity : ";
                    cin >> quantity;
                    if (quantity > searchedItem->totalQuantity)
                    {
                        cout << "\nSORRY ... That much Items are not Available" << endl;
                    }
                    else
                    {
                        searchedItem->totalQuantity -= quantity;
                        writeItems(); // To update quantity on file.
                        bill += quantity * searchedItem->price;
                    }
                }
            }
            else
            {
                cout << "\nThis Product is not Available" << endl;
            }
        }
        else if (choose == "3")
        {
            cout << "Your Total Bill is " << bill << endl;
            bill = 0;
        }
        else if (choose == "0")
        {
            main();
            exit(0);
        }
    }
}

int main()
{
    cout << "-------------------------------------" << endl;
    cout << "<--- Welcome To Green Light Mart --->" << endl;
    cout << "-------------------------------------" << endl;
    string mainMenu;
    while (true)
    {
        cout << "\nWho Are You ?" << endl;
        cout << "      ( 1 )  Seller" << endl;
        cout << "      ( 2 )  Customer" << endl;
        cout << "      ( 0 )  To Exit" << endl;
        mainMenu = checkedInputThroughStringForMain(" 1 2 0");
        //---Seller---
        if (mainMenu == "1")
        {
            sellerPerformFunctionality();
        }
        //---Customer
        else if (mainMenu == "2")
        {
            customerPerformFunctionality();
        }
        //---Exit
        else if (mainMenu == "0")
        {
            exit(0);
        }
    }
}
