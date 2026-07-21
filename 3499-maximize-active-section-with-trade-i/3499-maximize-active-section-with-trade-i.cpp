class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for(char c:s)
            if(c == '1')
                ones++;
        string t = '1' + s + "1";
        int m = t.size();
        vector<pair<char,int>> blocks;
        for(int i = 0; i <m;){
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            blocks.push_back({t[i], j-i});
            i = j;
        }
        int ans = ones;
        for (int i = 1; i +1 < blocks.size(); i++){
            if(blocks[i].first == '1' && blocks[i-1].first == '0' && blocks[i+1].first == '0'){
                ans =max(ans, ones+ blocks[i-1].second + blocks[i+1].second);
            }
        }
        return ans;
    }
};