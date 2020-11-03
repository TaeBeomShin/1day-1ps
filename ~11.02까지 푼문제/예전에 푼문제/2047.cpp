#include<iostream>
using namespace std;

typedef long long ll;

long long tree[3000001];
long long A[1000001];

ll maketree(int node,int start,int end)
{
	if(start==end){
		//leaf 노드에 도달했을 경우.
		return tree[node]=A[start];//해당되는 인덱스에 값을 넣는다. 
	}
	int mid=(start+end)/2;
	//내부 노드들의 값 정리. 
	tree[node]=maketree(node*2,start,mid)+maketree(node*2+1,mid+1,end);
	return tree[node];
}

ll query(int node,int start,int end,int qleft,int qright){
	if(qright<start||qleft>end) return 0;//완전히 벗어 날 경우. 
	else if(qleft<=start&&qright>=end) return tree[node]; //완전히 포함될 경우. 
	// 사이에 있을 경우.
	int mid=(start+end)/2;
	
	return query(node*2,start,mid,qleft,qright)+query(node*2+1,mid+1,end,qleft,qright); 
}

void update(int node,int start,int end,int index,ll diff){//값을 갱신해 준다.
	if(start<=index&&index<=end)//index가 사이에 있을때. 
		tree[node]+=diff;
	else// 아예 바깥에 있을때. 
		return;
	if(start==end) return;
	int mid=(start+end)/2;
	update(node*2,start,mid,index,diff);
	update(node*2+1,mid+1,end,index,diff);
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M,K;
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++){
		cin>>A[i];
	}
	maketree(1,1,N);
	
	for(int i=0;i<(M+K);i++){
		int input1,input2;
		ll input3;
		cin>>input1>>input2>>input3;
		
		if(input1==1)
		{
			ll diff=input3-A[input2];
			update(1,1,N,input2,diff);
			A[input2]=input3;
		}
		else if(input1==2)
			cout<<query(1,1,N,input2,input3)<<"\n";
	}
	
	return 0;
} 
