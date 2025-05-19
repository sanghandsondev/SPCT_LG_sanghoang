#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ull long long
#define mod 1000000007

int n, m, k;
vector<pair<vector<int>,int>> combo;        // [{1,2,3},500], [{1,2}, 700], [{1,3}, 1000]

void input(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int num; cin >> num;
        pair<vector<int>,int> comb;
        for(int j = 0; j < num; j++) {
            int x; cin >> x;
            comb.first.push_back(x);
        }
        cin >> comb.second;
        combo.push_back(comb);
    }
}

void solve(){
    int min_cost = INT_MAX;
    int total_combinations = 1;
    // 1. Generate all combinations of using 0-2 times of each combo
    for(int i = 0; i < m; i++) total_combinations *= 3;     // 0, 1, 2 times

    // 2. For each combination, calculate the cost
    for(int mask = 0; mask < total_combinations; mask++){
        map<int,int> mp;
        int cost = 0;
        int tmp = mask;
        // 3. For each combo, check how many times it is used
        for(int i = 0; i < m; i++){
            // tmp % 3 = 0, 1, 2 times
            int use = tmp % 3;
            tmp /= 3;   

            // 4. Calculate the cost and update the map
            cost += use * combo[i].second;
            for(auto it : combo[i].first){
                mp[it] += use;
            }
        }
        // 5. Check if all pieces are used at least 2 times
        for(int j = 1; j <= n; j++){
            if (mp[j] < 2) {
                cost += k * (2 - mp[j]);
            }
        }

        // 6. Update the minimum cost
        min_cost = min(min_cost, cost);
    }
    cout << min_cost << endl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    input();
    solve();
    return 0;
}