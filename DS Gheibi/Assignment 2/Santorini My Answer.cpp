#include <iostream>
#include <list>

using namespace std;



int main()
{

    int n,q,i;
    cin >> n;
    cin >> q;

    list <int> base[n+1];
    bool del_check[n+1];

    for(int i = 1; i <= n; i++)
    {
        del_check [i] = false;
        base[i].push_front(i);
    }

    i = 1;
    string input;


    while(i <= q)
    {
        cin >> input;
        int a;
        if(input[0] == 'P')
        {
            int b;
            cin >> a;
            cin >> b;
            base[b].splice(base[b].end(), base[a]);
        }
        else if(input[0] == 'R')
        {
            cin >> a;
            base[a].reverse();
        }


        else if(input[0] == 'D')
        {
            cin >> a;

            del_check[a] = true;
        }

        i++;
    }
for(int i = 1; i <= n; i++)
{

    if(base[i].empty())
    {
        cout << "Empty" << endl;
    }

    else
    {
        int k= 0;
        for(auto it = base[i].begin(); it != base[i].end(); it++)
        {
            if(del_check[(*it)] == false)
            {
                cout << (*it) << " ";
                k++;
            }
        }
        if(k == 0)
        {
            cout << "Empty" << endl;
        }
        else
        {
            cout << endl;
        }
    }
}
    return 0;
}
