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
	int cnt = 0;
	rep(i,N) {
		int n;
		cin >> n;
		if (n != (i + 1)) {
			++cnt;
		}
	}
	cout << (cnt == 0 || cnt == 2 ? "YES" : "NO") << endl;
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
