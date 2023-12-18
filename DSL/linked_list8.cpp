#include<iostream>
#include<string>
using namespace std;

class Node{
    public:
    string name;
    Node*next;

    Node(string newName){       //parameterised constructor
        name=newName;
        next=NULL;
    }
};
class linkedList{
    public:
    Node*head;
    Node*tail;

    void appendName(string newName){
        if(tail){
            tail->next=new Node(newName);
            tail=tail->next;
        }
        else{
            head=new Node(newName);
            tail=head;
        }
    }


    linkedList(string names[],int size){
        head=NULL;
        tail=NULL;
        appendNames(names,size);
    }

    
    linkedList(){
        head=NULL;
        tail=NULL;
    }

    void appendNames(string names[],int size){   //no scope res op required as it is within class itself
        for(int i=0;i<size;i++){
            appendName(names[i]); //use of parameters declared above
        }
    }

    bool search(string name){       //for searching obvio a parameter is needed
        Node*itr=head;              //iterator pointer
        while(itr){                 //while itr ptr exists
            if(itr->name==name){
                return 1;
            }
            itr=itr->next;
        }
        return 0; 
    }

    void print(){
        Node*itr=head;
        while(itr){
            cout<<itr->name<<" ";
            itr=itr->next;
        }
        cout<<"\n";
    }
};

linkedList Union(linkedList list1,linkedList list2){
    linkedList list3;
    Node*itr=list1.head;
    while(itr){
        list3.appendName(itr->name); 
        itr=itr->next;
    }
    itr=list2.head;
    while(itr){
        if(!list3.search(itr->name)){
            list3.appendName(itr->name);
        }
        itr=itr->next;
    }
    return list3;
}

linkedList intersection(linkedList list1,linkedList list2){
    linkedList list3;
    Node*itr=list1.head;
    while(itr){
        if(list2.search(itr->name)){
            list3.appendName(itr->name);
        }
        itr=itr->next;
    }
    return list3; 
}

linkedList subtraction(linkedList list1,linkedList list2){
    linkedList list3;
    Node*itr=list1.head;
    while(itr){
        if(!list2.search(itr->name)){
            list3.appendName(itr->name);
        }
        itr=itr->next;
    }
    return list3;
}

int main(){
    string butterscotch[5]={"ram","sham","harry","larry","carry"};
    string vanilla[3]={"romeo","juliet","carry"};

    linkedList butterscotchlist=linkedList(butterscotch,5);
    linkedList vanillalist=linkedList(vanilla,3);

    butterscotchlist.print();
    vanillalist.print();

    Union(butterscotchlist,vanillalist).print();
    intersection(butterscotchlist,vanillalist).print();
    subtraction(butterscotchlist,vanillalist).print();
}
