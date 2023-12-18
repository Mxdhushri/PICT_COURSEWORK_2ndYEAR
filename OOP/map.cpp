#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
	typedef map<string,int>mapType;
	mapType populationmap;
	populationmap.insert(pair<string,int>("mp",3456156));
	populationmap.insert(pair<string,int>("up",34565656));
	populationmap.insert(pair<string,int>("maharashtra",345656));
	populationmap.insert(pair<string,int>("jharkhand",1345656));
	mapType::iterator itr;
	cout<<"choose state from following:"<<endl;
	cout<<"1.maharashtra"<<endl;
	cout<<"2.mp"<<endl;
	cout<<"3.jharkhand"<<endl;
	cout<<"4.up"<<endl;
	cout<<"enter name of state:";
	string state;
	cin>>state;
	itr=populationmap.find(state);
	if(itr!=populationmap.end()){
		cout<<"population is:"<<itr->second;
	}
	else{
		cout<<"invalid";
	}
}
