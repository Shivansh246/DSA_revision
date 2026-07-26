#include <iostream>
using namespace std;
int helper1(string s1,int i,string s2,int j){
    if(i>=s1.length()|| j>=s2.length()){
        return 0;
    }
    if(s1[i]==s2[i]){
        return 1+helper1(s1,i+1,s2,j+1);
    }else{
        return max(helper1(s1,i+1,s2,j),helper1(s1,i,s2,j+1));
    }
}
int lcs1(string s1,string s2){
    return helper1(s1,0,s2,0);
}
int lcs2(string s1,string s2){
    int m = s1.size();
    int n = s2.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    /*between apple and mango the longest common subsequence is 'a' with lenght 1;
    between apple and ample the longest common subsequence is "aple", with lenghth 4
    */
   string s1,s2;
   cin>>s1;
   cin>>s2;
   //cout<<lcs1(s1,s2);// time consuming

   cout<<lcs2(s1,s2);

    return 0;
}