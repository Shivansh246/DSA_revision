#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

void heapSort(vector<int> &v){
    ///converting to heap
    for(int i=1;i<v.size();i++){
        int cI=i;
        while(cI>0){
            int pI=(cI-1)/2;
            if(v[cI]<v[pI]){
                swap(v[cI],v[pI]);
                cI=pI;
            }else{
                break;
            }
        }
    }
    /// pseudo removeMin to sort in descending order
    for(int i=v.size()-1;i>0;i--){//i>=0 also works but it is meaningless
        swap(v[0],v[i]);
        int pi=0;
        while(true){
            int lci=2*pi+1;
            int rci=2*pi+2;
            int mini=pi;
            if(lci<i && v[lci]<v[mini]){
                mini=lci;
            }
            if(rci<i && v[rci]<v[mini]){
                mini =rci;
            }
            if(mini==pi){
                break;
            }
            swap(v[pi],v[mini]);
            pi=mini;
        }
    }
}
void heapSortAscOrder(vector<int> &v){
    /// converting to a maxHeap
    for(int i=1;i<v.size();i++){
        int ci=i;
        while(ci>0){
            int pi = (ci -1)/2;
            if(v[ci]>v[pi]){
                swap(v[ci],v[pi]);
                ci=pi;
            }else{
                break;
            }
        }
    }

    ///pseudo removeMax
    for(int i=v.size()-1;i>0;i--){
        swap(v[0],v[i]);
        int pi = 0;
        while(true){
            int lci = 2*pi +1; 
            int rci = 2*pi +2; 
            int max=pi;
            if(lci <i && v[lci]>v[max]){
                max= lci;
            }
            if(rci < i && v[rci]>v[max]){
                max= rci;
            }
            if(max== pi){
                break;
            }
            swap(v[max],v[pi]);
            pi = max;
        }
    }
}
int main(){
    /*if an Input array is given the problem with heap sort is that it requires extra space to store the data in a vector
    
    To make it take constant space, we need to make changes in the given array only
    Firstly -> making it into a minHeap
    then -> removing the min element (not in real just assuming) -> this is required as a min heap is not a sorted array
     But this will give a descending sorted array as we are taking min element to the last then acting on the reamining array
    */
    vector<int> v={100,10,15,4,17};
    //heapSort(v);
    //reverse(v.begin(),v.end());
    heapSortAscOrder(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}