#include <iostream>
#include  <bits/stdc++.h>
#include <deque>
#include <string>
using namespace std;

struct box
{
    int value;
    int n;
};

int main()
{
    char inp;
    int q, d, t;
    cin >> q;
    deque <struct box> megaque;
    struct box to_add;
    for(int i = 0; i < q; i++)
    {

        cin >> inp;

        if(inp == '?')
        {
            if(megaque.empty())
            {
                cout << "empty" << endl;
            }
            else
            {
                cout << (megaque.front()).value << endl;
            }
        }

        else
        {
            if(inp == '-')
            {
                cin >> t;
                while((!megaque.empty()) && t > 0)
                {
                   if(t >= megaque.front().n)
                   {
                       t -= megaque.front().n;
                       megaque.pop_front();
                   }
                   else
                   {
                        megaque.front().n -= t;
                        t = 0;
                   }
                }
            }

            else if(inp == '+')
            {
               cin >> to_add.value;
               cin >> to_add.n;
               megaque.push_back(to_add);
            }
        }
    }





    return 0;
}
