#include<iostream>
#include<algorithm>

using namespace std;

bool compare (int a,int b){
	return a>b;
} 
int main(){
	int A[51]={0,};
	int B[51]={0,};
	
	int N;
	cin>>N;
	
	for(int i=1;i<=N;i++) cin>>A[i];
	for(int i=1;i<=N;i++) cin>>B[i];
	//A�迭�� ��迭�ϴ� ���� ����� �� 50!=> �ſ�ū��
	//� ����� ���� ��迭�� ���ΰ�?
	//B�� ���� ū���� A�� �������� ���� �����ϸ�ɵ�. 
	//B�� �ִ¼��� ��迭�� ��� �ſ� ���� Ǯ�� ������ 
	
	sort(A+1,A+N+1);
	sort(B+1,B+N+1,compare);
	
	long long s=0;
	for(int i=1;i<=N;i++){
		s+=A[i]*B[i];
	}
	
	cout<<s;
	return 0;
}
