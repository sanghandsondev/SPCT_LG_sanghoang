#include <bits/stdc++.h>
#include <algorithm>    // sort()
using namespace std;

// Trả về con trỏ / iterator trỏ đến phần tử đầu tiên có giá trị > X
// upper_bound(a, a + n, X) -> O(logN)
// upper_bound(v.begin(), v.end(), X)

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // -------------- Vector: đã được sắp xếp tăng dần  -----------------
    vector<int> v = {1, 2, 3, 3, 3, 4, 5, 9};   // => v[0, n-1]

    auto it = upper_bound(v.begin(), v.end(), 5);   // {9} 
    cout << (it - v.begin()) << endl;   // it = 7 => v[7]

    it = upper_bound(v.begin(), v.end(), 3);   // {4, 5, 9} 
    cout << (it - v.begin()) << endl;   // it = 5 => v[2]

    it = upper_bound(v.begin(), v.end(), 9); 
    cout << (it - v.begin()) << endl;   // it = v.end() = 8 -> giá trị rác, đứng sau phần tử cuối cùng, index = n

    // for (auto x : v){
    //     cout << x << ' ';
    // }

    return 0;
}