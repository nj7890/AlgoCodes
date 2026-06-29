#include<iostream>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int32_t maxi=0, mini=10, x=0;
        for(int i=0;i<n;++i){
            cin>>x;
            if(x>maxi){
                maxi=x;
            }
            if(x<mini){
                mini = x;                
            }
        }
        // cout<<maxi<<" "<<mini<<endl;
        cout<<(maxi-mini)+1<<endl;         
    }
}