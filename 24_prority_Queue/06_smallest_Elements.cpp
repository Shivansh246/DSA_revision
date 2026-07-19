#include <iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> kSmallest(int *arr,int n,int k){
    priority_queue<int> pq;
    vector<int> ans;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    /* or
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
        if(pq.size() >k){
            pq.pop()// will pop the largest element
        }
    }
    
    */
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}
int main(){
    int arr[]={5,6,9,12,3,13,2};
    vector<int> v=kSmallest(arr,7,3);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}