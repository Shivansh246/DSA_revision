#include <iostream>
using namespace std;
int mD(string s1, int m, string s2, int n){
    if(m==0){
        return n;/// we need to insert n characters to s1
    }
    if(n==0){
        return m;/// we need to delete all i.e. m charcters from s1
    }
    if(s1[m-1]==s2[n-1]){
        return mD(s1,m-1,s2,n-1);
    }
    int i = mD(s1,m,s2,n-1);// the last character of s2 is inserted to s1
    int d = mD(s1,m-1,s2,n);// the last character of s1 is deleted
    int r = mD(s1,m-1,s2,n-1);// the last character of s1 is replaced by last chacter of s2

    return 1+min(i,min(d,r));
}
int minDist1(string s1,string s2){
    return mD(s1,s1.size(),s2,s2.size());
}
int minDist2(string s1,string s2){
    int m= s1.size();
    int n= s2.size();
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }else if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                int insert = dp[i][j-1];
                int del = dp[i-1][j];
                int replace = dp[i-1][j-1];
                dp[i][j] = 1+min(insert, min(del,replace));
            }
        }
    }
    return dp[m][n];
}


int main(){
    /*minimum distanace required to convert word1 to word 2
    operations allowed:
    ->insert a character
    ->delete a character 
    ->replace a character*/
    string s1,s2;
    cin>>s1>>s2;
    // cout<<minDist1(s1,s2);
    cout<<minDist2(s1,s2);
    return 0;
}