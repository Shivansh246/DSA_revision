#include <bits/stdc++.h>
using namespace std;
int eval(vector<string> const &token){
    stack<int>st;
    for(int i=0;i<token.size();i++){
        if(token[i]=="+"||token[i]=="-"||token[i]=="/"||token[i]=="*"){
            int v1=st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
            if(token[i]=="+"){
                st.push(v2+v1);
            }else if(token[i]=="-"){
                st.push(v2-v1);
            }else if(token[i]=="*"){
                st.push(v2*v1);
            }else if(token[i]=="/"){
                st.push(v2/v1);
            }
        }else{
            st.push(atoi(token[i].c_str()));///char to int -> atoi, atoi -> takes c type character arrays as argument
                                                /// c++ string to c type char arrays -> .c_str()
        }
    }
    return st.top();
}     
int main(){
    vector<string>v = {"4","13","5","/","+"};
    cout<<eval(v);
    return 0;
}
