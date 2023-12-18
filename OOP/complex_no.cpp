 #include<iostream>
using namespace std;
class complex{
    public:
    int real;
    int img;

    complex(){
        real=0;
        img=0;
    }

    complex(int a, int b){
        real=a;
        img=b;
    }

    complex operator + (complex c2){     //when operations are to be performed on objects rather than 
        complex c3;                      //normal parameters then op overloading is used
        c3.real=real+c2.real;
        c3.img=img+c2.img;
        return c3;
    }

    complex operator * (complex c2){
        complex c4;
        c4.real=((real*c2.real)-(img*c2.img));
        c4.img=((real*c2.img)+(img*c2.real));
        return c4;
    }
};
int main(){
    int r1,r2,i1,i2,n;
    cout<<"img and real part of no1 is:"<<endl;
    cin>>r1>>i1;
    cout<<"img and real part of no1 is:"<<endl;
    cin>>r2>>i2;
    cout<<"no1 is"<<r1<<"+"<<i1<<"i"<<endl;
    cout<<"no2 is"<<r2<<"+"<<i2<<"i"<<endl;
    complex c1(r1,i1),c2(r2,i2),c3,c4;
    c3=c1+c2;
    c4=c1*c2;


for(int i=0;i<2;i++)
{
    cout<<"enter 1 for addition and 2 for product:"<<endl;
    cin>>n;
    if(n==1){
        cout<<"addition is"<<c3.real<<"+"<<c3.img<<"i"<<endl;
}
    else if(n==2){
        cout<<"product is"<<c4.real<<"+"<<c4.img<<"i"<<endl;
}
    else{
        cout<<"invalid input"<<endl;
}
}
}

