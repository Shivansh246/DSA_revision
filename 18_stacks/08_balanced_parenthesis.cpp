#include <bits/stdc++.h>
using namespace std;
/*
()[]{} is a balanced string
([)] is an unbalanced string
{[]} is a balanced a string 
([]{}()) also a balanced string
*/

bool isValid(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('|| str[i]=='{'||str[i]=='['){
            s.push(str[i]);
        }else{
            if(s.empty()){
                return false;
            }else if(str[i]==')'){
                if(s.top()=='('){
                    s.pop();
                }else{
                    return false;
                }
            }else if(str[i]=='}'){
                if(s.top()=='{'){
                    s.pop();
                }else{
                    return false;
                } 
            }else{
                if(s.top()=='['){
                    s.pop();
                }else{
                    return false;
                }
            }
        }
    }    
    if(s.empty()){
        return true;
    }
    return false;
}
int main(){
    string str;
    cin>>str;

    if(isValid(str)){
        cout<<"string is valid"<<endl;
    }else{
        cout<<"Invalid string"<<endl;
    }
    return 0;
}