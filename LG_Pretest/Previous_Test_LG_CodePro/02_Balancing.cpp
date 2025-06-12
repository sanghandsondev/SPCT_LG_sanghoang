// https://codepro.lge.com/exam/19/overseas-questions-for-previous-test/quiz/2%3Fembed?embed
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int N; // 상자의 크기
int Box[151][151];

void InputData() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Box[i][j];
		}
	}
}

int solve(){
    int maxSum = INT_MIN;
    int res = 0;
    for (int r = 0; r < N; r++){
        for(int c = 0; c < N; c++) {
            Box[r][N] += Box[r][c];
        }
    }
    for(int c = 0; c < N; c++){
        for(int r = 0; r < N; r++){
            Box[N][c] += Box[r][c];
        }
    }
    for(int i = 0; i < N; i++) {
        maxSum = max(maxSum, Box[i][N]);
        maxSum = max(maxSum, Box[N][i]);
    }
    for(int i = 0; i < N; i++) {
        res += (maxSum - Box[i][N]);
    }
    return res;
}

int main() {
	int ans = -1;
	InputData(); // 입력 받는 부분

	// 여기서부터 작성
    ans = solve();
	
	cout << ans << endl;// 출력하는 부분
	return 0;
}