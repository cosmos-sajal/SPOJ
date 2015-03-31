/*
USER: zobayer
TASK: MDOLLS
ALGO: sorting, greedy
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 20000;

typedef struct { int ff, ss; } pii;

inline bool scomp(const pii &a, const pii &b) {
    return a.ss != b.ss ? a.ss > b.ss : a.ff < b.ff;
}

inline bool bcomp(const pii &a, const pii &b) {
    return a.ff < b.ff;
}

int main() {
    int test, i, j, k, n, ans;
    pii p[MAX];
    scanf("%d", &test);
    while(test--) {
        scanf("%d", &n);
        for(i = 0; i < n; i++) scanf("%d %d", &p[i].ff, &p[i].ss);
        sort(p, p + n, scomp);
    	for(i = 0 ; i < n ; i++)
    		printf("%d %d\n", p[i].ff, p[i].ss);
        for(i = j = 0, ans = n; i < n; i++) {
            k = upper_bound(p, p+j, p[i], bcomp) - p;
            printf("k = %d j = %d\n", k, j);
            if(k == j) p[j++] = p[i];
            else ans--, p[k].ff = p[i].ff;
        }
        printf("%d\n", ans);
    }
    return 0;
}