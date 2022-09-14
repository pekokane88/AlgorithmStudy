/*
 이 코드는 실패 코드입니다... 아이디어 Thinking중.
*/
#include<iostream>
#include<queue>
using namespace std;

int N, M;
int Hx, Hy;
int Ex, Ey;
int arr[1001][1001] = { 0 };
int cost[1001][1001] = { 0 };
int answer = 0;

struct node {
	int nowRow, nowCol;
	int canBreak = 1;
};

queue<node> qu;

void bfs(int Y, int X) {
	qu.push({ Y,X });
	cost[Hx][Hy] = 1;

	int dr[4] = { 0,-1, 0, 1 };
	int dc[4] = { -1, 0, 1, 0 };

	while (!qu.empty())
	{
		node now = qu.front(); qu.pop();
		int row = now.nowRow;
		int col = now.nowCol;
		int cB = now.canBreak;

		for (int i = 0; i < 4; i++) {
			int nextRow = row + dr[i];
			int nextCol = col + dc[i];
			if (nextRow < 0 || nextCol < 0 || nextRow >= N || nextCol >= M) continue;
			if (arr[nextRow][nextCol] == 1 && cB != 1) continue;
			if (cost[nextRow][nextCol] != 0 && cost[nextRow][nextCol] < cost[row][col] + 1) continue;
			if (arr[nextRow][nextCol] == 1) {
				qu.push({ nextRow, nextCol, 0 });
				cost[nextRow][nextCol] = cost[row][col] + 1;
			}
			else {
				qu.push({ nextRow,nextCol, cB });
				cost[nextRow][nextCol] = cost[row][col] + 1;
			}
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> Hx >> Hy >> Ex >> Ey;

	Hx -= 1; Hy -= 1;
	Ex -= 1; Ey -= 1;
	
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> arr[y][x];
		}
	}

	bfs(Hx, Hy);

	if (cost[Ex][Ey] == 0) cout << -1;
	else cout << cost[Ex][Ey] - 1;

	return 0;
}
