#include <iostream>
#include<vector>
using namespace std;
int knapSack(int n,int W,vector<int> &price,vector<int> &wts){
    if(n==0||W==0){
        return 0;
    }
    if(wts[n-1]>W){
        return knapSack(n-1,W,price,wts);
    }
    int inc = price[n-1]+knapSack(n-1,W-wts[n-1] ,price,wts);//n-1 as we are taking the item only once
    int exl = knapSack(n-1,W,price,wts);// if question mentions infinite items we can replace n-1 with n in all the cases
    return max(inc,exl);
}
int knapSack2(int n,int W,vector<int> &price,vector<int> &wts){
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            //dp[i][j]= i->items, j->weight
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(wts[i]>j){// item weight is greater than the knapsack weight(j is iterating over the knapsack weight)
                dp[i][j] = dp[i-1][j];
            }else{
                int inc=price[i-1]+dp[i-1][j-wts[i-1]] ;
                int exl =dp[i-1][j];
                dp[i][j] = max(inc,exl);
            }
        }
    }

    return dp[n][W];
}
int main(){
    /*
    a theif wants to steal items from the store , he has a knapsack of weight W,
    there are some items present with certain weight and certain price 
    we have to get the items such that the theif makes the most profit on filling the 
    knapsack with certain items taking items only once
    return the maximum profit*/
    vector<int> price;
    vector<int> wts;
    int W;
    cin>> W;
    //cout<<knapSack(price.size(),W,price,wts);//recursive
    cout<<knapSack2(price.size(),W,price,wts);
    return 0;
}