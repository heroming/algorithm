/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/04 09:41:27
 */
#include <vector>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <unordered_map>
using namespace std;

#define px first
#define py second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define clr(v, e) memset(v, e, sizeof(v))
#define rep(it, v) for (auto it : v)
#define forn(i, n) for (int i = 0; i < (n); ++ i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; -- i)
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define rform(i, a, b) for (int i = (b); i >= (a); -- i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int letter = 26;
const int maxe = 16;
const int maxn = 500000;

struct TrieNode {
    int cnt;
    int word;
    int data[letter];
    TrieNode() {
        cnt = 0;
        word = 0;
        clr(data, 0);
    }
} trie[maxn];

int idx;
int n, m;
char s[maxe];

void insert() {
    int v = 0;
    const int t = strlen(s);
    forn (i, t) {
        trie[v].cnt += 1;
        int k = s[i] - 'a';
        if (trie[v].data[k] == 0) {
            trie[v].data[k] = idx ++;
        }
        v = trie[v].data[k];
    }
    trie[v].cnt += 1;
    trie[v].word += 1;
}

int search() {
    int v = 0;
    const int t = strlen(s);
    forn (i, t) {
        int k = s[i] - 'a';
        if (trie[v].data[k] == 0) return 0;
        v = trie[v].data[k];
    }
    return trie[v].cnt;
}

int main() {
    idx = 1;
    scanf("%d", &n);
    forn (i, n) {
        scanf("%s", s);
        insert();
    }
    scanf("%d", &m);
    forn (i, m) {
        scanf("%s", s);
        printf("%d\n", search());
    }
    return 0;
}

