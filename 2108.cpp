#include<bits/stdc++.h>
using namespace std;

int num[8001]={0,}; //0~8000��° �ε���. 0�� 4000��°. -4000�� 0��°. 
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
	
	//������ �������. �ֺ��� �ι�°�� ������. 
	int max=0;
	int maxnum=0;
	
	for(int i=0;i<=8000;i++){
		if(num[i]>max){
			max=num[i];
			maxnum=i;//ù��°�� �������� ���Ѵ�. 
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
	
	//������, �߾Ӱ�, �ֺ�-> ��������� �����̿�, ����. 
}
