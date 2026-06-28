#include <bits/stdc++.h>
using namespace std;
void removeDuplicate(char str[]){
    if(str[0]=='\0'){
        return;
    }
    if(str[0]!=str[1]){
        return removeDuplicate(str+1);
    }
    for(int i=0;str[i]!='\0';i++){
        str[i]=str[i+1];
    }
    return removeDuplicate(str);
}
int main(){
    char str[]="aabbbccccdeef";
    removeDuplicate(str);
    cout<<str;
    return 0;
}