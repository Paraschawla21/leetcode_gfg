class LRUCache {
public:
    unordered_map<int, vector<int>> mp;
    queue<int> q;
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if (mp.count(key))
        {
            mp[key][1]++;
            q.push(key);
            return mp[key][0];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key))
        {
            mp[key][0] = value;
            mp[key][1]++;
            q.push(key);
        }
        else
        {
            mp[key] = {value, 1};
            q.push(key);
        }
        if (mp.size() > n)
        {
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                mp[curr][1]--;
                if (mp[curr][1] == 0)
                {
                    mp.erase(curr);
                    break;
                }
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */