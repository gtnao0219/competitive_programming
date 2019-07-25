// https://atcoder.jp/contests/arc029/tasks/arc029_1

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
    int N; cin >> N;
    int t[10];
    rep(i, N) cin >> t[i];
    
    int res = 1e9;
    for (int bit = 0; bit < (1<<N); ++bit) {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                sum1 += t[i];
            } else {
                sum2 += t[i];
            }
        }
        res = min(res, max(sum1, sum2));
    }
    cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
