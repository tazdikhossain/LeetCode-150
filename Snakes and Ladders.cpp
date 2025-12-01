class Solution {
public:

    pair<int,int> getPos(int s,int n){
        int r = n - 1 - (s-1)/n;
        int c = (s-1)%n;
        if(((n-1-r)%2)==1)   // reverse direction every alternate row
            c = n-1-c;
        return {r,c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> dist(n*n+1,-1);
        queue<int> q;

        dist[1]=0;
        q.push(1);

        while(!q.empty()){
            int cur = q.front(); q.pop();
            if(cur==n*n) return dist[cur];

            for(int dice=1;dice<=6;dice++){
                int nxt = cur + dice;
                if(nxt > n*n) break;

                auto [r,c] = getPos(nxt,n);
                if(board[r][c] != -1) nxt = board[r][c];

                if(dist[nxt] == -1){
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        return -1;
    }
};
