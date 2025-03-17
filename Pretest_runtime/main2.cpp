#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ull long long

// size M x N
// Giống dâu tây nhạy cảm với ánh sáng khi quả vẫn còn xanh
// Trong ngày HOT SUNNY, nếu không được che, nó sẽ lớn chậm và màu sắc chán đời
// Méo đủ tiền che toàn bộ vườn -> chỉ đủ H x W

// ------------------- Prefix sum: Cộng dồn trên mảng 2 chiều -----------------------------
// Mảng 2 chiều B[n][m] cho trước
// prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + B[i][j];

int M, N, H, W;
int V[1501][1501];
ull prefix[1501][1501];

void solve(){
    cin >> M >> N;
    for(int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++){
            cin >> V[r][c];
        }
    }
    cin >> H >> W;
    // for(int r = 1; r <= M; r++) {
    //     for (int c = 1; c <= N; c++){
    //         cout << V[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    for(int r = 1; r <= M; r++) {
        for (int c = 1; c <= N; c++){
            prefix[r][c] = prefix[r-1][c] + prefix[r][c-1] - prefix[r-1][c-1] + V[r][c];
        }
    }
    // for(int r = 1; r <= M; r++) {
    //     for (int c = 1; c <= N; c++){
    //         cout << prefix[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    ull maxi = 0;
    for(int r = H; r <= M; r++) {
        for (int c = W; c <= N; c++){
            ull temp = prefix[r][c] - prefix[r][c-W] - prefix[r - H][c] + prefix[r-H][c-W];
            maxi = max(maxi, temp);
        }
    }
    cout << maxi;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
}