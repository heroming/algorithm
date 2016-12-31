最小表示法:
const int MAXN = 1000010;

int n;
char S[MAXN];

int min_position()
{
    int a = 0, b = 1, k = 0;
    while (a < n && b < n && k < n)
    {
        int e = S[(a + k) % n] - S[(b + k) % n];
        if (e == 0)
            ++ k;
        else
        {
            if (e > 0)
                a += k + 1;
            else
                b += k + 1;
            if (a == b)
                ++ a;
            k = 0;
        }
    }
    return min(a, b);
}


筛素数法：
const int MAXN = 1000010;

int n;
bool flag[MAXN];
vector<int> V;

void get_prime()
{
    V.clear();
    memset(flag, 0, sizeof(flag));
    for (int i = 2; i < n; ++ i)
    {
        if (! flag[i])
            V.push_back(i);
        for (int k = 0; k < SZ(V) && i * V[k] < n; ++ k)
        {
            flag[i * V[k]] = 1;
            if (i % V[k] == 0)
                break;
        }
    }
}
快速幂：
int power(int x, int n, int m)
{
    int s = 1, e = x % m;
    while (n)
    {
        if (n & 1)
            s = (s * e) % m;
        e = (e * e) % m;
        n >>= 1;
    }
    return s;
}

扩展欧几里得：

int S, m, m1, r1, m2, r2;
int x, y, z;
int extend_gcd(int a, int b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int e = extend_gcd(b, a % b);
    z = x;
    x = y;
    y = z - (a / b) * y;
    return e;
}
int g = extend_gcd(m1, m2);
x = ((r2 - r1) / g * x % (m2 / g) + (m2 / g)) % (m2 / g);
S = x * m1 + r1;
m = m1 * m2 / g;

图论

1.Bellman_ford:
Vector<int> V[MAXN], W[MAXN];
Bool bellman_ford(int n)
{
    memset(visit, 0, sizeof(visit));
    for (int k = 1; k < n; ++ k)
        for (int i = 0; i < n; ++ i)
            for (int j = 0; j < SZ(V[i]); ++ j)
                if (dis[i] + W[i][j] < dis[V[i][j]])
                    dis[V[i][j]] = dis[i] + W[i][j];
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < SZ(V[i]); ++ j)
            if (dis[i] + W[i][j] < dis[V[i][j]])
                return 0;
    return 1;
}

2.Prim:
int dis[MAXN];
bool visit[MAXN];
int k, H[MAXN], V[MAXE], W[MAXE], N[MAXE];
vector<int> T;

void prim(int x)
{
    visit[x] = 1;
    for (int i = 1; i <= n; ++ i)
        dis[i] = INFI;
    for (int e = H[x]; e != -1; e = N[e])
        dis[V[e]] = min(dis[V[e]], W[e]);
    while (true)
    {
        int v, min_dis = INFI;
        for (int i = 1; i <= n; ++ i)
            if (! visit[i] && dis[i] < min_dis)
            {
                v = i;
                min_dis = dis[i];
            }
        if (min_dis == INFI)
            return;
        visit[v] = 1;
        T.push_back(min_dis);
        for (int e = H[v]; e != -1; e = N[e])
            if (! visit[V[e]] && W[e] < dis[V[e]])
                dis[V[e]] = W[e];
    }
}

3.Tarjan 算法
一：求强连通分量(有向图，有inS数组记录)、双连通分量、割边、割点(无向图，无inS数组记录)
bool inS[MAXN];
int t, n, m;
int top, S[MAXN];
int inx, low[MAXN], dfn[MAXN];
int s, belong[MAXN], degree[MAXN];
vector<int> maps[MAXN];

void tarjan(int u, int p)
{
    low[u] = dfn[u] = ++ inx;
    S[++ top] = u;
    inS[u] = 1;
    for (int i = 0; i < SZ(maps[u]); ++ i)
    {
        int v = maps[u][i];
        if (dfn[v] == -1)
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if (inS[v] && v != p)
            low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        ++ s;
        int v;
        do
        {
            v = S[top --];
            inS[v] = 0;
            belong[v] = s;
        } while (v != u);
    }
}


