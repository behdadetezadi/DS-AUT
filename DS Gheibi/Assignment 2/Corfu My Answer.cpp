#include <iostream>
#include <stack>

using namespace std;



struct Node
{
    int data;
    int index;
};



int NGE(Node arr[], int n, int when[])
{

    stack<Node> s;
    int max_giant;
    bool check;
    for (int i = n; i > 0; i--)
    {
        max_giant = 0;
        check = false;
        if (!s.empty())
        {
            while (!s.empty() && s.top().data <= arr[i].data)
                {
                    if(when[s.top().index] > max_giant)
                    {
                        max_giant = when[s.top().index];
                        check = true;
                    }
                    s.pop();
                }
        }
        if(i==n || s.empty())
        {
            when[i] = 0;
        }
        else
        {
            when[i] = max_giant+1;
        }
        s.push(arr[i]);
    }

    int to_return = 0;
    for(int i = 1 ; i <= n; i++)
    {
        if(when[i] > to_return)
        {
            to_return = when[i];
        }
    }
    return to_return;
}


int main()
{
    int  input;
    int n;

    cin >> n;

    Node weight[n + 1];
    int when[n+1];


    for(int i = n; i > 0; i--)
    {
        cin >> input;
        weight[i].data = input;
        weight[i].index = i;
    }

    when[n] = 0;
    int max_time = 0;


    max_time = NGE(weight, n, when);

    cout << max_time;


    return 0;
}
