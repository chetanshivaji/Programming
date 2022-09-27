#include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    int cap;
    unordered_map<int,list<pair<int,int>>::iterator>m; //map<key, list<key,value>::iterator>
    list<pair<int,int>>listValues;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        int value = (*m[key]).second;   //get address and return * of it as value;
        //maintain LRU
        listValues.erase(m[key]);
        listValues.push_back(make_pair(key,value));
        m[key]= prev(listValues.end());
        return value;
    }
    
    void put(int key, int value) {
        if(m.size()==cap)
        {
            //evict.
            int keyToDeleteFromFront = (*listValues.begin()).first;
            listValues.erase(listValues.begin());
            m.erase(keyToDeleteFromFront);
            //evicts from front;
        }
        //if key present
        if(m.find(key)!=m.end())
        {
            listValues.erase(m[key]); //get address of value in linked list and delete it
        }
            listValues.push_back(make_pair(key,value));//push back to list.
            m[key] = prev(listValues.end()); //update address in map.
    }
        
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 int main()
 {
    LRUCache obj(2);
    obj.put(1,1);
    obj.put(2,2);
    cout<<obj.get(1)<<endl;
    obj.put(3,3);
    cout<<obj.get(2)<<endl;;
    obj.put(4,4);
    cout<<obj.get(1)<<endl;
    cout<<obj.get(3)<<endl;
    cout<<obj.get(4)<<endl;
  	return 0;
 }
 /*
 ["LRUCache","get","put","get","put","put","get","get"]
[[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
*/
