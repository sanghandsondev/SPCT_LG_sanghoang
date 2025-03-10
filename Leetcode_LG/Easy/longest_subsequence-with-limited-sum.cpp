// https://leetcode.com/problems/longest-subsequence-with-limited-sum/

// Cách 1: Sắp xếp mảng tăng dần -> Duyệt từ index 0 -> cho đến khi sum > queries[] thì break và get số index => số phần tử tối đa thỏa mãn
// Cách 2 (Binary-search) Sắp xếp mảng tăng dần -> Prefix sum -> Sử dụng Binary search để tìm vị trí lớn nhất thỏa mãn <= queries[]

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ull long long
#define mod 1000000007

void solve(){
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}