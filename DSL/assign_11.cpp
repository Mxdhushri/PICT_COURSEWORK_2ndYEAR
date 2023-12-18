#include<iostream>
using namespace std;

class job {
private :
int front =-1;
int rear = -1;
int jobq[10];             //jobq is an array
int size;
int jobid ;

public:
job(){ 
    cout<<"enter size of que"<<endl;
    cin>>size;
     // int jobq[size];
}

int enq(){
    if (qfull()){
        return -1;
    }
    else {
        cout<<"enter job id "<<endl;
        cin>>jobid;
        if (front == rear && front == -1){           // if front=-1,then queue does not exist
            front=0;                                 //so we make front=0 ie create new array
        }
        jobq[++rear]=jobid;                         // rear is the index
        return jobid; 
    }
}

int deq(){
    if (qempty()){
        return -1;
    }                               //front is index or pointer
    else {                          //here nested if else is used bcoz, if both front and rear are =
        int x;                      //then the stack is empty so we need to initize front,rear to 0again
        x=jobq[front];
        if (front == rear ){         // |a|                       |a|      
            front=rear=-1;           // |b| <--front              |b|
        }                            // |c|                       |c|<--front(deque op performed)
        else {                       // |d| <--rear               |d|<--rear
            front++;                 // else we just increment front.
        }
        return x;
    }
}

bool qfull(){
    if (rear== size-1){
        cout<<"que is full"<<endl;
        return true;
    }
    return false;
}

bool qempty(){
    if (front==rear){
        cout<<"que is already empty"<<endl;
        return true;
    }
    return false;
}
void display(){
    if (qempty()==-1){
        cout<<"qempty"<<endl;
    }
    else {
    cout<<"que is :";

    for (int k=front;k<=rear;k++){
        cout<<jobq[k]<<" ";
    }
    cout<<endl;
    }
}
};

int main(){
    job j1;
 int choice;
 while(choice != 4)
 { 
  cout<<" menu"<<endl;
  cout<<"1. insert job "<<endl;
  cout<<"2. delete job"<<endl;
  cout<<"3. Display job "<<endl;
  cout<<"4. Exit "<<endl;
  cin>>choice;
  if(choice == 1){
   j1.enq();
  }
  else if (choice==2){
   cout<<j1.deq()<<endl;
    j1.display();
  }
  else if (choice==3){
   j1.display();
  }
 }  
    return 0;
}

