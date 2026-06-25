#include <iostream>
using namespace std;
void printasc(int n){
    ///base case
    if(n==0){
        return;
    }
    /// recursion
    printasc(n-1);

    ///calculation
    cout<<n<<endl;
}
void printdsc(int n){
  
    if(n==0){
        return;
    }
    cout<<n<<endl;
    
    printdsc(n-1);

}
int main(){
    int n;
    cin>>n;
    printasc(n);
    cout<<endl;
    printdsc(n);
    return 0;
}