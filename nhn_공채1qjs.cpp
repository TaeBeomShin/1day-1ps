#include <iostream>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void solution(int sizeOfMatrix, int **matrix){
	// bfs Ǯ��
	int n=sizeOfMatrix;	int size,count=0;
	vector<int> v;
	// 1. ��� ���� ���������� �ؼ� ������ -> ��� �迭Ž��
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(matrix[i][j]==0) continue;//�湮�߰ų� ���Ұ� 0�̸� ���ư���.
	// 2. �������� �����ϸ� bfs�� �����ϰ�, ����� ���.
			count++;
			queue< pair<int,int> >q;
			q.push({i,j});// �������� �����Ѵ�.
			matrix[i][j]=0;// �������� �湮ǥ�ø� �Ѵ�.
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
			// 3. �ش� ������ ��� ������ Ž�������� ���� ���������� �̵��Ѵ�.
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
