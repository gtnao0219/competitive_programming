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

ll MAX = 1000000000000000000;
ll X_Y_MAX = 1000000000;

void Main()
{
	ll S; cin >> S;
	ll res[10];
	if (S <= X_Y_MAX) {
		res[0] = 1;
		res[1] = 0;
		res[2] = 0;
		res[3] = S;
	} else {
		ll div = S / X_Y_MAX;
	    ll mod = S % X_Y_MAX;
		if (mod == 0) {
			res[0] = div;
			res[1] = 0;
			res[2] = 0;
			res[3] = X_Y_MAX;
		} else {
			for (ll i = 1; i * i <= mod; i++) {
		    	if (mod % i == 0) {
		    		if (div + i > X_Y_MAX) {
		    			continue;
		    		}
	        		res[0] = div;
	        		res[1] = mod / i;
	        		res[2] = -i;
	        		res[3] = X_Y_MAX;
                }
            }
		}
	}
	
	cout << 0 - res[2] << " 0" << " ";
	cout << res[0] - res[2] << " ";
	cout << res[1] << " ";
	cout << 0 << " ";
	cout << res[3] << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
