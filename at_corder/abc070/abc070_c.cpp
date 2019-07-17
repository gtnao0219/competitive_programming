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

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll n = gcd(a, b);
    return a / n * b;
}

void Main()
{
    int N; cin >> N;
    ll T[110];
    rep(i, N) cin >> T[i];

    ll res = 1;
    rep(i, N)
    {
        res = lcm(T[i], res);
    }
    cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