int main()
{
    scanf("%d", &t);
    for (int l = 1; l <= t; ++ l)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++ i)
            maps[i].clear();
        int u, v;
        for (int i = 0; i < m; ++ i)
        {
            scanf("%d%d", &u, &v);
            maps[u].push_back(v);
            maps[v].push_back(u);
        }
        s = inx = top = 0;
        memset(dfn, -1, sizeof(dfn));
        memset(inS, 0, sizeof(inS));
        for (int i = 0; i < n; ++ i)
            if (dfn[i] == -1)
                tarjan(i, -1);
    }
    return 0;
}

4.LCA: 
一：<n * log(n), sqrt(n)>算法:分为sqrt(n)层，分别处理(用于数据较少情况)
bool visit[MAXN];
int n, k, W[MAXN], V[MAXN];
int h, m, P[MAXN], D[MAXN], S[MAXN];
vector<int> maps[MAXN], edge[MAXN];

void prepare_dfs(int u, int e)
{
    visit[u] = 1;
    D[u] = e;
    h = max(h, e);
    for (int i = 0; i <  SZ(maps[u]); ++ i)
    {
        int v = maps[u][i];
        if (! visit[v])
        {
            P[v] = u;
            prepare_dfs(v, e + 1);
        }
    }
}

void get_level_dfs(int u)
{
    visit[u] = 1;
    if (D[u] < m)
        S[u] = 1;
    else
    {
        if (D[u] % m == 0)
            S[u] = P[u];
        else
            S[u] = S[P[u]];
    }
    for (int i = 0; i < SZ(maps[u]); ++ i)
    {
        int v = maps[u][i];
        if (! visit[v])
            get_level_dfs(v);
    }
}

void prepare()
{
    h = 0;
    P[1] = 1;
    memset(visit, 0, sizeof(visit));
    prepare_dfs(1, 0);
    m = sqrt(h + 0.0);
    memset(visit, 0, sizeof(visit));
    get_level_dfs(1);
    memset(W, 0, sizeof(W));
}

int LCA(int a, int b)
{
    while (S[a] != S[b])
    {
        if (D[a] < D[b])
            b = S[b];
        else
            a = S[a];
    }
    while (a != b)
    {
        if (D[a] < D[b])
            b = P[b];
        else
            a = P[a];
    }
    return a;
}

二．<n * log(n), log(n)>增量法:
bool visit[MAXN];
int n, k, W[MAXN], V[MAXN];
int P[MAXN], D[MAXN], S[MAXN][MAXLOG];
vector<int> maps[MAXN], edge[MAXN];

void prepare_dfs(int u, int e)
{
    visit[u] = 1;
    D[u] = e;
    for (int i = 0; i <  SZ(maps[u]); ++ i)
    {
        int v = maps[u][i];
        if (! visit[v])
        {
            P[v] = u;
            prepare_dfs(v, e + 1);
        }
    }
}

void prepare()
{
    P[1] = -1;
    memset(visit, 0, sizeof(visit));
    prepare_dfs(1, 0);
    memset(S, -1, sizeof(S));
    for (int i = 1; i <= n; ++ i)
        S[i][0] = P[i];
    for (int j = 1; 1 << j < n; ++ j)
        for (int i = 1; i <= n; ++ i)
            if (S[i][j - 1] != -1)
                S[i][j] = S[S[i][j - 1]][j - 1];
    memset(W, 0, sizeof(W));
}

int LCA(int a, int b)
{
    if (D[a] < D[b])
        swap(a, b);
    int m = 0;
    while (1 << (m + 1) <= D[a])
        ++ m;
    for (int i = m; i >= 0; -- i)
        if (D[a] - (1 << i) >= D[b])
            a = S[a][i];
    if (a == b)
        return a;
    for (int i = m; i >= 0; -- i)
        if (S[a][i] != -1 && S[a][i] != S[b][i])
        {
            a = S[a][i];
            b = S[b][i];
        }
    return P[a];
}

