#include <iostream>
#include<vector>
using namespace std;
class priorityQueue{
    private:
    vector<int> pq;
    public:
    priorityQueue(){

    }
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }
    void insert(int element){
        pq.push_back(element);
        int cI=pq.size()- 1;
        while(cI>0){
            int pI = (cI-1)/2;
            if(pq[cI]<pq[pI]){
                swap(pq[cI],pq[pI]);
                cI=pI;
                
            }else{
                break;
            }
        }
    }
    int removeMin(){
        if(isEmpty()){
            return 0;
        }
        int ans=pq[0];
        swap(pq[0],pq[pq.size()-1]);/// CBT done
        pq.pop_back();

        //down heapify
        int pI =0;
        while(true){
            int lcI= 2*pI +1;
            int rcI = 2*pI +2;
            int mini = pI;
            if(lcI < pq.size() && pq[lcI]<pq[mini]){
                mini=lcI;
            }
            if(rcI<pq.size() && pq[rcI]<pq[mini]){
                mini = rcI;
            }
            if(mini == pI){
                break;
            }
            swap(pq[mini],pq[pI]);
            pI=mini;
        }
        return ans;
    }
};
int main(){
    priorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout<<"size: "<<p.getSize()<<endl;
    cout<<"min: "<<p.getMin()<<endl;

    cout<<endl;
    while(!p.isEmpty()){
        cout<<p.removeMin()<<" ";/* this outputs a sorted data and this sorting mechanism is called heap sort with time complexity 
                                    nlog(n) and space complexity O(n)*/
    }
    return 0;
}