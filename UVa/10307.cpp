#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const int N = 55;
const int M = 3000;

typedef struct Node{
    int x,y,w;
}Node;
struct str{
    int x,y,w;
}a[M<<2];
char s[N][N];
int maze[N][N],vis[N][N],fa[M];
int n,m,cnt;
int op[4][2]={0,1,1,0,0,-1,-1,0};

void bfs(int x,int y){
    memset(vis,0,sizeof vis);
    queue<Node> que;
    Node p,q;
    p.x = x;p.y = y;p.w = 0;//到自己的距離為0
    vis[x][y] = 1;//標記已經走過
    que.push(p);//存到隊列中
    while(!que.empty()){
        p = que.front();//從隊列中取出来
        que.pop();
        for(int i = 0;i < 4;i++){
            q.x = op[i][0]+p.x;
            q.y = op[i][1]+p.y;
            q.w = p.w+1;//距離也要統計一下
            //尋找在範圍內並且沒有走過的點，還是可以走的通的
            if(q.x>=1&&q.x<=n&&q.y>=1&&q.y<=m&&vis[q.x][q.y]==0&&maze[q.x][q.y]>=0){
                vis[q.x][q.y] = 1;//標記這個點已經走過了
                que.push(q);
                if(maze[q.x][q.y] > 0){// 如果是可達的節點，記錄距離資料
                    a[cnt].x = maze[x][y];
                    a[cnt].y = maze[q.x][q.y];
                    a[cnt++].w = q.w;
                }
            }
        }
    }
    return;
}
bool cmp(struct str a,struct str b){
    return a.w < b.w;
}
int Find(int x){
    if(fa[x] == x) return x;
    else return fa[x] = Find(fa[x]);
}
int kruskal(){
    
    for(int i = 0;i < M;i++) fa[i] = i;
    sort(a,a+cnt,cmp);
    int ans = 0,i = 0;
    while(i < cnt){
        int fx = Find(a[i].x);
        int fy = Find(a[i].y);
        if(fx != fy){
            fa[fx] = fy;
            ans += a[i].w;
        }
        i++;
    }
    return ans;
}
void solve(){
    memset(maze,0,sizeof maze);
    int num = 0;
    cnt = 0;
    scanf("%d%d",&m,&n);
    gets(s[0]);
    for(int i = 1;i <= n;i++){
        gets(s[i]+1);
        for(int j = 1;j <= m;j++){
            //表示>=0的就是可以走的通的
            if(s[i][j] == 'A' || s[i][j] == 'S'){
                maze[i][j] = ++num;
            }else if(s[i][j] == '#'){
                maze[i][j] = -1;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(maze[i][j] > 0){
                bfs(i,j);//用bfs计算這個點到其他點的距離
            }
        }
    }
    printf("%d\n",kruskal());
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
