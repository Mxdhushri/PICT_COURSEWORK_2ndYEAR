#include<iostream>
using namespace std;
#define N 10
class Deque{
    int Q[N];
    int front;
    int rear;

    public:
    Deque(){
        front=rear=-1;
        cout<<"deque is created successfully and initialized to empty";
    }

    void AddFront(){
        if(front==0){ cout<<"\nNot possible to add at front";
       }
        else{
            if(front==-1){ 
                front=rear=0;}
           else {
            front=front-1;                           //front pe in this case add kar rahe hai
            }
            cout<<"\nEnter value to be added at front:";
          cin>>Q[front];
        }
    }

    void AddRear(){
        if(rear==N-1)cout<<"\nNot possible to add at rear";
        else{
            if(rear==-1) front=rear=0;
            else rear=rear+1;                       //rear pe add karte hai
            cout<<"\nEnter value to add at rear:";
            cin>>Q[rear];
        }
    }

    void DeleteFront(){
        int value;
        //check if it is empty,if not empty,then check  
        //if front=0,it is at first postion, so we move first pointer
        // to next ,hence the intial first is kind of deleted  
        if(front==-1)cout<<"\nthe Deque is empty";
        else{
            value=Q[front];
            if(front==rear) front=rear=-1;
            else front=front+1;
            cout<<"\nTHe data"<<value<<"is deleted from front of deque";
        }
    }

    void DeleteRear(){ 
        int value;
        if(rear==-1)cout<<"deque is empty";
        else{
            value=Q[rear];
            if(front==rear)front=rear=-1;
            else rear=rear-1;
            cout<<"\nTHe data"<<value<<"is deleted from rear of deque";
        }
    }

    void Display(){
        if(front==-1)cout<<"\nThe deque is empty ";
        else{
        int i=front;
        cout<<"\nNodes in deque are"; 
        while(i<=rear){
            cout<<" "<<Q[i];
            i++;
        }
    }
    }
};

int main(){
    int choice;
    Deque obj;
    while(1){

        cout<<"\n\n****Menu****\n1.Add from Front\n2.Add from rear";
        cout<<"\n3.delete from front\n4.delete from rear\n5.display\n6.exit";
        cout<<"\nEnter your choice:";
        cin>>choice;

        switch(choice){
            case 1:
            obj.AddFront();
            break;
            case 2:
            obj.AddRear();
            break;
            case 3:
            obj.DeleteFront();
            break;
            case 4:
            obj.DeleteRear();
            case 5:
            obj.Display();
            break;
            case 6:
            exit(0);
        }
    }
}