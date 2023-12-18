#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
	string s;
	int val;
	node*next;
public:
	node(string str,int i){
		s=str;
		val=i;
		next=NULL;
	}
	friend class hasht;
};
class hasht{
	node*arr[10];
public:
	void initialize(){
		for(int i=0;i<10;i++){
			arr[i]=NULL;
		}
	}
	void insert()
	{
		int key;string fun;
		cout<<"Enter the Key: ";cin>>key;
		cout<<"Enter the string: ";cin>>fun;
		
		int loc=(fun[0]%10);
		node*temp=arr[loc];
		if(temp==NULL){1
		
			arr[loc]=temp;
		}
		else{
			if(temp->next!=NULL)
			{
				temp=temp->next;
			}
			node* tem =new node(fun,key);
			temp->next=tem;
		}
	}
	void display(){
		node*t;
		for(int i=0;i<10;i++)
		{
			t=arr[i];
			cout<<i<<"---->  ";
			if(t!=NULL){
			while(t!=NULL){
				cout<<t->s<<"("<<t->val<<")"<<" | ";
				t=t->next;


			}
			}
			else{
				cout<<0;;
			}
			cout<<endl;
		}
	}
	void search(){
		cout<<"Enter The String You want To search:";
		string a;cin>>a;
		int loc=a[0]%10;
		node*t=arr[loc];
		if(t==NULL){
			cout<<"Unsuccessful Search"<<endl;
			return;
		}
		while(t->s!=a && t!=NULL){
			t=t->next;
			if(t==NULL){
				cout<<"Unsuccessful Search"<<endl;
				return;
			}
		}
		if(t==NULL){
			cout<<"Unsuccessful Search"<<endl;
		}
		else if(t->s==a){
			cout<<"Successful Search"<<endl;
		}
	}
	void deletee(){
				cout<<"Enter The String You want To delete:";
				string a;cin>>a;
				int loc=a[0]%10;
				node*t=arr[loc];
				if(t->next==NULL){
					arr[loc]=NULL;
					return;
				}
				node*trail;
				if(t==NULL){
					cout<<"Element Not Present"<<endl;
					return;
				}
				while(t->s!=a && t!=NULL)
				{
					trail=t;
					t=t->next;
					if(t==NULL){
						cout<<"Element Not Present"<<endl;
						return;
					}
				}
				if(t==arr[loc]){
					arr[loc]=arr[loc]->next;
				}
				if(t->s==a){
					trail->next=t->next;
					delete t;
				}
	}
};
int main() {

	hasht t;
	t.initialize();
	while(true){
		cout<<"---------------------------------------------------"<<endl;
		cout<<"Enter 1 to insert: "<<endl;
		cout<<"Enter 2 to display: "<<endl;
		cout<<"Enter 3 to Search: "<<endl;
		cout<<"---------------------------------------------------"<<endl;
		int code;cin>>code;
		if(code==1){
			t.insert();
		}
		else if(code==2){
			t.display();
		}
		else if(code==3){
			t.search();
		}
		else if(code==4){
			t.deletee();
		}
		else{
			break;
		}

	}
	return 0;
}