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

int a[1010];
int b[1010];
int dp[1010][1010];

void Main()
{
	int A, B; cin >> A >> B;
	rep(i,A) cin >> a[i]; 
	rep(i,B) cin >> b[i];

	dp[0][0] = 0;
	rep(i,A) {
		rep(j,B) {
			if (i == 0) {
				dp[i + 1][j + 1] = dp[i + 1][j - 1] + 
			}
			if (j == 0) {

			}
			int a_num = a[A - i - 1];
			int b_num = b[B - i - 1];
		}
	}
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
