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

int dp[100010][4];
int A[100010];
int B[100010];
int C[100010];

void Main()
{
	int N; cin >> N;
	rep(i,N) {
		int a, b, c; cin >> a >> b >> c;
		A[i] = a;
		B[i] = b;
		C[i] = c;
	}
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	rep(i,N) {
		dp[i + 1][0] = max(dp[i][1] + A[i], dp[i][2] + A[i]);
		dp[i + 1][1] = max(dp[i][0] + B[i], dp[i][2] + B[i]);
		dp[i + 1][2] = max(dp[i][0] + C[i], dp[i][1] + C[i]);
	}
	int res = max({dp[N][0], dp[N][1], dp[N][2]});
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