三．Tarjan的LCA算法(离线算法，首先要记录下所有的询问，然后再一次tarjan得到所有的答案。)

bool visit[MAXN];
int n, P[MAXN];
vector<int> maps[MAXN], Q[MAXN];

int find_set(int e)
{
    if (e != P[e])
        P[e] = find_set(P[e]);
    return P[e];
}

void union_set(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        P[b] = a;
}

//对于无向图需要添加参数parent
void tarjan(int u)
{
    for (int i = 0; i < SZ(maps[u]); ++ i)
    {
        int v = maps[u][i];
        tarjan(v);
        union_set(u, v);
    }
    visit[u] = 1;
    for (int i = 0; i < SZ(Q[u]); ++ i)
    {
        int v = Q[u][i];
        if (visit[v])
            ancestor of (u, v) = find_set(v);
    }
}
RMQ:

void RMQ()
{
    for (int i = 1; i <= n; ++ i)
        RMQ[i][0] = S[i];
    for (int k = 1; (1 << k) <= n; ++ k)
        for (int i = 1; i <= n - (1 << k) + 1; ++ i)
            RMQ[i][k] = max(RMQ[i][k - 1], RMQ[i + (1 << (k - 1))][k - 1]);
    for (int i = 1; i <= m; ++ i)
    {
        int k = log(b - a + 1.0) / log(2.0);
        ans = max(RMQ[a][k], RMQ[b - (1 << k) + 1][k]);
    }
}

网络流：
一．	最大流
1. Edmonds-Karp算法
int n, m;
int pre[MAXN], min_flow[MAXN];
int maps[MAXN][MAXN], flow[MAXN][MAXN];

int edmonds_karp()
{
    min_flow[1] = INFI;
    queue<int> Q;
    int max_flow = 0;
    while (1)
    {
        memset(pre, 0, sizeof(pre));
        Q.push(1);
        while (! Q.empty() && pre[m] == 0)
        {
            int u = Q.front();
            Q.pop();
            for (int i = 2; i <= m; ++ i)
                if (! pre[i] && flow[u][i] < maps[u][i])
                {
                    pre[i] = u;
                    min_flow[i] = min(min_flow[u], maps[u][i] - flow[u][i]);
                    Q.push(i);
                }
        }
        if (! pre[m])
            return max_flow;
        max_flow += min_flow[m];
        for (int k = m; k != 1; k = pre[k])
        {
            flow[pre[k]][k] += min_flow[m];
            flow[k][pre[k]] -= min_flow[m];
        }
    }
}

2.dinic算法(未分层)：
bool visit[MAXN];
bool flag[MAXN][MAXN];
int front, rear, Q[MAXN];
int S, T, maps[MAXN][MAXN];

bool bfs()
{
    memset(flag, 0, sizeof(flag));
    memset(visit, 0, sizeof(visit));
    front = rear = 0;
    Q[rear ++] = S;
    visit[S] = 1;
    while (front < rear)
    {
        int u = Q[front ++];
        for (int i = S; i <= T; ++ i)
            if (! visit[i] && maps[u][i])
            {
                Q[rear ++] = i;
                visit[i] = 1;
                flag[u][i] = 1;
            }
    }
    if (visit[T])
        return 1;
    return 0;
}

int dfs(int u, int w)
{
    if (u == T)
        return w;
    int s = w;
    for (int i = S; i <= T; ++ i)
        if (flag[u][i])
        {
            int t = dfs(i, min(w, maps[u][i]));
            maps[u][i] -= t;
            maps[i][u] += t;
            w -= t;
        }
    return s - w;
}

int Dinic()
{
    int max_flow = m;
    while (bfs())
        max_flow -= dfs(S, INF);
    return max_flow;
}


