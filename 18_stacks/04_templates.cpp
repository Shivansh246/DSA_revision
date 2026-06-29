#include <bits/stdc++.h>
using namespace std;
/*template<typename T>
class Pair{
    T x;
    T y;
    public:
    void setX(T x){
        this->x = x;
    }
    void setY(T y){
        this->y = y;
    }
    T getX(){
        return x;
    }
    T getY(){
        return y;
    }
};*/
template<typename T,typename V> 
class Pair{
    T x;
    V y;
    public:
    void setX(T x){
        this->x = x;
    }
    void setY(V y){
        this->y = y;
    }
    T getX(){
        return x;
    }
    V getY(){
        return y;
    }
};
int main(){
    /*Pair<int> p1;
    Pair<double> p2;
    Pair<char> p3;*/
    // Pair<int,double> p;
    // p.setX(1.23);
    // p.setY(3.45);
    // cout<<p.getX()<<" "<<p.getY();

    ///creating triplets using pair class
    Pair<Pair<int,int>,double> p;
    p.setY(2.43);
    Pair<int,int> temp;
    temp.setX(2);
    temp.setY(4);
    p.setX(temp);
    cout<<p.getX().getX()<<" "<<p.getX().getY()<<" "<<p.getY()<<endl;

    return 0;
}