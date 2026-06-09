#include<iostream>
#include<cstring>
using namespace std;
void printallprefixes(char str[]){
    for(int i=0;i<strlen(str);i++){
        for(int j=0;j<=i;j++){
            cout<<str[j];
        }
        cout<<endl;
    }
}
void printallsuffixes(char str[]){
    for(int i=0;i<strlen(str);i++){
        for(int j=strlen(str);j>=strlen(str)-i;j--){
            cout<<str[j-1];
        }
        cout<<endl;
    }
}
int main(){
    char str[100];
    cin.getline(str,sizeof(str));
    printallprefixes(str);
    printallsuffixes(str);
    return 0;
}
