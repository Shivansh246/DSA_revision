#include<iostream>
#include"Student_class.cpp"
using namespace std;



int main(){
    Student s1(10,100);
    Student s2(20,200);
    s2.display();
    /*Copy assignment operator works when both the objects are created*/
    s2=s1;
    s1.display();
    s2.display();
    return 0;
}
