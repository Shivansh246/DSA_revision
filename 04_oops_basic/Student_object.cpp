#include<iostream>
#include"Student_class.cpp"
using namespace std;
int main(){
    Student s1;
    Student *s2=new Student;
    s1.setAge(4);
    s1.display();

    s2->setAge(-5);
    s2->display();
    return 0;
}