3.dinic算法(分层)：
int S, T, D[MAXN];
int front, rear, Q[MAXN];
int inx, H[MAXN], V[MAXE], W[MAXE], N[MAXE];

void add_edge(int u, int v, int w)
{
    //正边
    V[inx] = v;
    W[inx] = w;
    N[inx] = H[u];
    H[u] = inx ++;
    //反边
    V[inx] = u;
    W[inx] = 0;
    N[inx] = H[v];
    H[v] = inx ++;
}

void build_maps()
{
    inx = 0;
    memset(H, -1, sizeof(H));
    //to every (u, v) path which has the flow
    add_edge(u, v, w);
}

bool dinic_bfs()
{
    memset(D, 0, sizeof(D));
    front = rear = 0;
    Q[rear ++] = S;
    D[S] = 1;
    while (front < rear)
    {
        int u = Q[front ++];
        for (int e = H[u]; e != -1; e = N[e])
            if (D[V[e]] == 0 && W[e])
            {
                D[V[e]] = D[u] + 1;
                if (V[e] == T)
                    return 1;
                Q[rear ++] = V[e];
            }
    }
    return 0;
}

int dinic_dfs(int u, int w)
{
    if (u == T)
        return w;
    int s = w;
    for (int e = H[u]; e != -1; e = N[e])
        if (D[V[e]] == D[u] + 1 && W[e])
        {
            int t = dinic_dfs(V[e], min(s, W[e]));
            if (t)
            {
                W[e] -= t;
                W[e ^ 1] += t;
                s -= t;
                if (s == 0)
                    return w;
            }
            else
                D[V[e]] = -1;
        }
    return w - s;
}
 
int dinic()
{
    int max_flow = 0;
    build_maps();
    while (dinic_bfs())
        max_flow += dinic_dfs(S, INF);
    return max_flow;
}


4.push_relable：
queue<int> Q;
int S, T, D[MAXN], flow[MAXN];
int inx, H[MAXN], V[MAXE], W[MAXE], N[MAXE];

int push_relabel()
{
    int max_flow = 0;
    memset(D, 0, sizeof(D));
    memset(flow, 0, sizeof(flow));
    D[S] = T;
    flow[S] = INF;
    flow[T] = -INF;
    Q.push(S);
    while (! Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int e = H[u]; e != -1; e = N[e])
        {
            int w = min(W[e], flow[u]);
            if (w > 0 && (u == S || D[u] == D[V[e]] + 1))
            {
                W[e] -= w;
                W[e ^ 1] += w;
                if (V[e] == T)
                    max_flow += w;
                flow[u] -= w;
                flow[V[e]] += w;
                if (V[e] != S && V[e] != T)
                    Q.push(V[e]);
            }
        }
        if (u != S && u != T && flow[u] > 0)
        {
            ++ D[u];
            Q.push(u);
        }
    }
    return max_flow;
}

5．sap算法(递归版本)：
int n, S, T, D[MAXN], G[MAXN];
int inx, H[MAXN], V[MAXE], W[MAXE], N[MAXE];

int sap_dfs(int u, int w)
{
    if (u == T)
        return w;
    int s = w, low = n - 1;
    for (int e = H[u]; e != -1; e = N[e])
    {
        if (D[u] == D[V[e]] + 1 && W[e] > 0)
        {
            int t = sap_dfs(V[e], min(s, W[e]));
            if (t)
            {
                W[e] -= t;
                W[e ^ 1] += t;
                s -= t;
            }
            if (s == 0 || D[S] >= n)
                return w - s;
        }
        if (W[e] > 0)
            low = min(low, D[V[e]]);
    }
    if (s == w)
    {
        if (-- G[D[u]] == 0)
            D[S] = n;
        ++ G[D[u] = low + 1];
    }
    return w - s;
}

