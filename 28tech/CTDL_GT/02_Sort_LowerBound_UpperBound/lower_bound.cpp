#include <bits/stdc++.h>
#include <algorithm>    // sort()
using namespace std;

// Trả về con trỏ / iterator trỏ đến phần tử đầu tiên có giá trị >= X
// lower_bound(a, a + n, X) -> O(logN)
// lower_bound(v.begin(), v.end(), X)

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    // -------------- Vector: đã được sắp xếp tăng dần  -----------------
    vector<int> v = {1, 2, 3, 3, 3, 4, 5, 9};   // => v[0, n-1]

    auto it = lower_bound(v.begin(), v.end(), 5);   // {5, 9} 
    cout << (it - v.begin()) << endl;           // it = 6 => v[6]

    it = lower_bound(v.begin(), v.end(), 3);   // {3, 3, 3, 4, 5, 9} 
    cout << (it - v.begin()) << endl;       //  it = 2 => v[2]

    it = lower_bound(v.begin(), v.end(), 10);   
    cout << (it - v.begin()) << endl;       // it = v.end() -> giá trị rác, đứng sau phần tử cuối cùng, index = n

    // for (auto x : v){
    //     cout << x << ' ';
    // }

    return 0;
}