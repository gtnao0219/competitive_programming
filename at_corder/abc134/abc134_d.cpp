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
    int n; cin >> n;
    int a[200010];
    rep(i, n) cin >> a[i + 1];
    int res[200010];
    int cnt = 0;
    for (int i = n; i > 0; --i) {
        int other = 0;
        for (int j = 2; true; ++j) {
            if (j * i > n) {
                break;
            }
            if (res[j * i] == 1) {
                ++other;
            }
        }
        if (a[i] == 0) {
            if (other % 2 == 0) {
                res[i] = 0;
            } else {
                res[i] = 1;
                ++cnt;
            }
        } else {
            if (other % 2 == 0) {
                res[i] = 1;
                ++cnt;
            } else {
                res[i] = 0;
            }
        }
    }
    cout << cnt << endl;
    rep(i, n)
    {
        if (res[i + 1] == 1) {
            cout << (i + 1);
            if (i == n - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
