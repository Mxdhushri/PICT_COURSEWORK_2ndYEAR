//queue uses the principle of fifo,addition takes place through rear end and removal from front end
// in 1 block of array we need to store 2 things, data and priority. hence we create 1 object that stores
//both data and priority and then we store that 1 obj containing 2 things in the array block
// stored in the form of 1.8,2.7,9.4,8.2  see the seconds place because that represents the priority 
//and our array is sorted acc to priority ,hence 8 comes first. 
//we have to use template as asked in question.
#include<iostream>
using namespace std;

template<class t>
class job{
    public:
    t name;   //name of type template(type is declared later)
    int pri;  //priority of type int(priority/preference is always a number)

    int getpri(){    //function to get the priority
        return pri;
    }

    t getname(){      //function to get the data ie.name here 
        return name;
    }

    void getdata(){       //fuction to get name and priority from the user
        cout<<"enter name"<<endl;
        cin>>name;
        cout<<"priority"<<endl;
        cin>>pri;
    }
    template<typename u> //syntax
    friend bool operator>=(job <u>&obj1,job <u>&obj2); //declaration of the friend operator(defined below)

    void display(){                                 //function that displays
        cout<<"Name: "<<name<<endl;
        cout<<"Priority : "<<pri<<endl;
    }
};

 template<typename u>                           //in Operator overloading, operator used is comparison operator
 bool operator>=(job <u>&obj1,job <u>&obj2){    //using reference & to avoid interchanging of obj1 and obj2. now obj1 is first 
    if(obj1.getpri()>=obj2.getpri()){           //using bool as we want true/false in return
        return true;
    }
    else{
        return false;
    }
 }

 template<class w>
 class priority
 {
    int front,rear;

    job<w> Q[100];  
    int size=100;
public:
    priority(){
        front=rear=-1;                  //0 index se bhi pehle -1 aata hai, no array exists, queue empty
    }
    bool isempty(){
        if (front==-1){
            return true;
        }
        else return false;
    }
    bool isfull(){
        if(rear==size-1){              //index is 0 to 8 ,size is 9, therefore size-1=8, if rear=8,then array is full
            return true;
        }
        else return false;
    }
    void enque(job <w>ele){             // operation to add 
        if (isfull()){                  //agar full hai toh hum kyu hi add karenge
            cout<<"queue is full"<<endl;
        }
        else if(front==-1){             //agar full nahi hai,and exits hi nahi karta,toh hum front and rear ko ek se inc karke 0 banate
            front=0;                    //queue ke end ko apna ele object de dete ie.add of ele obj at rear is done
            rear=0;
            Q[rear]=ele;
        }
        else{
            rear++;                     //nahi toh agar array already hai toh , obj ko as in elements ko compare karte
            int j=rear-1;               //and insertion sort type lagate hai
            while(ele.getpri()>=Q[j].getpri()){
                Q[j+1]=Q[j];            //and then rear pe insert karte hai
                j--;                    //"insertion sort"
            }
            Q[j+1]=ele;
        }
    }
    void dequeue(){                     //fuction to remove ele from start
        if (isempty()){                 //agare mppty hai toh kya hi remove karenge
            cout<<"queue is empty"<<endl;
        }
        else{                           //we remove the first ele/obj
            cout<<Q[front].name<<" is hired "<<Q[front].pri<<endl;
            front=front+1;              //then the front pointer is moved to next index
        }
    }
    void display1()
    {
        for(int i=front;i<=rear;i++){
            Q[i].display();
        }
    }
 };


 int main(){
    priority<string> ob;
    int n;
     int choice;
    while(1)
    {
    cout<<"\nMENU\n1.enqueue\n2.display\n3.dequeue\n4.exit";
    cout<<"\n5.enter your choice:";
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"enter the number of jobs"<<endl;
        cin>>n;
        while(n--){
        job<string> j1;
        j1.getdata();
        ob.enque(j1);
        }
            break;
        case 2:
            ob.display1();
            break;
        case 3:
            ob.dequeue();
            break;
        case 4:
            exit(0);
        default:
        cout<<"enter valid choice";    
    }
}    
    return 0;
 }




