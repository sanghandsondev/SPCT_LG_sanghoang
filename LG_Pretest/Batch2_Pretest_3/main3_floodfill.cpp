#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ull long long

int M, N;
int K;
int V[1000][1000];
int check[1000][1000];
int C[10000], res[10000];
int g_count;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void reset(){
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++){
            check[i][j] = 1;
        }
    }
    g_count = 0;
}

void domain_expansion(int x, int y, int i){
    check[x][y] = 0;
    g_count++;
    for (int k = 0; k < 4; k++){
        int x1 = x + dx[k];
        int y1 = y + dy[k];
        if (x1 >= 0 && x1 < M && y1 >= 0 && y1 < N && check[x1][y1] == 1 && C[i] > V[x1][y1]) {
            domain_expansion(x1, y1, i);
        }
    }
}

void solve(){
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++){
            cin >> V[i][j];
            check[i][j] = 1;
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> C[i];
        res[i] = 0;
    }
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < N; j++){
    //         cout << V[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // DFS
    for (int i = 0; i < K; i++) {
        reset();
        if (C[i] > V[0][0]) {
            domain_expansion(0, 0, i);
            res[i] = g_count;
        } else {
            res[i] = 0;
        }
    }

    for(int i = 0; i < K; i++){
        cout << res[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
}