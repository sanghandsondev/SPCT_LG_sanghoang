// https://codepro.lge.com/exam/19/overseas-questions-for-previous-test/quiz/3?embed
// MỚI ĐÚNG ĐƯỢC 1 NỬA, HIC
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define MAX_RC	(100)

int R, C;
char grid[MAX_RC][MAX_RC + 1];
int sx, sy;
bool visited[MAX_RC][MAX_RC + 1];
int step[MAX_RC][MAX_RC + 1];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};  // right left bottom top
int result;
unordered_map <int, int> mp;

bool check(){
    for(auto it : mp) {
        if (it.second == 2) return false;
    }
    return true;
}

void Input_Data(void) {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for(int c = 0; c < C; c++){
            cin >> grid[r][c];
            if (grid[r][c] == 'S') {
                sx = r; sy = c;
            } else if (grid[r][c] != '*' && grid[r][c] != '.') {
                int num = grid[r][c] - '0';
                mp[num] = 2;
            }
        }
	}
}

pair<int,int> bfs(int x, int y){
    memset(visited, false, sizeof(visited));
    memset(step, 0, sizeof(step));
    
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    step[x][y] = 0;
    
    while(!q.empty()){
        pair<int,int> tm = q.front(); q.pop();
        int x1 = tm.first;
        int y1 = tm.second;
        // cout << "Get: " << x1 << " " << y1 << endl;
        for(int k = 0; k < 4; k++){
            int x2 = x1 + dx[k];
            int y2 = y1 + dy[k];
            if (x2 >= 0 && y2 >= 0 && x2 < R && y2 < C && visited[x2][y2] == false && grid[x2][y2] != '*') {
                // ---- enough -------
                if (check()) {
                    // if Start point
                    if (grid[x2][y2] == 'S') {
                        // cout << "A" << endl;
                        result += step[x1][y1] + 1;
                        return {-1, -1};
                    // if not -> push
                    } else {
                        q.push({x2,y2});
                        step[x2][y2] = step[x1][y1] + 1;
                        visited[x2][y2] = true;
                    }
                // ---- not enough ------
                } else {
                    // if Explo planet
                    if (grid[x2][y2] >= '0' && grid[x2][y2] <= '9') {
                        result += step[x1][y1] + 1;
                        int num = grid[x2][y2] - '0';
                        mp[num] = 1;
                        grid[x2][y2] = '.';
                        return {x2, y2};
                    // if not -> push
                    } else {
                        q.push({x2,y2});
                        step[x2][y2] = step[x1][y1] + 1;
                        visited[x2][y2] = true;
                    }
                }
            }
        }
    }
    return {-1, -1};
}

int solve(){
    result = 0;
    pair<int,int> point = {sx,sy};
    while(point.first != -1) {
        point = bfs(point.first, point.second);
    }
    return result;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int sol = -1;
	Input_Data();
    sol = solve();
	cout << sol << '\n';
	return 0;
}