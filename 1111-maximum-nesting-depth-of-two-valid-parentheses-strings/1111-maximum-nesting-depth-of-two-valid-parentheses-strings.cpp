class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = 0;
        vector<int> ans;
        for(char i: seq){
            if(i == '('){
                depth++;
                ans.push_back(depth % 2);
            }
            else{
                ans.push_back(depth % 2);
                depth--;
            }
        }
        return ans;
    }
};