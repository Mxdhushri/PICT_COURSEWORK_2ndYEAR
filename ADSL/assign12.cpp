#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Hashtable
{
public:
    int addr;
    friend class employee;
} ht[10];
class employee
{
    int emp_id;
    char salary[10];
    char name[10];
    // Hashtable ht[10];
public:
    employee()
    {
        for (int i = 0; i < 10; i++)
        {
            ht[i].addr = -1;
        }
        emp_id = 0;
    }
    void add_rec()
    {
        int location;
        int index, count, tablesize = 10;
        cout << "enter number of records:";
        cin >> count;
        ofstream fout;
        fout.open("FileDAF.txt", ios::out);
        for (int i = 0; i < count; i++)
        {
            cout << "\n Enter Employee id/name/sal: ";
            cin >> emp_id >> name >> salary;
            //		cin >>emp_id>>name>>salary;
            //		cout << "\n Enter Employee name: ";
            //		cin >> name;
            //		cout << "\n Enter Employee salary: ";
            //		cin >> salary;
            //
            location = fout.tellp();    //...Return location
            index = emp_id % tablesize; //....Find index of Hashtable
            ht[index].addr = location;  //...Store location in Hashtable
            //.........Write the Record in File
            fout << emp_id << " " << name << " "
                 << ""
                 << " " << salary << endl;
        }
        fout.close();
    }
    void displayrec()
    {
        char buffer[40];
        fstream fobj("FileDAF.txt", ios::in);
        while (!fobj.eof())
        {
            fobj.getline(buffer, 40);
            cout << buffer << endl;
        }
    }
    void search()
    {
        int id;
        int tablesize = 10;
        //.......Accept Emp_id to search
        cout << "Enter Emp_id to search record: ";
        cin >> id;
        //......Find index to get the address of record
        int index = id % tablesize;
        //......read and store the address
        int location = ht[index].addr;
        //....Open the file for reading
        ifstream fin;
        fin.open("FileDAF.txt", ios::in);
        //.....go to the location
        fin.seekg(location, ios::beg);
        //.....Read from location
        char buffer[40];
        fin.getline(buffer, 40);
        cout << "\n\t Found Record : " << buffer;
    }
    void deletes()
    {
        int i, id;
        int tablesize = 10;
        cout << "\n\t Enter the Emp_id to delete: ";
        cin >> id;
        int index = id % tablesize;
        int location = ht[index].addr;
        //....Open the file for reading
        ifstream fin;

        fin.open("FileDAF.txt", ios::in);
        //.....go to the location
        fin.seekg(location, ios::beg);
        //.....Read from location
        char buffer[40];
        fin.getline(buffer, 40);
        cout << "\n\t Deleted Record : " << buffer;
        fin.close();
        cout << "\n\t Remaining Records:- ";
        //....Open the file for reading
        fin.open("FileDAF.txt", ios::in);
        for (i = 0; i < 10; i++)
        {
            if (ht[i].addr != -1 && ht[i].addr != location)
            {
                //.....Read from location
                fin.seekg(ht[i].addr, ios::beg);
                fin.getline(buffer, 40);
                cout << "\n\t Record : " << buffer;
            }
        
        fin.close();
          }  }
};

int main()
{
    cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
    employee e;
    e.add_rec();
    e.displayrec();
    e.search();
    e.deletes();
    return 0;
}