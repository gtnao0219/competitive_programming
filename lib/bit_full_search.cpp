#include <vector>

using namespace std;

void search(int n)
{
    for (int bit = 0; bit < (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                S.push_back(i);
            }
        }
    }
}
