class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival,
                               vector<int>& load) {

        // Free servers
        set<int> available;

        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishTime, serverId}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        vector<int> count(k, 0);

        for (int i = 0; i < arrival.size(); i++) {

            // Free servers whose requests are completed
            while (!busy.empty() &&
                   busy.top().first <= arrival[i]) {

                int server = busy.top().second;
                busy.pop();

                available.insert(server);
            }

            // All servers are busy
            if (available.empty()) {
                continue;
            }

            // Start searching from i % k
            int start = i % k;

            auto it = available.lower_bound(start);

            // Wrap around
            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            available.erase(it);

            count[server]++;

            // Server becomes free after this request
            busy.push({
                (long long)arrival[i] + load[i],
                server
            });
        }

        // Find maximum number of handled requests
        int mx = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == mx) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};