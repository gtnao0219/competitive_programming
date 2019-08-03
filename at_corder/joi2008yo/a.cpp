// https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_a
// greedy coin

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

void Main()
{
    int coin[6] = {500, 100, 50, 10, 5, 1};
    int _n; cin >> _n;
    int n = 1000 - _n;
    int res = 0;
    rep(i,6) {
        int div = n / coin[i];
        n -= coin[i] * div;
        res += div;
    }
    cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
