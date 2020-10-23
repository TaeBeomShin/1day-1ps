#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solution(int sizeOfMatrix, int **matrix){
	// bfs 풀이
	int n=sizeOfMatrix;	int size,count=0;
	vector<int> v;
	// 1. 모든 곳을 시작점으로 해서 만들어본다 -> 모든 배열탐색
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==0) continue;//방문했거나 원소가 0이면 돌아간다.
	// 2. 시작점에 도달하면 bfs를 수행하고, 사이즈를 잰다.
			count++;
			queue< pair<int,int> >q;
			q.push({i,j});// 시작점을 대입한다.
			matrix[i][j]=0;// 시작점에 방문표시를 한다.
			size=0;
			
			while(!q.empty()){
				size++;
				auto cur=q.front(); q.pop();
				for(int dir=0;dir<4;dir++){
					int nx=cur.first+dx[dir];
					int ny=cur.second+dy[dir];
					if(nx<0|nx>=n|ny<0|ny>=n) continue;
					if(matrix[nx][ny]==0) continue;
					q.push({nx,ny});matrix[nx][ny]=0;
				}
			}
			v.push_back(size);
			// 3. 해당 영역의 모든 공간을 탐색했으면 다음 시작점으로 이동한다.
		}
	}
}

struct input_data {
  int sizeOfMatrix;
  int **matrix;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.sizeOfMatrix;

  inputData.matrix = new int*[inputData.sizeOfMatrix];
  for (int i = 0; i < inputData.sizeOfMatrix; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.matrix[i] = new int[inputData.sizeOfMatrix];
    for (int j = 0; j < inputData.sizeOfMatrix; j++) {
      iss >> inputData.matrix[i][j];
    }
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.sizeOfMatrix, inputData.matrix);
  return 0;
}
