#include <bits/stdc++.h>
using namespace std;
void printSteps(int n,char s,char d,char h){
    if(n==0){
        return;
    }
    printSteps(n-1,s,h,d);
    cout<<"moving disc "<<n<<" from "<< s<< " to "<<d<<endl;
    printSteps(n-1,h,d,s);
}
int main(){
    int n;
    cin>>n;
    printSteps(n,'a','c','b');
    return 0;
}