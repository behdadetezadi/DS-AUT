#include <iostream>
#include <list>
#include<queue>
#include <iterator>
using namespace std;

int area_count = 1;

void find_areas(vector<bool> & ,list<int> [],int ,int *);

void check_areas(list<int> vec[],int V, int *areas)
{
    vector<bool> visited(V+1,false);

    for(int i=1; i<=V; i++)
    {
        if(visited[i] == false)
        {
            find_areas(visited,vec,i, areas);
        }
    }
}

void find_areas(vector<bool> &visited ,list<int> vec[],int i,int *areas)
{

    list<int> q;

    visited[i] = true;
    q.push_back(i);

    list<int> :: iterator it;

    areas[i] = area_count;

    if(vec[i].size()==0)
    {
        area_count++;
        return;
    }

    while(!q.empty())
    {
        i = q.front();
        q.pop_front();
        for(it = vec[i].begin(); it!= vec[i].end(); it++)
        {
            if(visited[*it] == false)
            {
                q.push_back(*it);
                visited[*it] = true;
                areas[*it] = area_count;
            }
        }
    }
    area_count++;
}


int main()
{

    int m,n;

    cin >> n;
    cin >> m;

    int table[n][m];

    int areas[n*m + 1];

    string input;

    for(int i = 0; i < n; i++)
    {
        cin >> input;

        for(int j = 0; j < m; j++)
        {

            if(input[j] == '.')
            {
                table[i][j] = 1;
            }
            else if(input[j] == '#')
            {
                table[i][j] = 0;
            }
        }
    }

    list<int> adj_list[n*m + 1];
    int k = 1;


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(table[i][j] == 1)
            {
                if(j < m - 1)
                {
                    if(table[i][j+1] == 1)
                    {
                        adj_list[k].push_back(k+1);
                    }
                }
                if(j > 0)
                {
                    if(table[i][j-1] == 1)
                    {
                        adj_list[k].push_back(k-1);
                    }
                }
                if(i < n - 1)
                {
                    if(table[i+1][j] == 1)
                    {
                        adj_list[k].push_back(k+m);
                    }
                }
                if(i > 0)
                {
                    if(table[i-1][j] == 1)
                    {
                        adj_list[k].push_back(k-m);
                    }
                }
            }
                k++;
        }
    }


    check_areas(adj_list, n*m, areas);

    int q, r1, c1, r2, c2;

    cin >> q;

    string answers[q];

    for(int i = 0; i < q; i++)
    {
        cin >> r1;
        cin >> c1;

        cin >> r2;
        cin >> c2;

        if(areas[m* (r1-1) + c1] == areas[m* (r2-1) + c2])
        {
            answers[i] = "YES";
        }
        else
        {
            answers[i] = "NO";
        }
    }

    for(int i = 0; i < q;i++)
    {
        cout << answers[i] << endl;
    }



    return 0;
}

