#include<iostream>

using namespace std;

#define MAX 1000001

int candy[MAX];//������ ���� ������ �迭. 
int tree[4*MAX];//������ ���� ������ ���׸�Ʈ Ʈ��. 

void update(int node,int start,int end,int index,int diff){
	int mid=(start+end)/2;
	if(start>index||end<index){
		//�ٱ������� �ε����� �������. Ż��. 
		return; 
	}
	tree[node]+=diff;
	if(start==end) return;
	update(2*node,start,mid,index,diff);
	update(2*node+1,mid+1,end,index,diff);

}

int query(int node,int start,int end,int seq){
	
	int mid=(start+end)/2;
	if(start==end){//����忡 �����ߴ�. 
		return start; 
	}
	if(seq<=tree[2*node]){//������ �������� ����, �ڽĳ�尡 �ִٸ�. 
		return query(node*2,start,mid,seq);
	}
	else if(seq>=tree[2*node+1]){//ã�� ���� �����ʿ� �ִ°��. 
		return query(node*2+1,mid+1,end,seq-tree[node*2]);//�����ڽ��� ���� �������. �ƴϸ� ������. 
	}
}

int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL);
	int N; cin>>N;
	

	for(int i=0;i<N;i++){
		int A,B,C;cin>>A;
		if(A==2){//update�� ����. 
			cin>>B>>C;
			candy[B]+=C;
			update(1,1,MAX,B,C);
		}
		else{//query�� update �������. 
			cin>>B;
			int index= query(1,1,MAX,B);
			cout<<index<<"\n";
			candy[index]--;
			update(1,1,MAX,index,-1);
		}
	}
	return 0;
}
