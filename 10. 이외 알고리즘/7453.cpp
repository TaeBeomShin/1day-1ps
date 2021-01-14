/*
	https://www.acmicpc.net/problem/7453 ���� 0�� �� ����
	
	�������� ������ �̿��Ͽ� ������ Ǯ����
	(�ڷ����� long long�� �ƴ� int�� �Ἥ �����ɸ�..)
	
	1. �迭 2�� ���� ���� ���� ���Ѵ�.
	2. �� �迭�� ���� ��Ų��.
	3. �ѹ迭�� �տ������� �ٸ� �迭�� �ڿ������� start,end ������ ���� Ž���Ѵ�.
	   - ���� ������ start ++, ���� ������� end--;
	4. ���� 0�̸� ���� ���� �ִ��� Ž���Ѵ�.
	5. �̰����� �ݺ��ؼ� ���� ���Ѵ�.
	
	* �ڷ��� long long ���� int���� �ľ��ϱ�.
	* ��Ÿ �����ϱ�. 
*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

vector<int> A(4002),B(4002),C(4002),D(4002);
int main(){
	fastio;
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	
	vector<int> Group1;
	vector<int> Group2;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			Group1.push_back(A[i]+B[j]);
			Group2.push_back(C[i]+D[j]);
		}
	sort(Group1.begin(),Group1.end());
	sort(Group2.begin(),Group2.end());
	
	int index=n*n;
	int start=0,end=index-1;
	
	long long count=0,x,y;
	while(start<index&&end>=0){
		x=0,y=0;
		if(Group1[start]+Group2[end]==0){
			int s=start;
			while(Group1[start]+Group2[end]==0){
				if(start>=index) break;
				x++;
				start++;
			}
			while(Group1[s]+Group2[end]==0){
				if(end<0) break;
				y++;
				end--;
			}
			count=count+x*y;
		}else if(Group1[start]+Group2[end]<0){
			start++;	 
		}else end--;
	}
	cout<<count;
}
