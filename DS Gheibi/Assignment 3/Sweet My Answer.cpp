#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main()
{
    map <string, int> ranks;
    int n, q;
    string input;


    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        ranks[input] = i+1;
    }


    map<string, int>:: iterator it;
    cin >> q;
    int output[q];
    string name;
    for(int i = 0; i < q; i++)
    {
       cin >> name;
       it = ranks.find(name);
       if(it != ranks.end())
       {
           output[i] = it->second;
       }
       else
       {
           output[i] = 0;
       }

    }

    for(int i = 0; i < q; i++)
    {
        if(output[i] != 0)
        {
            cout << output[i] << endl;
        }
        else
        {
            cout << "Unknown!" << endl;
        }
    }
    return 0;
}
