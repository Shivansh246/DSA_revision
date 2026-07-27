#include <iostream>
#include<vector>

using namespace std;
void printDFS(vector<vector<int>> v,int sv,vector<bool> &visited){//sv ->Starting vertex
    cout<<sv<<endl;
    visited[sv]=true;
    int n=v.size();
    for(int i=0;i<n;i++){
        if(v[sv][i]==1&& visited[i]==false){
            printDFS(v,i,visited);
        }
    }
}
void print(vector<vector<int>> v){
    int n=v.size();
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            printDFS(v,i,visited);
        }
    }
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    for(int i=1;i<=e;i++){
        int fv,sv;
        cin>>fv>>sv;
        matrix[fv][sv]=1;
        matrix[sv][fv]=1;
    }
    
    print(matrix);
    return 0;
}