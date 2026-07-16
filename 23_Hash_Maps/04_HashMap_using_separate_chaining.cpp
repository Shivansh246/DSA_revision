#include <iostream>
using namespace std;

template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode<V> *next;
    MapNode(string key,V value){
        this key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode(){
        delete next;//recursive
    }
};

template<typename V>
class mymap{
    MapNode<V>**bucket;///array of buckets with entries of type MapNode<V>*
    int count;
    int numBucket;///size of the array

    int getBucketIndex(string key){
        int hashcode =0;
        int base =1;
        int p=37;
        for(int i=key.size()-1;i>=0;i--){
            hashcode+=key[i] * base;
            base *=p;
            hashcode=hashcode % numBucket;
            base = base % numBucket;
        }
       return hashcode % numBucket;
    }
    public:
    mymap(){
        count =0;
        numBucket=5;
        for(int i =0;i<5 ;i++){
            bucket[i]=NULL;// otherwise they would contain garbage addresses which is dangerous
        }
    }
    ~mymap(){
        for(int i=0;i<numBucket;i++){
            delete bucket[i];
        }
        delete []bucket;
    }
    int size(){
        return count;
    }

    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head= bucket[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    void insert(string key,V value){
        int bucketIndex = getBucketIndex(key)/// hash function

        ///to check if the key exist in this linked list
        MapNode<V> *head = bucket[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                head->vaue=value;/// if found then update
                return;
            }
            head=head->next;
        }
        /// if not found
        MapNode<V> *node = new MapNode<V>(key,value);
        node->next = bucket[bucketIndex];
        bucket[bucketIndex]=node;
        count++;
    }
    V remove(string key){// will return the corresponding value
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head= bucket[bucketIndex];
        MapNode<V> *prev = NULL;
        while(head!=NULL){
            if(head->key==key){
                if(prev==NULL){
                    bucket[bucketIndex]=head->next;
                }else{
                    prev->next = head->next;
                }
                V value = head->value;
                    head->next=NULL;
                    delete head; 
                    count--;
                    return value;
            }
            prev = head;
            head = head->next;
        }
    }
    return 0;
};
int main(){
    
    return 0;
}