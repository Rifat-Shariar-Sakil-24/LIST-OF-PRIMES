#include<bits/stdc++.h>
#define ll long long
#define MAX 32000
using namespace std;
 vector<bool> isprime(MAX+1);
 vector<ll> primes;

void sieve()
{
    for(int i=3; i*i<=MAX; i+=2)
    {
        if(isprime[i]==false)
        {
            for(int j=i*i; j<=MAX; j+=2*i)
            {
                isprime[j] = true;
            }
        }
    }

    primes.push_back(2);
    for(int i=3; i<=MAX; i+=2)
    {
        if(isprime[i]==false) primes.push_back(i);
    }
}

void segsieve(ll l,ll r)
{
    bool isprime[r-l+1];
    for(int i=0;i<r-l+1; i++) isprime[i]=true;

    for(int i=0; primes[i]*primes[i]<=r; i++)
    {

        ll currentprime = primes[i];
        ll base = (l/currentprime)*currentprime;
        if(base<l) base+=currentprime;

        for(int j=base; j<=r; j+=currentprime){ isprime[j-l] = false;}
        if(base==currentprime) isprime[base-l] = true;
    }
    for(int i=0;i<r-l+1;i++)
    {
        if(isprime[i]) cout <<  i+l << endl;
    }
}
int main()
{
    sieve();
    int t;
    cin >> t;
    while(t--)
    {
        ll l,r; cin >> l >> r;
         segsieve(l,r);
    }

}

