/*
  1. bool_attach : 그 좌표에서 n*n 사이즈의 색종이를 붙일 수 있는지 확인하는 함수.
  2. update_board : 색종이를 붙였다고 board에 표시하는 함수. (중복 방문 방지)
  3. dfs : board[y][x] 가 1인 좌표에서 색종이를 붙이고 다음 좌표로 넘어간다. 계속 하면서 지금까지 붙인 색종이 개수보다 더 작은 값이 있으면
           그 값으로 min_ans 를 갱신한다.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_SIZE 10
using namespace std;

int paper_cnt[6] = { 0 };
int board[MAX_SIZE][MAX_SIZE] = { 0 };
int one_count = 0;
int min_ans;

bool can_attach(int x, int y, int size) {
	register int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (!board[y + i][x + j]) {
				return false;
			}
		}
	}	
	return true;
}

void update_board(int x, int y, int size, int is_attach) {
	register int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			board[y + i][x + j] = is_attach;
		}
	}
	return;
}

//attach_cnt 는 색종이를 사용한 총 개수
void dfs(int x, int y, int attach_cnt) {
	while (!board[y][x]) {
		if (++x >= MAX_SIZE) {
			if (++y >= MAX_SIZE) {
				min_ans = min(min_ans, attach_cnt);
				return;
			}
			x = 0;
		}
	}

	if (min_ans <= attach_cnt) return;
	
	for (int size = 5; size > 0; size--) {
		if (x + size > MAX_SIZE || y + size > MAX_SIZE || paper_cnt[size] == 5) continue;
		
		if (can_attach(x, y, size)) {
			update_board(x, y, size, 0);
			paper_cnt[size] += 1;

			dfs(x, y, attach_cnt + 1);

			update_board(x, y, size, 1);
			paper_cnt[size] -= 1;
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	register int i, j;
	min_ans = 987654321;

	for (i = 0; i < MAX_SIZE; i++) {
		for (j = 0; j < MAX_SIZE; j++) {
			cin >> board[i][j];
			if (board[i][j]) one_count += 1;
		}
	}
	
	if (one_count == MAX_SIZE * MAX_SIZE) {
		cout << 4;
		return 0;
	}

	dfs(0, 0, 0);
	if (min_ans == 987654321) {
		cout << -1;
		return 0;
	}
	cout << min_ans;
	int de = 1;

	return 0;
}
