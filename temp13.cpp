/* 
 * Author: Hakobyan Tigran
 */

#define printTime(begin, end) printf("%.3lf\n", (double)(end - begin) / (double)CLOCKS_PER_SEC) 


#include <string.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <complex>
#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <limits>
#include <ctime>
#include <cassert>
#include <valarray>

using namespace std;

#define IN(a) freopen(a, "r", stdin)
#define OUT(a) freopen(a, "w", stdout)

#define mp(a, b) make_pair(a, b)
#define det(a, b, c, d) (a * d - c * b)
#define sbstr(s, i, j) s.substr(i, j - i + 1)

#define clear(dp) memset(dp, -1, sizeof(dp))
#define reset(arr) memset(arr, 0, sizeof(arr))

#define EPS 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define IINF 1000000000
#define LINF 6000000000000000000LL

const int maxN = 107;

int mat[4][maxN];

int go (vector < int > &v) {
  int ans = 1;
	int n = v.size();
	vector < int > d(n, 1);
	for(int i = 1; i < n; ++i) {
		int mmax = -1;
		for(int j = 0; j < i; ++j) {
			if(v[j] < v[i] && (mmax == -1 || d[mmax] < d[j])) {
				mmax = j;
			}
		}
		if(mmax != -1) 
			d[i] += d[mmax];
		ans = max(ans, d[i]);
	}
	return ans;
}

int main () {

  int test_case = 1;

	while(test_case--) {
		int c, n;
		scanf("%d%d", &c, &n);
		int t = n * c;
		vector < int > colors(t), values(t);
		for(int i = 0; i < t; ++i) {
			scanf("%d%d", &colors[i], &values[i]);
		}
		vector < int > ind;
		for(int i = 0; i < c; ++i) {
			ind.push_back(i);
		}
		int mmin = IINF;
		vector < int > v(t);
		do {
			int cnt = 0;
			for(int i = 0; i < c; ++i) {
				for(int j = 0; j < n; ++j) {
					mat[ind[i]][j] = cnt++;
				}
			}
			for(int i = 0; i < t; ++i) {
				v[i] = mat[colors[i] - 1][values[i] - 1];
			}
			mmin = min(mmin, t - go(v));
		}while(next_permutation(ind.begin(), ind.end()));
		printf("%d\n", mmin);
	}
	return 0;
}