class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26,0);
        for(char &ch : word){
            mp[ch - 'a']++;
        }
        sort(begin(mp), end(mp), greater<int>());
        int result = 0;
        for(int i = 0; i<26; i++){
            int freq = mp[i];
            int press = i/8 + 1;
            result += press * freq;
        }
        return result;
    }
};