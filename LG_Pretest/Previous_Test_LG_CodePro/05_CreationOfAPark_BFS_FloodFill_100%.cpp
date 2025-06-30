// https://codepro.lge.com/exam/19/overseas-questions-for-previous-test/quiz/5%3Fembed?embed
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define MAXN (100)

int N;
char grid[MAXN + 10][MAXN + 10];
bool visited[MAXN + 10][MAXN + 10];

char ans;//구매자 이름 Buyer's name
int areacnt;//구매자 영역 개수 Number of buyer's area

int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
		    cin >> grid[i][j];
	    }
	}
}

int bfs(int i, int j, char c){
    int count = 0;
    
    queue<pair<int,int>> q;
    q.push({i,j});
    visited[i][j] = true;
    count++;
    while(!q.empty()){
        pair<int,int> tmp = q.front(); q.pop();
        int i1 = tmp.first;
        int j1 = tmp.second;
        for(int k = 0; k < 4; k++){
            int i2 = i1 + dx[k];
            int j2 = j1 + dy[k];
            if (i2 >= 0 && i2 < N && j2 >= 0 && j2 < N && visited[i2][j2] == false && grid[i2][j2] == c) {
                q.push({i2,j2});
                visited[i2][j2] = true;
                count++;
            }
        }
    }
    
    return count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();// 입력받는 부분 Input

	// 여기서부터 작성 Write from here
    memset(visited, false, sizeof(visited));
    int cnt[3] = {0};
    int area[3] = {0};
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if (visited[i][j] == false) {
                if (grid[i][j] == 'R') {
                    cnt[0]++;
                    area[0] += bfs(i,j,grid[i][j]);
                } else if (grid[i][j] == 'G') {
                    cnt[1]++;
                    area[1] += bfs(i,j,grid[i][j]); 
                } else if (grid[i][j] == 'B') {
                    cnt[2]++;
                    area[2] += bfs(i,j,grid[i][j]);
                }
            }
        }
    }
    // cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << endl;
    // cout << area[0] << " " << area[1] << " " << area[2] << endl;
    int res = 0, zone_max = INT_MIN, area_max = INT_MIN;
    for(int i = 0; i < 3; i++){
        if (cnt[i] > zone_max) {
            zone_max = cnt[i];
            res = i;
            area_max = area[i];
        } else if (cnt[i] == zone_max) {
            if (area[i] > area_max) {
                res = i;
                area_max = area[i];
            }
        }
    }
    if (res == 0) {
        ans = 'R';
    } else if (res == 1) {
        ans = 'G';
    } else ans = 'B';
    areacnt = cnt[res];
    
	cout << ans << " " << areacnt << "\n";// 출력하는 부분 Output
	return 0;
}