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
using namespace std;

#define px first
#define py second
#define pb push_back
#define mp make_pair
#define pque priority_queue
#define lowbit(x) ((x) & -(x))
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
typedef vector<string> vstr;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

class FillInTheMaze {
public:
	vector <string> filled(int, int, int);
};

vector <string> FillInTheMaze::filled(int R, int C, int X) {
    const int n = (R << 1) | 1;
    const int m = (C << 1) | 1;

	vstr v;
    string a = "", b = "", c = "";
    for (int i = 0; i < m; ++ i) {
        a += i == 1 ? "." : "#";
        b += (i == 0 || i + 1 == m) ? "#" : ".";
        c += "#";
    }
    for (int i = 0; i < n; ++ i) {
        if (i == 0 || i + 1 == n) {
            v.pb(c);
        } else {
            v.pb((i & 1) ? b : a);
        }
    }
    if (X <= R) {
        for (int i = 0; i < X; ++ i) {
            v[i << 1 | 1][0] = '.';
        }
    } else if (X <= (R << 1)) {
        for (int i = 0; i < R; ++ i) {
            v[i << 1 | 1][0] = '.';
            if (R + i < X) {
                v[i << 1 | 1][m - 1] = '.';
            }
        }
    } else {
        for (int i = 0; i < R; ++ i) {
            v[i << 1 | 1][0] = v[i << 1 | 1][m - 1] = '.';
        }
        if (X <= (R << 1) + C) {
            for (int i = 0; i < X - (R << 1); ++ i) {
                v[0][i << 1 | 1] = '.';
            }
        } else {
            for (int i = 0; i < C; ++ i) {
                v[0][i << 1 | 1] = '.';
                if ((R << 1) + C + i < X) {
                    v[n - 1][i << 1 | 1] = '.';
                }
            }
        }
    }

    return v;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, vector <string> p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	FillInTheMaze *obj;
	vector <string> answer;
	obj = new FillInTheMaze();
	clock_t startTime = clock();
	answer = obj->filled(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p3.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p3[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p3.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p3[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	int p1;
	int p2;
	vector <string> p3;

	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 6;
	p2 = 3;
	string t3[] = {"#######.#####","......#.#...#","#.###.#.#.#.#","#.#.......#.#","#.#######.#.#","#.......#.#.#","#########.###"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 3;
	p2 = 2;
	string t3[] = {"#######",".......","#######"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 2;
	p1 = 2;
	p2 = 8;
	string t3[] = {"#.#.#",".....","#.###",".....","#.#.#"};
			p3.assign(t3, t3 + sizeof(t3) / sizeof(t3[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 12;
	p1 = 3;
	p2 = 14;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, false, p3) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// 
// There is a very simple way to draw mazes using ASCII characters.
// One sample maze with three entrances is shown below.
// (The '#'s represent walls, the '.'s represent empty cells.)
// 
// 
// #######.#####
// ......#.#...#
// #.###.#.#.#.#
// #.#.......#.#
// #.#######.#.#
// #.......#.#.#
// #########.###
// 
// 
// Here is the construction of such a maze in more detail.
// Let's take a look at an unfinished maze that has walls everywhere.
// 
// 
// #############
// #.#.#.#.#.#.#
// #############
// #.#.#.#.#.#.#
// #############
// #.#.#.#.#.#.#
// #############
// 
// 
// Rows and columns of the bitmap are numbered starting from 0 in the top left corner.
// Notice that the cells with both coordinates odd are still empty.
// These cells are called rooms.
// The cells that share a side with a room are called hallways and the remaining cells are called pillars.
// Hence, pillars have both coordinates even. 
// Pillars will always be walls.
// Some hallways will eventually be empty while others will be walls.
// 
// 
// You are given ints R, C, and X.
// Your task is to design any maze with R rows and C columns of rooms (that is, 2R+1 rows of characters, each containing 2C+1 characters).
// The maze must have the following additional properties:
// 
// 
// Each room must be reachable from each other room, without leaving the maze.
// There have to be exactly X exits (i.e., empty hallways on the boundary of the maze).
// The total number of wall cells ('#' characters) must be maximized.
// 
// 
// Return a vector <string> with the resulting maze. Any valid answer will be accepted.
// 
// 
// DEFINITION
// Class:FillInTheMaze
// Method:filled
// Parameters:int, int, int
// Returns:vector <string>
// Method signature:vector <string> filled(int R, int C, int X)
// 
// 
// CONSTRAINTS
// -R will be between 1 and 24, inclusive.
// -C will be between 1 and 24, inclusive.
// -X will be between 1 and 2R+2C, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 6
// 3
// 
// Returns: {"#######.#####", "......#.#...#", "#.###.#.#.#.#", "#.#.......#.#", "#.#######.#.#", "#.......#.#.#", "#########.###" }
// 
// These dimensions correspond to the examples in the problem statement. The maze shown in the statement is indeed one of the optimal solutions.
// 
// 1)
// 1
// 3
// 2
// 
// Returns: {"#######", ".......", "#######" }
// 
// A very simple maze with just one row of rooms and with two exits.
// 
// 2)
// 2
// 2
// 8
// 
// Returns: {"#.#.#", ".....", "#.###", ".....", "#.#.#" }
// 
// The returned maze:
// 
// #.#.#
// .....
// #.###
// .....
// #.#.#
// 
// 
// Notice the one hallway that remained a wall. An answer without that wall would not be accepted, as the number of '#'s would not be as large as possible.
// 
// 
// END KAWIGIEDIT TESTING










//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!