#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Multiset tương tự như set nhưng có thể lưu trữ nhiều phần tử có cùng giá trị (vẫn sắp xếp theo thứ tự tăng dần)
// -> Khác với set một chút về hàm find, count, erase.

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    multiset<int> se;
    se.insert(1);
    se.insert(1);
    se.insert(3);
    se.insert(1);
    se.insert(2);
    se.insert(2);
    se.insert(4);   //1 1 1 2 2 3 4
    
    for (auto x : se){
        cout << x << " ";
    }
    cout << endl;
    
    auto it = se.find(2);     // first to come
    cout << distance(se.begin(), it) << endl;

    cout << se.count(2) << endl;
    // ---------- Erase() -----------------------
    se.erase(2);    // 1 1 1 3 4 : xoa het cac phan tu co gia tri la 2
    for (auto x : se){
        cout << x << " ";
    }
    cout << endl;

    auto it2 = se.find(1);   // first to come
    se.erase(it2);      // 1 1 3 4: xoa het phan tu dau tien co gia tri la 1
    for (auto x : se){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}