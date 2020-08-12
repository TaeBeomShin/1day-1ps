//보석의 개수
//보석의 무게와 가격(무게와 가격을 가지는 객체로 생성) 
//K개의 가방 각 가방의 무게다름, 최대 한개의 보석. 
//훔칠 수 있는 보석의 최대가격 구하기.
//how? 간단히 생각해봤을 경우.
//보석을 가격을 기준으로 정렬.(1.가격, 2무게)
//가장은 무게를 기준으로정렬. 
//
//가격을 기준으로 선택하고,무게를 기준으로 정렬한다.
//가벼운가방에 먼저 집어넣는다. 무게때문에 못넣는게 있다면 다시 선택?

//힙구조를 어떻게 활용할 수 있을까? 우선순위 큐 구조. 
//
//큐에서 하나씩 꺼집어내면서 가장 비슷한 가방에 넣는다.
//모든 가방의 용량보다 크다면 버린다. 
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

pair<int,int> jewelry[300000];
priority_queue<int> pq;

int main(){
	int N,K;
//1. 값을 입력받는다. 
	cin>>N>>K;
	int bag[K];
	int m,v;
	for(int i=0;i<N;i++){
		cin>>jewelry[i].first>>jewelry[i].second;	
}
	for(int i=0;i<K;i++){
		cin>>bag[i];
	}
	
	sort(bag,bag+K);
	sort(jewelry,jewelry+N);
	
	long long result=0;
	int idx=0;
	
	for(int i=0;i<K;i++){
		//일반적인 그리디 알고리즘 코드. 
		while(idx<N&&jewelry[idx].first<=bag[i]){
		//while문 사용에 익숙해지자. 조건이 여러개인 상황에서 쓰면 좋음. 
		//i번째 가방보다 가벼운 보석들을 모두 꺼낼때 까지. 
			pq.push(jewelry[idx++].second);
		}
		if(!pq.empty()){
		//우선순위 큐를 최대힙으로 저장했기때문에, 꺼낼때마다 그 케이스의 최대 값을꺼내오게 된다. 
			result+=pq.top();
			pq.pop();
		}
	}
	cout<<result<<"\n";

	return 0;
	
}
 
