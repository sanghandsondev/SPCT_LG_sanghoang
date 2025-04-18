#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define ull long long

// Nguyên tắc khi sử dụng ĐỆ QUY: Hàm đệ quy phải có điểm dừng
// Kiểm tra 1 mảng có phải đối xứng hay không
// Ví dụ: 1 2 3 3 2 1      1 4 6 4 1

int palin(int a[], int l, int r){
    if (l >= r) return 1;       // Đã xét hết tất cả các cặp trong mảng
    if (a[l] != a[r]) 
        return 0;
    else 
        return palin(a, l+1, r-1);  // Xét cặp tiếp theo nếu cặp hiện tại thỏa mãn
}

int main(){
    int arr1[5] = {1, 4, 6, 3, 1};
    int arr2[5] = {1, 4, 6, 4, 1};
    cout << palin(arr1, 0, 4) << endl;
    cout << palin(arr2, 0, 4) << endl;
    return 0;
}