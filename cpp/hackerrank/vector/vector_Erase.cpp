#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,i=0;
  cin>>n;
  vector  <int> v(n);
  while(n--){
  cin >>  v[i++];  
  }
  int p,s,e;
  cin >>  p ;
  v.erase(v.begin()+p-1);
  cin >>  s >>  e ;
  v.erase(v.begin()+s-1,v.begin()+e-1);
  i=0;
  cout  <<  v.size()  <<endl;
  while(v.size()!=i){
    cout  <<  v[i++]  <<  " ";
  }
  return  0;
}
