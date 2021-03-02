/*
    @uthor: Varun Mishra
    "varun21999" ->  Codechef, Codeforce, Hackerrank, Hackerearth;
*/
#include <bits/stdc++.h>
using namespace std;

class shoping
{
    char batch_no[10];
    char item_name[26];
    float item_cost;
    int pq;

public:
    void input();
    void display();
    int checkpc(char ac[])
    {
        return strcmp(batch_no, ac);
    }
    void modify();
} s, sh;
void shoping::modify()
{
    cout << "Product Name: " << item_name << endl;
    cout << "Product Code: " << batch_no << endl;
    cout << "Product Cost: " << item_cost << endl;
    cout << "Product Quantity: " << pq << endl;
    char pn[2] = " ", pc[2] = " ";
    float pcs;
    int pqq;
    cout << "New Item Name:(Enter '.' to retain old one)";
    cin >> pn;
    cout << "New Item code:(Enter '.' to retain old one)";
    cin >> pc;
    cout << "New Item Price:(Enter '0' to retain old one)";
    cin >> pcs;
    cout << "New Item Quantity:(Enter '0' to retain old one)";
    cin >> pqq;
    if (strcmp(pn, ".") != 0)
        strcpy(item_name, pn);
    if (strcmp(pc, ".") != 0)
        strcpy(batch_no, pc);
    if (pcs != 0)
        item_cost = pcs;
    if (pqq != 0)
        pq = pqq;
}
void add()
{
    ofstream fo;
    fo.open("items.dat", ios::app | ios::binary);
    char ans = 'y';
    while ((ans == 'y') || (ans == 'Y'))
    {
        s.input();
        fo.write((char *)&s, sizeof(s));
        cout << "Item added to file!!\n";
        cout << "Want to Add more items(y/n):- ";
        cin >> ans;
    }
    fo.close();
}
void firmod()
{
    fstream fio;
    fio.open("items.dat", ios::in | ios::out | ios::binary);
    char mpc[10];
    long pos;
    char found = 'f';
    cout << "\nEnter the Product code to be modified:-";
    cin >> mpc;
    while (!fio.eof())
    {
        pos = fio.tellg(); //befor reading a record its begining pos is determined with tellg()
        fio.read((char *)&s, sizeof(s));
        if (s.checkpc(mpc) == 0)
        {
            s.modify();
            fio.seekg(pos);
            fio.write((char *)&s, sizeof(s));
            found = 't';
            break;
        }
    }
    if (found == 'f')
        cout << "\nRecord not found!!\n";
    fio.close();
}
void delt()
{
    ifstream fio("items.dat", ios::binary);
    ofstream file("temp.dat", ios::out | ios::binary);
    char mpc1[10];
    char found = 'f', confirm = 'n';
    cout << "\nEnter the Item Batch No to be modified:-";
    cin >> mpc1;
    while (!fio.eof())
    {
        fio.read((char *)&s, sizeof(s));
        if (s.checkpc(mpc1) == 0)
        {
            s.display();
            found = 't';
            cout << "Are you sure want to delete this record(y/n):.. ";
            cin >> confirm;
            if (confirm == 'n')
                file.write((char *)&s, sizeof(s));
        }
        else
            file.write((char *)&s, sizeof(s));
    }
    if (found == 'f')
        cout << "\nRecord not found!!\n";
    fio.close();
    file.close();
    remove("items.dat");
    rename("temp.dat", "items.dat"); //old file is removed and temp file is renamed
}
void dis()
{
    cout << "\nThe file contains:\n";
    ifstream fio("items.dat");
    while (!fio.eof())

    {
        fio.read((char *)&sh, sizeof(sh));
        if (fio.eof())
            break;
        sh.display();
    }
    fio.close();
}
void shoping::input()
{
    cout << "Input the Item Batch No: " << endl;
    cin >> batch_no;
    cout << "Input the Item Name: " << endl;
    cin >> item_name;
    cout << "Input the Item Price: " << endl;
    cin >> item_cost;
    cout << "Input the Item Quantity: " << endl;
    cin >> pq;
}
void shoping::display()
{
    cout << "Name of the Item:-" << item_name << endl;
    cout << "Batch No of Item:-" << batch_no << endl;
    cout << "Price of the Item:-" << item_cost << endl;
    cout << "Quantity of Item in stock:-" << pq << endl;
}
int main()
{
    cout << "\n\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  Shoping Advisary Welcome's you:)  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    int c;
    while (c != 6)
    {
        cout << "\n\t\t\t\t\t\t\t\tFirstly Enter What you want in given options: \n\n";
        cout << "\t\t\t\t\t\t\t\t1. To Add New Items" << endl;
        cout << "\t\t\t\t\t\t\t\t2. To Modyfing Saved Items" << endl;
        cout << "\t\t\t\t\t\t\t\t3. To Delete an Existing Item" << endl;
        cout << "\t\t\t\t\t\t\t\t4. To Showing Saved Items:" << endl;
        cout << "\t\t\t\t\t\t\t\t5. Move out from Here :)" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            add();
            break;
        case 2:
            firmod();
            break;
        case 3:
            delt();
            break;
        case 4:
            dis();
            break;
        case 5:
            exit(1);
            break;
        default:
            cout << "\nSorry! Wrong input!!";
        }
    }
    return 0;
}
