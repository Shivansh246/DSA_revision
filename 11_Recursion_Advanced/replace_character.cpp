#include <bits/stdc++.h>
using namespace std;
void replace(char str[],char i, char x){
    if (str[0]=='\0'){
        return;
    }
    if(str[0]==i){
        str[0]=x;
    }
    replace(str+1,i,x);
}
int main(){
    char str[]="abababab";
    replace(str,'a','x');
    cout<<str;
    return 0;
}