#include<iostream>
#include<vector>
#define ll long long
#define M 1000005


using namespace std;

vector <ll> primes;

void sieve()
{
    vector <bool> isprime(M,0);
    for(int i=3;i*i<=M;i+=2)
    {
        if(isprime[i]==0)
        {
            for(int j = i*i;j<=M;j+=(2*i))isprime[j] = 1;
        }
    }
    primes.push_back(2);
    for(ll i=3;i<=M;i+=2)
    {
        if(isprime[i]==0) primes.push_back(i);
    }
}

int solve(ll n)
{
    ll res=1;
    for(ll i=0;primes[i]*primes[i]<=n;i++)
    {
        ll co=0;
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
            {
                co++;
                n/=primes[i];
            }
            co++;
            res*=co;
        }
    }
    if(n!=1)
        res*=2;
    return res;
}
int main()
{

   sieve();
   int n; cin >> n;
  cout <<  solve(n) << endl;

}
