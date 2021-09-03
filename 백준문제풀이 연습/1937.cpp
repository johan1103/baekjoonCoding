#include<iostream>
#include<vector>

using namespace std;

int map[509][509]; //문제에서 제시된 맵 (최대크기 500에 맞춰서 조금 여유 있게 선언)
int memory[509][509]; //메모이제이션 할 메모리

int mapHeight; //맵의 높이
int mapWidth; //맵의 너비 (문제 제출 할때야 무조건 정사각형인거 알았음.....)

//맵을 상하좌우로 이동할 때, 편리하게 하기 위한 dx,dy
//ex) x+dx[0], y+dy[0]하면 현재위치에서 한칸 위로, x+dx[1], y+dy[1]하면 한칸 오른쪽으로 움직인거임
const int dx[4] = { 0,1,0,-1 };
const int dy[4] = { -1,0,1,0 };

int pandaRoot(int nx, int ny) {//nx, ny는 현재 판다가 있는 x,y좌표
	//방문한적 있으면 저장된 메모리 return
	if (memory[nx][ny] != -1)
		return memory[nx][ny];
	//result는 return할 결과값, 일단 방문한적 없고, 도착한것은 사실이니 1로 시작
	int result = 1;
	for (int i = 0; i < 4; i++) {
		//dx, dy의 4가지 경우의 수로 앞으로의 경로를 확인하기 위한 4번반복하는 for문
		if (nx + dx[i] <= 0 || nx + dx[i] > mapWidth)
			continue;
		if (ny + dy[i] <= 0 || ny + dy[i] > mapHeight)
			continue;
		//위의 continue는 맵의 밖을 벗어났을때의 예외 처리
		if (map[nx][ny] < map[nx + dx[i]][ny + dy[i]]) {
			//만약 인접지역의 대나무의 수가 현재 있는 구역의 대나무보다 많다면
			result = max(result, 1 + pandaRoot(nx + dx[i], ny + dy[i]));
			//해당 경로로 갔을 때 방문한 칸수와 현재까지 기록된 최대값을 비교해서 최대값 구하기
		}
	}
	//모두 계산된 result를 메모리에 저장
	memory[nx][ny] = result;
	return result;
}

//문제를 풀기 전에 미리 memory값을 -1로, map은 0으로 초기화
void setMemory() {
	for (int i = 0; i <= mapHeight; i++) {
		for (int j = 0; j <= mapWidth; j++) {
			memory[j][i] = -1;
			map[j][i] = 0;
		}
	}
	return;
}


int main() {
	int result = 0;
	cin >> mapHeight;
	mapWidth = mapHeight;
	setMemory();
	for (int i = 1; i <= mapHeight; i++) {
		for (int j = 1; j <= mapWidth; j++) {
			cin >> map[j][i];
		}
	}
	//모든 칸에서 시작해 보면서 최댓값을 구해야 하므로 2중 for문
	for (int i = 1; i <= mapHeight; i++) {
		for (int j = 1; j <= mapWidth; j++) {
			result = max(result, pandaRoot(j, i));
		}
	}
	cout << result;
	return 0;
}