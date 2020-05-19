#include <iostream>
#include <stdio.h>
using namespace std;

int n, m;
int arr[510][510], temp[510][510];

void rorate1(int i, int j, int *a, int *b) {
    (*a) -= j;
    (*b) += i;
}

void rorate2(int i, int j, int *a, int *b) {
    (*a) += j;
    (*b) -= i;
}


int main() {
    cin >> n >> m;
    int x, y, r, z, t = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = ++t;
        }
    }
    for(int i=0; i<m; i++){
        scanf("%d%d%d%d", &x, &y, &r, &z);
        if(z) {
            for(int i = x-r; i <= x+r; i++){
                for(int j = y-r; j <= y+r; j++){
                    int a = x, b = y;
                    rorate1(i - x, j - y, &a, &b);
                    temp[a][b] = arr[i][j];
                }
            }
            for(int i = x-r; i <= x+r; i++){
                for(int j = y-r; j <= y+r; j++){
                    arr[i][j] = temp[i][j];
                }
            }
        }
        else {
            for(int i = x-r; i <= x+r; i++){
                for(int j = y-r; j <= y+r; j++){
                    int a = x, b = y;
                    rorate2(i - x, j - y, &a, &b);
                    temp[a][b] = arr[i][j];
                }
            }
            for(int j = y-r; j <= y+r; j++){
                for(int i = x-r; i <= x+r; i++){
                    arr[i][j] = temp[i][j];
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            j == 1 || printf(" ");
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}


