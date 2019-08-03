// https://atcoder.jp/contests/abc077/tasks/arc084_a
// lower_bound upper_bound

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
#include<iomanip>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }

int A[100010];
int B[100010];
int C[100010];
ll lb_a[100010];
ll ub_c[100010];

void Main()
{
	int N; cin >> N;
	rep(i,N) cin >> A[i];
	rep(i,N) cin >> B[i];
	rep(i,N) cin >> C[i];

	sort(A, A + N);
	sort(B, B + N);
	sort(C, C + N);
	rep(i,N) {
		lb_a[i] = lower_bound(A, A + N, B[i]) - A;
		ub_c[i] = upper_bound(C, C + N, B[i]) - C;
	}
	ll res = 0;
	rep(i,N) {
		res += lb_a[i] * (N - ub_c[i]);
	}
	cout << res << endl;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
