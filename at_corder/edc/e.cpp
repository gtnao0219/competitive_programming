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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int w[110];
int v[110];
ll dp[110][100010];

void Main()
{
	int N, W; cin >> N >> W;
	rep(i,N) cin >> w[i] >> v[i];

	rep(i,N) {
		rep(j,100010) {
			dp[i][j] = 1e18;
		}
	}
	dp[0][0] = 0;
	rep(i,N) {
		rep(j,100010) {
			dp[i + 1][j] = dp[i][j];
			if (j >= v[i]) {
				dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
			}
		}
	}
	int res = 0;
	rep(i,N + 1) {
		rep(j,100010) {
			if (dp[i][j] <= W) {
				res = max(res, j);
			}
		}
	}
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
