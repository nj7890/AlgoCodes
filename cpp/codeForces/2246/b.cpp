#include<iostream>
using namespace std;

int main(){
    int_fast32_t t;cin>>t;

    while(t--){
        int_fast32_t n; cin>>n;
        if(n==1){
            cout<<1;
        }else if(n==2){
            cout<<-1;
        }else{
            cout<<"1 2 ";
            n-=2;
            long long num = 3;
            while(n--){
                cout<<num<<" ";
                num*=2;
            }
        }
        cout<<endl;
    }
}