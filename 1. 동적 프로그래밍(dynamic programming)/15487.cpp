#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005
#define INF 1e8
int num[MAX],ldp[MAX],rdp[MAX],n;
/*
	BOJ 15487 - �α������� ����� dp(����� ���������� ������ �ִ�?) 
	
	1. ���� �κ�(A[j]-A[i])�� ���� �ִ��� ������ ã�´�(0�ε��� ���� ã��) 
	
	2. ������ �κп���(A[L]-A[K])�� ���� �ִ��� ������ ã�´�(N-1 �ε��� ���� ã��) 
	
	3. ���� ���� �ִ밡 �ɶ��� ���� �����Ѵ�. 
*/
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>num[i];
	
	int maxn=-INF,minn=INF;
	ldp[0]=-INF;
	rdp[n-1]=-INF;
	
	for(int i=0;i<n-1;i++){
		if(i) ldp[i]=max(ldp[i-1],num[i]-minn);
		minn=min(minn,num[i]);
	}
	
	maxn=num[n-1];
	for(int i=n-2;i>1;i--){
		rdp[i]=max(rdp[i+1],maxn-num[i]);
		maxn=max(maxn,num[i]);
	}
	
	int ans=-INF;
	for(int i=1;i<n-1;i++) ans=max(ans,ldp[i]+rdp[i+1]);
	
	cout<<ans;
	
}
