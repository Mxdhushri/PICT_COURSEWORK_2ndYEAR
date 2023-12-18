#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    int data;
    Node*left;
    Node*right;
    public:
    Node(){
        left=NULL;
        right=NULL;
    }
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
    friend class BST;
};
class BST{
    Node*root;
    public:
    BST(){
        root=NULL; //root pointer ko null kiya
    }
    void create(int d){
        root=new Node(d); //line 13
    }
    void insert(int d){
        realinsert(root,d);
    }
    void realinsert(Node*root,int d){
          if(root==NULL){
            root=new Node(d);
          }
          else{
            Node*temp=new Node(d);
            //forming the left side
            if(d<root->data){             //v v imp. if 50<100
                if(root->left==NULL){     // agar null hai ie agar jagah vacant hai
                    root->left=temp;      // toh phir value insert kar do
                }
                else{
                    realinsert(root->left,d);  // otherwise agar jagah is not vacant ie it is full with 
                  // say value N . phir N ko hi next root bana dete. aur liye aage chk karo if vacant or no
                  // here 100 root tha.uska next(L) 50 tha (not vacant)
                 //uska next 35 (L)tha(not vacant). 35 ka next is vacant then 40,41 line
                }
            }
            //forming right side
            if(d>root->data){
                if(root->right==NULL){
                    root->right=temp;
                }
                else{
                    realinsert(root->right,d);
                }
            }
          }
    }
 void display()
    {
        cout<<"Enter 1 for Preorder Traversal"<<endl;        
        int code1;

        while(true)
        {
            cin>>code1;
            if(code1==1){
            	cout<<"Preorder Traversal: ";
                Preorder(root);
                break;
            }
            else if(code1==4){
                cout<<"Invalid Choice, Enter Again: ";
            }
        }
    }
    void Preorder(Node*root){
        if(root!=NULL){
            cout<<root->data<<" ";
            Preorder(root->left);
            Preorder(root->right);
        }
    }
};

int main()
{
    BST t;
    int code;
    while(true){
    cout<<"-----------------------------------------"<<endl;
    cout<<"Enter 1 to create Tree"<<endl;
    cout<<"Enter 2 to Insert New Node in Tree"<<endl;
    cout<<"Enter 3 to Display Tree"<<endl;
    cout<<"-----------------------------------------"<<endl;
    cin>>code;
    if (code==1){
    	int x;
    	cout<<"Enter the value of root Node to create the Tree: ";
    	cin>>x;
    	t.create(x);
    	cout<<endl;
    }
    else if(code==2){
    	int x;
    	cout<<"Enter the value to be Inserted: ";
    	cin>>x;
    	t.insert(x);
    }
    else if(code==3){
    	t.display();
    	cout<<endl;
    }
    else{
    	cout<<"Exiting The Program!!!!!"<<endl;
    	break;
    }
    }
}