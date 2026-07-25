#include <iostream>
using namespace std;

int staircase(int n, int k){
    int *dp = new int[n+1];
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++){
        int a=0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                a+=dp[i-j];
                
            }
        }
        dp[i]=a;
    }
    int ans = dp[n];
    delete []dp;
    return ans;
}

int main(){
    int n;
    cout<<"Enter level to reach: ";
    cin>>n;
    cout<<"Upto how many steps at a time: ";/// to take steps form 0 to k 
    int k;
    cin>>k;

    int steps = staircase(n,k);
    cout<<"Total steps : "<<steps<<endl;
    return 0;
}