#include<iostream>
using namespace std;
#define size 11      //size of hashtable
class Entry{
public:
string key;      //node has one element key
string value;    //center element is value
Entry* next;     // next pointer of class type- Entry 
Entry(){         //default constructor
key="";
value="";
next=NULL;
}
Entry(string k,string v){  //parameterized constructor , dictionary type
key=k;
value=v;
next=NULL;
}
};

class HT{
Entry* dict[size];   
public:
HT(){
for(int i=0;i<size;i++){   //initializing all elements of array as zero
dict[i]=NULL;
}
}
int hashfunction(string k,string v){     //this fuction has k and v as parameters
int s=0;
for(int i=0;i<k.length();i++){        // k string ka length is k.length
s+=(i+1)*k[i];                        //s+= mens that result is incremented in s everytime 
}
return (s%size);                     //return index in hashtable(simple)
}

void insert(string k,string v){
int r=hashfunction(k,v);            //insert r 
cout<<r<<endl;
Entry* temp=dict[r];
if(temp==NULL){
dict[r]=new Entry(k,v);            //if null then insert new entry  
}
else{
while(temp->next!=0){             //if not null then just go to next block
temp=temp->next;                  //after this again go to line 41 (loop)
}
Entry* newnode=new Entry(k,v);    
temp->next=newnode;
}
}

// in search their are 3 types say:

void search(string k,string v){     
int r=hashfunction(k,v);
Entry* temp=dict[r];
int probes=1;    // no of times we compare (in our case - 3 max)
int flag=0; // to detect element in ht
while(temp->next!=0){
if(temp->key==k ){       //we check if temp ka key is equal to k we have given
cout<<"Element Found"<<endl;
cout<<temp->value<<endl;     //printing value
cout<<"Probes:"<<probes<<endl;
flag=1;
}
probes++;   //if this fuction executes then probes(comparison) is incremented 
temp=temp->next;
if(temp->next==NULL)
{
cout<<temp->value<<endl;  //as soon as next of temp is null print value
break;
}
}

if(flag==0){
cout<<"Element Not Found"<<endl;
}

}
void deletion(string k,string v){   //same as linked list
Entry* prevnode=NULL;
Entry* currnode=NULL;
int r=hashfunction(k,v);

currnode=dict[r];
prevnode=currnode;
if(currnode->key==k && currnode->value==v){
dict[r]=currnode->next;
delete currnode;
}
else{
currnode=currnode->next;
while(currnode!=NULL){
if(currnode->key==k && currnode->value==v){
prevnode->next=currnode->next;    //for deleting middle element
delete currnode;
break;
}
prevnode=currnode;
currnode=currnode->next;
}
}
}
void display(){
for(int i=0;i<size;i++){
Entry* temp=dict[i];
cout<<(i+1)<<":-";
while(temp!=0){
cout<< "["<<temp->key<<" "<<temp->value <<"]"<<" --->  ";
temp=temp->next;
}
cout<<endl;
}
}

};
int main(){
HT h;
int choice;
while(true)
{ cout<<endl;
cout<<"1. Insert Elements "<<endl;
cout<<"2. Delete the Elements "<<endl;
cout<<"3. Search the Elements "<<endl;
cout<<"4. Display Hash Table "<<endl;
cout<<endl;

cout<<"Enter the choice "<<endl;
cin>>choice;

if(choice==1)
{
int n;
cout<<"Enter the total elements to add"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
string a,b;
cout<<"Enter the word"<<endl;
cin>>a;
cout<<"Enter the meaning "<<endl;
cin>>b;
h.insert(a,b);
}
}

else if(choice==2)
{
string a,b;
cout<<"Enter the word to delete"<<endl;
cin>>a;
cout<<"Enter its meaning to delete"<<endl;
cin>>b;
h.deletion(a,b);
}

else if(choice==3)
{
string a,b;
cout<<"Enter the word to search"<<endl;
cin>>a;

h.search(a,"v");
}

else if(choice==4)
{
h.display();
}

else
{
break;
}

}

return 0;
}