#include<iostream>
using namespace std;
int length(char name[]){
    int count=0;
    for(int i=0;name[i]!='\0';i++){
        count++;
    }
    return count;
}
int main(){
    char name[100];
    cin>>name;
    /*while(name[length]!='\0'){
    int length=0;
        length++;
    }
    cout<<length;*/
    /*using function*/
    cout<<length(name)<<endl;
    char a[4];
    cin>>a;
    cout<<a;
    return 0;
}
