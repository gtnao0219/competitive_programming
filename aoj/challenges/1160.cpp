// https://onlinejudge.u-aizu.ac.jp/challenges/search/titles/1160
// dfs

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

int field[55][55];
int W, H;

void dfs(int y, int x)
{
    field[y][x] = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) continue;
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && ny >= 0 && nx < W && ny < H && field[ny][nx] == 1) {
                dfs(ny, nx);
            }
        }
    }
}

void Main()
{
    while (true) {
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        memset(field, 0, sizeof(field));
        rep(i, H)
        {
            rep(j, W)
            {
                cin >> field[i][j];
            }
        }
        int cnt = 0;
        rep(i, H)
        {
            rep(j, W)
            {
                if (field[i][j] == 1) {
                    dfs(i, j);
                    ++cnt;
                }
            }
        }
        cout << cnt << endl;
    }
}

int main()
{
    // cin.tie(nullptr);
	// ios_base::sync_with_stdio(false);
	Main();
}
