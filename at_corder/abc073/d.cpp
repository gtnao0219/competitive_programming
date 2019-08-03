// https://atcoder.jp/contests/abc073/tasks/abc073_d
// Warshall Floyd
// next permutation (sortしてから)

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

#define MAX_V 210
ll d[MAX_V][MAX_V];
int V;
vector<int> r;

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
	int N, M, R; cin >> N >> M >> R;
	V = N;
	rep(i,R) {
		int _r; cin >> _r;
		--_r;
		r.push_back(_r);
	}
	rep(i,N) {
		rep(j,N) {
			if (i == j) {
				d[i][i] = 0;
			} else {
				d[i][j] = 1e18;
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
	ll res = 1e18;
	sort(r.begin(), r.end());
	do {
		ll sum = 0;
		rep(i, r.size() - 1) {
			sum += d[r[i]][r[i + 1]];
		}
		res = min(res, sum);
    } while(next_permutation(r.begin(), r.end()));
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
