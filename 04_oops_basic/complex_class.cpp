#include <iostream>
using namespace std;
class Complex{
    int real;
    int img;
    public:
    Complex(int r,int i){
        real = r;
        img = i;
    }
    void print(){
        cout<<real<<" + i"<<img;
    }
     void plus(Complex const &c2){
        real=real+c2.real;
        img = img+ c2.img;
     }
     void multiply(Complex const &c2){
        int temp = real*c2.img+ c2.real*img;
        real = real*c2.real - img*c2.img;
        img=temp;
        
     }
};