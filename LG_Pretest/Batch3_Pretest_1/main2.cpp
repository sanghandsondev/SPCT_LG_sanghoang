#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ull long long
#define mod 1000000007

int t, k;
string flagS;
bool red[10003];
bool green[10003];
bool blue[10003];

void solve(){
    cin >> k;
    cin >> flagS;
    memset(red, false , sizeof(red));
    memset(green, false , sizeof(green));
    memset(blue, false , sizeof(blue));
    int len = flagS.length();
    for(int i = 0; i < len; i++){
        if (flagS[i] == 'U') {
        } else if (flagS[i] == 'R') {
            red[i] = true;
        } else if (flagS[i] == 'B') {
            blue[i] = true;
        } else if (flagS[i] == 'G') {
            green[i] = true;
        } else if (flagS[i] == 'Y') {
            red[i] = green[i] = true;
        } else if (flagS[i] == 'C') {
            green[i] = blue[i] = true;
        } else if (flagS[i] == 'P') {
            red[i] = blue[i] = true;
        } else if (flagS[i] == 'W') {
            red[i] = green[i] = blue[i] = true;
        }
    }
    // for(int i = 0; i < len; i++){
    //     cout << red[i] << blue[i] << green[i] << endl;
    // }
    int cntR = 0, cntB = 0, cntG = 0;
    vector<int> tempR, tempB, tempG;
    for(int i = 0; i < len; i++) {
        if (red[i] == true) {
            tempR.push_back(1);
            if (tempR.size() == k) {
                cntR++;
                tempR.clear();
            }
        } else {
            if (!tempR.empty()) {
                cntR++;
                tempR.clear();
            } 
        }
    }
    for(int i = 0; i < len; i++) {
        if (blue[i] == true) {
            tempB.push_back(1);
            if (tempB.size() == k) {
                cntB++;
                tempB.clear();
            }
        } else {
            if (!tempB.empty()) {
                cntB++;
                tempB.clear();
            } 
        }
    }
    for(int i = 0; i < len; i++) {
        if (green[i] == true) {
            tempG.push_back(1);
            if (tempG.size() == k) {
                cntG++;
                tempG.clear();
            }
        } else {
            if (!tempG.empty()) {
                cntG++;
                tempG.clear();
            } 
        }
    }
    if (!tempR.empty()) cntR++;
    if (!tempB.empty()) cntB++;
    if (!tempG.empty()) cntG++;
    cout << cntR + cntB + cntG << endl;
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}