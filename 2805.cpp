#include<iostream>
#include<algorithm>

using namespace std;

int N,M;
//주어진 M에 가장 근접한 값을 구하는 binary search. 
int main(){
	
	cin>>N>>M;
	
	int tree[N];
	int max=0;
	for(int i=0;i<N;i++){
		cin>>tree[i];
		if(tree[i]>max) max=tree[i];
	}
	sort(tree,tree+N);
	
	
	int start=0;
	int end=max;
	int mid;
	int result=0;
	
	long long sum=0;
	
	while(true){
		mid=(start+end)/2;
		//나무를 잘라내고 합을 구한다.
		sum=0;
		for(int i=0;i<N;i++){
			if(tree[i]-mid>0) sum+=tree[i]-mid;
		}
		//잘라낸 총 나무의 길이를 기준으로 탐색을 한다.
		//1.잘라낸 나무의 길이가 M값과 같으면 
		if(sum==M){
			result=mid;
			break;
		}
		//2.잘라낸 나무의 길이가 M값보다 크면
		else if(sum>M){
			result=mid;
		 	start=mid+1;
		 }
		//3.잘라낸 나무의 길이가 M값보다 작으면 
		else{
			end=mid-1;
		}
		if(start>end){
			break;
		}
	}
	cout<<result;
	return 0;
}
