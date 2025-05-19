#include <bits/stdc++.h>
using namespace std;

// -------- SOLVE: Sử dụng TWO POINTER và một chút THAM LAM --------------
// Sắp xếp cân nặng của các nhà thám hiểm, 1 2 4 6 7 9, k = 7
// 1 + 9 = 10 > 7 nên không thể đi chung, cho thằng 9 đi riêng
// 1 + 7 = 8 > 7 nên không thể đi chung, cho thằng 7 đi riêng
// 1 + 6 = 7 <= 7 nên cho đi chung, thằng 1 và 6 đi chung
// 2 + 4 = 6 < 7 nên cho đi chung, thằng 2 và 4 đi chung
// Thoát vòng lặp khi left > right
// ------------------------------------------------------------------------

int N, limit;
vector<int> weights;

int solve(){
    int res = 0;
    int left = 0;
    int right = weights.size() - 1;
    while (left <= right) {
        if (left == right){
            res++;
            break;
        }    
        if (weights[left] + weights[right] <= limit){
            left++;
            right--;
            res++;
        }
        else {
            right--;
            res++;
        }
    }

    return res;
}

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        weights.push_back(temp);
    }
    cin >> limit;
    sort(weights.begin(),weights.end());
}

int main(){
    input();
    cout << solve();
    return 0;
}