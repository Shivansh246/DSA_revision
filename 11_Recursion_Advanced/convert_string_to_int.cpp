#include <bits/stdc++.h>
using namespace std;
int stringToInt(string str,int n){
    if(n==0){
        return 0;
    }
    int smallAns= stringToInt(str,n-1);
    int lastDigit=str[n-1]-'0';
    return smallAns*10+lastDigit;
}
int main(){
    string str;
    cin>>str;
    int n=str.length();
    cout<<stringToInt(str,n);
    
    return 0;
}