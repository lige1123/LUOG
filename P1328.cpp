/*************************************************************************
	> File Name: P1328.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月14日 星期四 00时11分15秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstring>
#include<deque>
#include<functional>
#include<list>
#include<map>
#include<iomanip>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;

int a[205], b[205];


int main() {
    int n, na, nb;
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }
    int ans = 0, bns = 0;
    for (int i = 0; i < n; i++) {
        int s = a[i % na], t = b[i % nb];
        if (s == t) continue;
        if (
            ((s == 0) && (t == 1 || t == 4)) ||
           ((s == 1) && (t == 2 || t == 4)) ||
            ((s == 2) && (t == 3)) ||
            (t == 0 && (s == 2 || s == 3)) ||
            (t == 1 && s == 3) ||
            (t == 2 && s == 4) ||
            (t == 3 && s == 4)
           )
        {
               bns++;
           } else {
               ans++;
           }
    }
    cout << ans << " " << bns << endl;
    return 0;
}


