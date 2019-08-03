// https://atcoder.jp/contests/kupc2015/tasks/kupc2015_a
// greedy 区間スケジューリング

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

vector<pair<int, int>> find_all(string s)
{
    vector<pair<int, int>> res;
    int tokyo_pos = s.find("tokyo");
    int kyoto_pos = s.find("kyoto");
    while (tokyo_pos != string::npos) {
        res.push_back(make_pair(tokyo_pos + 5, tokyo_pos));
        tokyo_pos = s.find("tokyo", tokyo_pos + 5);
    }
    while (kyoto_pos != string::npos) {
        res.push_back(make_pair(kyoto_pos + 5, kyoto_pos));
        kyoto_pos = s.find("kyoto", kyoto_pos + 5);
    }
    return res;
}

string s[110];

void Main()
{
    int T; cin >> T;
    rep(i,T) cin >> s[i];
    rep(i,T) {
        auto ps = find_all(s[i]);
        if (ps.size() == 0) {
            cout << 0 << endl;
            continue;
        }
        sort(ps.begin(), ps.end());
        pair<int, int> current = ps[0];
        int res = 1;
        for (auto p : ps) {
            if (current.first <= p.second) {
                ++res;
                current = p;
                continue;
            }
        }
        cout << res << endl;
    }
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
