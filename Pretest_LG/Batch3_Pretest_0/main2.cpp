#include <bits/stdc++.h>
using namespace std;

// Sau động đất thì vài con đường đã phải đóng cửa
// T nhóm được thnahf kapja, có thể di chuyển tới bất kì vùng ô nào nếu con đường cho phép 
// 2 nhóm được coi là SEPARATE COVERAGE ZONES nếu mà họ không thể tiếp cận nhau mà không phải đi qua ít nhất một con đường đóng
// Task: Đếm số cặp nhóm cứu hộ riêng biệt ở các vùng phủ sóng riêng biệt (Separate coverage zones)

int N;
long long T, R;
vector<pair<pair<int,int>, pair<int,int>>> closed_roads;
vector<pair<int,int>> teams;

void input(){
    cin >> N >> T >> R;
    for (int i = 0; i < R; i++){
        pair<pair<int,int>, pair<int,int>> road;
        cin >> road.first.first >> road.first.second >> road.second.first >> road.second.second;
        closed_roads.push_back(road);
    }
    for (int i = 0; i < T; i++){
        pair<int, int> team;
        cin >> team.first >> team.second;
        teams.push_back(team);
    }
}
int main(){
    return 0;
}