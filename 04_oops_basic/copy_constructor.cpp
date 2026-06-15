#include<iostream>
using namespace std;
class Student{
int age;
public:
    int roll;
    Student(int age,int roll){
        cout<<endl<<"Inside constructor"<<endl;
       // cout<<"this = "<<this<<endl;
        this->age = age;
        this->roll = roll;
    }
    void display(){
        cout<<"age: "<<age<<endl;
        cout<<"roll: "<<roll<<endl;
    }
};
int main(){
    Student s1(10,100);
    //cout<<"Address of s1: "<<&s1<<endl;
    cout<<"s1: "<<endl;
    s1.display();

    Student s2(s1);
    cout<<"s2: "<<endl;
    s2.display();

    Student *s3 = new Student(20,200);
    (*s3).display();
    cout<<endl;
    Student *s4=new Student(*s3);
    s4->display();
    cout<<endl;
    Student s5(*s3);
    s5.display();
    
    return 0;
}
