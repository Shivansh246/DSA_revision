#include <bits/stdc++.h>
using namespace std;
int getfirst(vector<int>const &v,int x){
    int s=0;
    int e = v.size()-1;
    int ans= -1;
    while(s<=e){
        int mid = s+ (e-s)/2;
        if(v[mid]==x){
            ans = mid;
            e = mid-1;
        }else if(v[mid]>x){
            e = mid-1;
        }else{
            s =mid+1;
        }
    }
    return ans;
}
int getlast(vector<int>const &v,int x){
    int s=0;
    int e = v.size()-1;
    int ans=-1;
    while(s<=e){
        int mid = s+ (e-s)/2;
        if(v[mid]==x){
            ans = mid;
            s = mid+1;
        }else if(v[mid]>x){
            e = mid-1;
        }else{
            s =mid+1;
        }
    }
    return ans;
}
int getindex(vector<int> const & v,int x, bool check){
    int s=0;
    int e = v.size()-1;
    int ans=-1;
    while(s<=e){
        int mid = s+ (e-s)/2;
        if(v[mid]==x){
            ans = mid;
            if(check){
                e = mid-1;
            }else{
                s = mid+1;
            }
        }else if(v[mid]>x){
            e = mid-1;
        }else{
            s =mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> v ={1,2,3,8,8,8,9};
    vector<int> ans(2,-1);
    // int first = getfirst(v,8);
    // int last = getlast(v,8);
    int first = getindex(v,8,true);
    int last = getindex(v,8,false);
    ans[0] = first;
    ans[1] = last;
    for(int i = 0;i<2;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}