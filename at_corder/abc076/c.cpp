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
	string S, T; cin >> S >> T;
	int idx = -1;
	for (int i = S.size() - 1; i >= T.size() - 1; --i) {
		bool match = true;
		rep(j,T.size()) {
			if (S[i - j] != T[T.size() - j - 1] && S[i - j] != '?') {
				match  = false;
				break;
			}
		}
		if (match) {
			idx = i - T.size() + 1;
			break;
		}
	}
	if (idx == -1) {
		cout << "UNRESTORABLE" << endl;
		return;
	}
	rep(i,S.size()) {
		if (i >= idx && i < idx + T.size()) {
			cout << T[i - idx];
		} else if (S[i] == '?') {
			cout << "a";
		} else {
			cout << S[i];
		}
	}
	cout << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
