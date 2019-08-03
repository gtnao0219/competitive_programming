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

vector<int> A;
vector<int> B;

void Main()
{
	int N; cin >> N;
	rep(i,N + 1) {
		int a; cin >> a;
		A.push_back(a);
	}
	rep(i,N) {
		int b; cin >> b;
		B.push_back(b);
	}

	ll res = 0;
	rep(i,N) {
		int idx = B.size() - i - 1;
		int num = B[idx];
		num = num - A[idx + 1];
		if (num <= 0) {
			res += B[idx];
			continue;
		}
		num = num - A[idx];
		if (num <= 0) {
			res += B[idx];
			A[idx] = -num;
		} else {
			res += (B[idx] - num);
			A[idx] = 0;
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
