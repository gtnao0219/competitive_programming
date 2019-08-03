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
	ll A, B; cin >> A >> B;
	ll sum = A + B;
	int div = sum / 2;
	int mod = sum % 2;
	if (mod == 0) {
		cout << div << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}

int main()
{
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	Main();
}
