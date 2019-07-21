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
    int n; cin >> n;
	int a[200010];
	int f_m = 0;
	int s_m = 0;
	rep(i, n)
	{
		cin >> a[i];
		if (f_m < a[i]) {
			s_m = f_m;
			f_m = a[i];
		} else {
			if (s_m < a[i]) {
				s_m = a[i];
			}
		}
	}
	rep (i, n)
	{
		if (a[i] == f_m) {
			cout << s_m << endl;
		} else {
			cout << f_m << endl;
		}
	}

}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
