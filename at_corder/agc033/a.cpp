// https://atcoder.jp/contests/agc033/tasks/agc033_a
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

int H, W;
vector<pair<int, int>> start;
char Maze[1010][1010];
int min_path[1010][1010];
int done[1010][1010];

void Main()
{
    cin >> H >> W;
    rep(i,H) {
        rep(j,W) {
            cin >> Maze[i][j];
            if (Maze[i][j] == '#') {
                start.push_back(make_pair(i, j));
            }
        }
    }
    memset(min_path, -1, sizeof(min_path));
    for (auto s : start) {
        memset(done, -1, sizeof(done));
        queue<pair<int, int>> q;
        q.push(make_pair(s.first, s.second));
        min_path[s.first][s.second] = 0;
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int y = p.first;
            int x = p.second;
            rep(i,4) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (nx >= 0 && ny >= 0 && nx < W && ny < H && done[ny][nx] == -1) {
                    q.push(make_pair(ny, nx));
                    if (min_path[ny][nx] == -1) {
                        min_path[ny][nx] =min_path[y][x] + 1;
                    } else {
                        min_path[ny][nx] = min(min_path[y][x] + 1, min_path[ny][nx]);
                    }
                    done[ny][nx] = 1;
                }
            }
        }
    }
    int _max = -1;
    rep(i,H) {
        rep(j,W) {
            _max = max(min_path[i][j], _max);
            // cout << min_path[i][j] << " ";
        }
        // cout << endl;
    }
    cout << _max << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
