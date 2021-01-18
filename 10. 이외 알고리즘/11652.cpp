#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	map<long,int> cards;
	
	long long num;
	for(int i=0;i<n;i++){
		cin>>num;
		if(cards.find(num)==cards.end())
			cards[num]=1;
		else
			cards[num]+=1;
	}
	
	long long mnum=0;
	int mvalue=0;
	for(auto card:cards){
		if(card.second>mvalue){
			mvalue=card.second;
			mnum=card.first;
		}
	}
	cout<<mnum;
}
