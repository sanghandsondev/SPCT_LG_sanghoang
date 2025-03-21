#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ull long long

// =================== Priority_Queue == Tính chất có vẻ khá giống với multiset ===================================
// top() -> truy cập phần tử ở đầu, mặc định là lớn nhất
// pop() -> xóa phần tử ở đầu (phần tử lớn nhất hiện tại trong queue)
// push()
// size(), empty()

// NOTE: Priority_queue nhanh hơn multiset một tí
// Khi nào sử dụng: Khi mà luôn muốn tìm đến thằng nhỏ nhất / lớn nhất trong mảng mà vị trí của nó biến thiên liên tục

int main(){
    // ------ Mặc định ưu tiên thằng lớn nhất ---------------------
    priority_queue<int> pq;
    pq.push(1);
    pq.push(4);
    pq.push(3);
    pq.push(5);
    cout << pq.top() << endl;  // 5

    pq.push(100); 
    pq.push(30);
    cout << pq.top() << endl;  // 100

    pq.pop();  // xóa 100
    cout << pq.top() << endl;  // 309

    // ------ Chuyển sang ưu tiên get ra thằng nhỏ nhất ------------
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(1);
    pq2.push(4);
    pq2.push(3);
    pq2.push(5);
    cout << pq2.top() << endl;  // 1

    pq2.push(0); 
    pq2.push(30);
    cout << pq2.top() << endl;  // 0

    pq2.pop();  // xóa 0
    cout << pq2.top() << endl;  // 1

    return 0;
}