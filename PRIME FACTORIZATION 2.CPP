#include<bits/stdc++.h>
#define ll long long
#define MAX 32000
using namespace std;

void factorization(ll n)
{
    if(n%2==0)
    {
        while(n%2==0)
        {
            cout << "2 ";
            n/=2;
        }
    }
    for(ll i=3;i*i<=n;i+=2)
    {

            while(n%i==0)
            {
                cout << i << " ";
                n/=i;
            }

    }

    if(n!=1)cout << n << " ";
    cout << endl;
}
int main()
{

    int t; cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        factorization(n);
    }
}

