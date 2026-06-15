#include <iostream>
using namespace std;

class Fraction{
    int numerator;
    int denominator;
    public:
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }

    void add(Fraction &f2){
        int lcm = denominator*f2.denominator;
        int x = lcm/denominator;
        int y = lcm/f2.denominator;

        numerator=numerator*x + f2.numerator*y;
        denominator=lcm;
        simplify();
    }
    void simplify(){
        int min_num = min(numerator,denominator);
        int gcd = 1;
        for(int i=2;i<=min_num;i++){
            if(numerator%i==0 && denominator%i==0){
                gcd = i;
            }
        }
        numerator = numerator/gcd;
        denominator = denominator/gcd;
    }
    void display(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
};

int main(){
    int n1,d1,n2,d2;
    cin>>n1>>d1>>n2>>d2;
    Fraction f1(n1,d1);
    Fraction f2(n2,d2);
    f1.add(f2);
    f1.display();
    return 0;
}