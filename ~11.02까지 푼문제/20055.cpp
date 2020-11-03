#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

typedef pair<int, int> pii;

int main(){
	fastio;
	int n,k; cin>>n>>k;
	deque<int> belt(2*n),robot(2*n);
	for(int i=0;i<2*n;i++) cin>>belt[i];
	int count=0,level=0;
	
	while(count<k){
		level++;
		//1.��Ʈ�� �� ĭ ȸ���Ѵ�, ��������� �����ؾ���. 
		belt.push_front(belt.back());belt.pop_back();
		robot.push_front(robot.back());robot.pop_back();
		robot[n-1]=0; //n��° ĭ�� �ִ� �κ��� �����Ѵ�.
		 
		//2.���� ���� ��Ʈ�� �ö� �κ�����, ��Ʈ�� ȸ���ϴ� �������� �� ĭ �̵��� �� �ִٸ� �̵��Ѵ�. ���� �̵��� �� ���ٸ� ������ �ִ´�.
		priority_queue<pii,vector<pii>,greater<pii>> PQ;
		for(int i=0;i<n;i++) if(robot[i]) PQ.push({robot[i],i});
		
		while(!PQ.empty()){
			int i=PQ.top().second; PQ.pop();
			if(!robot[i+1]&&belt[i+1]){
				robot[i+1]=robot[i];
				robot[i]=0;
				belt[i+1]--;
				if(!belt[i+1]) count++;
			}
		}
		robot[n-1]=0;
		//3. �ø��� ĭ�� ����ְ�, �������� 0�� �ƴϸ�. 
		if(!robot[0]&&belt[0]){
			robot[0]=level;
			belt[0]--;
			if(!belt[0]) count++;
		}
	}
	cout<<level;
}
