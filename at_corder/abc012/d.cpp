// https://atcoder.jp/contests/abc012/tasks/abc012_4
// Warshall Floyd

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

#define MAX_V 310

int d[MAX_V][MAX_V];
int V;

void warshall_floyd()
{
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void Main()
{
	int N, M; cin >> N >> M;
	V = N;
	rep(i,N) {
		rep(j,N) {
			if (i == j) {
				d[i][i] = 0;
			} else {
				d[i][j] = 1e9;
			}
		}
	}
	rep(i,M) {
		int a, b, t; cin >> a >> b >> t;
		--a, --b;
		d[a][b] = t;
		d[b][a] = t;
	}
	warshall_floyd();
	int res = 1e9;
	rep(i,N) {
		int _max = -1e9;
		rep(j,N) {
 			_max = max(_max, d[i][j]);
		}
		res = min(res, _max);
	}
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
