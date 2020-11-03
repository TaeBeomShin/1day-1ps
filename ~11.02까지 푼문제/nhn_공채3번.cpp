#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

void solution(int day, int width, int **blocks) {
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	vector <int> v;//현재 상태를 저장하는 배열.
	//둘중에 더 낮은것 만큼 부을 수 있음. 
	for(int i=0;i<width;i++) v.push_back(blocks[0][i]);
	
	vector <int> getnum;
	for(int i=0;i<width;i++) getnum.push_back(0);
	//좌측에서 가장 높은것, 우측에서 가장 높은것 저장. 그중에서 큰값 저장.
	int sum=0;
	for(int i=1;i<width-1;i++){
		int left=0,right=0;
		for(int j=0;j<i;j++)
			left=max(v[j],left);
		for(int j=i;j<width;j++)
			right=max(v[j],right);
		getnum[i]=max(min(left,right)-v[i],0);
		v[i]+=getnum[i];
		sum+=getnum[i];
	}
	
	for(int i=1;i<day;i++){//공시기간 일수.
		for(int j=0;j<width;j++) v[j]+=blocks[i][j];
		for(int j=0;j<width;j++) getnum[j]=0;
	//좌측에서 가장 높은것, 우측에서 가장 높은것 저장. 그중에서 큰값 저장.
		for(int j=1;j<width-1;j++){
			int left=0,right=0;
			for(int k=0;k<j;k++)
				left=max(v[k],left);
			for(int k=j;k<width;k++)
				right=max(v[k],right);
			getnum[j]=max(min(left,right)-v[j],0);
			v[j]+=getnum[j];
			sum+=getnum[j];
		}
	}
	cout<<sum;
}

struct input_data {
  int day;
  int width;
  int **blocks;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.day;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.width;

  inputData.blocks = new int*[inputData.day];
  for (int i = 0; i < inputData.day; i++) {
    getline(cin, line);
    iss.clear();
    iss.str(line);
    inputData.blocks[i] = new int[inputData.width];
    for (int j = 0; j < inputData.width; j++) {
      iss >> inputData.blocks[i][j];
    }
  }
}

int main() {
	struct input_data inputData;
	process_stdin(inputData);

	solution(inputData.day, inputData.width, inputData.blocks);
	return 0;
}
