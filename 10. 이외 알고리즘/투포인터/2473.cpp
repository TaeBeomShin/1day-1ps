/*
	������ �ٸ� �������Ϳ� ���� ����.
	������ ���� int �ڷ��� ���� ���ϸ� longlong���� �Ⱥ��Ѵٴ°�. 
*/
#include<bits/stdc++.h>
using namespace std;

long long A[5001],n;
vector<int> v;

void input(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
}

void getAns(){
	sort(A,A+n);
	
	long long minn=3*1e9+1;
	int v1,v2,v3;
	for(int i=0;i<n;i++){
		int start=0,end=n-1;
		long long sum=0;
		while(start<end){
			//���� ��� �� ��� ���� 
			sum=A[i]+A[start]+A[end];
			if(start==i){
				start++;
				continue;
			}else if(end==i){
				end--;
				continue;
			}
			if(abs(sum)<minn){
				minn=abs(sum);
				v1=i,v2=start,v3=end;
			}
//			cout<<A[start]<<" "<<A[end]<<" "<<A[i]<<" "<<sum<<"\n";
			if(sum==0){
				v.push_back(i);
				v.push_back(start);
				v.push_back(end);
				return;
			}else if(sum<0){
				start++;
			}else{
				end--;
			}
		}
		
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
}
int main(){
	input();
	getAns();
	for(int i=0;i<3;i++) cout<<A[v[i]]<<" ";
}
