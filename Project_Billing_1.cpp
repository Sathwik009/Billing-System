#include <bits/stdc++.h>
using namespace std;
class shopping
{
private:
    int prod_code;
    float prod_price;
    float discount;
    string prod_name;

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
void shopping ::menu()
{
m:
    int choice;
    string email;
    string password;

    cout << "___________________________\n";
    cout << "\n";
    cout << "         Main Menu         \n";
    cout << "___________________________\n";
    cout << "\n";
    cout << " 1. Administrator\n";
    cout << "\n";
    cout << " 2. Buyer\n";
    cout << "\n";
    cout << " 3. Exit\n";
    cout << "\n";
    cout << " Please Select your choice from the above\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Login\n";
        cout << " Enter your Email Id \n";
        cin >> email;
        cout << "Enter your password\n";
        cin >> password;
        if (email == "sathwikpadigela@gmail.com" && password == "asdfasdf")
            administrator();
        else
            cout << "Invalid Credentials\n";
        break;
    case 2:
        buyer();
    case 3:
        exit(0);
    default:
        cout << " Invalid Choice, Please select one from the above options";
    }
    goto m;
}
void shopping ::administrator()
{
m:
    int choice;
    cout << "Administrator Menu\n";
    cout << " 1. Add Product\n";
    cout << " 2. Modify Product\n";
    cout << " 3. Delete Product\n";
    cout << " 4. Main Menu\n";
    cout << " Please enter your choice from the above\n";
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
        cout << "Invalid Choice, Please select one from the above options\n";
    }
    goto m;
}
void shopping ::buyer()
{
m:
    int choice;
    cout << "1.Buy Product\n";
    cout << "2.Go back\n";
    cout << "Enter your choice : \n";
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
        cout << "Invalid Choice, Please select one from the above options\n";
    }
    goto m;
}
void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "Add new product\n";
    cout << "Enter the product code\n";
    cin >> prod_code;
    cout << "Enter the product name\n";
    cin >> prod_name;
    cout << "Enter the product price\n";
    cin >> prod_price;
    cout << "Enter the discount on product\n";
    cin >> discount;

    // if the file is empty we add directly but if it isn't empty we check for duplicacy and then add the details
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << prod_code << " " << prod_name << " " << prod_price << " " << discount << "\n"; // writing in a file
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;
        while (!data.eof())
        { // eof=end of file;
            if (c == prod_code)
                token++;
            data >> c >> n >> p >> d;
        }
        data.close();
        if (token == 1)
        {
            cout << "Product already exists\n";
            goto m;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << prod_code << " " << prod_name << " " << prod_price << " " << discount << "\n";
            data.close();
        }
    }
    cout << "Details of the product are saved successfully !\n";
}
void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "Enter the product code which you want to modify : \n";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File doesn't exist\n";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> prod_code >> prod_name >> prod_price >> discount; // reading in a file
        while (!data.eof())
        {
            if (pkey == prod_code)
            {
                cout << " Product new code\n";
                cin >> c;
                cout << " Name of the product\n";
                cin >> n;
                cout << " Enter the price of the product\n";
                cin >> p;
                cout << " Discount\n";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << " Record Modified Successfull !\n";
                token++;
            }
            else
            {
                data1 << " " << prod_code << " " << prod_name << " " << prod_price << " " << discount << "\n";
            }
            data >> prod_code >> prod_name >> prod_price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
            cout << "Record not found\n";
    }
}
void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << " Enter the product code which you want to delete\n";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
        cout << " File doesn't exist\n";
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> prod_code >> prod_name >> prod_price >> discount;
        while (!data.eof())
        {
            if (prod_code == pkey)
            {
                cout << "Product Deleted Successfully !\n";
                token++;
            }
            else
            {
                data1 << " " << prod_code << " " << prod_name << " " << prod_price << " " << discount << "\n";
            }
            data >> prod_code >> prod_name >> prod_price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
            cout << "Record Not Found\n";
    }
}
void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n";
    cout << "Prod No    Product Name       Price\n\n";
    data >> prod_code >> prod_name >> prod_price >> discount;
    while (!data.eof())
    {
        cout << prod_code << "\t\t" << prod_name << "\t\t" << prod_price << endl;
        data >> prod_code >> prod_name >> prod_price >> discount;
    }
    data.close();
}
void shopping::receipt()
{
    fstream data;
    int code[10010], quantity[10010];
    string choice;
    int c = 0, i;
    float total = 0, amount, disc;
    cout << "\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt", ios::in);
    if (!data)
        cout << " Empty database\n";
    else
    {
        data.close();
        list();
        cout << "\n___________________________________\n";
        cout << "\n|                                  \n";
        cout << "      Please Place the Order         \n";
        cout << "\n___________________________________\n";
        do
        {
        m:
            cout << "\n Enter the product code : ";
            cin >> code[c];
            cout << "\n\nEnter the product quantity : ";
            cin >> quantity[c];
            for (int i = 0; i < c; i++)
            {
                if (code[c] == code[i])
                {
                    cout << "\n Duplicate product code, Please try again";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? If yes, press 'y'; otherwise, press 'n': ";
            cin >> choice;
        } while (choice == "y");

        cout << "\n\n\t\t\t________________RECEIPT______________\n";
        cout << "\n Product No\t Product Name\t Product quantity\t price\t Amount\t Amount after discount\n";

        data.open("database.txt", ios::in);
        while (data >> prod_code >> prod_name >> prod_price >> discount)
        {
            for (i = 0; i < c; i++)
            {
                if (prod_code == code[i])
                {
                    amount = prod_price * quantity[i];
                    disc = amount - (amount * discount / 100);
                    total += disc;
                    cout << "\n"
                         << prod_code << "\t\t" << prod_name << "\t\t" << quantity[i] << "\t\t\t" << prod_price << "\t" << amount << "\t\t" << disc;
                    break; // Break the loop once the matching product is found
                }
            }
        }
        data.close();
    }
    cout << "\n\n________________________________________";
    cout << "\n Total Amount : " << total << endl;
}
int main()
{
    shopping s;
    s.menu();
}
/*
    Administrator Login Credentials : 
        mail id: sathwikpadigela@gmail.com 
        password: asdfasdf 
    Initially There is no data stored, you need to login through administrator credentials and add data. */
