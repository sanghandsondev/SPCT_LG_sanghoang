//https://www.hackerrank.com/contests/spct2025batch-3-pretest-practice/challenges

// ---- SOLVE: Xài Backtracking để tìm tất cả các cách đặt quân hậu trên bàn cờ N*N ----

#include <bits/stdc++.h>
using namespace std;

int N, X[11], column[11], d1[30], d2[30];
char a[11][11];
int res;

void input(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> a[i][j];
        }
        column[i] = 1;
    }
    res = 0;
}

void Try(int i){
    for (int j = 1; j <= N; j++) {
        if (column[j] == 1 && d1[i - j + N] == 1 && d2[i+j-1] == 1 && a[i][j] != '*'){  
            X[i] = j;
            column[j] = d1[i - j + N] = d2[i + j - 1] = 0;      // Status 1 -> 0
            if (i == N) {
                res++;
            } else {
                Try(i+1);
            }
            column[j] = d1[i - j + N] = d2[i + j - 1] = 1;      // Status 0 -> 1
        }
    }
}

int main(){
    input();
    for (int i = 1; i <= 29; i++){
        d1[i] = d2[i] = 1;
    }
    Try(1);
    cout << res;
    return 0;
}