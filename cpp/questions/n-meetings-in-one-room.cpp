#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compTiming(const vector<int>&a,const vector<int>& b){
    return a[1]>b[1];
}

int main(){
    int n;cin>>n;
    vector<vector<int>> timing(3,vector<int> (n,0));

    for(int i=0;i<n;i++){
        timing[2][i]=i+1;   
        cin>>timing[0][i];
    }

    for(int i=0;i<n;++i)
        cin>>timing[1][i];

    sort(timing.begin(),timing.end(),compTiming);
    // debug
    // cout<<"Debug:"<<endl;
    // for(int i=0;i<n;++i){
    //     cout<<timing[0][i]<<" "<<timing[1][i]<<" "<<timing[2][i]<<endl;
    // }

    int time = timing[0][0];
    vector<int> ans;
    // Base case for First meeting
    ans.push_back(timing[2][0]);

    for(int i=1;i<n;++i){
        if(timing[1][i]>time){
            time = timing[0][i];
            ans.push_back(timing[2][i]);
        }
    }

    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";

    return 0;
}