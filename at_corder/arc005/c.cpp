// https://atcoder.jp/contests/arc005/tasks/arc005_3
// 0-1BFS

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
int sy, sx, gy, gx;
char Maze[510][510];
int min_path[510][510];

void Main()
{
    cin >> H >> W;
    rep(i,H) {
        rep(j,W) {
            char c;
            cin >> c;
            Maze[i][j] = c;
            if (c == 's') {
                sy = i; sx = j;
            }
            if (c == 'g') {
                gy = i; gx = j;
            }
        }
    }
    memset(min_path, -1, sizeof(min_path));
    min_path[sy][sx] = 0;
    deque<pair<int, int>> q;
    q.push_front(make_pair(sy, sx));
    while (!q.empty()) {
        auto p = q.front(); q.pop_front();
        int y = p.first;
        int x = p.second;
        if (y == gy && x == gx) {
            break;
        }
        rep(i,4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nx >= 0 && ny >= 0 && ny < H && nx < W && min_path[ny][nx] == -1) {
                if (Maze[ny][nx] == '#') {
                    q.push_back(make_pair(ny, nx));
                    min_path[ny][nx] = min_path[y][x] + 1;
                } else {
                    q.push_front(make_pair(ny, nx));
                    min_path[ny][nx] = min_path[y][x];
                }
            }
        }
    }
    // rep(i,H) {
    //     rep(j,W) {
    //         cout << min_path[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ((min_path[gy][gx] <= 2 && min_path[gy][gx] >= 0) ? "YES" : "NO") << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
