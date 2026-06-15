#include <iostream>
#include"complex_class.cpp"
using namespace std;

int main(){
    Complex c1(1,2);
    Complex c2(3,4);
    int choice;
    cin>>choice;
    if(choice==1){
        c1.plus(c2);
        c1.print();
    }
    else{
        c1.multiply(c2);
        c1.print();
    }
    return 0;
}