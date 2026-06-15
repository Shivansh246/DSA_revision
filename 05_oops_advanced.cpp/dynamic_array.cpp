#include <iostream>
using namespace std;
class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
    DynamicArray(){
        data = new int[5];
        nextIndex=0;
        capacity=5;
    }
    DynamicArray(const DynamicArray &d2){
        capacity=d2.capacity;
        nextIndex=d2.nextIndex;
        data = new int[capacity];
        for(int i=0;i<nextIndex;i++){
            data[i]=d2.data[i];
        }
    }
    void operator=(const DynamicArray &d2){
        capacity=d2.capacity;
        nextIndex=d2.nextIndex;
        data = new int[capacity];
        for(int i=0;i<nextIndex;i++){
            data[i]=d2.data[i];
        }
    }
    void add(int element){
        if(nextIndex==capacity){
            int *newData=new int [2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i]=data[i];
            }
            delete [] data;
            data = newData;
            capacity*=2;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    int getElement(int i) const{
        if(i>=0 && i<nextIndex){
            return data[i];
        }else{
            return -1;
        }
    }
    void add(int element,int index){
        if(index<nextIndex){
            data[index]=element;

        }else if(index==nextIndex){
            add(element);
        }else{
            return;
        }
    }
    void print()const{
        for(int i=0;i<nextIndex;i++){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    void getCapacity()const{
       cout<<capacity<<endl;
    }
};
int main(){
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);
    cout<<d1.getElement(4)<<endl;
    d1.print();
    d1.getCapacity();
    DynamicArray d2=d1;// copy constructor 
    DynamicArray d3; //our default constroctor
    d3=d1; // copy assignment operator
    d1.add(100,0);
    d1.print();
    d2.print();
    d3.print();
    return 0;
}
