#include <iostream>
#include <list>
#include<queue>
#include <iterator>
#include <map>

using namespace std;



list <int> to_print;
int keep_count;


void BFS(int v, int n, list<int> adj[], map<pair<int,int>,int> my_map)
{
    bool *visited = new bool[n+1];
    for(int i = 0; i < n+1; i++)
    {
        visited[i] = false;
    }

    list<int> q;
    list<int>::iterator i;

    visited[v] = true;
    q.push_back(v);


    pair<int,int> to_check;

    while(!(q.empty()))
    {
        v = q.front();

        q.pop_front();

        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if (!(visited[(*i)]))
            {
                keep_count++;

                to_check.first = v;
                to_check.second = (*i);

                map<pair<int,int>,int>::iterator it = my_map.find(to_check);

                if(it != my_map.end())
                {
                    to_print.push_front(it->second);
                }
                else
                {
                    to_check.first = (*i);
                    to_check.second = v;

                    it = my_map.find(to_check);

                    if(it != my_map.end())
                    {
                        to_print.push_front(it->second);
                    }

                }

                visited[(*i)] = true;
                q.push_back(*i);
            }
        }
    }
}




int main()
{
    int m,n;

    cin >> n;
    cin >> m;

    list<int> adj[n+1];

    map<pair<int,int>, int> custom;

    pair<int,int> k;

    int v,u;


    for(int i = 1; i < m+1; i++)
    {
        cin >> v;
        cin >> u;

        k.first = v;
        k.second = u;

        custom[{v, u}] = i;

        adj[v].push_back(u);
        adj[u].push_back(v);


    }

    BFS(1, n, adj, custom);

    cout << keep_count << endl;

    for (auto i = to_print.begin(); i != to_print.end(); ++i)
    {
        cout << (*i) << " ";
    }


    return 0;
}
