#include <iostream>
#include<queue>
using namespace std;
void kSmallest(vector<int> v,int k){
    // priority_queue<int,vector<int>, greater<int>> pq;// in this the time complexity is nlog(n)
    // for(int i=0;i<v.size();i++){
    //     pq.push(v[i]);
    // }
    priority_queue<int,vector<int>, greater<int>> pq(v.begin(),v.end());/// better way as the time complexity is only O(n)
    for(int i=1;i<=k;i++){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main(){
    // priority_queue<int,vector<int>,greater<int>> pq;
    // pq.push(1);
    // pq.push(75);
    // pq.push(33);
    // pq.push(23);

    // cout<<"size: "<<pq.size()<<endl;
    // while(!pq.empty()){
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }

    //min k elements
    vector<int> v={5,6,9,12,3,13,2};
    kSmallest(v,4);/// 
    return 0;
}