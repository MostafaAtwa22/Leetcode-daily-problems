#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>

class RandomizedSet {
public:
    std::unordered_map<int, int> mp;
    std::vector<int> a;

    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end())
            return false;
        a.push_back(val);
        mp[val] = a.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;

        int index = mp[val];
        int last_element = a.back();

        a[index] = last_element;
        mp[last_element] = index;

        a.pop_back();
        mp.erase(val);

        return true;
    }

    int getRandom() {
        return a[rand() % a.size()];
    }
};
