#include <iostream>
using namespace std;
/*
given a number n we have to reach 1 from that number the only steps allowed are:
 1-> decrement by one
 2-> divide by 2 only if the remainder is zero
 3-> divide by 3 only if the remainder is zero*/

 int countMin1(int n){// wrong
    if(n==1){
        return 0;
    }
    if(n%3==0){
        return 1+countMin1(n/3);
    }
    if(n%2==0){
        return 1+countMin1(n/2);
    }
    return 1+countMin1(n-1);
 }
int countMin2(int n){//recursive brute force
    if(n<=1){
        return 0;
    }
    int decrement = countMin2(n-1);
    int two = INT_MAX;
    int three = INT_MAX;
    if(n%2==0){
        two = countMin2(n/2);
    }
    if(n%3==0){
        three = countMin2(n/3);
    }
    return min(decrement,min(two,three))+1;
}
int countMin3(int n,int *arr){// top down DP
    if(arr[n-1]!=0){
        return arr[n-1];
    }

    if(n<=1){
        return 0;
    }
    int decrement = countMin2(n-1);
    int two = INT_MAX;
    int three = INT_MAX;
    if(n%2==0){
        two = countMin2(n/2);
    }
    if(n%3==0){
        three = countMin2(n/3);
    }
    int output= min(decrement,min(two,three))+1;
    arr[n-1] = output;
    return output;
}
int countMin4(int n){// bottom up DP
    int *dp = new int[n+1];
    dp[0] =0;
    dp[1] = 0;
    // dp[i] = min steps req to move from i to 1;
    for(int i=2;i<=n;i++){
        int x = dp[i-1];
        int y = INT_MAX;
        int z = INT_MAX;
        if(i%2==0){
            y=dp[i/2];
        }
        if(i%3==0){
            z=dp[i/3];
        }
        int output = min(min(x,y),z)+1;
        dp[i]=output;
    }
    delete[] dp;
    return dp[n];
}
int main(){
    int n;
    cin>>n;

    int minSteps1 = countMin1(n);// wrong approach like for example for 10, it will divide by2 first then 5 is decremented then 
                                //4 is divided by 2 then 2 is divided by hence 4 steps
                                // but if we decrement it by 1 then divide by 3 and again divide by 3 we will reach 1 in just 3 ways 
    

    int minSteps2 = countMin2(n);/// recursive brute force

    int arr[n]={-1};
    int minSteps3 = countMin3(n,arr);/// top down DP, memorisation
    int minSteps4 = countMin4(n);///bottom up DP, iterative

    cout<<"min steps 1: "<< minSteps1<<endl;
    cout<<"min steps 2: "<< minSteps2<<endl;
    cout<<"min steps 3: "<< minSteps3<<endl;
    cout<<"min steps 4: "<< minSteps4<<endl;
    return 0;
}