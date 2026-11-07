class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // {weight, index}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> free;

        // {freeTime, index}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        // Initially all servers are free
        for (int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        vector<int> ans;
        long long time = 0;

        for (int i = 0; i < m; i++) {

            // Task i arrives at second i
            time = max(time, (long long)i);

            // Free all servers that have completed their tasks
            while (!busy.empty() && busy.top().first <= time) {
                int idx = busy.top().second;
                busy.pop();

                free.push({servers[idx], idx});
            }

            // If no server is free, wait for the earliest server
            if (free.empty()) {
                time = busy.top().first;

                // Multiple servers may become free at the same time
                while (!busy.empty() && busy.top().first <= time) {
                    int idx = busy.top().second;
                    busy.pop();

                    free.push({servers[idx], idx});
                }
            }

            // Choose server with smallest weight, then smallest index
            auto [weight, idx] = free.top();
            free.pop();

            ans.push_back(idx);

            // Server becomes free after processing this task
            busy.push({time + tasks[i], idx});
        }

        return ans;
    }
};