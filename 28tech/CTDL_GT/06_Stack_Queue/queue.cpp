#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ull long long

// FIFO: First in first out ---> O(1)
// push(), pop()
// front(), empty(), size()

// NOTE: giải các bài toán liên quan đến BFS (tìm đường đi ngắn nhất blabla), các bài toán mà vẽ yêu cầu bài toán ra dạng tree nhị phân được
// Hoặc là các dạng bài từ số A -> số B

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << endl;      // 1
    cout << q.size() << endl;       // 4
    q.pop();    // pop front element ra khỏi queue
    cout << q.front() << endl;      // 2

    return 0;
}