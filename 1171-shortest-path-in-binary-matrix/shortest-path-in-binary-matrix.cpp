int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

bool vis[102][102];
int n,m;

bool valid(int i,int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}

int bfs(vector<vector<int>>& a,int sx,int sy){
    queue<pair<int,pair<int,int>>> q;
    q.push({1,{sx,sy}});
    vis[sx][sy]=true;

    while(!q.empty()){
        auto cur=q.front(); q.pop();

        int d=cur.first;
        int r=cur.second.first;
        int c=cur.second.second;

        if(r==n-1 && c==m-1)
            return d;

        for(int i=0;i<8;i++){
            int nx=r+dx[i];
            int ny=c+dy[i];

            if(valid(nx,ny) && a[nx][ny]==0 && !vis[nx][ny]){
                vis[nx][ny]=true;
                q.push({d+1,{nx,ny}});
            }
        }
    }

    return -1;
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        n=a.size();
        m=a[0].size();

        if(a[0][0]) return -1;

        memset(vis,false,sizeof(vis));

        return bfs(a,0,0);
    }
};
