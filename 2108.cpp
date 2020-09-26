#include<bits/stdc++.h>
using namespace std;

int num[8001]={0,}; //0~8000번째 인덱스. 0이 4000번째. -4000이 0번째. 
int main(){
	int n;cin>>n;
	int a[n]={0,};
	double sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		num[a[i]+4000]++;
	}
	cout<<round(sum/n)<<"\n";
	sort(a,a+n);
	cout<<a[n/2]<<"\n";
	
	//여러개 있을경우. 최빈값중 두번째로 작은값. 
	int max=0;
	int maxnum=0;
	
	for(int i=0;i<=8000;i++){
		if(num[i]>max){
			max=num[i];
			maxnum=i;//첫번째로 작은수를 구한다. 
		}
	}
	
	int count=0;
	for(int i=0;i<=8000;i++){
		if(num[i]==max){
			count++;
			if(count==2){
				maxnum=i;
			}
		}
	}
	cout<<maxnum-4000<<"\n";
	cout<<a[n-1]-a[0]<<"\n";
	
	//산술평균, 중앙값, 최빈값-> 기수정렬의 개념이용, 범위. 
}
