#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll maxi;
vector<ll> primeList,sieve(15000000);
map<ll,ll> cumFactors;
map<ll,ll> numbers, afterNumbers;
void factorize(ll n)
{
    ll num = n;
    unordered_set<ll> factors;
    while(sieve[n])
    {
        factors.insert(sieve[n]);
        n /= sieve[n];
    }
    if (n > 1)
        factors.insert(n);
    for(auto factor : factors)
    {
        cumFactors[factor] += afterNumbers[num];
        if(cumFactors[factor] > cumFactors[maxi])
            maxi = factor;
    }
}
void prepareSieve()
{
    for (ll x = 2; x < sieve.size(); x++) {
        if (sieve[x]) continue;
        primeList.push_back(x);
        for (ll u = 2*x; u < sieve.size(); u += x) {
            sieve[u] = x;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, i, gcd, result = 0, num;
    cin>>n;
    cin>>num;
    numbers[num]++;
    gcd = num;
    for(i = 1; i < n; i++)
    {
        cin>>num;
        numbers[num]++;
        gcd = __gcd(num, gcd);
    }
    if(numbers.find(gcd) != numbers.end())
    {
        result += numbers[gcd];
        numbers.erase(gcd);
    }
    if(result == n)
        cout<<-1;
    else
    {
        num = 0;
        for(auto item : numbers)
            afterNumbers[item.first / gcd] += item.second;
        prepareSieve();
        for(auto item : afterNumbers)
            factorize(item.first);
        result = n - cumFactors[maxi];
        cout<<result;
    }
    return 0;
}