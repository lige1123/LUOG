/*************************************************************************
	> File Name: P1563.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月13日 星期三 02时50分37秒
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
    int a;
    string job;
} Num;


Num num[100005];



int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i].a >> num[i].job;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int c, b;
        cin >> c >> b;
        if ((c + num[ans].a) == 1) {
            ans += b;
        } else {
            ans -= b;
        }
        ans = (ans % n + n) % n;
    }
    cout << num[((ans % n) + n) % n].job << endl;
    return 0;
}


