class Solution {
public:
    using ll = long long;
    ll gcdll(ll a, ll b){
        while(b) {
            ll temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ll lcmll(ll a, ll b){
        return a/gcdll(a, b) * b;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n =coins.size();
        sort(coins.begin(), coins.end());
        vector<int> useful;
        for(int coin : coins){
            bool redundant = false;
            for(int x : useful){
                if(coin % x == 0){
                    redundant = true;
                    break;
                }
            }
            if(!redundant){
                useful.push_back(coin);
            }
        }
        coins = useful;
        n = coins.size();
        auto count= [&](ll X) -> ll{
            ll total = 0;
            for(int mask=1; mask < (1<<n); mask++){
                ll L=1;
                int bits = 0;
                bool valid = true;
                for(int i = 0; i<n; i++){
                    if(mask & (1 << i)){
                        bits++;
                        L=lcmll(L, coins[i]);
                        if(L > X){
                            valid = false;
                            break;
                        }
                    }
                }
                if(!valid)
                    continue;
                ll multiples = X / L;
                if(bits % 2 == 1)
                    total += multiples;
                else
                    total -= multiples;
            }
            return total;
        };
        ll low = 1;
        ll high =1LL * coins[0] * k;
        while(low < high){
            ll mid = low + (high - low)/ 2;
            if(count(mid) >= k){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};