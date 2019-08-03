// https://atcoder.jp/contests/abc126/tasks/abc126_d
// 二部グラフ

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

struct edge {
	int to;
	ll cost;
};

vector<edge> graph[100010];
int color[100010];

void Main()
{
	int N; cin >> N;
	rep(i,N - 1) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		--u, --v;
		graph[u].push_back({v,w});
		if (u != v) {
			graph[v].push_back({u,w});
		}
	}

	memset(color, -1, sizeof(color));
	color[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		auto idx = q.front(); q.pop();
		for (auto e : graph[idx]) {
			if (color[e.to] != -1) continue;
			if (e.cost % 2 == 0) {
				color[e.to] = color[idx];
				q.push(e.to);
			} else {
				color[e.to] = (color[idx] + 1) % 2;
				q.push(e.to);
			}
		}
	}
	rep(i,N) {
		cout << color[i] << endl;
	}
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
