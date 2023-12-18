/*Beginning with an empty binary tree,
Construct binary tree by inserting the values in the order given.
After constructing a binary tree perform following operations on it-
 Perform in order / pre order and post order traversal
 Change a tree so that the roles of the left and right pointers are swapped at every node
 Find the height of tree 
 Copy this tree to another [operator=] 
 Count number of leaves, number of internal nodes.
 Erase all nodes in a binary tree. (implement both recursive and non-recursive methods)*/


#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    node*left;
    node*right;
    int data;
    public:
    node(){
        left=NULL;   //left pointer initially null hai
        right=NULL;
        data=0;
    }
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
    friend class Tree;
};

class Tree{
    node*root;  // root pointer declare
    public:
    Tree(){root=NULL;}
    void Create(){
        queue<node*>q;   // queue template that contains node pointer as its element
        cout<<"Enter The Value of Root Node: ";
        int x;cin>>x;
        root=new node(x); //imp:line 25 function is called and a brand new node is created
        q.push(root);     //pehle q mai root jayega
        while(q.empty()!=1){
            node*p=q.front();  //p pointer is pointing to front of q
            q.pop();           // p pointer ke pehle ka ele del kar do

            //Creating Left Node
            // BT is simple..here value of nodes taken from user 
            // whereas in BST we have to do comparisons 
            cout<<"Enter The Value For Left Child for "<<p->data<<": ";
            int x;cin>>x;
            if(x!=-1){    // -1 pe terminate hoga prog isliye
                node*temp=new node(x); //line 25 used to create new node that is T pointer
                p->left=temp;
                q.push(temp);
            }
            //Creating Right Node
            cout<<"Enter The Value For right Child for "<<p->data<<": ";
            int y;cin>>y;
            if(y!=-1){
                node*temp=new node(y);
                p->right=temp;
                q.push(temp);
            }
// pehle 100 daala q mai ,phir 100 cacel and add 50(L) and 120(R) ,then 50 cancel
// and add 35(L) and 70(R),then cancel 120 and add 105(L) and 130(R). over.
        }
    }
    void display(){
        
        int code;
        while (true){
            cout<<"Enter 1 for Recursive Preorder Traversal: "<<endl;
            cout<<"Enter 2 for Recursive Inorder Traversal: "<<endl;
            cout<<"Enter 3 for Recursive Postorder Traversal: "<<endl;
            cout<<"Enter 4 for Iterative Preorder Traversal: "<<endl;
            cout<<"Enter 5 for Iterative Inorder Traversal: "<<endl;
            cout<<"Enter 6 for Iterative Level order Traversal: "<<endl;
            cin>>code;
            if(code==1){
                cout<<"Recursive preorder: ";
                r_preorder(root);
                 cout<<endl;
                //break;
            }
            else if(code==2){
                 cout<<"Recursive inorder: ";
                r_inorder(root);
                 cout<<endl;
                //break;
            }

            else if(code==3){
                cout<<"Recursive postorder: ";
                r_postorder(root);
                 cout<<endl;
                //break;
            }
            else if(code==4){
                cout<<"Iterative Preorder: ";
                i_preorder(root);
                cout<<endl;
            }
            else if(code==5){
                cout<<"Iterative Inorder: ";
                i_inorder(root);
                cout<<endl;
            }
            else if(code==6){
                cout<<"Level Order Traversal: ";
                i_levelorder(root);
            }
            else{
                break;
            }
        }
       
        
    }
    void r_inorder(node*root){
       
        if(root!=NULL){            // agar root null nahi h toh
            r_inorder(root->left);  //left
            cout<<root->data<<" ";  //root
            r_inorder(root->right); //right
        }
    }
    void r_preorder(node*root){
        
        if(root!=NULL){
            cout<<root->data<<" ";       
            r_preorder(root->left);    // yaha se line 128 wapas call hota hai(hence recursive)
                                       //and then 128 call hone ke baad wapas line 131 execute
                                       // hoke data hi ultimately print hota hai...left ka
            r_preorder(root->right); 
        }                             
    }
    void r_postorder(node*root){
        
        if(root){
            r_postorder(root->left);
            r_postorder(root->right);
            cout<<root->data<<" ";
        }
    }
    void i_preorder(node*t){
        stack<node*>st;
        do
        { 
            if(t!=NULL){
                cout<<t->data<<" ";
                st.push(t);
                t=t->left;
            }
            else{
                t=st.top();
                st.pop();
                t=t->right;
            }
            
        }while (t!=NULL || st.empty()!=1);
        cout<<endl;
        
    }
    void i_inorder(node*t){
        stack<node*>st;
        do
        {
            if(t!=NULL){
                st.push(t);
                t=t->left;
            }
            else{
                t=st.top();
                st.pop();
                cout<<t->data<<" ";
                t=t->right;

            }
        } while (t!=NULL || st.empty()!=1);
        
    }
    void i_levelorder(node*t){
        queue<node*>q;
        cout<<t->data<<" ";
        do{
            if(t->left){
                cout<<t->left->data<<" ";
                q.push(t->left);
            }
            if(t->right){
                cout<<t->right->data<<" ";
                q.push(t->right);
            }
            t=q.front();
            q.pop();
        }while(q.empty()!=1);
        cout<<endl;
    }
    int count(){
        return countt(root);
    }
    int countt(node*root){
        int lc,rc;
        if (root!=NULL)
        {
            lc=countt(root->left);
            rc=countt(root->right);
            return rc+lc+1;
        }
        return 0;
    }
    int height(){
        return heightt(root);
    }
    int heightt(node*root){
        int lc,rc;
        if (root)
        {
            lc=countt(root->left);
            rc=countt(root->right);
            return max(lc,rc)+1;
        }
        return 0;
    }
    void swap(){
        swapp(root);
    }
    void swapp(node*root){
        node*temp=root->left;
        root->left=root->right;
        root->right=temp;
        if(root->left){
            swapp(root->left);
        }
        if(root->right){
            swapp(root->right);
        }
     }
     int countleaf(){
        return counttleaff(root);
     }
     int counttleaff(node*root){
        if(root==NULL){
            return 0;
        }
        else if(root->left==NULL && root->right==NULL){
            return 1;
        }
        else{
            return counttleaff(root->left)+counttleaff(root->right);
        }
     }
     int nonleaf(){
        return countt(root)-counttleaff(root);
     }
     void Erase(){
        EraseAll(root);
     }
     void EraseAll(node*root){
        if(root==NULL){
            return;
        }
        EraseAll(root->left);
        EraseAll(root->right);
        delete root;
     }
};
int main()
{
    Tree t;
    while(true){
    cout<<"-----------------------------------------"<<endl;
    cout<<"Enter 1 to create Tree"<<endl;
    cout<<"Enter 2 to Display Tree"<<endl;
    cout<<"Enter 3 to Swap The Tree"<<endl;
    cout<<"Enter 4 to Get Height Of Tree"<<endl;
    cout<<"Enter 5 to Get Total NUmber Of leaf Nodes In Tree"<<endl;
    cout<<"Enter 6 to Get Total NUmber Of Internal Nodes In Tree"<<endl;
    cout<<"Enter 7 to Get Total NUmber Of Nodes In Tree"<<endl;
    cout<<"Enter 8 to Erase all Nodes In Tree"<<endl;
    cout<<"-----------------------------------------"<<endl;
    int code;cin>>code;
        if (code==1){
    	t.Create();
    	cout<<endl;
    }
    else if(code==2){
    	t.display();
    	cout<<endl;
    }
    else if(code==3){
    	t.swap();
    }
    else if(code==4){
    	cout<<"Height of Tree:  "<<t.height()<<endl;
    }
    else if(code==5){
    	cout<<"Total Number Of leaf Node: "<<t.countleaf()<<endl;
    }
    else if(code==6){
    	cout<<"Total Number Of Internal Node: "<<t.nonleaf()<<endl;
    }
    else if(code==7){
    	cout<<"Total Number Of Node: "<<t.count()<<endl;
    }
    else if(code==8){
        t.Erase();
    }
    else{
    	cout<<"Exiting The Program!!!!!"<<endl;
    	break;
    }

    }
}