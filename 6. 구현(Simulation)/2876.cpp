#include<bits/stdc++.h>
using namespace std;

int seats[6][100001];
int maxNum=0, maxNumGrade=6;

void renewMaxNum(int i,int num);

int main(){
	int n;cin>>n;
	
	for(int i=0;i<n;i++){
		int num1,num2;cin>>num1>>num2;
		renewMaxNum(i,num1);
		renewMaxNum(i,num2);
	}
	
	cout<<maxNum<<" "<<maxNumGrade;
}

void renewMaxNum(int index,int num){
	if(index!=0&&seats[num][index-1]>=1){
		seats[num][index]=seats[num][index-1]+1;	
	}else{
		seats[num][index]=1;
	}
	
	if(maxNum<seats[num][index]||(maxNum==seats[num][index]&&maxNumGrade>num)){
		maxNum=seats[num][index];
		maxNumGrade=num;
	}
}
