// https://atcoder.jp/contests/tdpc/tasks/tdpc_number
// 桁DP

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

ll dp[10010][3][110];

void Main()
{
    int D; cin >> D;
    string N; cin >> N;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    rep(i, N.size())
    {
        rep(j, 2)
        {
            int _d = N[i] - '0';
            for (int d = 0; d <= (j ? 9 : _d); ++d) {
                rep(k, D)
                {
                    dp[i + 1][j || (d < _d)][(k + d) % D] += (dp[i][j][k] % 1000000007);
                }
            }
        }
    }
    cout << ((dp[N.size()][0][0] + dp[N.size()][1][0]) % 1000000007 - 1) << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
