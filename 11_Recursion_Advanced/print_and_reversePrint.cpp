#include <bits/stdc++.h>
using namespace std;
void print(char input[]){
    if(input[0]=='\0'){
        return;
    }
    cout<<input[0];
    return print(input+1);
}
void reversePrint(char input[]){
    if(input[0]=='\0'){
        return;
    }
    reversePrint(input+1);
    cout<<input[0];
}
int main(){
    char input[]="abc";
    print(input);
    cout<<endl;
    reversePrint(input);
    return 0;
}