/*************************************************************************
	> File Name: P1067.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月14日 星期四 08时34分48秒
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


int main() {
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        int a;
        cin >> a;
        if (a == 0) continue;
        if (a > 0 && i != n) {
            cout << "+";
        } else if(a < 0) {
            cout << "-";
        }
        if (a != 1 && a != -1 || i == 0) cout << fabs(a);
        if (i == 0) break;
        cout << "x";
        if (i == 1) continue;
        cout << "^" << i;
    }
    cout << endl;
    return 0;
}


