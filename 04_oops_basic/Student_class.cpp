#include<iostream>
using namespace std;

class Student{
    int age;
    int id;
public:
    Student(int age=0,int id=0){
        this->age = age;
        this->id = id;
    }
    void setAge(int a){
        if (a<0){
            return;
        }
        age = a;
    }
    int getAge(){
        return age;
    }
    void display(){
    cout<<age<<" "<<id<<endl;
    }
};
