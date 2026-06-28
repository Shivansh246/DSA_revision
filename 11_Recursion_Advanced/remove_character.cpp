#include <bits/stdc++.h>
using namespace std;
void remove(char str[],char x){
    if(str[0]=='\0'){
        return;
    }
    if(str[0]==x){
        for(int i=0;str[i]!='\0';i++){
            str[i]=str[i+1];
        }
        return remove(str,x);
    }
    return remove(str+1,x);

}
int main(){
    char str[]="abcbaba";
    remove(str,'a');
    cout<<str;
    return 0;
}