int sap()
{
    int max_flow = 0;
    memset(D, 0, sizeof(D));
    memset(G, 0, sizeof(G));
    G[S] = n;       //the number of the nodes
    while (D[S] < n)
        max_flow += sap_dfs(S, INF);
    return max_flow;
}

6．sap算法(非递归版本)：
int sap(int n)
{
    int max_flow = 0, aug = INF;
    for (int i = S; i <= T; ++ i)
    {
        G[i] = D[i] = 0;
        C[i] = H[i];
    }
    G[0] = n;
    int u = P[S] = S, v;
    while (D[S] < n)
    {
loop:
        for (int e = C[u]; e != -1; e = N[e])
            if (D[u] == D[V[e]] + 1 && W[e] > 0)
            {
                aug = min(aug, W[e]);
                P[V[e]] = u;
                C[u] = e;
                u = V[e];
                if (u == T)
                {
                    for (u = P[u], v = V[e]; v != S; v = u, u = P[u])
                    {
                        W[C[u]] -= aug;
                        W[C[u] ^ 1] += aug;
                    }
                    max_flow += aug;
                    aug = INF;
                }
                goto loop;
            }
        int low = n - 1;
        for (int e = H[u]; e != -1; e = N[e])
            if (D[V[e]] < low && W[e] > 0)
            {
                low = D[V[e]];
                C[u] = e;
            }
        if (-- G[D[u]] == 0)
            break;
        ++ G[D[u] = low + 1];
        u = P[u];
    }
    return max_flow;
}

7. 欧拉路径(最大流解混合图的欧拉回路问题)
1 定义
欧拉通路 (Euler tour)——通过图中每条边一次且仅一次，并且过每一顶点的通路。
欧拉回路 (Euler circuit)——通过图中每条边一次且仅一次，并且过每一顶点的回路。
欧拉图——存在欧拉回路的图。
2 无向图是否具有欧拉通路或回路的判定
G有欧拉通路的充分必要条件为：G 连通，G中只有两个奇度顶点(它们分别是欧拉通路的两个端点)。
G有欧拉回路(G为欧拉图)：G连通，G中均为偶度顶点。
3 有向图是否具有欧拉通路或回路的判定
D有欧拉通路：D连通，除两个顶点外，其余顶点的入度均等于出度，这两个特殊的顶点中，一个顶点的入度比出度大1，另一个顶点的入度比出度小1。
D有欧拉回路(D为欧拉图)：D连通，D中所有顶点的入度等于出度。
4 混合图。混合图也就是无向图与有向图的混合，即图中的边既有有向边也有无向边。
5 混合图欧拉回路
混合图欧拉回路用的是网络流。
把该图的无向边随便定向，计算每个点的入度和出度。如果有某个点出入度之差为奇数，那么肯定不存在欧拉回路。因为欧拉回路要求每点入度 = 出度，也就是总度数为偶数，存在奇数度点必不能有欧拉回路。
现在每个点入度和出度之差均为偶数。将这个偶数除以2，得x。即是说，对于每一个点，只要将x条边反向（入>出就是变入，出>入就是变出），就能保证出 = 入。如果每个点都是出 = 入，那么很明显，该图就存在欧拉回路。
现在的问题就变成了：该改变哪些边，可以让每个点出 = 入？构造网络流模型。有向边不能改变方向，直接删掉。开始已定向的无向边，定的是什么向，就把网络构建成什么样，边长容量上限1。另新建s和t。对于入 > 出的点u，连接边(u, t)、容量为x，对于出 > 入的点v，连接边(s, v)，容量为x（注意对不同的点x不同）。之后，察看是否有满流的分配。有就是能有欧拉回路，没有就是没有。查看流值分配，将所有流量非 0（上限是1，流值不是0就是1）的边反向，就能得到每点入度 = 出度的欧拉图。
由于是满流，所以每个入 > 出的点，都有x条边进来，将这些进来的边反向，OK，入 = 出了。对于出 > 入的点亦然。那么，没和s、t连接的点怎么办？和s连接的条件是出 > 入，和t连接的条件是入 > 出，那么这个既没和s也没和t连接的点，自然早在开始就已经满足入 = 出了。那么在网络流过程中，这些点属于“中间点”。我们知道中间点流量不允许有累积的，这样，进去多少就出来多少，反向之后，自然仍保持平衡。
所以，就这样，混合图欧拉回路问题，解了。

