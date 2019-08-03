// https://atcoder.jp/contests/joi2010yo/tasks/joi2010yo_d
// permutation

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
    int n, k; cin >> n >> k;
    string card[15];
    rep(i,n) cin >> card[i];
    set<string> st;
    rep(i1,n) {
        rep(i2,n) {
            if (i1 == i2) continue;
            if (k == 2) {
                st.insert(card[i1] + card[i2]);
                continue;
            }
            rep(i3,n) {
                if (i1 == i3 || i2 == i3) continue;
                if (k == 3) {
                    st.insert(card[i1] + card[i2] + card[i3]);
                    continue;
                }
                rep(i4,n) {
                    if (i1 == i4 || i2 == i4 || i3 == i4) continue;
                    if (k == 4) {
                        st.insert(card[i1] + card[i2] + card[i3] + card[i4]);
                    }
                }
            }
        }
    }
    cout << st.size() << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
