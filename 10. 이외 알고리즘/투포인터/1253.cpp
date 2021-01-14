#include<bits/stdc++.h>
using namespace std;
/*
	�������� �˰���. ����.
	
	1. �迭�� �����Ѵ�.
	2. ������ ���� �ϳ� �� ���캻��.
		- �μ��� ���� �����ϴ� ������ ������ start++, ũ�� end--;
		- ����) ���ҷ� 0�� �־����� ��찡 corner case�� �̿� ���� ����ϱ�.
	3. ���� ���� ����Ѵ�. 
*/
int arr[2001]={0,},n;
long long answer=0;

void input(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	
}

void getAnswer(){
	//���� �����Ѵ�. O(nlog n)
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++){
		//ū �� ���� �ϳ��� ���캽.
		int num=arr[i];
		int start=0,end=n-1;
		while(start<end){
			int sum=arr[start]+arr[end];
			if(sum==num){
				if(start!=i && end !=i){
				//�� �߿� 0�� ���� ����. 
					answer++;
					break;
				}else if(start==i){
				//end�� 0��. 
					start++;
				}else{
				//right�� 0��.
					end--; 
				}
			}else if(sum>num){
				end--;
			}else{
				start++;
			}
		}
	}
}
int main(){
	input();
	getAnswer();
	cout<<answer;
}
