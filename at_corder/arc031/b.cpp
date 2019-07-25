// https://atcoder.jp/contests/arc031/tasks/arc031_2
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

char rows[15][15];
int tmp_x_cnt[15][15];
int x_cnt[15][15];

void dfs(int y, int x)
{
    rows[y][x] = '-';
    rep(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < 10 && ny < 10 && rows[ny][nx] != 'x' && rows[ny][nx] != '-') {
            dfs(ny, nx);
        } else if (rows[ny][nx] == 'x') {
            ++tmp_x_cnt[ny][nx];
        }
    }
}

void Main()
{
    memset(tmp_x_cnt, 0, sizeof(tmp_x_cnt));
    memset(x_cnt, 0, sizeof(x_cnt));
    rep(i, 10)
    {
        string row; cin >> row;
        rep(j, 10)
        {
            rows[i][j] = row.at(j);
        }
    }
    int cnt = 0;
    rep(i, 10)
    {
        rep(j, 10)
        {
            if (rows[i][j] == 'o') {
                dfs(i, j);
                rep(i, 10)
                {
                    rep(j, 10)
                    {
                        if (tmp_x_cnt[i][j] > 0) ++x_cnt[i][j];
                    }
                }
                memset(tmp_x_cnt, 0, sizeof(tmp_x_cnt));
                ++cnt;
            }
        }
    }
    string res = "NO";
    rep(i, 10)
    {
        rep(j, 10)
        {
            if (x_cnt[i][j] == cnt) {
                res = "YES";
                break;
            }
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
