/*
K.D. Vinit  /,,/
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;
const int Fact_Length = 2e5 + 100;     //Max length

//Takes a&b as input and Returns : The power (a,b), (a^b)%mod
int Power(int base, int expo)
{
   int result=1; base%=mod;
   while(expo) {   if(expo%2==1)  result=(result*base)%mod;     base=(base*base)%mod;     expo/=2; }
   return result;
}

// It give the modulo inverse of a, (1/a)%mod
int Mod_Inv(int aa) { return Power(aa,mod-2); }

int Factorial[Fact_Length];
// It make the above Factorial[i] = i! array
int Make_Factorial()
{
   Factorial[0]=1;
   for(int i=1;i<Fact_Length;i++) { Factorial[i]=(i*Factorial[i-1])%mod; } return 0;
}
int Implement_Make_Factorial=Make_Factorial();      //To Implement Make_Factorial

// Takes n&r as input and Returns : nCr%mod
int nCr(int nn,int rr)
{
   if(nn<rr || nn<0 || rr<0) return 0;
   //if(>Fact_Length) { cout<<"Error"<<endl; return; }
   int fans=(Factorial[nn]*Mod_Inv(Factorial[rr]))%mod;
   fans=(fans*Mod_Inv(Factorial[nn-rr]))%mod;
   return fans;
}

int calc(int x1, int y1, int x2, int y2)
{
    int r = x2-x1;
    int d = y2-y1;
    int ans = nCr(r+d, r);
    return ans;
}

void solve()
{
    int h, w, a, b;
    cin>>h>>w>>a>>b;

    a=h-a+1;

    int ans=0;
    for(int i=1; i<a; i++)
    {
        int cur = (calc(1, 1, i, b)*calc(i, b+1, h, w))%mod;
        // (1,1)->(ith row,bth column) * (i,b+1,h,w);
        ans = (ans+cur)%mod;
    }

    if(ans<0) ans+=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
