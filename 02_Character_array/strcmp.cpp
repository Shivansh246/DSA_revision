#include<iostream>
#include<cstring>
using namespace std;

int mystrcmp(char str1[],char str2[]){
    if(strlen(str1)!=strlen(str2)){
        return -1;
    }
    for(int i=0;i<strlen(str1);i++){
        if(str1[i]!=str2[i]){
            return str1[i]-str2[i];
        }
    }
    return 0;
}


int main(){
    char str1[100],str2[100];
    cin.getline(str1,sizeof(str1));
    cin.getline(str2,sizeof(str2));
    if(mystrcmp(str1,str2)==0){
        cout<<"equal";
    }
    else{
    cout<<"not equal";
    }
    return 0;
}
