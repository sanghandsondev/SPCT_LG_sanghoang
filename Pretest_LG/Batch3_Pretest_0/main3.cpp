#include <bits/stdc++.h>
using namespace std;

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