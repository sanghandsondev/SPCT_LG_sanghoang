#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ull long long

// LIFO: Last in first out
// push, pop, top, size, empty
// O(1)
// Bài toán: kiểm tra dấu ngoặc hợp lệ
// Ví dụ: (()) ,  ()()   --> thỏa mãn
//        ((()) ,  ()()) --> ko thỏa mãn; 
// Hướng dẫn: Khi là '(' thì push vào stack, khi là ')' thì kiểm tra và pop nếu thỏa mãn

bool solve(string s){
    stack<char> st;
    for (char x : s){
        if (x == '('){
            st.push(x);
        } else {    // ')'
            if (st.empty()){
                return false;   // stack mà rỗng chứng tỏ trước đó k có kí tự '(' thừa, mà có kí ')' xuất hiện -> false
            } else 
                st.pop();
        }
    }
    if (st.empty())
        return 1;
    else
        return 0;       // trường hợp vẫn còn kí tự '(' ở trong stack -> false
}

int main(){
    string s1 = "(()())";       // valid
    string s2 = "(()()))";      // invalid
    if (solve(s1)) cout << "VALID\n"; else cout << "INVALID\n";
    if (solve(s2)) cout << "VALID\n"; else cout << "INVALID\n";
    
    return 0;
}