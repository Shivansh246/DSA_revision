#include <iostream>
#include<cstring>
using namespace std;
class Student{
    int age;
    char *name;
    public:
    Student(int age,char*name){
        this->age= age;
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    Student(const Student &s){ // reference is must or it wil be an infinite loop , as copy constructor will call 
                               //copy constructor we are creating as there is not default copy constructor
        this->age = s.age;
        //this->name = s.name;  Shallow copy
        this->name = new char[strlen(s.name)+1];
        strcpy(this->name,s.name); 
    }
    void display(){
        cout<<name<<" "<<age<<endl;
    }
};
int main(){
    char name[]= " abcd";
    Student s1(10,name);
    s1.display();
    Student s2(s1);
    s2.display();
    name[0]='x';
    s1.display();

    return 0;
}