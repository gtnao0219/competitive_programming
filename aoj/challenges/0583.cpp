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

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<int> divisor(int n)
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void Main()
{
    int n; cin >> n;
    int a[4];
    rep(i, n) cin >> a[i];
    int gcdnum = gcd(a[0], a[1]);
    if (n == 3) {
        gcdnum = gcd(gcdnum, a[2]);
    }
    vector<int> res = divisor(gcdnum);
    rep(i, res.size()) cout << res[i] << endl;
}

int main()
{
	Main();
}
