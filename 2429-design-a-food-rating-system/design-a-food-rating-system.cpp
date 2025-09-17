struct CustomCompare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
        if (a.first != b.first) {
            return a.first > b.first;   // higher rating first
        }
        return a.second < b.second;    // lexicographically smaller
    }
};

class FoodRatings {
public:
    unordered_map<string, set<pair<int, string>, CustomCompare>> type; 
    unordered_map<string, string> mp;  
    unordered_map<string, int> rat;   

    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) {
        int n = f.size();
        for (int i = 0; i < n; i++) {
            mp[f[i]] = c[i];
            type[c[i]].insert({r[i], f[i]});
            rat[f[i]] = r[i];
        }
    }
    
    void changeRating(string f, int r) {
        string c = mp[f];
        auto &s = type[c];
        s.erase({rat[f], f});  
        s.insert({r, f});       
        rat[f] = r;             
    }
    
    string highestRated(string c) {
        auto it = type[c].begin();
        return it->second;      
    }
};
