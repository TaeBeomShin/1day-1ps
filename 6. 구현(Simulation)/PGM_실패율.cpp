#include <bits/stdc++.h>
using namespace std;
/*
	https://programmers.co.kr/learn/courses/30/lessons/42889 실패율
	실패율을 계산해서 정렬해서 반환하는 문제.
	c++ compare 정의연습. 
*/
double arr[502]={0,};
bool compare(const pair<int,double> & a,const pair<int,double> &b){
    if(a.second!=b.second)
        return a.second>b.second;
    else
        return a.first<b.first;
}
vector<int> solution(int N, vector<int> stages) {
    int size=stages.size();//유저의 명수.
    vector<int> v;
    vector<pair<int,double>> answer;
    for(int i=0;i<size;i++) arr[stages[i]]++;
    for(int i=1;i<=N;i++){
        double sum=0;
        if(arr[i]==0){
            answer.push_back({i,0});
            continue;
        }
        for(int j=1;j<i;j++) sum+=arr[j];//이전단계까지 실패한 사람 수
        
        answer.push_back({i,arr[i]/(size-sum)});
    }
    sort(answer.begin(),answer.end(),compare);
    for(int i=0;i<answer.size();i++) v.push_back(answer[i].first);
    
    return v;
}
