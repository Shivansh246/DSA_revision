#include<iostream>
using namespace std;
int main(){
    int a =5;
    int b=7;
    cout<<"Before swapping: ";
    cout<<"a= "<<a<<" b= "<<b<<endl;
    a=a^b;
    b=a^b;
    a=a^b;
    cout<<"After swapping: ";
    cout<<"a= "<<a<<" b= "<<b<<endl;
    swap(a,b);
    cout<<"After built-in swapping: ";
    cout<<"a= "<<a<<" b= "<<b<<endl;
    return 0;
}
