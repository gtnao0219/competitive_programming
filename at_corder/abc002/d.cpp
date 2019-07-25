// https://atcoder.jp/contests/abc002/tasks/abc002_4
// 最大クリーク問題 (NP困難)
// 無向グラフにおいて、頂点の部分集合Cに対し、Cに含まれるあらゆる2つの頂点を繋ぐ辺が存在するようなCを、クリークと呼ぶ
// O(2^n * n^2)、n = 12でも2048 * 144

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
    int N, M; cin >> N >> M;
    bool con[15][15];
    rep(i, N)
    {
        rep(j, N)
        {
            if (i == j) {
                con[i + 1][i + 1] = true;
            } else {
                con[i + 1][j + 1] = false;
            }
        }
        
    }
    rep(i, M)
    {
        int x, y; cin >> x >> y;
        con[x][y] = true;
        con[y][x] = true;
    }
    int res = 0;
    for (int bit = 0; bit < (1<<N); ++bit) {
        vector<int> S;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                S.push_back(i + 1);
            }
        }
        bool ok = true;
		rep(i, S.size())
        {
            REP(j, i, S.size())
            {
                if (!con[S[i]][S[j]]) {
                    ok = false;
                }
            }
        }
        if (ok) {
            res = max(res, (int)S.size());
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
