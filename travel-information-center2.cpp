#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <utility>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)
#define rrep_st(i,s,t) for (int i = t-1; i >= s; --i)

typedef long long ll;
const double eps = 1e-9;
const int N = 4000010;

struct city {
	int dist;
	int id;
	city(int d, int i) : dist(d), id(i) {}

	bool operator<(const city &b) const {
		return dist > b.dist;
	}
};

int val[N], edge[N], ne[N], head[N];
int vval[N], eedge[N], nne[N], hhead[N];
int size[N], ma[N];
bool vis[N], fest[N];

int tot;
int mi,root,rt;
int n, m;

priority_queue<city> que[N];

void addedge(int x,int y) {
	val[tot] = y;
	ne[tot] = head[x];
	head[x] = tot;
	tot++;
}

void ADD(int x,int y,int z) {
	vval[tot] = y;
	eedge[tot] = z;
	nne[tot] = hhead[x];
	hhead[x] = tot;
	tot++;
}

void dfssize(int u,int fa) {
	size[u] = 1;
	ma[u] = 0;
	for (int i = head[u]; i != -1; i = ne[i]) {
		if (val[i] != fa && !vis[val[i]]) {
			dfssize(val[i],u);
			size[u] += size[val[i]];
			if (size[val[i]] > ma[u])
				ma[u] = size[val[i]];
		}
	}
}

void dfsroot(int u, int fa) {
	if (size[rt] - size[u] > ma[u])
		ma[u] = size[rt] - size[u];
	if(ma[u] < mi) {
		mi = ma[u];
		root = u;
	}
	for (int i = head[u]; i != -1; i = ne[i]) {
		if (val[i] != fa && !vis[val[i]])
			dfsroot(val[i], u);
	}
}

void dfsdis(int u, int fa, int dis) {
	ADD(u, root, dis);
	for (int i = head[u]; i != -1; i = ne[i]) {
		if (val[i] != fa && !vis[val[i]])
			dfsdis(val[i], u, dis+1);
	}
}

// divide tree
void dfs(int u) {
	mi = n;
	rt = u;
	dfssize(u, 0);
	dfsroot(u, 0);
	dfsdis(root, 0, 0);
	vis[root] = true;
	for (int i = head[root]; i != -1; i=ne[i]) {
		if (!vis[val[i]])
			dfs(val[i]);
	}
}

// the government announces a new festive city x
void rock(int x) {
	if (fest[x] == true) {
		fest[x] = false;
		return;
	}
	fest[x] = true;
	for (int i = hhead[x]; i != -1; i = nne[i])
		que[vval[i]].push(city(eedge[i], x));
}

// deal with the query
int query(int x) {
	int ret=INT_MAX;
	// from bottom to top
	for (int i=hhead[x]; i != -1; i=nne[i]){
		while(!que[vval[i]].empty() && fest[que[vval[i]].top().id] == false) que[vval[i]].pop();
		if(!que[vval[i]].empty())
			ret = min(que[vval[i]].top().dist + eedge[i], ret);
	}
	return ret == INT_MAX ? -1 : ret;
}

void solve() {
	int op,x;
	while(m--){
		scanf("%d%d", &op, &x);
		if(op==0)
			rock(x);
		else
			printf("%d\n",query(x));
	}
}

int main(){
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/WAP/in.txt", "r", stdin);
#else
	freopen("D:/Project/WAP/in.txt", "r", stdin);
#endif
#endif
	memset(head, -1, sizeof(head));
	tot = 0;

	scanf("%d", &n);
	int x, y;
	rep (i, n-1) {
		scanf("%d%d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}

	memset(hhead, -1, sizeof(hhead));
	tot = 0;
	dfs(1);
//	rock(1);
	scanf("%d", &m);
	solve();

	return 0;
}
