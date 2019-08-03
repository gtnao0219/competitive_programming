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
#include <bitset>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;

const int MAX_DIGIT = 50;

ll A[100010];
ll dp[MAX_DIGIT][3];

string bit_str(ll num)
{
	auto bit_k = bitset<MAX_DIGIT>(num);
	string res = "";
	for (int i = MAX_DIGIT - 1; i >= 0; --i) {
		if (bit_k[i]) {
			res += "1";
		} else {
			res += "0";
		}
	}
	return res;
}

void Main()
{
	int N; cin >> N;
	ll K; cin >> K;
	rep(i,N) cin >> A[i];
	string bit_k = bit_str(K);

	memset(dp, -1, sizeof(dp));
	dp[0][1] = 0;
	rep(i,MAX_DIGIT) {
		char b = bit_k[i];
		int one_bit_sum = 0;
		rep(k,N) {
			if (A[k] & (1LL<<(MAX_DIGIT - i - 1))) {
				++one_bit_sum;
			}
		}
		ll zero_bit_cost = pow(2, MAX_DIGIT - i - 1) * one_bit_sum;
		ll one_bit_cost = pow(2, MAX_DIGIT - i - 1) * (N - one_bit_sum);

		if (dp[i][0] != -1) {
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + max(zero_bit_cost, one_bit_cost));
		}
		
		if (dp[i][1] != -1) {
			if (b == '1') {
		    	dp[i + 1][0] = max(dp[i + 1][0], dp[i][1] + zero_bit_cost);
		    }
		}

		if (dp[i][1] != -1) {
			if (b == '1') {
		    	dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + one_bit_cost);
		    }
		    if (b == '0') {
		    	dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + zero_bit_cost);
		    }
		}
	}
	cout << max(dp[bit_k.size()][0], dp[bit_k.size()][1]) << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
