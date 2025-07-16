class LRUCache {
public:
    list<int>dll;
    map<int, pair<list<int>::iterator,int>>mp;
    int n;
    LRUCache(int capacity) {
        n= capacity;
    }
    
    void markRecentlyUsed(int key){
       //erase 
       dll.erase(mp[key].first);
       // push 
       dll.push_front(key);
       // update in the map 
       mp[key].first= dll.begin();
        
    }

    int get(int key) {
        if(mp.find(key)== mp.end()) return -1;
        // get 
        markRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        // if present in mp
        if(mp.find(key)!= mp.end()){
            // mark recently used 
        markRecentlyUsed(key);
            // update 
            mp[key].second=value;
        }
        else {
            dll.push_front(key);
            mp[key]={dll.begin(), value};
            n--;// cap decresaes ho rhi 
        }
        if(n<0){
            int key = dll.back();
            dll.pop_back();
            mp.erase(key);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */