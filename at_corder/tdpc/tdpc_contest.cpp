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

void Main()
{
    int dp[110][10010];
    memset(dp, 0, sizeof(dp));
    int N; cin >> N;
    int p[110];
    rep(i, N) cin >> p[i];

    dp[0][0] = 1;
    rep(i, N)
    {
        rep(j, 10001)
        {
            dp[i + 1][j] |= dp[i][j];
            if (p[i] <= j) {
                dp[i + 1][j] |= dp[i][j - p[i]];
            }
        }
    }
    int res = 0;
    rep(i, 10001)
    {
        if (dp[N][i]) ++res;
    }
    cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
