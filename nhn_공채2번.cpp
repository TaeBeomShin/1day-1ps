#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	fastio;
  // TODO: 이곳에 코드를 작성하세요. 추가로 필요한 함수와 전역변수를 선언해서 사용하셔도 됩니다.
	//(6<=게임에 참여하는 사람수<=26, 0<달리기가 빨라 술래에 걸리지 않는 사람<=n/2, 달리기가 빠른 사람의 이름, 게임진행횟수<=100, -100<=술래가 이동하는 칸수<=100)
	int n=numOfAllPlayers;
	int m=numOfQuickPlayers;
	vector <int> v;//술래를 걸린횟수를 저장할 벡터.
	vector <char> v2; // 현재 원형의 상태를 저장할 벡터.
	for(int i=0;i<n;i++) v.push_back(0); //초기화 시킨다.
	for(int i=0;i<n-1;i++){
		char t='B'+i;
		v2.push_back(t); //원형상태 초기화
	}// 2.첫번째 게임에서는 A가 술래, 동그랗게 앉아있음
	
	char man='A'; //술래를 저장할 변수.
	v[0]++;
	int cur=0;
	
	for(int i=0;i<numOfGames;i++){
		int next=(cur+numOfMovesPerGame[i])%(n-1);
		if(next<0) next=next+(n-1);
		bool check=false;
		for(int j=0;j<m;j++){//달리기가 빠른 사람인지 확인.
			if(v2[next]==namesOfQuickPlayers[j])check=true;	
		}
		if(check){
			v[man-'A']++;//현재 술래인 사람의 술래횟수가 늘어난다.
			cur=next;
		}
		else{//2.달리기 빠른사람이 아닌 경우.
			cur=next;//술래가 바뀐다.
			char temp=v2[cur];
			v2[cur]=man;
			man=temp;
			v[man-'A']++;
		}
		cout<<v2[cur]<<" "<<man<<"\n";
	}
	// 	2-5.술래가 원을 달리는 방향은 양수이면 시계방향 음수이면 반시계방향.
	for(int i=0;i<v2.size();i++) cout<<v2[i]<<" "<<v[v2[i]-'A']<<"\n";
	cout<<man<<" "<<v[man-'A'];
}

struct input_data {
  int numOfAllPlayers;
  int numOfQuickPlayers;
  char *namesOfQuickPlayers;
  int numOfGames;
  int *numOfMovesPerGame;
};

void process_stdin(struct input_data& inputData) {
  string line;
  istringstream iss;

  getline(cin, line);
  iss.str(line);
  iss >> inputData.numOfAllPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfQuickPlayers;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.namesOfQuickPlayers = new char[inputData.numOfQuickPlayers];
  for (int i = 0; i < inputData.numOfQuickPlayers; i++) {
    iss >> inputData.namesOfQuickPlayers[i];
  }

  getline(cin, line);
  iss.clear();
  iss.str(line);
  iss >> inputData.numOfGames;

  getline(cin, line);
  iss.clear();
  iss.str(line);
  inputData.numOfMovesPerGame = new int[inputData.numOfGames];
  for (int i = 0; i < inputData.numOfGames; i++) {
    iss >> inputData.numOfMovesPerGame[i];
  }
}

int main() {
  struct input_data inputData;
  process_stdin(inputData);

  solution(inputData.numOfAllPlayers, inputData.numOfQuickPlayers, inputData.namesOfQuickPlayers, inputData.numOfGames, inputData.numOfMovesPerGame);
  return 0;
}
