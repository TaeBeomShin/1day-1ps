#include<bits/stdc++.h>
using namespace std;

int num[21];
int n,s;// N: 정수의개수< 20 , S: 정수< 1000000. 
int total=0;
bool check[21];
vector <int> v; 
void go(int count,int max){
	if(count==max){//원하는 개수가 되면. 
		int sum=0;
		for(int i=0;i<v.size();i++){
			cout<<v[i]<<" ";
		}
		for(int i=0;i<v.size();i++){
			v.pop_back();
		}
		if(sum==s) total++;
		memset(check,0,21);
		cout<<"\n";
	}
	else{//아직 개수가 안채워졌다면. 
		for(int i=0;i<n;i++){
			if(!check[i]){
				check[i]=true;
				v.push_back(num[i]);
				go(count++,max);
				check[i]=false;
			}
		}
	}
} 
int main(){
	cin>>n>>s;
	//만들 수 있는 부분수열의 개수 2^20; 선택하고 선택안하고.
	for(int i=0;i<n;i++) cin>>num[i];
	
	for(int i=1;i<=n;i++){//고르는 숫자의 개수. 
		go(0,i);
	}
	cout<<total;
	
}
