#include <iostream>

using namespace std;


int main()
{

   int n;
   cin >> n;
   int weight[n];
   int is_eaten[n];

   cin >> weight[0];
   is_eaten[0] = 0;
   for(int i = 1; i < n; i++)
   {
       cin >> weight[i];
       is_eaten[i] = 0;
       if(weight[i] > weight[i-1])
       {
           for(int j = i - 1; j >= 0; j--)
           {
               if(weight[j] > weight[i])
               {
                   break;
               }
               else if(is_eaten[j] == 0 && weight[i] > weight[j])
               {
                   is_eaten[j] = i+1;
               }
           }
       }
   }
   for(int i = 0; i < n; i++)
   {
       cout <<is_eaten[i]<<" ";
   }
    return 0;
}

