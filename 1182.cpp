#include<bits/stdc++.h>
using namespace std;

int num[21];
int n,s;// N: �����ǰ���< 20 , S: ����< 1000000. 
int total=0;
bool check[21];
vector <int> v; 
void go(int count,int max){
	if(count==max){//���ϴ� ������ �Ǹ�. 
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
	else{//���� ������ ��ä�����ٸ�. 
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
	//���� �� �ִ� �κм����� ���� 2^20; �����ϰ� ���þ��ϰ�.
	for(int i=0;i<n;i++) cin>>num[i];
	
	for(int i=1;i<=n;i++){//���� ������ ����. 
		go(0,i);
	}
	cout<<total;
	
}
