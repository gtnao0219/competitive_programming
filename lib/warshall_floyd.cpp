#include <algorithm>
using namespace std;

#define MAX_V 310

// a, b間のコスト、a=bのときは0、経路が存在しない場合INF
int d[MAX_V][MAX_V];
int V;

void warshall_floyd()
{
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}