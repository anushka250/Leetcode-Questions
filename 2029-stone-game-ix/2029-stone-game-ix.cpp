class Solution {
public:
    bool check (int zero, int one, int two){
         if (one == 0)
            return false;
        one--;
        int pairs = min(one, two);
        int len = 1 + 2 * pairs + zero;
        one -= pairs;
        two -= pairs;
        if(one > 0){
            len++;
            one--;
        }
         return (len % 2 == 1 && one + two > 0);   
    }
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for(int x :  stones){
            cnt[x % 3]++;
        }
        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];
        return check(zero, one, two) || check(zero, two, one);
    }

};