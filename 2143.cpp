#include<iostream>
#include<algorithm>
#include<vector> 
using namespace std;

int lowerbound(vector<long long>& array,int value){
	int start=0;
	int end=array.size();

	while(end>start)
	{
		int mid=(start+end)/2;
		if(array[mid]>=value)
			end=mid;
		else start =mid+1;
	}
	return end;
}

int upperbound(vector<long long>& array,int value){
	int start=0;
	int end=array.size();

	while(end>start)
	{
		int mid=(start+end)/2;
		if(array[mid]>value)
			end=mid;
		else start =mid+1;
	}
	return end;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    
	int T;
	int n,m;
	cin>>T>>n;
	int A[n];vector<long long> subA;
	//원소의 개수가 n인 배열에대한 부분합은 n(n+1)/2 개 
	for(int i=0;i<n;i++) cin>>A[i];
	cin>>m;
	int B[m];vector<long long> subB;
	for(int i=0;i<m;i++) cin>>B[i];
	
	//subA를 구한다.
	for(int i=0;i<n;i++){
		long long sum=A[i];
		subA.push_back(sum);
		for(int j=i+1;j<n;j++){
			sum+=A[j];
			subA.push_back(sum);
		}
	}
	
	//subB를 구한다. 
	for(int i=0;i<m;i++){
		long long sum=B[i];
		subB.push_back(sum);
		for(int j=i+1;j<m;j++){
			sum+=B[j];
			subB.push_back(sum);
		}
	}

	sort(subB.begin(),subB.end());
	
	long long result=0;
	for(int i=0;i<subA.size();i++){
		int value= T-subA[i];
		long long ub=upperbound(subB,value);
		long long lb=lowerbound(subB,value);
		result+=ub-lb;
	
	}
	cout<<result;
	 
	return 0;
}


