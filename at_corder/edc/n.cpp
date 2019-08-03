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

int a[410];
ll dp[410][410];

ll rec(int l, int r)
{
	if (dp[l][r] != -1) return dp[l][r];
	ll res;
	if (r - l == 2) res = a[l] + a[r - 1];
	else res = min(rec(l, r - 1) * 2 + a[r - 1], rec(l + 1, r) * 2 + a[l]);
	return dp[l][r] = res; 
}

void Main()
{
	int N; cin >> N;
	rep(i,N) cin >> a[i];

	memset(dp, -1, sizeof(dp));
	cout << rec(0, N) << endl;
	rep(i,N + 1) {
		rep(j,N + 1) {
			cout << i << j << dp[i][j] << endl;
		}
	}
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
