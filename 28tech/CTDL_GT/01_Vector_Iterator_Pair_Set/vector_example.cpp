#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/* ------- Input -----------
7
1 58
2
2
1 52
1 81
1 12
1 2
---------------------------- */
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int tt; cin >> tt;
        if (tt == 1){
            int x; cin >> x;
            v.push_back(x);
        } else {
            if (!v.empty()) {
                v.pop_back();
            }
        }
    }
    if (v.empty()) cout << "EMPTY\n";
    else{
        for(auto x : v) cout << x << ' ';
    }

    return 0;
}