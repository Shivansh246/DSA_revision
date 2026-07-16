#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string,int> mymap;///use inbuilt pair class for storing data
    ////insert
    pair<string,int> p("abc",1);
    mymap.insert(p);
    
    ///better way to insert
    mymap["def"]=2;

    ///access
    cout<<mymap["abc"]<<endl;
    cout<<mymap.at("abc")<<endl;

   // cout<<mymap.at("ghi")<<endl;/// throws an error as "ghi" is not present
    cout<<mymap["ghi"]<<endl;///pushes element "ghi" with default value 0 and returns it

    ////check presence of a key
    if(mymap.count("ghi")>0){/// count can only return 0 or 1 as the keys are unique
        cout<<"ghi is present"<<endl;
    }else{
        cout<<"not present"<<endl;
    }

    ///update
    mymap["abc"]=2;
    cout<<mymap["abc"]<<endl;

    ///check size
    cout<<"size: "<< mymap.size()<<endl;

    ///erasing an entry from the map
    mymap.erase("ghi");
    cout<<"size: "<< mymap.size()<<endl;
    if(mymap.count("ghi")>0){/// count can only return 0 or 1 as the keys are unique
        cout<<"ghi is present"<<endl;
    }else{
        cout<<"not present"<<endl;
    }
    return 0;
}