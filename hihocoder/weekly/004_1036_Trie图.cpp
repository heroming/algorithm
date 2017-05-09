/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2017/01/05 10:08:15
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

struct TrieNode {
    static const int letter = 26;
 
    int word;
    TrieNode * suffix;
    TrieNode * next[letter];
    
    TrieNode() {
        word = 0;
        suffix = NULL;
        clr(next, 0);
    }
};

struct Trie {
    TrieNode * root;
    Trie() {
        root = new TrieNode;
    }
    
    void insert(const string & s) {
        TrieNode * it = root;
        rep (c, s) {
            int idx = c - 'a';
            if (!it->next[idx]) {
                it->next[idx] = new TrieNode();
            }
            it = it->next[idx];
        }
        it->word = 1;
    }
    
    void build() {
        root->suffix = root;
        queue<TrieNode *> que;
        forn (i, TrieNode::letter) {
            if (!root->next[i]) {
                root->next[i] = root;
            } else {
                root->next[i]->suffix = root;
                que.push(root->next[i]);
            }
        }

        TrieNode * it, * suf;
        while (!que.empty()) {
            it = que.front();
            suf = it->suffix;
            que.pop();
            forn (i, TrieNode::letter) {
                if (!it->next[i]) {
                    it->next[i] = suf->next[i];
                } else {
                    it->next[i]->suffix = suf->next[i];
                    que.push(it->next[i]);
                }
            }
        }
    }
    
    bool query(const string & s) {
        TrieNode * it = root;
        rep (c, s) {
            int idx = c-  'a';
            it = it->next[idx];
            if (it->word) return 1;
        }
        return 0;
    }
};

int n;
string s;

int main() {
    scanf("%d", &n);
    Trie trie;
    forn (i, n) {
        cin >> s;
        trie.insert(s);
    }
    trie.build();
    cin >> s;
    printf("%s\n", trie.query(s) ? "YES" : "NO");
    return 0;
}
