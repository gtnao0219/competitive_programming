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

int dp[3010][3010];

void Main()
{
	string s, t; cin >> s >> t;
	int S = s.size();
	int T = t.size();
	memset(dp, 0, sizeof(dp));
	rep(i,S + 1) {
		rep(j,T + 1) {
			if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
			chmax(dp[i + 1][j + 1], dp[i + 1][j]);
			chmax(dp[i + 1][j + 1], dp[i][j + 1]);
		}
	}
	string res = "";
	int i = S; int j = T;
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			--i;
		} else if (dp[i][j] == dp[i][j - 1]) {
			--j;
		} else {
			res = s[i - 1] + res;
			--i; --j;
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
