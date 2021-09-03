#include<iostream>
#include<vector>

using namespace std;

int map[509][509]; //제공 되는 맵의 최대 크기
int memory[509][509]; //메모이제이션 할 메모리들 (맵의 위치에 따라 메모이제이션할거라서)
int mapWidth; //제공되는 맵의 너비
int mapHeight; //제공되는 맵의 높이

const int dx[4] = { 0, 1, 0, -1 }; //위, 오른쪽, 아래, 왼쪽으로 움직이게 할 좌표
const int dy[4] = { -1, 0, 1, 0 }; // ex) x좌표에 +dx[0], y좌표에 +dy[0] 하면 위로 이동.


int downTown(int nx, int ny) {
	if (memory[nx][ny] != -1) //방문한 적 있는 좌표이면 저장된 메모리를 return
		return memory[nx][ny];
	if (nx == mapWidth && ny == mapHeight) {
		return 1; //목적지에 제대로 도달 했으면, 경우의 수를 완성한 것이므로 1 return
	}
	int nowNum = map[nx][ny]; //map[nx][ny]를 자주사용해서, 헷갈리지 않기 위해 변수에 저장
	int result = 0; //모든 경우의 수를 result에 저장해서 return
	for (int i = 0; i < 4; i++) { //위 오른쪽 아래 왼쪽으로 가는 경우의 수를 고려한 for문
		if (nx + dx[i] <= 0 || nx + dx[i] > mapWidth)
			continue;
		if (ny + dy[i] <= 0 || ny + dy[i] > mapHeight)
			continue;
		//맵의 밖을 벗어나면 continue로 예외 처리
		if (map[nx + dx[i]][ny + dy[i]] < nowNum) {
			// 현재 좌표의 값이 다음 위치로 가려는 좌표값보다 크면 재귀 호출해서 result에 저장
			result += downTown(nx + dx[i], ny + dy[i]);
		}
	}
	//메모리에 계산완료한 result값 저장
	memory[nx][ny] = result;
	return result;
}

//문제풀기 전에 미리 방문하지 않은 메모리 -1로 초기화
void setMemory() {
	for (int i = 0; i <= mapHeight; i++) {
		for (int j = 0; j <= mapWidth; j++) {
			memory[j][i] = -1;
			map[j][i] = 0;
		}
	}
}


int main() {
	cin >> mapHeight >> mapWidth;
	//메모리 초기화
	setMemory();
	for (int i = 1; i <= mapHeight; i++) {
		for (int j = 1; j <= mapWidth; j++) {
			cin >> map[j][i];
		}
	}
	//1,1에서 출발.
	cout << downTown(1, 1);

	return 0;
}