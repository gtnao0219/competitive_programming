// https://atcoder.jp/contests/abc007c./tasks/abc007_3
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

int R, C;
int sy, sx, gy, gx;
char Maze[55][55];
int min_path[55][55];

void Main()
{
    cin >> R >> C >> sy >> sx >> gy >> gx;
    --sy, --sx, --gy, --gx;
    rep(i,R) {
        rep(j,C) {
            cin >> Maze[i][j];
        }
    }
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
            if (nx >= 0 && ny >= 0 && nx < C && ny < R && Maze[ny][nx] != '#' && min_path[ny][nx] == -1) {
                q.push(make_pair(ny, nx));
                min_path[ny][nx] = min_path[y][x] + 1;
            }
        }
    }
    cout << min_path[gy][gx] << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
