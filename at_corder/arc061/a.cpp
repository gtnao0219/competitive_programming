// https://atcoder.jp/contests/arc061/tasks/arc061_a
// bit全探索

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
	string s; cin >> s;
	int n = s.size() - 1;
	ll res = 0;
	for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                S.push_back(i + 1);
            }
        }
		int itr = 0;
		S.push_back(n + 1);
		rep(i, S.size())
		{
			string str_num = s.substr(itr, S[i] - itr);
			res += atol(str_num.c_str());
			itr = S[i];
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
