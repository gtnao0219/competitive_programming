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
    ll N;
    string X;
    cin >> N >> X;
    REP(M, 2, 11) {
        ll sum = 0;
        bool flg = false;
        rep(i, X.size()) {
            int n = atoi(X.substr(X.size() - i - 1, 1).c_str());
            if (n >= M) flg = true;
            sum += n * pow(M, i);
        }
        if (flg) {
            continue;
        }
        if (N == sum) {
            cout << M << endl;
            return;
        }
    }
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
