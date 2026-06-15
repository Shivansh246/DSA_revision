#include <iostream>
using namespace std;
class Fraction{
    int numerator;
    int denominator;
    public:
    Fraction(int num,int den){
        numerator=num;
        denominator=den;
    }
    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
    void simplify(){
        int gcd=1;
        int j = min(numerator,denominator);
        for(int i=2;i<=j;i++){
            if(numerator%i==0 && denominator%i==0){
                gcd=i;
            }
        }
        numerator=numerator/gcd;
        denominator=denominator/gcd;
    }

    Fraction operator+(Fraction const &f2){
        int num=numerator*f2.denominator + f2.numerator*denominator;
        int den=denominator*f2.denominator;
        Fraction fnew(num,den);
        fnew.simplify();
        return fnew;
    }
    Fraction operator*(Fraction const &f2){
        int num=numerator*f2.numerator;
        int den=denominator*f2.denominator;
        Fraction fnew(num,den);
        fnew.simplify();
        return fnew;
    }
    bool operator==(Fraction const & f2){
        return (numerator==f2.numerator && denominator==f2.denominator);
    }
    Fraction &operator++(){ // returning by reference to avoid copy in system buffer
        numerator=numerator+denominator;
        simplify();//this->simplify();
        return *this;
    }
    Fraction operator++(int){// no returning by reference as nesting is not allowed for post increment
        Fraction fnew(numerator,denominator);
        numerator=numerator+denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }
    Fraction &operator+=(Fraction const &f2){//nesting is allowed for += operator
        numerator=numerator*f2.denominator+ f2.numerator*denominator;
        denominator=denominator*f2.denominator;
        simplify();
        return *this;
    }
};
int main(){
    Fraction f1(10,2);
    Fraction f2(15,4);
    // Fraction f3 = f1+f2;
    // f1.print();
    // f2.print();
    // f3.print();
    // Fraction f4=f1*f2;
    // f4.print();
    // if(f1==f1){
    //     cout<<"equal"<<endl;
    // }else{
    //     cout<<"unequal"<<endl;
    // }

    //// PRE-INCREMENT OPERATOR
    /*++f1;
    f1.print();
    => for return type void
    */


   /*Fraction f3 = ++f1;
   f3.print();
   => return type Fraction
   */

    // ++(++f1);
    // f1.print(); gives 6/7

    /*Fraction f3=++(++f1);
    f3.print(); //gives 7/1
    f1.print();//gives 7/1*/


    ////POST-INCREMENT OPERATOR
    /*Fraction f3=f1++;
    f1.print();
    f3.print();*/

    ///+= OPERATOR
    //f1+=f2;
    (f1+=f2)+=f2;
    f1.print();
    f2.print();
    return 0;
}