#include <bits/stdc++.h>
using namespace std;
void print_subs(string input,string output,vector<string> &v){
    if(input.length()==0){
        cout<<"_"<<" ";
    }else{
        cout<<input<<" ";
    }
    if(input.length()==0){
        v.push_back(output);
        return;
    }
    print_subs(input.substr(1),output,v);//excluding the character
    
    print_subs(input.substr(1),output+input[0],v);//including the character
    /*
    ->"bc","" || "bc","a"

    ->"c",""  || "c","b"  || "c","a" || "c","ab"

    ->"",""   || "","c"   || "","b"  || "","bc" || "","a" ||"","ac" || "","ab" || "","abc" as input is "" in all
        hence the output will be printed

    */

}
void print_subs2(char input[],char output[],int i,vector<string> &v){
    if(input[0]=='\0'){
        output[i]='\0';
        v.push_back(output);
        return;
    }
    output[i]=input[0];
    print_subs2(input+1,output,i+1,v);//including the character
    print_subs2(input+1,output,i,v);//excluding the character
}
int main(){
    string input;
    cin>>input;
    char in[10];
    cin>>in;
    char out[10];
    string output = "";
    vector<string> v1;
    vector<string> v2;
    print_subs(input,output,v1);// exclude then include

    cout<<endl<<endl<<"output"<<endl;
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
    cout<<endl;
    print_subs2(in,out,0,v2);//include then  exclude
    for(int i=0;i<v2.size();i++){
        cout<<v2[i]<<endl;
    }
    return 0;
}