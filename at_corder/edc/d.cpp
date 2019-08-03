#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;

int w[110];
int v[110];
ll dp[110][100010];

void Main()
{
	int N, W; cin >> N >> W;
	rep(i,N) cin >> w[i] >> v[i];

	memset(dp, 0, sizeof(dp));
	rep(i,N) {
		rep(j,W + 1) {
			dp[i + 1][j] = dp[i][j];
			if (j >= w[i]) {
				dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
			}
		}
	}
	ll res = -1;
	rep(i,W + 1) {
		res = max(res, dp[N][i]);
	}
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
