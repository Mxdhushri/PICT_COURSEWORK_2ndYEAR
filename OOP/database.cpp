#include <iostream>
#include <string.h> // header file declares a set of functions to work on strings.
using namespace std;

class Database
{
  int roll;
  char Name[20];
  char Class[10];
  char Div[10];
  char Dob[12];
  char Blood_Grp[5], city[10];
  char Phone[12], License[12];
  static int Student_no; // declaration of static variable

public:
  static void count() // defination of static function.no of times obj is created static count increment
  {
    cout << "\n No.of objects created: " << Student_no;
  }

  Database() // default constructor
  {
    roll = 7;
    strcpy(Name, "Madhushri");
    strcpy(Class, "SE");
    strcpy(Div, "A");
    strcpy(Dob, "3/08/2003");
    strcpy(Blood_Grp, "B+");
    strcpy(city, "Pune");
    strcpy(Phone, "900000000");
    strcpy(License, "A1010");
    Student_no++;
  }
  Database(Database &r) // Copy constructor
  {
    roll = r.roll;
    strcpy(Name, r.Name);
    strcpy(Class, r.Class);
    strcpy(Div, r.Div);
    strcpy(Dob, r.Dob);
    strcpy(Blood_Grp, r.Blood_Grp);
    strcpy(city, r.city);
    strcpy(Phone, r.Phone);
    strcpy(License, r.License);
    Student_no++;
  }
  void getdata() // defining member function
  {
    cout << "\n\nEnter:\n1. Name\n2. Roll\n3. Class,\n4. Div\n5. Dob\n6. Blood Group\n7. City\n8. Phone number\n9. License \n\n";
    cin >> Name >> roll >> Class >> Div >> Dob >> Blood_Grp >> city >> Phone >> License;
  }
  friend void display(Database d); // declaration of friend function

  ~Database() // destructor
  {
    cout << "\n"
         << "(Object) is destroyed!\n";
  }
};

void display(Database d) // defination of friend function
{
  cout << "\n Name:" << d.Name;
  cout << "\n Roll_No:" << d.roll;
  cout << "\n Class:" << d.Class;
  cout << "\n Div:" << d.Div;
  cout << "\n DOB:" << d.Dob;
  cout << "\n Blood group:" << d.Blood_Grp;
  cout << "\n City:" << d.city;
  cout << "\n Phone_No:" << d.Phone;
  cout << " \n License_No:" << d.License;
}
int Database::Student_no=0; // Define static data member stdno outside the class;

int main()
{
  int n, i;

  Database d1, *ptr[5], d2(d1);
  cout << "\nDefault values:";
  display(d2);

  d1.getdata();
  display(d1);

  cout << "\nHow many objects u want to create?:";
  cin >> n;
  for (i = 0; i < n; i++)
  {
    ptr[i] = new Database(); // new operator use to dynamic memory(run time) allocation
    ptr[i]->getdata();
  }
  cout << "\n"
       << "name"
       << "roll"
       << "Class"
       << "Div"
       << "dob"
       << "bg"
       << "contact"
       << "phone"
       << "license";
  for (i = 0; i < n; i++)
    display(*ptr[i]);
  Database::count(); // calling of static function

  for (i = 0; i < n; i++)
  {
    delete (ptr[i]); // delete operator use to deallocation of memory
  }
  cout << "\nObjects deleted!";
}
