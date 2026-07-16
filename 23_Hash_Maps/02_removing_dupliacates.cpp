#include <iostream>
#include<unordered_map>
#include<vector>

using namespace std;
vector<int> removeDuplicates(int*arr,int n){
    vector<int> output;
    unordered_map<int,bool> mymap;
    for(int i=0;i<n;i++){
        if(mymap.count(arr[i])==0){
            output.push_back(arr[i]);
            mymap[arr[i]]=true;
        }
    }
    return output;
}
int main(){
    int arr[]={1,1,2,3,4,3,2};
    vector<int> v =removeDuplicates(arr,7);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}