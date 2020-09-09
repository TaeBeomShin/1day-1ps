#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

using namespace std;

int num[1500];

int main(){
	int A,B;
	cin>>A>>B;
	
	// 1 :1 ,2:2,3 , 3:4,5,6, 4:7,8,9,10 5:11,12,13,14,15
	
	int index=0;
	
//	i=1, index=0, j=0~1 (0)
//	i=2, index=1, j=1~3 (1,2)
//	i=3, index=3, j=3~6 (3,4,5)
//	i=4, index=6, j=6~10 (6,7,8,9)

	for(int i=1;i<=50;i++){
		for(int j=index;j<index+i;j++){
			num[j]=i;
		}
		index+=i;
	}
	
	int sum=0;
	for(int i=A-1;i<=B-1;i++){
//		cout<<num[i]<<"\n";
		sum+=num[i];
	}	
	
	cout<<sum;
	return 0;	
}
