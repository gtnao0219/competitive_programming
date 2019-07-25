// https://atcoder.jp/contests/abc079/tasks/abc079_c
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
    int n = 3;
    int sum = 0;
    rep(i, 4)
    {
        sum += atoi(s.substr(i, 1).c_str());
    }
	for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                S.push_back(i + 1);
            }
        }
        int _sum = sum;
        rep(i, S.size())
        {
            _sum -= 2 * atoi(s.substr(S[i], 1).c_str());
        }
        if (_sum == 7) {
            char op[4];
            rep(i, 4)
            {
                if (i == 3) {
                    op[i] = '=';
                } else {
                    op[i] = '+';
                }
            }
            rep(i, S.size())
            {
                op[S[i] - 1] = '-';
            }
            rep(i, 4)
            {
                cout << s.at(i) << op[i];
            }
            cout << 7 << endl;
            break;
        }
    }
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
