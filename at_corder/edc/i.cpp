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
#include<iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

long double p[3010];
long double dp[3010][3010];

void Main()
{
	int N; cin >> N;
	rep(i, N) cin >> p[i];

	rep(i,N) {
		rep(j, N) dp[i][j] = 0;
	}
	dp[0][0] = 1;
	rep(i, N) {
		for (int j = 0; j <= i + 1; ++j) {
			if (j == 0) {
				dp[i + 1][j] = dp[i][j] * (1 - p[i]);
			} else {
				dp[i + 1][j] = dp[i][j - 1] * p[i] + dp[i][j] * (1 - p[i]);
			}
		}
	}
	long double res = 0;
	rep(i,N+1) {
		if (i > N / 2) {
			res += dp[N][i];
		}
	}
	cout << res << endl;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
