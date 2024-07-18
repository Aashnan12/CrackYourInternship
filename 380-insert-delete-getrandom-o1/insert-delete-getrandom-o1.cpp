class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int,int> map;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(map.find(val) != map.end()) return false;
        arr.push_back(val);
        map[val] = arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(map.find(val) == map.end()) return false;
        int idx = map[val];
        int last_element = arr.back();
        arr[idx] = last_element;
        arr.pop_back();

        map[last_element] = idx;
        map.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */