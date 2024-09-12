#include <iostream>
#include <stack>
using namespace std;

struct p
{
    char c;
    int ind;
};
int main()
{

   int n, counter;
   struct p res;
   cin >> n;
   stack<struct p> store;
   int arr[2*n];
   //char my_stack[2*n];
   for(int i = 0; i < 2*n; i++)
   {
       struct p temp;
       cin >> temp.c;
       temp.ind = i;
       if(temp.c == '(')
       {
           store.push(temp);
       }
       else
        {
            res = store.top();
            store.pop();
            arr[i] = res.ind;
            arr[res.ind] = i;
        }
   }
    for(int i = 0;i<2*n;i++)
    {
            cout << arr[i] + 1 << " ";
    }

    return 0;
}
