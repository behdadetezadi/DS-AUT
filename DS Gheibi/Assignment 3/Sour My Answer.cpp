#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main()
{
    map <int, int> mylist;
    int q;
    cin >> q;


    map<int, int>:: iterator it;
    string input;
    int a;

    for(int i = 0 ; i<q; i++)
    {
        cin >> input;
        cin >> a;
        it = mylist.find(a);

        if(input[0] == 'A')
        {
            if(it != mylist.end())
            {
                mylist[a]++;
            }
            else
            {
                mylist[a] = 1;
            }
        }
        else if(input[0] == 'R')
        {
            if(it != mylist.end() && mylist[a] > 1)
            {
                mylist[a]--;
            }
            else
            {
                if(it != mylist.end())
                {
                    mylist.erase(a);
                }
            }


        }
        else if(input[0] == 'C')
        {
            cout << mylist[a] << endl;
        }

    }


    return 0;
}
