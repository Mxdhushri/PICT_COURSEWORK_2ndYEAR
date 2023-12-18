#include<iostream>
using namespace std;

class DLL{
    bool num;  //data
    DLL*next; //doubly linked list has 2 pointers
    DLL*prev;

    public:
    static DLL*start,*end;

    DLL(){
        cout<<"enter next binary bit of number";
        cin>>num;
        next=prev=NULL;
        if(start==NULL) //list empty
        {
            start=end=this; 
        }
        else{ //node present in Dll
            end->next=this;
            this->prev=end;
            end=this;
        }
    }

    void display(){
        DLL*ptr=start;
        cout<<"NULL";
        while(ptr!=NULL){
            cout<<"|"<<ptr->num<<"|"<<"<->";
            ptr=ptr->next;
        }
        cout<<"NULL";
    }

    void onesComplement(){
        DLL*ptr=start;
        cout<<"ones complement of the given binary number is:";
        while(ptr !=NULL){
            cout<<!(ptr->num);
            ptr=ptr->next;
        }
    }

    void twosComplement(){
        DLL*ptr=end;
        bool twoscomp[15];
        int i=-1;
        while(ptr!=NULL && ptr->num==0 ){ //writing 0 from lsb
            twoscomp[++i]=0;
            ptr=ptr->prev;
        }
        twoscomp[++i]=1;     //writing 1 when loop breaks first time
        ptr=ptr->prev;
        while(ptr !=NULL){
            twoscomp[++i]=!(ptr->num); //then changing 1 to 0 and viceversa
            ptr=ptr->prev;
        }
        cout<<"\nTwos Complement of the given binary number is:";
        while(i>=0){
            cout<<twoscomp[i];
            i=i-1;
        }
    }
}; 
DLL*DLL::start=NULL;
DLL*DLL::end=NULL;
int main(){
    DLL*obj;
    int choice;
    while(1)
    {
    cout<<"\nMENU\n1.add bit into binary number\n2.display\n3.onesComplement\n4.twoscomplement\n5.exit";
    cout<<"\n5.enter your choice:";
    cin>>choice;
    switch(choice){
        case 1:
            obj=new DLL();
            break;
        case 2:
            obj->display();
            break;
        case 3:
            obj->onesComplement();
            break;
        case 4:
            obj->twosComplement();
        case 5:
            exit(0);
        default:
        cout<<"enter valid choice";    
    }
}
return 0;
}
































#include <iostream>

using namespace std;

class Node {
public:
    bool bit;
    Node* next;
    Node* prev;
    
    Node(bool newBit = 0) {
        bit = newBit;
        next = NULL;
        prev = NULL;
    }
};

class BinaryNumber {
public:
    Node* head;
    Node* tail;
    
    BinaryNumber() {
        head = NULL;
        tail = NULL;
    }
    
    BinaryNumber(int n) {
        head = NULL;
        tail = NULL;
        Node* itr;
        while (n) {
            itr = tail;
            bool nextBit = n%2;
            if (itr) {
//                cout<<"if\n";
                itr->next = new Node(nextBit);
                itr->next->prev = itr;
                tail = itr->next;
            } else {
//                cout<<"else\n";
                head = new Node(nextBit);
                tail = head;
            }
            n = n/2;
        }
    }
    
    void print() {
        Node* itr = tail;
        while (itr) {
            cout<<itr->bit;
            itr = itr->prev;
        }
        cout<<endl;
    }
};

BinaryNumber onesComplement(BinaryNumber n) {
    BinaryNumber complement;
    Node* itrR = n.head;
    while (itrR) {
        Node* itrW = complement.tail;
        if (itrW) {
            itrW->next = new Node(!itrR->bit);
            itrW->next->prev = itrW;
            complement.tail = itrW->next;
            
        } else {
            complement.head = new Node(!itrR->bit);
            complement.tail = complement.head;
        }
        itrR = itrR->next;
    }
    return complement;
}

BinaryNumber addNumbers(BinaryNumber a, BinaryNumber b) {
    BinaryNumber sum;
    bool carry = 0;
    
    Node *itrA = a.head, *itrB = b.head;
    
    while (itrA && itrB) {
        if (sum.tail) {
            sum.tail->next = new Node(itrA->bit^itrB->bit^carry);
            carry = (itrA->bit&&itrB->bit) || (itrA->bit&&carry) || (carry&&itrB->bit);
            sum.tail->next->prev = sum.tail;
            sum.tail = sum.tail->next;
        } else {
            sum.head = new Node(itrA->bit^itrB->bit^carry);
            carry = (itrA->bit&&itrB->bit) || (itrA->bit&&carry) || (carry&&itrB->bit);
            sum.tail = sum.head;
        }
        itrA = itrA->next;
        itrB = itrB->next;
    }
    
    while (itrA) {
        if (sum.tail) {
            sum.tail->next = new Node(itrA->bit^carry);
            carry = itrA->bit && carry;
            sum.tail->next->prev = sum.tail;
            sum.tail = sum.tail->next;
        } else {
            sum.head = new Node(itrA->bit^carry);
            carry = itrA->bit && carry;
            sum.tail = sum.head;
        }
        itrA = itrA->next;
    }
    
    while (itrB) {
        if (sum.tail) {
            sum.tail->next = new Node(itrB->bit^carry);
            carry = itrB->bit && carry;
            sum.tail->next->prev = sum.tail;
            sum.tail = sum.tail->next;
        } else {
            sum.head = new Node(itrB->bit^carry);
            carry = itrB->bit && carry;
            sum.tail = sum.head;
        }
        itrB = itrB->next;
    }
    
    if (carry) {
        sum.tail->next = new Node(carry);
        sum.tail->next->prev = sum.tail;
        sum.tail = sum.tail->next;
    }
    
    return sum;
}

BinaryNumber twosComplement(BinaryNumber n) {
    BinaryNumber complement = onesComplement(n);
    Node* itr = complement.head;
        while (itr) {
            if (itr->bit) {
                itr->bit = 0;
                if (itr->next) {
                    itr = itr->next;
                } else {
                    itr->next = new Node(1);
                    itr->next->prev = itr;
                    return complement;
                }
            } else {
                itr->bit = 1;
                return complement;
            }
        }
        return complement;
}

BinaryNumber subtractNumbers(BinaryNumber a, BinaryNumber b) {
    BinaryNumber complement = twosComplement(b);
    return addNumbers(a, complement);
}

int main() {
    BinaryNumber a(72), b(43), c(115);
    c.print();
    addNumbers(a, b).print();
    return 0;
}

 