class Solution {
public:
    set<string> parse(string& s, int& i) {
        set<string> res;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                for (string str : cur) {
                    res.insert(str);
                }

                cur.clear();
                cur.insert("");

                i++;
                continue;
            }

            set<string> next;

            if (s[i] == '{') {
                i++;  // skip '{'
                next = parse(s, i);
                i++;  // skip '}'
            }
            else {
                next.insert(string(1, s[i]));
                i++;
            }

            set<string> temp;

            for (string a : cur) {
                for (string b : next) {
                    temp.insert(a + b);
                }
            }

            cur = temp;
        }

        for (string str : cur) {
            res.insert(str);
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};