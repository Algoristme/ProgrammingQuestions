// LRU Cache
class LRUCache {
public:
    typedef list<int>::iterator qIt;
    LRUCache(int capacity) : limit(capacity) {
        
    }
    
    int get(int key) {
        auto res = kvMap.find(key);
        if(res != kvMap.end()) {            
            auto newIt = updateQEntry(res->second.second);
            res->second.second = newIt;
            return res->second.first;            
        }
        return -1;
    }
    
    void put(int key, int value) {        
        if(kvMap.find(key) == kvMap.end()) {
            if(cacheIsFull()) {
                evictLeastRecentlyUsed();
            }
            auto it = makeQEntry(key);
            cout << " Made q entry " << *it << endl;
            cout << " Q size " << q.size() << endl;
            kvMap[key] = pair<int,qIt>(value, it);            
        }        
        else {
            // Update map and Q
            auto res = kvMap.find(key);
            auto it = updateQEntry(res->second.second);
            res->second.first = value;
            res->second.second = it;
        }
    }
    
private :
    bool cacheIsFull() {
        return q.size() >= limit ;
    }
        
    void evictLeastRecentlyUsed() {
        auto it = q.begin();
        cout << "Evicting " << *it << endl;
        if(kvMap.find(*it) != kvMap.end()) {
            kvMap.erase(kvMap.find(*it));
        }
        q.pop_front();
    }    
                        
    list<int>::iterator  makeQEntry(int key) {
        q.push_back(key);
        return --q.end();
    }
    
    list<int>::iterator  updateQEntry(list<int>::iterator &it) {
        int val = *it;
        q.erase(it);
        return makeQEntry(val);
    }
    
private :
    unordered_map<int,pair<int,qIt>> kvMap;
    list<int> q;
    int limit;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */