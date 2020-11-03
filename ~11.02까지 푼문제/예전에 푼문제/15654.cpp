#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int m,n;
int list[10];
vector <int> array;

void go(int index,int count){
	if(count==m){
		for(int i=0;i<m;i++){
			cout<<list[i]<<" ";
		}
		cout<<"\n";
	}
	else{
		int before=-1;
		for(int i=index;i<array.size();i++){
			if(i==0||before!=array[i]){
			before=array[i];
			list[count]=array[i];
			go(i,count+1);
			}
		}
	}
}
int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		array.push_back(temp);
	}
	
	sort(array.begin(),array.end());
	
//	for(int i=0;i<array.size();i++) cout<<array[i]<<"\n";
	
	go(0,0);
	return 0;
}
