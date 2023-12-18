#include <iostream>
#include <string>
using namespace std;
class Publication
{
public:
	string title;
	float prices;

	Publication()
	{
		title="";
		prices=0.00;
	}
	void getdata()
	{
		cout<<"enter title: \n";
		cin>>title;
		cout<<"enter price: \n";
		cin>>prices;
	}
    void display()
	{
		cout<<"welcome"<<endl;
	}


};
class Book: public Publication
{
private:
	int pages;

public:
	Book()
	{
		pages=0;
	}
	void getdata()
	{
		Publication::getdata();
		cout<<"enter page count of the book \n";

		cin>>pages;

	}
	void display()
	{
		Publication::display();
		try{
			if(pages<0)
				throw pages;

		}
		catch(int p)
		{

			pages=0;
			prices=0;
			title="0";


		}
		cout<<"the title of the book is:"<<title<<endl;
		cout<<"price of the book is:"<<prices<<endl;
		cout<<"the page count is:"<<pages<<endl;


	}

};
class tape: public Publication
{
private:
	float playtime;

public:
	tape()
	{
		playtime=0.0;
	}
	void getdata()
	{
		Publication::getdata();
		cout<<"enter playtime of the casette"<<endl;
		cin>>playtime;
	}
	void display()
	{
		Publication::display();
		try{
			if(playtime<0.0)
				throw playtime;

		}
			catch(float r)
			{
				playtime=0.0;
				title="0";
				prices=0;
			}
        cout<<"title of the casette is:"<<title<<endl;
        cout<<"price of the casette is:"<<prices<<endl;
		cout<<"playtime of the casette is:"<<playtime;

	}
};

int main() {
	cout << "book and casset" << endl;
	Book b;
	b.getdata();
	b.display();
	tape c;
	c.getdata();
	c.display();
	return 0;
}
