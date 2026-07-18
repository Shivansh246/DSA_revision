#include <iostream>
using namespace std;

template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode<V> *next;
    MapNode(string key,V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~MapNode(){
        delete next;//recursive
    }
};

template<typename V>
class mymap{
    private:
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
    void rehash(){
        MapNode<V>* *temp = bucket;
        bucket = new MapNode<V> * [2*numBucket];
        for(int i=0;i<2*numBucket;i++){
            bucket[i]=NULL;
        }
        int oldNumBucket= numBucket;
        numBucket*=2;
        count = 0;
        for(int i=0;i<oldNumBucket;i++){
            MapNode<V> *head = temp[i];
            while(head!=NULL){
                string key = head->key;
                V value = head->value;
                insert(key,value);
                head=head->next;
            }
        }
        for(int i=0;i<oldNumBucket;i++){
            delete temp[i];
        }
        delete temp;
    }
    public:
    mymap(){
        count =0;
        numBucket=5;
        bucket = new MapNode<V> *[numBucket];
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
        int bucketIndex = getBucketIndex(key);/// hash function

        ///to check if the key exist in this linked list
        MapNode<V> *head = bucket[bucketIndex];
        while(head!=NULL){
            if(head->key == key){
                head->value=value;/// if found then update
                return;
            }
            head=head->next;
        }
        /// if not found
        MapNode<V> *node = new MapNode<V>(key,value);
        node->next = bucket[bucketIndex];
        bucket[bucketIndex]=node;
        count++;
        float loadFactor = (1.0 * count )/ numBucket;
        if(loadFactor > 0.7){
            rehash();
        }
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
        return 0;
    }
    float getLoadFactor(){
        return (1.0* count )/ numBucket;
    }
};
int main(){
    mymap<int> ourmap;
    for(int i=0;i<10;i++){
        char c = '0'+i;
        string key = "abc";
        key += c;
        int value = i+ 1;
        ourmap.insert(key,value);
    }
    for(int i=0;i<10;i++){
        char c = '0'+i;
        string key = "abc";
        key += c;
        cout<<key<<" "<<ourmap.getValue(key)<<endl;
    }
    cout<<ourmap.size();

    ourmap.remove("abc2");
    ourmap.remove("abc5");
    cout<<endl;
    for(int i=0;i<10;i++){
        char c = '0'+i;
        string key = "abc";
        key += c;
        cout<<key<<" "<<ourmap.getValue(key)<<endl;
    }
    cout<<ourmap.size();
    return 0;
}