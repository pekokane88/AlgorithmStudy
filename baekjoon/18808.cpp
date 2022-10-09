/*
  주어진 맵에서 차례대로 스티커를 붙이는 문제.
  만약에 위, 왼쪽부터 차례대로 스티커를 붙여나간다는 조건이 없었다면 재귀, 완탐 등을 이용해서 풀어야 했을 것이라고 생각됨.
  하지만 조건이 있기 때문에, 왼쪽위에서부터 주어진 스티커들을 차례대로 붙여 나간다. 그리고 0,90,180,270 도 상태에서 붙일 수 있다면 맵을 갱신하고, 그것이 아니라면 버린다.
  무조건 왼쪽 위부터가 기준이기 때문에, 전체 맵에서 왼쪽 위를 기준으로 스티커 사이즈를  비교해 나간다.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, M, K, R, C;
int MAP[41][41] = { 0 };
vector<vector<int>> sticker;

void rotateSticker(void) {
	int newR = C; int newC = R;
	vector<vector<int>> temp(newR + 1, vector<int>(newC + 1, 0));
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			temp[i][R - 1 - j] = sticker[j][i];
		}
	}
	sticker = temp;
	R = newR;
	C = newC;
	return;
}

bool canAttach(int Y, int X) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (sticker[i][j] == 1 && MAP[i + Y][j + X] == 1)
				return false;
		}
	}
	return true;
}

void Attach(int Y, int X) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (sticker[i][j] == 1) {
				MAP[i + Y][j + X] = 1;
			}
		}
	}
	return;
}

bool attachSticker(void) {
	for (int i = 0; i < (N - R + 1); i++) {
		for (int j = 0; j < (M - C + 1); j++) {
			if (canAttach(i, j)) {
				Attach(i, j);
				return true;
			}
		}
	}
	return false;
}

void calcMap(void) {
	int one_cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 1) one_cnt += 1;
		}
	}
	cout << one_cnt;
	return;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	register int i, j, k;

	for (i = 0; i < K; i++) {
		cin >> R >> C;
		sticker = vector<vector<int>>(R + 1, vector<int>(C + 1, 0));

		for (j = 0; j < R; j++) {
			for (k = 0; k < C; k++) {
				cin >> sticker[j][k];
			}
		}

		bool isAttach = attachSticker();
		if (isAttach) continue;

		for (k = 0; k < 3; k++) {
			rotateSticker();
			isAttach = attachSticker();
			if (isAttach) break;
		}
	}

	calcMap();
	int de = 1;
	return 0;
}
