#include <iostream>
#include<vector>
#include<queue>
using namespace std;
void print(vector<vector<int>> matrix,int sv){
    int n=matrix.size();
    vector<bool> visited(n,false);
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<endl;
        for(int i=0;i<n;i++){
            if(matrix[front][i] && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
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
   
    print(matrix,0);
    return 0;
}