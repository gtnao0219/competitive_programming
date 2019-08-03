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

#define INF 1000000000000000000

int h[100010];
ll dp[100010];

void Main()
{
	int N, K; cin >> N >> K;
	rep(i,N) cin >> h[i];

	rep(i,N) dp[i] = INF;
	dp[0] = 0;
	rep(i,N) {
		REP(j,1,K + 1) {
			dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
		}
	}
	cout << dp[N - 1] << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
