#include<bits/stdc++.h>
using namespace std;
/*
	BOJ 20181 ��Ʋ��Ʋ ȣ������, �������� + DP
	 
	��� 1. Ż�� �������� �ִ밡�ǵ��� �ϴ� ��츦 ��� Ž��. -> 2^N 
	 -> N�� ������ Ŀ���� n log n �Ǵ� O(n) ���� �ذ��ؾ���.
	 
	��� 2. �������� + DP �̿�. 
	-> dp[i]�� i��°���� ���� �� �ִ� �ִ� ����Ż�ǿ������� ����
	-> && k�� �������� �������͸� ���� Ż�ǿ����� ���� ����. 

*/

long long dp[100001],arr[100001]; 
int main(){
	long long n,k;cin>>n>>k;

	for(int i=1;i<=n;i++)
		cin>>arr[i];
		
	long long sum=0; 
	for(int start=0,end=1;end<=n;end++){
		sum+=arr[end];
		dp[end]=dp[end-1];
		while(sum>=k){
			dp[end]=max(dp[end],dp[start]+sum-k);
			sum-=arr[++start];
		}
	}
	cout<<dp[n];
	
}
