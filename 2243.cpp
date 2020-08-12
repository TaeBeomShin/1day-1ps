#include<iostream>

using namespace std;

#define MAX 1000001

int candy[MAX];//사탕의 개수 저장할 배열. 
int tree[4*MAX];//사탕의 개수 저장할 세그먼트 트리. 

void update(int node,int start,int end,int index,int diff){
	int mid=(start+end)/2;
	if(start>index||end<index){
		//바깥범위에 인덱스가 있을경우. 탈출. 
		return; 
	}
	tree[node]+=diff;
	if(start==end) return;
	update(2*node,start,mid,index,diff);
	update(2*node+1,mid+1,end,index,diff);

}

int query(int node,int start,int end,int seq){
	
	int mid=(start+end)/2;
	if(start==end){//끝노드에 도달했다. 
		return start; 
	}
	if(seq<=tree[2*node]){//작으면 왼쪽으로 간다, 자식노드가 있다면. 
		return query(node*2,start,mid,seq);
	}
	else if(seq>=tree[2*node+1]){//찾는 것이 오른쪽에 있는경우. 
		return query(node*2+1,mid+1,end,seq-tree[node*2]);//왼쪽자식의 값을 빼줘야함. 아니면 에러남. 
	}
}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	int N; cin>>N;
	

	for(int i=0;i<N;i++){
		int A,B,C;cin>>A;
		if(A==2){//update만 해줌. 
			cin>>B>>C;
			candy[B]+=C;
			update(1,1,MAX,B,C);
		}
		else{//query와 update 모두해줌. 
			cin>>B;
			int index= query(1,1,MAX,B);
			cout<<index<<"\n";
			candy[index]--;
			update(1,1,MAX,index,-1);
		}
	}
	return 0;
}
