#include<iostream>

using namespace std;

typedef long long ll;

int A[100001]={0,};
ll tree[400001]={0,};

ll maketree(int node,int start,int end){
	int mid=(start+end)/2;
	
	if(start==end){//리프노드에 도달했을 경우. 
		return tree[node]=A[start];
	}
	tree[node]=maketree(node*2,start,mid)+maketree(node*2+1,mid+1,end);
	
	return tree[node];
}

void update(int node,int start,int end,int index,ll diff){

	if(start<=index&&index<=end)//index가 사이에 있을때. 
		tree[node]+=diff;
	else// 아예 바깥에 있을때. 
		return;
	if(start==end) return;
	int mid=(start+end)/2;
	update(node*2,start,mid,index,diff);
	update(node*2+1,mid+1,end,index,diff);
}

ll query(int node,int start,int end,int qstart,int qright){
	
	int mid=(start+end)/2;
	
	if(start>qright||end<qstart){//구간이 어느곳에도 속하지 않을경우. 
		return 0;
	}
	else if(start>=qstart&&end<=qright){//구간이 완전히 속하는 경우. 
		return tree[node];
	}
	return query(node*2,start,mid,qstart, qright)+query(node*2+1,mid+1,end,qstart,qright);
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int N,Q;
	cin>>N>>Q;
	for(int i=1;i<=N;i++) cin>>A[i];
	
	maketree(1,1,N);
	
	long long x,y,a,b;//b를 longlong으로 선언안하면 틀림. 
	
	for(int i=0;i<Q;i++){
		cin>>x>>y>>a>>b;
		if(y>x)
			cout<<query(1,1,N,x,y)<<"\n";
		else
			cout<<query(1,1,N,y,x)<<"\n";

		update(1,1,N,a,b-A[a]);
		A[a]=b;
	}
	
	return 0;
}
