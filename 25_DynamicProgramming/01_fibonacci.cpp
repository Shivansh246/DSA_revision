#include <iostream>
using namespace std;
int get_fibonacci(int n){
    if(n==1 ){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return get_fibonacci(n-1) + get_fibonacci(n-2);
}
int fibonacci2(int n, int *a){
    if(n==1 ){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(a[n]!=0){
        return a[n];
    }
    int output = fibonacci2(n-1,a)+fibonacci2(n-2,a);// left function calls will fill the array and right function calls will 
                                                     // simply return from the array
    a[n]=output;/// store for future use
    return output;
}
int fibonacci3(int n){
    int *a = new int[n+1];
    a[0]=0;
    a[1]=1;
    if(n==1 ){
        return 0;
    }
    if(n==2){
        return 1;
    }
    for(int i=2;i<=n;i++){
        a[i] = a[i-1] + a[i-2];
    }
    int output = a[n-1];
    delete []a;
    return output;
}
int main(){
    int n;
    cin>>n;
    //cout<< get_fibonacci(n);// very bad the time complexity is 2^n
    int a[n+1]={0};
    //cout<<fibonacci2(n,a);// first traversing the array from right to left due to recursion till base case 
                         // then filling the array from starting to end two iterations

    cout<<fibonacci3(n);// will iterate the array only once as we are creating array and filling iteratively from the start
    return 0;
}