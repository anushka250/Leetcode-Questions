class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftsum = 0, rightsum = 0;
        int leftq = 0, rightq = 0;
        for(int i = 0; i < n / 2; i++){
            if(num[i] == '?')
                leftq++;
            else
                leftsum += num[i] - '0';
        }
        for(int i = n/2; i<n; i++){
            if(num[i] == '?')
                rightq++;
            else
                rightsum += num[i] - '0';
        }
        if((leftq + rightq) % 2 == 1)
            return true;
        return 2 * (leftsum - rightsum) != 9 * (rightq - leftq);
    }
};