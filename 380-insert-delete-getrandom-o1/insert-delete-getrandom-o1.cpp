class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> a;
    int last = 0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp[val])
            return false;
        last++;
        a.push_back(val);
        mp[val] = last;
        return true;
    }
    
    bool remove(int val) {
        if (!mp[val])
            return false;
        if (mp[val] != last)
        {
            a[mp[val] - 1] = a[last - 1];
            mp[a[last - 1]] = mp[val];
        }
        a.pop_back();
        mp[val] = 0;
        last--;
        return true;
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distr(0, a.size() - 1);

        int random_index = distr(gen);
        int random_value = a[random_index];
        return random_value;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */