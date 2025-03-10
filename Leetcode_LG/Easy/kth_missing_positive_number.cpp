// https://leetcode.com/problems/kth-missing-positive-number/description/

// Cách 1: Tạo mảng b[3000], xét b[i] = 1 khi i tồn tại trong mảng đã cho. For từ 1 -> 2999 để tìm ra phần tử b[i] != 1 và tại thời điểm đó count == k. Return i
//     int b[3000];
//     int count = 0;
//     int findKthPositive(vector<int>& arr, int k) {
//         for (auto x : arr){
//             b[x] = 1;
//         }
//         for (int i = 1; i < 3000; i++){
//             if (b[i] != 1) count++;
//             if (count == k) return i;
//         }
//         return 1;
//     }

// Cách 2: Binary search - Khoai vãi

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ull long long
#define mod 1000000007

void solve(){
    
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // int t; cin >> t;
    // while(t--) solve();
    solve();
    return 0;
}