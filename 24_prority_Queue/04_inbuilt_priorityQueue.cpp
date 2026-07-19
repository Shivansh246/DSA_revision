#include <iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq;///by default maximum heap
    pq.push(10);
    pq.push(6);
    pq.push(167);
    pq.push(42);
    pq.push(35);

    cout<<"size: "<<pq.size()<<endl;

    cout<<"Top"<<pq.top()<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}