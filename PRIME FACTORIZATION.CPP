#include<bits/stdc++.h>
#define ll long long
#define MAX 32000
using namespace std;

vector <ll> primes;
void sieve()
{
    bool isprime[MAX]={false};
    for(int i=3;i*i<=MAX;i+=2)
    {
        if(!isprime[i])
        {
            for(int j=i*i;j<=MAX;j+=(2*i))isprime[j]=true;
        }
    }
    primes.push_back(2);
    for(int i=3;i<=MAX;i+=2){
        if(!isprime[i])primes.push_back(i);

      }
}

void factorization(ll n)
{
    for(int i=0;primes[i]*primes[i]<=n;i++)
    {
        if(n%primes[i]==0)
        {
            while(n%primes[i]==0)
            {
               // co++;
               cout << primes[i] << " ";
                n/=primes[i];
            }
        }
    }
    if(n!=1)cout << n << " ";
    cout << endl;
}
int main()
{
    sieve();
    int t; cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        factorization(n);
    }
}
