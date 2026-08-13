class Solution {
public:
    struct Node{
        char leftChar, rightChar;
        int leftLen, rightLen;
        int best, len;
        Node(){
            leftChar = rightChar = '#';
            leftLen = rightLen = best = len = 0;

        }
        Node(char c){
            leftChar = rightChar = c;
            leftLen = rightLen = best = len = 1;
        }
    };
    vector<Node> seg;
    Node merge(Node a, Node b){
        if (a.len == 0) return b;
        if(b.len == 0) return a;
        Node res;
        res.len = a.len + b.len;
        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.leftLen = a.leftLen;

        if(a.leftLen == a.len && a.rightChar == b.leftChar)
            res.leftLen = a.len+b.leftLen;
        res.rightLen = b.rightLen;

        if(b.rightLen == b.len && a.rightChar == b.leftChar)
            res.rightLen = b.len + a.rightLen;
        res.best = max(a.best, b.best);
        if(a.rightChar == b.leftChar){
            res.best = max(res.best, a.rightLen + b.leftLen);
        }
        return res;
    }

    void build(int node, int l, int r, string &s){
        if( l == r){
            seg[node]= Node(s[l]);
        
        return;
        }
        int mid = (l + r)/2;
        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid+1, r, s);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c){
        if(l==r){
            seg[node] = Node(c);
            return;
        }
        int mid = (l+r)/2;
        if(idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2+1, mid + 1, r, idx, c);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        seg.resize(4 * n + 5);
        build(1, 0, n-1, s);
        vector<int> ans;
        for(int i = 0; i < queryIndices.size(); i++){
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            update(1, 0, n-1, idx, c);
            ans.push_back(seg[1].best);
        }
        return ans;
    }
};