/*************************************************************************
	> File Name: P1786.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 10时16分19秒
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

typedef struct {
    string Name, Job;
    int bg;
    int dj, num;
} Peo;


Peo p[205];

bool cmp1(Peo p1, Peo p2) {
    if (p1.dj == p2.dj) return p1.num < p2.num;
    return (p1.dj) > (p2.dj);
}

bool cmp2(Peo p1, Peo p2) {
    if (p1.bg == p2.bg) return p1.num < p2.num;
    return (p1.bg) > (p2.bg);
}


int main() {
    int n, m = -1;
    cin >> n;
    while (m < n - 1) {
        ++m;
        cin >> p[0].Name >> p[0].Job >> p[0].bg >> p[0].dj;
        if (p[0].Job != "BangZhu" && p[0].Job != "FuBangZhu") break;
        cout << p[0].Name << " " << p[0].Job << " " << p[0].dj << endl;
    }
    if (n - 1 <= m) return 0;
    for (int i = 1; i < n - m; i++) {
        cin >> p[i].Name >> p[i].Job >> p[i].bg >> p[i].dj;
        p[i].num = i;
    }
    p[0].num = 0;
    n = n - m;
    int a = 0;
    sort(p, p + n, cmp2);
    sort(p, p + 2, cmp1);
    for (int i = 0; i < 2; i++) cout << p[i].Name << " HuFa "<< p[i].dj << endl;
    a = (6 <= n ? 6 : n);
    sort(p + 2, p + a, cmp1);
    for (int i = 2; i < a; i++) cout  << p[i].Name << " ZhangLao " << p[i].dj << endl;
    if (n < 6) return 0;
    a = (13 <= n ? 13 : n);
    sort(p + 6, p + a, cmp1);
    for (int i = 6; i < a; i++) cout  << p[i].Name << " TangZhu " << p[i].dj << endl;
    if (n < 13) return 0;
    a = (38 <= n ? 38 : n);
    sort(p + 13, p + a, cmp1);
    for (int i = 13; i < a; i++) cout  << p[i].Name << " JingYing " << p[i].dj << endl;
    if (n < 38) return 0;
    sort(p + 38, p + n, cmp1);
    for (int i = 38; i < n; i++) cout  << p[i].Name << " BangZhong " << p[i].dj << endl;


    return 0;
}


