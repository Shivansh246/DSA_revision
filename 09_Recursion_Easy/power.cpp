#include <iostream>
using namespace std;
int power(int n,int p){
    ///base case 
    if(p==0){
        return 1;
    }

    ///recursive case
    int smallest= power(n,p-1);

    ///returning calculation
    return n*smallest;
}
int main(){
    int n;
    cin>>n;
    int p;
    cin>>p;
    cout<<power(n,p);
    return 0;
}