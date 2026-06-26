#include <bits/stdc++.h>
using namespace std;
void print_positions(int arr[],int n, int x,int i){
    if(i==n){
        return;
    }
    if(arr[i]==x){
        cout<<i<<endl;
    }
    return print_positions(arr,n,x,i+1);
}
int main(){
    int arr[]={1,2,1,1,4};
    print_positions(arr,5,1,0);
    return 0;
}