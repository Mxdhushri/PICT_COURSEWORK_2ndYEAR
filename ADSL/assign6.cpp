#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<bool>vis(100,false); //vector is an array whose size is not defined so we can access any element easily
class node{
	int ver;
	node*next;
public:
	node(){
		ver=0;
		next=NULL;
	}
	node(int v){
		ver=v;
		next=NULL; 
	}
	friend class Graph;
};
class Graph{
	int totalv;
	node*arr[100];
public:
	void initialize(){
		int x;
		cout<<"Enter the Number Of vertices in the graph: ";cin>>x;
		totalv=x;
		for(int i=0;i<totalv;i++){
			arr[i]=NULL; //initially all the indexs are null 
		}
	}
	//node*arr[totalv];
	void ReadGraph(){
		int e;string str; //edges and name present at index
		for(int i=0;i<totalv;i++){
			cout<<"Enter the Number Of Vertices Connected to "<<i<<" ";cin>>e;
			for(int j=0;j<e;j++){
				int a;
				cout<<"Enter Vertex: ";
				cin>>a;
				node*temp=new node(a); //IMP: line 9 is called
				if(arr[i]==NULL){ 
					arr[i]=temp;
				}
				else{
					temp->next=arr[i];
					arr[i]=temp;
				}
			}
		}	
	}
	void DisplayGraph(){   //t....t is just a pointer bro
		for(int i=0;i<totalv;i++){
			node*t=arr[i];
			cout<<i<<"---> ";
			while(t){   //while t is not null
				cout<<t->ver<<" ";
				t=t->next;
			}
			cout<<endl;
		}
		cout<<endl;
	}
	void BFS(){
		queue<int>q;int sv; //sv=starting vertex
		vector<bool>visited(totalv,false);
		cout<<"Enter the Starting Vertex Number: ";cin>>sv;
		q.push(sv);
		cout<<"BFS: ";
		while(!q.empty()){  //while q is not empty
			int x;
			x=q.front();
			q.pop();
			if(visited[x]==false)
			{
				cout<<x<<" ";
				visited[x]=true;
				node*t=arr[x];
				while(t)    //when t is not null 
				            //as soon as t is null..after 3 
							//then go to 69 line and do for 2
				{
					if(visited[t->ver]==false){
					q.push(t->ver);
					}
				    t=t->next;
				}
			}

		}
	}
	void dfs(){
		cout<<"DFS: ";
		vector<int>v(totalv,false);
		DFS(0,v);
	}
	void DFS(int p,vector<int>&v){

		cout<<p<<" ";
		v[p]=true;

		// travers adjacency list

		node*q = arr[p];
		while(q)
		{
			if(v[q->ver]==false)
			{
				DFS(q->ver,v);
			}
			q=q->next;
		}
	}
};
int main() {

	Graph g;

	while(true){
		cout<<"Enter 1 to start the program "<<endl;
			cout<<"Enter 2 to Display Adjacency LIST OF Graph"<<endl;
			cout<<"Enter 3 to For BFS"<<endl;
			cout<<"Enter 4 to For DFS"<<endl;
			int code;cin>>code;
			if(code==1){
				g.initialize();
				g.ReadGraph();
			}
			else if(code==2){
				g.DisplayGraph();
			}
			else if(code==3){
				g.BFS();
			}
			else if(code==4){
				g.dfs();
			}
			else{
				cout<<"EXiting the Program"<<endl;
				break;
			}
	}
	return 0;
}