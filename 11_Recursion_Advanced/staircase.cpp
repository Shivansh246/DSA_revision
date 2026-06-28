#include <bits/stdc++.h>
using namespace std;
/*number of ways to jump from step 0 to step n, only 1,2&3 steps can be taken
number of ways to reach n -> number of ways to reach n-1 + no of ways to reach n-2 + no of ways to reach n-3

*/
int countWays(int n){
    if(n==0||n==1){return 1;}
    if(n==2){
        return 2;    }
    return countWays(n-1) + countWays(n-2) + countWays(n-3);
}
int main(){
    cout<<countWays(3);
    return 0;
}