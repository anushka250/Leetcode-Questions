class Solution {
public:
    struct State{
        int r, c;
        int mask;
        int energy;
        int dist;
    };
    int minMoves(vector<string>& classroom, int energy) {
       int m = classroom.size();
       int n = classroom[0].size();
       vector<vector<int>> litterId(m, vector<int>(n,-1));
       int litterCount = 0;
       int sr = -1, sc = -1;

       for (int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(classroom[i][j] == 'S'){
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L'){
                    litterId[i][j] = litterCount++;
                }
            }
       }
       if(litterCount == 0)
        return 0;
        int fullMask = (1<<litterCount) - 1;
        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1 << litterCount, -1)));
        queue<State> q;
        best[sr][sc][0] = energy;
        q.push({sr, sc, 0, energy, 0});
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()){
            State cur = q.front();
            q.pop();
            int r = cur.r;
            int c = cur.c;
            int mask =cur.mask;
            int e = cur.energy;
            int dist = cur.dist;

            if (mask == fullMask)
                return dist;
            for (int d = 0; d < 4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];

                if(nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                if (classroom[nr][nc] == 'X')
                    continue;
                if (e ==0)
                    continue;

                int newEnergy = e - 1;
                int newMask = mask;
                if(litterId[nr][nc] != -1){
                    int id = litterId[nr][nc];
                    newMask |= (1<<id);
                }
                if(classroom[nr][nc] == 'R'){
                    newEnergy = energy;
                }
                if (newEnergy <= best[nr][nc][newMask])
                    continue;
                best[nr][nc][newMask] = newEnergy;
                q.push({
                    nr, nc, newMask, newEnergy, dist+1
                });
            }
        }
        return -1;
    }
};