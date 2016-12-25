¿¿¿¿¿:
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


¿¿¿¿¿
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
¿¿¿¿
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

¿¿¿¿¿¿¿

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

¿¿

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

3.Tarjan ¿¿
¿¿¿¿¿¿¿¿(¿¿¿¿¿inS¿¿¿¿)¿¿¿¿¿¿¿¿¿¿¿¿(¿¿¿¿¿inS¿¿¿¿)
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
¿¿<n * log(n), sqrt(n)>¿¿:¿¿sqrt(n)¿¿¿¿¿¿(¿¿¿¿¿¿¿¿)
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

¿¿<n * log(n), log(n)>¿¿¿:
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

¿¿Tarjan¿LCA¿¿(¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿tarjan¿¿¿¿¿¿¿¿)
    
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

//¿¿¿¿¿¿¿¿¿¿¿parent
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

¿¿¿¿
¿¿¿¿¿
1. Edmonds-Karp¿¿
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

2.dinic¿¿(¿¿¿)¿
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


3.dinic¿¿(¿¿)¿
int S, T, D[MAXN];
int front, rear, Q[MAXN];
int inx, H[MAXN], V[MAXE], W[MAXE], N[MAXE];

void add_edge(int u, int v, int w)
{
    //¿¿
    V[inx] = v;
    W[inx] = w;
    N[inx] = H[u];
    H[u] = inx ++;
    //¿¿
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


4.push_relable¿
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

5¿sap¿¿(¿¿¿¿)¿
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

6¿sap¿¿(¿¿¿¿¿)¿
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

7. ¿¿¿¿(¿¿¿¿¿¿¿¿¿¿¿¿¿¿)
1 ¿¿
¿¿¿¿ (Euler tour)¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
¿¿¿¿ (Euler circuit)¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿¿¿¿¿
2 ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
G¿¿¿¿¿¿¿¿¿¿¿¿¿¿G ¿¿¿G¿¿¿¿¿¿¿¿¿(¿¿¿¿¿¿¿¿¿¿¿¿¿¿)¿
G¿¿¿¿¿(G¿¿¿¿)¿G¿¿¿G¿¿¿¿¿¿¿¿
3 ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
D¿¿¿¿¿¿D¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿1¿¿¿¿¿¿¿¿¿¿¿¿¿1¿
D¿¿¿¿¿(D¿¿¿¿)¿D¿¿¿D¿¿¿¿¿¿¿¿¿¿¿¿¿
4 ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
5 ¿¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ = ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿2¿¿x¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿x¿¿¿¿¿¿>¿¿¿¿¿¿¿>¿¿¿¿¿¿¿¿¿¿¿¿ = ¿¿¿¿¿¿¿¿¿¿ = ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ = ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿1¿¿¿¿s¿t¿¿¿¿ > ¿¿¿u¿¿¿¿(u, t)¿¿¿¿x¿¿¿¿ > ¿¿¿v¿¿¿¿(s, v)¿¿¿¿x¿¿¿¿¿¿¿¿x¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ 0¿¿¿¿1¿¿¿¿¿0¿¿1¿¿¿¿¿¿¿¿¿¿¿¿¿¿ = ¿¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿¿ > ¿¿¿¿¿¿x¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿OK¿¿ = ¿¿¿¿¿¿ > ¿¿¿¿¿¿¿¿¿¿¿s¿t¿¿¿¿¿¿¿¿¿s¿¿¿¿¿¿¿ > ¿¿¿t¿¿¿¿¿¿¿ > ¿¿¿¿¿¿¿¿¿s¿¿¿t¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ = ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
    
¿¿¿¿¿¿
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

¿¿¿¿¿¿¿(LIS)¿
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

¿¿¿¿
1. ¿¿¿¿¿¿¿¿
Point interact(const Point &A, const Point &B, const Point &C, const Point &D)
{
    Point E;
    double k = ((A.y - C.y) * (C.x - D.x) - (A.x - C.x) * (C.y - D.y)) / ((B.x - A.x) * (C.y - D.y) - (B.y - A.y) * (C.x - D.x));
    E.x = A.x + k * (B.x - A.x);
    E.y = A.y + k * (B.y - A.y);
    return E;
}

¿¿
1.  ¿¿¿p, q¿¿¿gcd(p, q) == 1¿¿¿px + qy¿¿¿¿¿¿¿¿¿pq ¿ p ¿ q, ¿gcd(p, q) != 1¿¿¿¿¿¿¿¿

2.¿¿¿¿¿
¿¿¿¿¿¿m > 1, gcd(a, m) == 1, ¿a^¿(m) % m == 1;
¿¿¿¿¿¿¿p¿¿¿¿¿a^p % p == a;

//¿¿¿¿¿n¿¿¿¿n¿¿¿¿¿¿¿
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

3.¿¿¿¿:
¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿ ¿¿¿¿¿¿¿¿¿
S = sqrt(p * (p ¿ a) * (p ¿ b) * (p ¿ c))¿
¿¿, p = (a + b + c) / 2;
    
4.Polya¿
N = (A1 + A2 + ¿ + Am) / m;
¿¿¿Ai¿¿i¿¿¿¿¿¿¿n¿¿¿¿¿¿¿¿¿
Ai¿¿¿ X1^a1 * X2^a2 * X3 * ¿ * Xm^am¿m¿¿¿¿¿¿a1,a2¿am¿¿¿¿¿¿¿¿1, 2, ..m¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿¿¿¿k¿¿¿¿¿¿¿¿¿gcd(k, N).
    
    
    
Dancing links
1.¿¿¿¿
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
2.¿¿¿¿¿
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
1.  ¿¿¿¿¿¿¿¿
¿¿¿¿¿¿¿¿¿¿v,¿¿¿¿¿¿u¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿C¿¿¿¿¿¿¿
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


¿¿
1.Nim¿
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
