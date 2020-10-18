#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000
using namespace std;
 vector<bool> isprime(MAX+1);
vector <ll> primes;

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
int main()
{
    sieve();
}
