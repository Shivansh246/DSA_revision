#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    //string and vectors
    string s="abc";
    vector<string> v;
    v.push_back(s);
    v.push_back("hello");
    for(int i=0;i<v.size();i++){
        cout<<v[i];
        sort(v[i].begin(),v[i].end());
        cout<<endl;
        cout<<v[i]<<endl;
    }

    //string concatenation
    string s1="abc";
    string s2 = "hello";
    string s3="";
    s3+=s1+s2+" world";
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;

    //string legth functions
    cout<<s3.size()<<endl;
    cout<<s3.length()<<endl;

    //substr function
    string s4=s3.substr(3);
    cout<<s4<<endl;
    cout<<s3.substr(3,3)<<endl;

    //find function
    cout<<s3.find("abc")<<endl;
    //cout<<s3.find("x")<<endl;

    //to_string
    int a = 345;
    string s5=to_string(a);
    s5[1]='8';
    cout<<s5<<endl;

    //atoi
    int b =atoi((s5+"1234").c_str());
    cout<<b<<endl;

    //push_back()
    s5.push_back('7');
    cout<<s5<<endl;;

    return 0;

}
