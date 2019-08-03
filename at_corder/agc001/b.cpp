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
	ll N, X; cin >> N >> X;
	ll res = N;
	ll a = N - X;
	ll b = X;
	while (b != 0) {
		ll div = a / b;
		ll mod = a % b;
		res += div * 2 * b;
		if (mod == 0) res -= b;
		a = b;
		b = mod;
	}
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
