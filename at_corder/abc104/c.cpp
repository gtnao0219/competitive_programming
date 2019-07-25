// https://atcoder.jp/contests/abc104/tasks/abc104_c

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
    int D, G; cin >> D >> G;
    int p[15];
    int c[15];
    rep(i, D) cin >> p[i] >> c[i];
    
    int res = 10000;
    for (int bit = 0; bit < (1<<D); ++bit) {
        vector<int> S;
        int max_num = -1;
        for (int i = 0; i < D; ++i) {
            if (bit & (1 << i)) {
                S.push_back(i);
            } else {
                max_num = max(i, max_num);
            }
        }
        int sum = 0;
        int cnt = 0;
        rep(i, S.size())
        {
            sum += (c[S[i]] + 100 * (S[i] + 1) * p[S[i]]);
            cnt += p[S[i]];
        }
        if (sum < G) {
            int a = G - sum;
            int b = (100 * (max_num + 1));
            int _cnt = (a + b - 1) / b;
            if (p[max_num] < _cnt) continue;
            cnt += _cnt;
        }
        res = min(res, cnt);
    }
    cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
