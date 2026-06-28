#include <bits/stdc++.h>
using namespace std;
/*
we have to put n blocks from source to destination with the help of helper
we can only put lighter block on heavier block and the blocks are arranged in decreasing weight from bottom to top
 no of ways to put n blocks = no of ways to put n-1 blocks from source to helper + 1 way to put the largest block from source to 
 destination + no of ways to put n-1 blocks to put from helper to destination
*/
int toh(int n){
    if(n==0){
        return 0;
    }
    return toh(n-1)+1+toh(n-1);
}
int main(){
    cout<<toh(3);
    return 0;
}