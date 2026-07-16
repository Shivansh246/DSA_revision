#include <iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

int main(){
    unordered_map<string,int> mymap;
    mymap["abc"]=1;
    mymap["abc1"]=2;
    mymap["abc2"]=3;
    mymap["abc3"]=4;
    mymap["abc4"]=5;
    mymap["abc5"]=6;
    cout<<endl<<"Unordred Map:"<<endl;
    for(unordered_map<string,int>:: iterator it=mymap.begin();it!=mymap.end();it++/* it++ goes to any element no order*/){
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;/// in pair class "first" stores the keys and "second" stores the value
    }
    map<string,int> mymap2;
    mymap2["abc"]=1;
    mymap2["abc1"]=2;
    mymap2["abc2"]=32;
    mymap2["abc3"]=4;
    mymap2["abc4"]=43;
    mymap2["abc5"]=6;
    
    cout<<endl<<"Ordred Map:"<<endl;
    for(map<string,int>:: iterator it=mymap2.begin();it!=mymap2.end();it++){//map<string,int>:: iterator it can be replaced by auto
        cout<<"key: "<<it->first<<" value: "<<it->second<<endl;
    }

    ///iterator for vector
    vector<int> v;
    v.push_back(10);
    v.push_back(3);
    v.push_back(14);
    v.push_back(32);
    v.push_back(7);
    cout<<endl<<"vector: "<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){///vector<int>::iterator can be replaced by auto
        cout<<*it<<" ";///vector are not implemented using any class hence *it
        //// the values are accessed in the same order as they are inserted
    }


    ///find 
    cout<<endl;
    if(mymap.find("abc")==mymap.end()){/// find returns an iterator, if the value is not found it returns .end(),
        cout<<"not present"<<endl;
    }else{
        cout<<"present"<<endl;
    }

    ///erase
    unordered_map<string,int>:: iterator it = mymap.find("abc");///unordered_map<string,int>:: iterator can be replaced by auto
    mymap.erase(it);/// can take a key or an iterator as input
    cout<<endl;
    if(mymap.find("abc")==mymap.end()){/// find returns an iterator to the element, if the value is not found it returns .end(),
        cout<<"not present"<<endl;
    }else{
        cout<<"present"<<endl;
    }

    ///erasing continuous entries in the map not the unordered map as there are no continuous entries
    mymap2.erase(mymap2.begin(),mymap2.end());
    for(map<string,int>::iterator it = mymap2.begin();it!=mymap2.end();it++){
        cout<<it->first<<"->"<<it->second<<endl;
    }
    cout<<"size of mymap2 after erasing is "<<mymap2.size();
    return 0;

    

}