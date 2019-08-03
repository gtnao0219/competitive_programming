#define MAX_V 1010
#define MAX_E 2010

struct edge {int from, to, cost;};
edge es[MAX_E];
int d[MAX_V];
int V, E;
int INF = 1e9;

// trueのとき負の閉路は存在する
bool bellman_ford(int start)
{
    for (int i = 0; i < V; ++i) {
        d[i] = INF;
    }
    d[start] = 0;
    int loop_cnt = 0;
    while (true) {
        ++loop_cnt;
        bool update = false;
        for (int i = 0; i < E; ++i) {
            edge e = es[i];
            if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
                if (loop_cnt == V) return true;
            }
        }
        if (!update) break;
    }
    return false;
}