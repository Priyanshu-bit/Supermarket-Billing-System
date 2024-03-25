#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping:: menu()
{
    m:
    int choice;
    string email;
    string password;
 cout << "\t\t\t\t\t\t\t\t\t\t\t SUPER MARKET MAIN MENU" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 1. Administrator" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 2. Buyer" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 3. Exit" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Enter your choice: ";
    cin >> choice;  

    switch (choice)
    {
    case 1:
        cout << "\t\t\t\t\t\t\t\t\t\t\t Please Login \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Email: ";
        cin >> email;
        cout << "\t\t\t\t\t\t\t\t\t\t\t Enter Password: ";
        cin >> password;    
        if (email == "I7DZi@example.com" && password == "12345")
        {
            administrator();
        }
        else
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t Invalid email/password" << endl;
        }
        break;      

    case 2:
        buyer();
        break;

    case 3:
        exit(0);
        break;

    default:
        cout << "\t\t\t\t\t\t\t\t\t\t\t Please select from the given options" << endl;
    }
    goto m;
}

void shopping:: administrator()
{
    m:
    int choice;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Administrator menu" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 1. Add the product" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 2. Edit the product" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 3. Delete the product" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 4. Back to main menu" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Enter your choice: ";
    cin >> choice;  

    switch (choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout << "\t\t\t\t\t\t\t\t\t\t\t Invalid choice" << endl;
    }
    goto m;
}

void shopping:: buyer()
{
    m:
    int choice;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Buyer" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 1. Buy product" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t 2. Go back" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;

    case 2:
        menu();
        break;

    default:
        cout << "\t\t\t\t\t\t\t\t\t\t\t Invalid choice" << endl;
    }
    goto m;
}

void shopping:: add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p; 
    float d;
    string n;

    cout << "\t\t\t\t\t\t\t\t\t\t\t Add new product" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Product code of the product: ";
    cin >> pcode;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Name of the product: ";
    cin >> pname;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Price of the product: ";
    cin >> price;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Discount on the product: ";
    cin >> dis;

    data.open("database.txt", ios::in);
    if(!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof()) 
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    
        if (token == 1)
        {
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            data.close();
        }
    }

    cout << "\t\t\t\t\t\t\t\t\t\t\t Record inserted successfully" << endl;
}

void shopping:: edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Modify record" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Enter product code: ";
    cin >> pkey;    

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t File doesn't exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\t\t\t\t\t\t\t\t\t\t\t Product new code: ";
                cin >> c;
                cout << "\t\t\t\t\t\t\t\t\t\t\t Name of the product: ";
                cin >> n;
                cout << "\t\t\t\t\t\t\t\t\t\t\t Product new price: ";
                cin >> p;
                cout << "\t\t\t\t\t\t\t\t\t\t\t Product new discount: ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << endl;
                cout << "\t\t\t\t\t\t\t\t\t\t\t Record edited" << endl;
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t Record not found" << endl;
        }
    }
}

void shopping:: rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Delete product" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Enter product code: ";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t File doesn't exist" << endl;
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\t\t\t\t\t\t\t\t\t\t\t Product deleted successfully" << endl;
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << endl;
            }
            data >> pcode >> pname >> price >> dis; 
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t Record not found" << endl;
        }
    }
}

void shopping:: list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\t\t\t\t\t\t\t\t\t\t\t Product list" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t ------------------" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t Pcode" << " | " << "Pname" << " | " << "Price" << " | " << "Discount" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\t ------------------" << endl;
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t " << pcode << " | " << pname << " | " << price << " | " << dis << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping:: receipt()
{
    fstream data;
    int arrc[50];
    int arrq[50];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\t\t\t\t\t\t\t\t\t\t\t RECEIPT" << endl;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t File doesn't exist" << endl;
    }
    else
    {
        data.close();
        list();
        cout << "\t\t\t\t\t\t\t\t\t\t\t Please place the order" << endl;
        do
        {
            m:
            cout << "\t\t\t\t\t\t\t\t\t\t\t Enter product code: ";
            cin >> arrc[c];
            cout << "\t\t\t\t\t\t\t\t\t\t\t Enter product quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\t\t\t\t\t\t\t\t\t\t\t Duplicate product code. Please try again" << endl;
                    goto m;
                }
            }
            c++;
            cout << "\t\t\t\t\t\t\t\t\t\t\t Do you want to buy another product? (y/n)";
            cin >> choice;
        } while (choice == 'y');
        cout << "\t\t\t\t\t\t\t\t\t\t\t Receipt" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t -------------------" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t Pcode" << " | " << "Pname" << " | " << "Quantity" << " | " << "Price" << " | " << "Amount" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t -------------------" << endl;
        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    total = total + amount;
                    cout << "\t\t\t\t\t\t\t\t\t\t\t " << pcode << " | " << pname << " | " << arrq[i] << " | " << price << " | " << amount << endl;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        cout << "\t\t\t\t\t\t\t\t\t\t\t -------------------" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t Total Amount: " << total << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t -------------------" << endl;
    }
}

int main()
{
    shopping s;
    s.menu();
    return 0;
}