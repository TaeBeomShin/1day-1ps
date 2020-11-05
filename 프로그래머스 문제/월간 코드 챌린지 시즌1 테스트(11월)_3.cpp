#include<bits/stdc++.h>
using namespace std;

int c[500001]={0,};
int solution(std::vector<int> a) {
    int answer = -1;
    int num=a.size();
    if(a.size()<=3) return answer=0;
    vector<int> b;
    b.push_back(a[0]);
    for(int i=1;i<a.size();i++){
        if(a[i-1]==a[i]){
            continue;  
        }else{
            b.push_back(a[i]);
        }
    }
    for(int i=0;i<b.size();i++) c[b[i]]++;
    int mn=0;
    for(int i=0;i<=num;i++) if(mn<c[i]) mn=c[i];
    
    if(mn*2<b.size()){
        answer=mn*2;
        cout<<mn;
    }
    else{
        if(b.size()%2==1) answer=b.size()-1;
        else answer=b.size();
    }
    if(answer<=3) answer=0;
    return answer;
}
