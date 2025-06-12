#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ull long long
#define mod 1000000007

int n;
// int a[10001];

int getback(int t){
    int res = 0 - t;
    return res;
}

void solve(){
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    stack<int> st;
    for(int i = 0; i < n; i++){
        // -- blue robot
        if (a[i] > 0){
            st.push(a[i]);
        // -- red robot
        } else {
            if (st.empty()) {
                st.push(a[i]);
            } else {
                while(!st.empty() && st.top() > 0 && getback(a[i]) > st.top()) {
                    st.pop();
                }
                if (!st.empty()) {
                    if (st.top() < 0) {
                        st.push(a[i]);
                    } else if (st.top() > 0){
                        if (st.top() == getback(a[i])) {
                            st.pop();
                        }
                    }
                } else {
                    st.push(a[i]);
                }
            }
        }
    }
    vector<int> res;
    if (!st.empty()) {
        while(!st.empty()) {
            int tp = st.top();
            res.push_back(tp);
            st.pop();
        }
        for(int i = res.size() - 1; i >= 0; i--){
            cout << res[i] << " ";
        }
    } else {
        cout << "88888888";
    }
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}