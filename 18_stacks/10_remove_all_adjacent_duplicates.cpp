#include <bits/stdc++.h>
using namespace std;
/*
abbaca ->after removing bb -> aaca -> after removing ->ca which is the final answer
*/
string remove_adj_duplicates(string a){
    
    /*stack<char> s;
    for(int i=0;i<a.size();i++){
        if(s.empty()||a[i]!=s.top()){
            s.push(a[i]);
        }
        else{
            s.pop();    
        }
    }
    string ans="";
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    if(ans.size()==0){
        return "Empty String";
    }
    reverse(ans.begin(),ans.end());
    return ans;*/
    ///____________________time and space complexity is linear O(n)

    ///simulating inplace stack for constant space complexity
    int sptr=-1;///
    for(int i=0;i<a.size();i++){
        if(sptr==-1||a[sptr]!=a[i]){
            sptr++;
            a[sptr]=a[i];
        }else{
            sptr--;
        }
    }
    string ans="";
    for(int i=0;i<=sptr;i++){
        ans.push_back(a[i]);
    } 
    if(ans.size()==0){
        return "Empty String";
    }
    return ans;
    ///time complexity is O(n)
    ///space complexity is O(1)
}
int main(){
    string a = "mississippi";
    //string a = "abbaca";
    cout<<remove_adj_duplicates(a);
    return 0;
}