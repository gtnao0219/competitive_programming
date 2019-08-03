// https://atcoder.jp/contests/e./tasks/joi2011yo_e
// BFS

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

int H, W, N;
char Maze[1010][1010];
int min_path[1010][1010];

int bfs(int sy, int sx, int gy, int gx)
{
    memset(min_path, -1, sizeof(min_path));
    min_path[sy][sx] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int y = p.first;
        int x = p.second;
        if (y == gy && x == gx) {
            break;
        }
        rep(i,4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx >= 0 && ny >= 0 && nx < W && ny < H && min_path[ny][nx] == -1 && Maze[ny][nx] != 'X') {
                q.push(make_pair(ny, nx));
                min_path[ny][nx] = min_path[y][x] + 1;
            }
        }
    }
    return min_path[gy][gx];
}

void Main()
{
    pair<int, int> cheese_p[15];
    cin >> H >> W >> N;
    rep(i,H) {
        rep(j,W) {
            char c;
            cin >> c;
            if (c == 'S') {
                cheese_p[0] = make_pair(i, j);
            } else if (c != 'X' && c != '.') {
                cheese_p[atoi(&c)] = make_pair(i, j);
            }
            Maze[i][j] = c;
        }
    }
    int res = 0;
    rep(i,N) {
        res += bfs(cheese_p[i].first, cheese_p[i].second, cheese_p[i + 1].first, cheese_p[i + 1].second);
    }
    cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
