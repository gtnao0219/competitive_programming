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

int a[200010];

void Main()
{
    int N, K; cin >> N >> K;
    int _max = -1;
    int res = -1;
    rep(i,N) {
        int a;
        cin >> a;
        if (a < K) {
            _max = max(_max, a);
            if (_max == a) {
                res = i + 1;
            }
        }
    }
    cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
