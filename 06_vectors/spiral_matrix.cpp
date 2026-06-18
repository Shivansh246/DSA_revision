#include <iostream>
#include<vector>
using namespace std;
class Solution{
    public:
    vector<int>spiralOrder(vector<vector<int>>&matrix)const{
        vector<int>ans;
        int m = matrix.size(); // returns number of rows which is number of elements in vector that is vector<int>
        int n = matrix[0].size();// returns number of elements in first row or number of cols
        int sr=0,er=m-1,sc=0,ec=n-1;
        int count = 0;
        if(m==0)return ans;
        if(n==0)return ans;
        while(sr<=er&& sc<=ec){
            ///print sr
            for(int i=sc;i<=ec;i++){
                ans.push_back(matrix[sr][i]);
                count++;
            }
            sr++;
            if(count==m*n){
                return ans;
            }
            //print ec
            for(int i = sr;i<= er;i++){
                ans.push_back(matrix[i][ec]);
                count++;
            }
            ec--;
            if(count==m*n){
                return ans;
            }
            /// print er
            for(int i=ec;i>=sc;i--){
                ans.push_back(matrix[er][i]);
                count++;
            }
            er--;
            if(count==m*n){
                return ans;
            }
            for(int i=er;i>=sr;i--){
                ans.push_back(matrix[i][sc]);
                count++;
            }
            sc++;
            if(count == m*n){
                return ans;
            }
        }
        return ans;
    }
};
int main(){
    vector<vector<int>> v = {{1 ,2 ,3 ,4 ,5 },
                             {4 ,5 ,6 ,7 ,8 },
                             {7 ,8 ,9 ,10,11},
                             {12,13,14,15,16}
                            };
    Solution S;
    vector<int> ans = S.spiralOrder(v);  
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}