二分图匹配：
bool visit[MAXN];
int n, m, match[MAXN];

vector<int> maps[MAXN];
bool dfs(int u)
{
    for (int i = 0; i < SZ(maps[u]); ++ i)
    {
        int v = maps[u][i];
        if (! visit[v])
        {
            visit[v] = 1;
            if (match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int ans = 0;
memset(match, -1, sizeof(match));
for (int i = 1; i <= n; ++ i)
{
    memset(visit, 0, sizeof(visit));
    if (dfs(i))
        ++ ans;
}

最长上升子序列(LIS)：
vector<int> S;
int get_lis(int n)
{
    int ans = 0;
    vector<int> V(n + 1, -1);
    for (int i = 0; i < SZ(S); ++ i)
    {
        if (V[ans] < S[i])
            V[++ ans] = S[i];
        else
        {
            vector<int>::iterator it = upper_bound(V.begin() + 1, V.begin() + ans, S[i]);
            *it = S[i];
        }
    }
    return ans;
}

计算几何
1. 交点的无斜率求法
Point interact(const Point &A, const Point &B, const Point &C, const Point &D)
{
    Point E;
    double k = ((A.y - C.y) * (C.x - D.x) - (A.x - C.x) * (C.y - D.y)) / ((B.x - A.x) * (C.y - D.y) - (B.y - A.y) * (C.x - D.x));
    E.x = A.x + k * (B.x - A.x);
    E.y = A.y + k * (B.y - A.y);
    return E;
}

数论
1.	两个数p, q，如果gcd(p, q) == 1，那么当x,y为正整数时，px + qy最大不能表示的数是pq – p – q, 若gcd(p, q) != 1，那么为无穷大。

2.欧拉函数：
欧拉定理：设m > 1, gcd(a, m) == 1, 则a^φ(m) % m == 1;
费马小定理：若p为素数，则a^p % p == a;

//求小于等于n的数中与n互质的数的个数
int Eluar(int n)
{
    int s = 1;
    for (int i = 2; i * i <= n; ++ i)
        if (n % i == 0)
        {
            n /= i;
            s *= (i - 1);
            while (n % i == 0)
            {
                n /= i;
                s *= i;
            }
        }
    if (n > 1)
        s *= (n - 1);
    return s;
}

3.海伦公式:
假设有一个三角形，边长分别为，三角形的面积 可由以下公式求得：
	S = sqrt(p * (p – a) * (p – b) * (p – c))，
这里, p = (a + b + c) / 2;

4.Polya：
N = (A1 + A2 + … + Am) / m;
其中，Ai指第i种置换的方式，n指置换方式的总数。
Ai形如： X1^a1 * X2^a2 * X3 * … * Xm^am，m为物品总数，a1,a2…am分别为循环长度为1, 2, ..m的环的个数。
旋转的情况中，当旋转的个数k时，循环节的个数为gcd(k, N).

5.贝祖等式
对于等式ax+by=z，若c为a,b的最大公约数，等式有整数解当且仅当z为c的倍数。




Dancing links
1.精确覆盖
void remove(const int c)
{
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    for (int i = D[c]; i != c; i = D[i])
        for (int j = R[i]; j != i; j = R[j])
        {
            U[D[j]] = U[j];
            D[U[j]] = D[j];
            -- S[C[j]];
        }
}

void resume(const int c)
{
    for (inti = U[c]; i != c; i = U[i])
        for (int j = L[i]; j != i; j = L[j])
        {
            ++ S[C[j]];
            D[U[j]] = j;
            U[D[j]] = j;
        }
    R[L[c]] = c;
    L[R[c]] = c;
}

bool dfs(const int k)
{
    if (R[head] == head)
        return 1;
    int c, w = inf;
    for (int i = R[head]; i != head; i = R[i])
        if (S[i] < w)
        {
            c = i;
            w = S[i];
        }
    remove(c);
    for (int i = D[c]; i != c; i = D[i])
    {
        for (int j = R[i]; j != i; j = R[j])
            remove(C[j]);
        if (dfs(k + 1))
            return 1;
        for (int j = L[i]; j != i; j = L[j])
            resume(C[j]);
    }
    resume(c);
    return 0;
}
2.可重复覆盖
void remove(const int c)
{
    for (int i = D[c]; i != c; i = D[i])
    {
        L[R[i]] = L[i];
        R[L[i]] = R[i];
    }
}

void resume(const int c)
{
    for (int i = L[c]; i != c; i = L[i])
    {
        R[L[i]] = i;
        L[R[i]] = i;
    }
}

int cost()
{
    int w = 0;
    memset(visit, 0, sizeof(visit));
    for (int i = R[head]; i != head; i = R[i])
        if (! visit[i])
        {
            ++ w;
            visit[i] = 1;
            for (int j = D[i]; j != i; j = D[j])
                for (int k = R[j]; k != j; k = R[k])
                    visit[C[k]] = 1;
        }
    return w;
}

bool dfs(const int k)
{
    if (R[head] == head)
        return 1;
    if (k + cost() >= m)
        return 0;
    int c, w = inf;
    for (int i = R[head]; i != head; i = R[i])
        if (S[i] < w)
        {
            c = i;
            w = S[i];
        }
    for (int i = D[c]; i != c; i = D[i])
    {
        remove(i);
        for (int j = R[i]; j != i; j = R[j])
            remove(j);
        if (dfs(k + 1))
            return 1;
        for (int j = L[i]; j != i; j = L[j])
            resume(j);
        resume(i);
    }
    return 0;
}


DP
1.	树上有限制的背包
有一些物品，若选择了v,就必须要选择u，这样就构成了一棵树。要求选择某些物品，使得消耗不大于C，总价值最大。
int n, m, c[maxn], w[maxn], dp[maxn][maxn];
vector<int> maps[maxn];

void dfs(const int u, const int e)
{
    for (int i = 0; i < SZ(maps[u]); ++ i)
    {
        int v = maps[u][i];
        for (int k = 0; k <= e - c[v]; ++ k)
            dp[v][k] = dp[u][k] + w[v];
        dfs(v, e - c[v]);
        for (int k = c[v]; k <= e; ++ k)
            dp[u][k] = max(dp[u][k], dp[v][k - c[v]]);
    }
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    dfs(0, m);
}


博弈
1.Nim积
const int nim[2][2] = {0, 0, 0, 1};
const lint bit[] = {2, 4, 16, 256, 65536, 4294967296};

int nim_mult_power(int x, int y)
{
    if (x < 2)
        return nim[x][y];
    int k = 0;
    while (! (bit[k] <= x && x < bit[k + 1]))
        ++ k;
    int m = bit[k];
    int p = x / m, s = y / m, t = y % m;
    int d1 = nim_mult_power(p, s), d2 = nim_mult_power(p, t);
    return ((d1 ^ d2) * m) ^ nim_mult_power(m >> 1, d1);
}

int nim_mult(int x, int y)
{
    if (x < y)
        return nim_mult(y, x);
    if (x < 2)
        return nim[x][y];
    int k = 0;
    while (! (bit[k] <= x && x < bit[k + 1]))
        ++ k;
    int m = bit[k];
    int p = x / m, q = x % m, s = y / m, t = y % m;
    int c1 = nim_mult(p, s), c2 = nim_mult(p, t) ^ nim_mult(q, s), c3 = nim_mult(q, t);
    return ((c1 ^ c2) * m) ^ c3 ^ nim_mult_power(m >> 1, c1);
}
