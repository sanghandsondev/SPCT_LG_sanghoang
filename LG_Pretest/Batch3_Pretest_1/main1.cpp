// https://www.hackerrank.com/contests/spct2025batch-3-pretest-1/challenges

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ull long long
#define mod 1000000007

int t, w;

void solve(){
    cin >> w;
    int cnt = 0;
    for (int i = 1; i <= w; i++){
        int number = i;
        int total = i;
        while(total < w) {
            number++;
            total+= number;
        }
        if (total == w) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t ;
    while(t--){
        solve();
    }
    return 0;
}