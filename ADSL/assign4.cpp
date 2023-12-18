#include<iostream>
using namespace std;
#define size 10  // defining size
class Entry
{
public:
int MobileNo;
string name;
};
class HT{
Entry ht[size]; // can write 10 also (array=class type/array of object)
public:
HT(){
for(int i=0;i<10;i++){
ht[i].MobileNo=-1;  
}
}
int hashFunc(int key)
{
return (key%10);  
}
void insert(string s,int n){
int r=hashFunc(n);  // defined with resp. to mobile no
                    // can define with respect to name also
while(true){
if(ht[r].MobileNo==-1)
{
ht[r].name=s;
ht[r].MobileNo=n;
break;
}
else{  //agar -1 nahi hai toh
r=(r+1)%size;
}
}
}
void search(int n){
int probes=0;
int choice=1;
int r=hashFunc(n);
while(choice){
if(ht[r].MobileNo==n){
cout<<"Probes:"<<probes<<endl; // probes is no of comparisons
//incase same index is obtained
break;
}
else if(r==10){
break;
}
else{
r=(r+1)%10;
probes+=1;
}
}
}
void display(){
for(int i=0;i<size;i++){
cout<<i<<" "<<ht[i].MobileNo<<" "<<ht[i].name<<" "<<endl;
}
cout<<endl;
}
};

int main(){
int choice=1;
HT h;
while(choice){
int n;
string s;
cout<<"Enter number:";
cin>>n;
cout<<"Enter name:";
cin>>s;
h.insert(s,n);
cout<<"Do you want to continue(0,1):";
cin>>choice;
}
h.display();
h.search(34);
return 0;
}