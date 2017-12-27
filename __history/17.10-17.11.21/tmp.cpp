#include<iostream>
long long s,n,a,b;int main(){std::cin>>n;for(a=1;a<=n;a=b){b=n/(n/a)+1;s+=(b-a)*(n/a);}std::cout<<s;}
