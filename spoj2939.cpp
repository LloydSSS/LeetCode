#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 400010
#define MAXM 3000010
#define BLACK 0
#define WHITE 1
int V[MAXM],E[MAXM],NEXT[MAXM],FIR[MAXN];
int v[MAXN],e[MAXN],next[MAXN],fir[MAXN];
int col[MAXN],size[MAXN],ma[MAXN],vis[MAXN];
int n,tot;int mi,root,rt;

struct point{
    int dist,id;
    bool operator<(const point&b)const{
        return dist>b.dist;
    }
};
priority_queue<point>Q[MAXN];

char buf[10000000],*pt = buf,*o = buf;
inline int getint(){
    int f = 1,x = 0;
    while((*pt != '-') && (*pt < '0' || *pt > '9'))    pt ++;
    if(*pt == '-')    f = -1,pt ++;    else    x = *pt++ - 48;
    while(*pt >= '0' && *pt <= '9')    x = x * 10 + *pt ++ - 48;
    return x * f;
}

void ADD(int x,int y,int z){
    V[tot]=y;E[tot]=z;NEXT[tot]=FIR[x];FIR[x]=tot;tot++;
}

void addedge(int x,int y){
    v[tot]=y;next[tot]=fir[x];fir[x]=tot;tot++;
    v[tot]=x;next[tot]=fir[y];fir[y]=tot;tot++;
}

void init(){
    memset(fir,255,sizeof(fir));tot=0;
    n=getint();
    for(int i=1;i<n;i++){
        int x=getint(),y=getint();
        addedge(x,y);
    }
    memset(FIR,255,sizeof(FIR));tot=0;
}

void dfssize(int u,int fa){
    size[u]=1;ma[u]=0;
    for(int i=fir[u];~i;i=next[i])
        if(v[i]!=fa&&!vis[v[i]]){
            dfssize(v[i],u);
            size[u]+=size[v[i]];
            if(size[v[i]]>ma[u]) ma[u]=size[v[i]];
        }
}

void dfsroot(int u,int fa){
    if(size[rt]-size[u]>ma[u]) ma[u]=size[rt]-size[u];
    if(ma[u]<mi) mi=ma[u],root=u;
    for(int i=fir[u];~i;i=next[i])
        if(v[i]!=fa&&!vis[v[i]])
            dfsroot(v[i],u);
}

void dfsdis(int u,int fa,int dis){
    ADD(u,root,dis);
    for(int i=fir[u];~i;i=next[i])
        if(v[i]!=fa&&!vis[v[i]])
            dfsdis(v[i],u,dis+1);
}

void dfs(int u){
    mi=n,rt=u;dfssize(u,0);dfsroot(u,0);
    dfsdis(root,0,0);
    vis[root]=1;
    for(int i=fir[root];~i;i=next[i])
        if(!vis[v[i]])
            dfs(v[i]);
}

void modify(int x){
    col[x]^=1;
    if(col[x]==WHITE)
        for(int i=FIR[x];~i;i=NEXT[i])
            Q[V[i]].push((point){E[i],x});
}

int query(int x){
    int ret=INF;
    for(int i=FIR[x];~i;i=NEXT[i]){
        while(!Q[V[i]].empty()&&(col[Q[V[i]].top().id]==BLACK)) Q[V[i]].pop();
        if(!Q[V[i]].empty()) ret=min(Q[V[i]].top().dist+E[i],ret);
    }
    return ret<INF?ret:-1;
}

void solve(){
    int q=getint();
    int op,x;
    while(q--){
        op=getint(),x=getint();
        if(op==0)
            modify(x);
        else
            printf("%d\n",query(x));
    }
}


int main(){
    fread(buf,1,10000000,stdin);
    init();
    dfs(1);
    solve();
    return 0;
}