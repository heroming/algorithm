/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/12/31 11:14:58
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

const string man = "man";
const int maxn = 32;

int t, n;
char s[maxn];

bool superhero() {
    const int m = strlen(s);
    if (m >= 3) {
        for (int i = 0; i < 3; ++ i) {
            if (man[i] != s[m - 3 + i]) return 0;
        }
        return 1;
    }
    return 0;
}

int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        int win = 0;
        int hero = 0, villain = 0;
        forn (i, n) {
            scanf("%s", s);
            if (win == 0) {
                if (superhero()) {
                    ++ hero;
                } else {
                    ++ villain;
                }
                if (hero - villain >= 2) win = 1;
                if (villain - hero >= 3) win = 2;
            }
        }
        if (win == 1) {
            printf("superheroes\n");
        } else {
            printf("%s\n", win ? "villains" : "draw");
        }
    }
    return 0;
}
