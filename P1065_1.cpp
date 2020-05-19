/*************************************************************************
	> File Name: P1065_1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 21时24分41秒
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
#define MAX_N 500
#define MAX_M 20

int m, n;

typedef struct {
    int Machine[25]; //工序对应的机器号；
    int Time[25]; //工序所需时间；
} Pro;

Pro a[MAX_M + 5];

int ProNum[MAX_N + 5];  
int yProNum[MAX_N + 5];

int f[MAX_M + 5];
int Mac[25][50000];
int atm[MAX_M + 5]; //同一个产品上一个程序结束时间；

int bns = 0;

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m * n; i++) {
        cin >> ProNum[i]; //产品编号；
        yProNum[i] = ++(f[ProNum[i]]);//产品的第几道程序
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i].Machine[j]; //第i 产品第j 程序 所用机器；
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i].Time[j]; // i产品j 程序 所用时间；
        }
    }
 //   int ans[25] = {0}; //每个机器时间
    for (int i = 1; i <= m * n; i++) {    //产品编号 + 程序；
        int linshi = a[ProNum[i]].Machine[yProNum[i]]; //机器
        int TIME = a[ProNum[i]].Time[yProNum[i]];  //时间
        int NUM = ProNum[i]; //产品号；
      //  int Gram = yProNum[i]; //程序
        int cnt = 0;
        for (int j = atm[NUM] + 1;; j++) {
            if (Mac[linshi][j] == 0) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == TIME) {
                for (int k = j; k > (j - cnt); k--) Mac[linshi][k] = 1;
                bns = max(bns, j);
                atm[NUM] = j;
                cnt = 0;
                break;
            }
        }
    }
    cout << bns << endl;
    
    return 0;
}


