/*************************************************************************
	> File Name: P1803_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月23日 星期六 12时51分40秒
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

#define MAX_N 1000000

struct Node {
    int b, e;
} arr[MAX_N + 5];



bool cmp(struct Node x, struct Node y) {
    if (x.e == y.e) return x.b < y.b;
    return x.e < y.e;
}


int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].b >> arr[i].e;
    }
    sort(arr, arr + n, cmp);
    int m = arr[0].e;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i].b < m) continue;
  //      cout << arr[i].b << " " << arr[i].e << endl;
        m = arr[i].e;
        ans++;
    }
    cout << ans << endl;
    return 0;
}



