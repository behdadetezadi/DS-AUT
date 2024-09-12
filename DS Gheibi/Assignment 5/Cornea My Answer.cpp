#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
using namespace std;

unsigned long long determine_sum(long long range, long long want, list<long long> adj[])
{
    unsigned long long sum=0;
    if(range < want)
    {
        return -1;
    }
    bool is_reachable[range+1];
    long long counter = 0;

    for(long long i = 0; i<=range; i++)
    {
        is_reachable[i]=false;
    }


    is_reachable[1] = true;

    for(long long i = 1; i<=range; i++)
    {
        if(counter == want)
        {
           return sum;
        }
        if(is_reachable[i])
        {
            sum += i;
            counter++;
            for(auto it = adj[i].begin(); it != adj[i].end(); it++)
            {
                is_reachable[*it] = true;
            }
        }
    }
    if(counter == want)
    {
        return sum;
    }

    return -1;
}

int main()
{
    long long n,m;

    cin >> n;
    cin >> m;

    list<long long> adj_list[n+1];

    long long neighbor_c, neighbor_i;

    for(long long i = 1; i<=n; i++)
    {
        cin >> neighbor_c;

        for(long long j = 0; j< neighbor_c; j++)
        {
            cin >> neighbor_i;
            adj_list[i].push_back(neighbor_i);
        }
    }

    unsigned  long long ans = determine_sum(n, m, adj_list);

    cout << ans;
    return 0;
}
