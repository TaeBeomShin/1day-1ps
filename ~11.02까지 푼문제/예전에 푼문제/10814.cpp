#include<bits/stdc++.h>
using namespace std;

typedef struct customer{
	int age;
	int rank;
	string name;
};

bool comp(customer a,customer b){
	return (a.age==b.age)?a.rank<b.rank:a.age<b.age;
}

int main(){
	int n;cin>>n;
	
	vector <customer> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].age>>v[i].name;
		v[i].rank=i;
	}
	
	sort(v.begin(),v.end(),comp);
	
	for(auto p:v) cout<<p.age<<" "<<p.name<<"\n";
}
