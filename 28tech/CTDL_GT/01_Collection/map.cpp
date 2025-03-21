#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using ll = long long;

// -------------------------- map <pair<key, value>> ---------------------
// -- (key là duy nhất cho mỗi phần tử) + (các phần tử được tự động sắp xếp theo key tăng dần)

// insert(), erase()
// size()
// begin(), end(), rbegin(), rend()
// count(), find()


// -- NOTE: ứng dụng để lưu tần suất xuất hiện của một phần tử nào đó trong mảng (1D/2D) / xâu.

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    map <int, int> mp;
    mp[100] = 200;          // {100, 200}
    mp[200] = 400;
    mp.insert({200, 300});  // mp[200] = 300;
    
    cout << mp.size() << endl;  // output:  2
    
    for (auto x : mp){
        cout << x.first << " " << x.second << endl;
    }
    for (auto it = mp.begin(); it != mp.end(); it++){
        cout << (*it).first << " " << (*it).second << endl;
    }
    
    if(mp.count(100) != 0) cout << "FOUND 100\n";
    if(mp.find(200) != mp.end()) cout << "FOUND 200\n";

    //----------------------
    mp.erase(200);
    if(mp.find(200) == mp.end()) cout << "NOT FOUND 200 after calling erase() function\n";

    return 0;
}