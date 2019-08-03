// https://atcoder.jp/contests/abc079/tasks/abc079_d
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

#define MAX_V 15
ll d[MAX_V][MAX_V];
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
	int H, W; cin >> H >> W;
	V = 10;
	rep(i,10) {
		rep(j,10) {
			cin >> d[i][j];
		}
	}
	int nums[15];
	memset(nums, 0, sizeof(nums));
	rep(i,H) {
		rep(j,W) {
			int a; cin >> a;
			if (a == -1) continue;
			++nums[a];
		}
	}
	warshall_floyd();
	ll res = 0;
	rep(i,10) {
		res += d[i][1] * nums[i];
	}
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
