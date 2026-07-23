#include <iostream>
using namespace std;
/*to reach at the top of the staircase
->can take only one or two steps 
->total how many ways?*/

int staircase1(int n){// brute force
    if(n==1||n==0){
        return 1;
    }
    return staircase1(n-1) + staircase1(n-2);
}
int helper(int n, int *arr){
    if(n<=1){
        return 1;
    }
    if(arr[n]!=0){
        return arr[n];
    }
    arr[n]= helper(n-1,arr)+helper(n-2,arr);
    return arr[n];
}
int staircase2(int n){
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=0;
    }
    int ans= helper(n,arr);
    delete []arr;
    return ans;
}
int staircase3(int n){
    int *arr = new int[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1] + arr[i-2];
    }
    int ans = arr[n];
    delete []arr;
    return ans;
}
int main(){
    int n;
    cin>>n;
    int steps1 = staircase1(n);
    cout<<"Total steps 1: "<<steps1<<endl;
    int steps2 = staircase2(n);
    cout<<"Total steps 2: "<<steps2<<endl;
    int steps3 = staircase3(n);
    cout<<"Total steps 3: "<<steps3<<endl;
    return 0;
}