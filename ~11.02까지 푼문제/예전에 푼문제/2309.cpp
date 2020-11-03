#include<bits/stdc++.h>

using namespace std;

vector <int> man;
int main(){
	int temp,sum=-100;
	for(int i=0;i<9;i++){
		cin>>temp;
		sum+=temp;
		man.push_back(temp);
	}
	cout<<sum<<"\n";
	int value1,value2;
	int	flag=0;
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(man[i]+man[j]==sum){
				value1=man[i];
				value2=man[j];
				flag=1;
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	sort(man.begin(),man.end());

	for(int i=0;i<9;i++){
		if(man[i]!=value1&&man[i]!=value2)
			cout<<man[i]<<"\n";
			
	}

	return 0;
}
