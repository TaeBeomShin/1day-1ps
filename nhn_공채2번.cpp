#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

void solution(int numOfAllPlayers, int numOfQuickPlayers, char *namesOfQuickPlayers, int numOfGames, int *numOfMovesPerGame) {
	fastio;
  // TODO: �̰��� �ڵ带 �ۼ��ϼ���. �߰��� �ʿ��� �Լ��� ���������� �����ؼ� ����ϼŵ� �˴ϴ�.
	//(6<=���ӿ� �����ϴ� �����<=26, 0<�޸��Ⱑ ���� ������ �ɸ��� �ʴ� ���<=n/2, �޸��Ⱑ ���� ����� �̸�, ��������Ƚ��<=100, -100<=������ �̵��ϴ� ĭ��<=100)
	int n=numOfAllPlayers;
	int m=numOfQuickPlayers;
	vector <int> v;//������ �ɸ�Ƚ���� ������ ����.
	vector <char> v2; // ���� ������ ���¸� ������ ����.
	for(int i=0;i<n;i++) v.push_back(0); //�ʱ�ȭ ��Ų��.
	for(int i=0;i<n-1;i++){
		char t='B'+i;
		v2.push_back(t); //�������� �ʱ�ȭ
	}// 2.ù��° ���ӿ����� A�� ����, ���׶��� �ɾ�����
	
	char man='A'; //������ ������ ����.
	v[0]++;
	int cur=0;
	
	for(int i=0;i<numOfGames;i++){
		int next=(cur+numOfMovesPerGame[i])%(n-1);
		if(next<0) next=next+(n-1);
		bool check=false;
		for(int j=0;j<m;j++){//�޸��Ⱑ ���� ������� Ȯ��.
			if(v2[next]==namesOfQuickPlayers[j])check=true;	
		}
		if(check){
			v[man-'A']++;//���� ������ ����� ����Ƚ���� �þ��.
			cur=next;
		}
		else{//2.�޸��� ��������� �ƴ� ���.
			cur=next;//������ �ٲ��.
			char temp=v2[cur];
			v2[cur]=man;
			man=temp;
			v[man-'A']++;
		}
		cout<<v2[cur]<<" "<<man<<"\n";
	}
	// 	2-5.������ ���� �޸��� ������ ����̸� �ð���� �����̸� �ݽð����.
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
