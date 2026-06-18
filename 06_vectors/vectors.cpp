#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> *vp = new vector<int>();//dynamic allocation
    vector<int> v; // static alocation
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //accessing elements just like an array
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;

    v[1]=100;
    v[3]=123;
    v[4]=233;
    v.push_back(23);
    v.push_back(43);

    /*
    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    cout<<v[5]<<endl;
    cout<<v[6]<<endl;
    */

    /// at function
    /*
    cout<<v.at(4);
    cout<<endl<<v.at(5)<<endl;
    */
   
    /// v.size
    /*
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    */

    /// pop_back -> pop outs last element
   // v.pop_back();

    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    
    ///Initialization 
    /*
    vector<int> v1(10,-2);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }
    */
   
   
   ///sorting
   sort(v.begin(),v.end());
   for(int i=0;i<v.size();i++){
       cout<<v[i]<<" ";
   }
    return 0;
}