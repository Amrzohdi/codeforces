#include <bits/stdc++.h>
using namespace std;
#define ll      long long
#define mp      make_pair
#define sz(v)   (int)v.size()
#define pb      push_back
#define b_p(n)      __builtin_popcount(n)

int ar[]= {1,0,-1,-1,    0 , 1};
int ar1[]={0,1,1,0      ,  -1 , -1};
int main() {
    ll x,y,z;
    cin>>x>>y>>z;
    if(x+y-2 <z ){
        cout<<-1<<endl;
        return 0;
    }

    if( (x*y)%(z+1)==0 ){
        cout<<(x*y)/(z+1)<<endl;
        return 0;
    }
    if(y>x)
        swap(x,y);
    if(x>=z+1){
    	ll res= -1;
        res=(x/(z+1) * y);
        if(y>z+1)
        	res= max(res,(y/(z+1) * x));
        cout<<res<<endl;
        return 0;
    }
    z+=2;
    ll num1= y/(z-x), num2= x/(z-y);
    cout<< max(num1,num2)<<endl;
    return 0;
}
