struct Compare {
    bool operator()(const pair<int, pair<int,int>>& a,
                    const pair<int, pair<int,int>>& b) const {
        if (a.first != b.first)
            return a.first > b.first;          // higher priority first
        if (a.second.second != b.second.second)
            return a.second.second > b.second.second; // smaller taskId first
        return a.second.first < b.second.first;       // tie-break by userId
    }
};

class TaskManager {
public:
    set<pair<int, pair<int,int>>, Compare> pq; 
    unordered_map<int, set<pair<int, pair<int,int>>, Compare>::iterator> pos;

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &i : tasks) {
            int userId = i[0];
            int taskId = i[1];
            int priority = i[2];
            auto it = pq.insert({priority, {userId, taskId}}).first;
            pos[taskId] = it;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        auto it = pq.insert({priority, {userId, taskId}}).first;
        pos[taskId] = it;
    }
    
    void edit(int taskId, int newPriority) {
        if (pos.count(taskId)) {
            auto it = pos[taskId];
            auto val = *it;
            pq.erase(it);
            auto newIt = pq.insert({newPriority, {val.second.first, taskId}}).first;
            pos[taskId] = newIt;
        }
    }
    
    void rmv(int taskId) {
        if (pos.count(taskId)) {
            pq.erase(pos[taskId]);
            pos.erase(taskId);
        }
    }
    
    int execTop() {
        if (pq.empty())
            return -1;
        auto it = pq.begin();
        int userId = it->second.first;
        int taskId = it->second.second;
        pos.erase(taskId);
        pq.erase(it);
        return userId;
    }
};
