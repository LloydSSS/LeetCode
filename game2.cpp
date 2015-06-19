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
#define rrep_st(i,s,t) for (int i = t-1; i >= s; --i)

typedef long long ll;
const double eps = 1e-9;
const int N = 500;

int n, m;
vector<vector<int> > puzzle(N, vector<int>(N));
vector<vector<ll> > dp(2, vector<ll>(N, -1));
vector<ll> ddp(N, -1);
vector<ll> udp(N, -1);

ll ans = -1;

void init() {
	// downward
	rep (i, n) {
		// if (puzzle[0][i] == -1) {
		// 	ddp[i] = -1;
		// 	continue;
		// }

		// if (i != 0 && ddp[i-1] != -1)
		if (i != 0 && ddp[i-1] > 0)
			ddp[i] = ddp[i-1] + puzzle[0][i];
		else
			ddp[i] = puzzle[0][i];
	}
	// upward
	rrep (i, n) {
		// if (puzzle[0][i] == -1) {
		// 	udp[i] = -1;
		// 	continue;
		// }

		// if (i != n-1 && udp[i+1] != -1)
		if (i != n-1 && udp[i+1] > 0)
			udp[i] = udp[i+1] + puzzle[0][i];
		else
			udp[i] = puzzle[0][i];
	}
	rep (i, n) {
		dp[0][i] = max(ddp[i], udp[i]);
	}

}

void solve() {
	init();

	bool cur = 0;
	// rep (i, n)
	// 	cout << dp[cur][i] << " ";
	// cout << endl;
	rep_st(j, 1, m) {

		cur = !cur;
		// rightward
		rep (i, n) {
			// if (puzzle[j][i] == -1 || dp[!cur][i] == -1) {
			// 	dp[cur][i] = -1;
			// 	continue;
			// }

			dp[cur][i] = puzzle[j][i] + dp[!cur][i];
		}
		// downward
		rep (i, n) {
			// if (puzzle[j][i] == -1) {
			// 	ddp[i] = -1;
			// 	continue;
			// }
			// if (i != 0 && ddp[i-1] != -1)
			if (i != 0)
				ddp[i] = max(dp[cur][i], ddp[i-1] + puzzle[j][i]);
			else
				ddp[i] = dp[cur][i];
		}
		// upward
		rrep (i, n) {
			// if (puzzle[j][i] == -1) {
			// 	udp[i] = -1;
			// 	continue;
			// }
			// if (i != n-1 && udp[i+1] != -1)
			if (i != n-1)
				udp[i] = max(dp[cur][i], udp[i+1] + puzzle[j][i]);
			else
				udp[i] = dp[cur][i];
		}

		// teleport from bottom to top
		// if (ddp[0] == -1 && puzzle[j][0] != -1 && ddp[n-1] != -1) {
		if (ddp[0] < puzzle[j][0]) {
			// the first pos can trun right from bottom to top
			int stop = n-1;
			// rrep (i, n) {
			// 	if (dp[!cur][i] != -1) {
			// 		stop = i;
			// 		break;
			// 	}
			// }
			rep (i, stop) {
				// if (puzzle[j][i] == -1)
				// 	break;
				// if (i == 0)
				// 	ddp[i] = puzzle[j][i];
				// else if (ddp[i-1] != -1)
				// 	ddp[i] = max(ddp[i], ddp[i-1] + puzzle[j][i]);
				// else
				// 	break;
				if (i == 0)
					ddp[i] = puzzle[j][i];
				else if (ddp[i-1] + puzzle[j][i] > ddp[i])
					ddp[i] = ddp[i-1] + puzzle[j][i];
				else
					break;
			}
		}
		// teleport from top to bottom
		// if (udp[n-1] == -1 && puzzle[j][n-1] != -1 && udp[0] != -1) {
		if (udp[n-1] < puzzle[j][n-1]) {
			// the first pos can trun right from top to bottom
			int stop = 0;
			// rep (i, n) {
			// 	if (dp[!cur][i] != -1) {
			// 		stop = i;
			// 		break;
			// 	}
			// }
			rrep_st (i, stop+1, n) {
				// if (puzzle[j][i] == -1)
				// 	break;
				// if (i == n-1)
				// 	udp[i] = puzzle[j][i];
				// else if (udp[i+1] != -1)
				// 	udp[i] = max(udp[i], udp[i+1] + puzzle[j][i]);
				// else
				// 	break;
				if (i == n-1)
					udp[i] = puzzle[j][i];
				else if (udp[i+1] < udp[i+1] + puzzle[j][i])
					udp[i] = udp[i+1] + puzzle[j][i];
				else
					break;
			}
		}

		rep (i, n) {
			dp[cur][i] = max(ddp[i], udp[i]);
		}
		// rep (i, n)
		// 	cout << dp[cur][i] << " ";
		// cout << endl;
	}

	rep (i, n) {
		ans = max(ans, dp[cur][i]);
	}
}

int main() {
#ifndef ONLINE_JUDGE
#ifdef __APPLE__
    freopen("/Users/G/Project/WAP/wapexam1/test8.txt", "r", stdin);
#else
	freopen("D:/Project/WAP/wapexam1/test3.txt", "r", stdin);
#endif
#endif

	scanf("%d%d", &n, &m);
	rep (i, n) {
		rep (j, m) {
			scanf("%d", &puzzle[j][i]);
		}
	}

	solve();

	printf("%lld\n", ans);
	return 0;
}
