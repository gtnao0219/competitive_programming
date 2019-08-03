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

string MAZE[1010];
ll dp[1010][1010];
ll law = 1000000007;

void Main()
{
	int H, W; cin >> H >> W;
	rep(i,H) cin >> MAZE[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	rep(i,H) {
		rep(j, W) {
			if (MAZE[i][j] == '#') continue;
			if (i + 1 < H && MAZE[i + 1][j] != '#') dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % law;
			if (j + 1 < W && MAZE[i][j + 1] != '#') dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % law;
		}
	}
	cout << dp[H - 1][W - 1] << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
