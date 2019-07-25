// https://atcoder.jp/contests/arc037/tasks/arc037_b
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

vector<int> comb[110];
int done[110];

bool dfs(int node, int from) {
    vector<int> nexts = comb[node];
    done[node] = 1;
    rep(i, nexts.size())
    {
        if (nexts[i] == from) continue;
        if (!done[nexts[i]]) {
            if (!dfs(nexts[i], node)) return false;
        } else {
            return false;
        }
    }
    return true;
}

void Main()
{
    int N, M; cin >> N >> M;
    rep(i, N)
    {
        std::vector<int> data;
        comb[i + 1] = data;
    }
    memset(done, 0, sizeof(done));
    rep(i, M)
    {
        int u, v; cin >> u >> v;
        comb[u].push_back(v);
        comb[v].push_back(u);
    }
    int cnt = 0;
    rep(i, N)
    {
        if (done[i + 1] == 0) {
            if (dfs(i + 1, -1)) {
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
