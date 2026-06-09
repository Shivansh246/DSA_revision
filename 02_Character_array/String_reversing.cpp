#include<iostream>
using namespace std;
int length(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}

void reverse(char name[]){
    int s=0;
    int e=length(name)-1;
    while(s<e){
        swap(name[s],name[e]);
        s++;
        e--;
    }
}
int main(){
    char name[100];
    cin.getline(name,100);
    cout<<name<<endl;
    reverse(name);
    cout<<name;
    return 0;
}
