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
#include <utility>
using namespace std;

#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep_st(i,s,t) for (int i = s; i < t; ++i)
#define rrep(i,n) for (int i = n-1; i >= 0; --i)

typedef long long ll;
const double eps = 1e-9;
const int N = 100010;

int n, m;

struct node {
	int dist;
	vector<int> neighbor;
	node(int d = -1) : dist(d) {}
}city[N];

bool visited[N];

void addedge(int s, int t) {
	city[s].neighbor.push_back(t);
	city[t].neighbor.push_back(s);
}

void rock(int s) {
	city[s].dist = 0;
}

int bfs(int s) {
	memset(visited, 0, sizeof(visited));
	queue<pair<int, int> > q;
	q.push(make_pair(s, 0));

	while (!q.empty()) {
		pair<int, int> pr = q.front();
		int x = pr.first;
		int d = pr.second;
		q.pop();

		visited[x] = true;
		if (city[x].dist == 0)
			return d;
		rep (i, city[x].neighbor.size()) {
			int y = city[x].neighbor[i];
			if (visited[y])
				continue;
			q.push(make_pair(y, d+1));
		}
	}

	return n-1;
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/WAP/in.txt", "r", stdin);
#else
	freopen("D:/Project/WAP/in.txt", "r", stdin);
#endif
#endif
	scanf("%d%d", &n, &m);
	int x, y;
	rep (i, n-1) {
		scanf("%d%d", &x, &y);
		addedge(x, y);
	}
	rock(1);

	rep (i, m) {
		scanf("%d%d", &x, &y);
		if (x == 1)
			rock(y);
		else
			printf("%d\n", bfs(y));
	}
	return 0;
}
