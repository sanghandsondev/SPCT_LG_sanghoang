#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ull long long

// Tuan phải pass 3 bài pretest
// Giải N bài pretest trước đó
// Mỗi pretest chứa các số problems khác nhau, mỗi problem có độ khó khác nhau
// Để giải một problem, kiến thức của Tuấn phải lớn hơn độ khó của problem
// Sau khi giải problem đó, kiến thức tăng lên 1
// Để hoàn thành pretest, Tuấn phải giải toàn bộ problems  theo "THỨ TỰ" đã cho.
// -- Giả sử Tuấn bắt đầu với kiến thức level là K

int n;
vector<vector<ull>> pretest;

bool check(ull k){
    for (auto exam : pretest) {
        for (auto problem : exam) {
            if (k > problem) {
                k++;
            } else {
                return false;
            }
        }
    }
    return true;
}

int binarySearch(int l, int r){
    while(l <= r){
        ull m = l + (r - l) / 2;
        if (check(m)) {
            r = m - 1;
        } else {
            l = m + 1;
        }     
    }
    return l;
}

void solve(){
    cin >> n;
    for (int i = 0; i < n; i++){
        vector<ull> v_temp;
        int m, x; cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> x;
            v_temp.push_back(x);
        }
        pretest.push_back(v_temp);
    }
    
    sort(pretest.begin(), pretest.end(), [](vector<ull> a, vector<ull> b){
        auto max_it1 = max_element(a.begin(), a.end());
        auto max_it2 = max_element(b.begin(), b.end());
        // if (*max_it1 == *max_it2) {
        //     int i1 = distance(a.begin(), max_it1);
        //     int i2 = distance(b.begin(), max_it2);
        //     return i1 >= i2;
        // }
        return *max_it1 < *max_it2;
    });

    // for (auto it : pretest){
    //     for (auto x : it) {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << binarySearch(1, 1e9);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    solve();
}