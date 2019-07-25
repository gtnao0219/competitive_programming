// https://atcoder.jp/contests/atc001/tasks/dfs_a
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int H, W;
char rows[510][510];

bool dfs(int x, int y)
{
    if (rows[y][x] == 'g') {
        return true;
    }
    rows[y][x] = '#';
    bool res = false;
    rep(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < W && ny < H && rows[ny][nx] != '#') {
            if (dfs(nx, ny)) {
                res = true;
                break;
            }
        }
    }
    return res;
}

void Main()
{
    cin >> H >> W;
    int sx, sy;
    rep(i, H)
    {
        string row; cin >> row;
        rep(j, W)
        {
            rows[i][j] = row.at(j);
            if (rows[i][j] == 's') {
                sy = i;
                sx = j;
            }
        }
    }
    cout << (dfs(sx, sy) ? "Yes": "No") << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
