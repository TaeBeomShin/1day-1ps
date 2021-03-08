#include<bits/stdc++.h>
using namespace std;

int root[100001];
void merge(int a,int b){
	x=find(x);
	y=find(y);
	//더 작은 값이 루트가 되게. 
	if(x>y) swap(x,y);
	root[y]=x;
}

void find(int a){
	if(a==root[a]) return a;
	else return find(root[a]);
}
int main(){
	int n;cin>>n;
	/*
		모든 행성을 터널로 연결하는 최소비용.
		두 행성 연결비용 min( abs(xa-xb),abs(ya-yb),abs(za-zb))
		
		최소 비용인 간선을 하나씩 선택, 사이클이 되면 제외
		-> 사이클인지 어떻게 판별? 부모가 달라야함. 
		
		1. 생길 수 있는 간선의 수 n^2 -> time out. 
		2. x좌표, y좌표, z좌표 정렬(행성 번호도 쌍으로 저장, 이웃한 점들 끼리만 간선 만듬 )
			(greedy 접근) 
	*/
	 
}
