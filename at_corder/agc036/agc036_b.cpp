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
	int N; cin >> N;
	ll K; cin >> K;
	int A[200010];
	rep(i, N) cin >> A[i];

	int dup[200010];
	stack<int> s;
	int loop = 0;
	while (true) {
		rep(i, N)
	    {
	    	if (dup[A[i]] > 0) {
	    		while (true) {
					int t = s.top();
	    			if (t == A[i]) {
	    				s.pop();
						dup[t] = 0;
	    				break;
	    			}
	    			s.pop();
					dup[t] = 0;
	    		}
	    	} else {
	    		dup[A[i]]++;
	    		s.push(A[i]);
	    	}
	    }
		loop++;
		if (s.size() == 0) {
			break;
		}
	}
	int mod = K % loop;
	int _dup[20];
	stack<int> _s;
	rep(j, mod)
	{
		rep(i, N)
	    {
	    	if (_dup[A[i]] > 0) {
	    		while (true) {
					int t = _s.top();
	    			if (t == A[i]) {
	    				_s.pop();
						_dup[t] = 0;
	    				break;
	    			}
	    			_s.pop();
					_dup[t] = 0;
	    		}
	    	} else {
	    		_dup[A[i]]++;
	    		_s.push(A[i]);
	    	}
	    }
		if (_s.size() == 0) {
			break;
		}
	}
	string res = "";
	rep(i, _s.size())
	{
		res = to_string(_s.top()) + " " + res;
		_s.pop();
	}
	cout << res << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
