#include <iostream>
using namespace std;

struct Node{
int val;
Node *prev, *next;
};


int main()
{
    Node *mid;
    Node *head;
    Node *tail;

    int q, i;

    cin >> q;

    string input;
    i = 1;
    Node *u = new Node;
    u->val = 1;
    u->next = nullptr;
    u->prev = nullptr;
    head = u;
    tail = u;
    mid = u;
    while(i <= q)
    {
        cin >> input;
        if(input == "Front")
        {
            Node *x = new Node;
            x->val = i + 1;
            x->next = head;
            head->prev = x;
            head = x;
            x->prev = nullptr;
            if(((i + 1) % 2) == 0)
            {
                mid = mid->prev;
            }
        }
        else if(input == "Back")
        {
            Node *x = new Node;
            x->val = i + 1;
            tail->next = x;
            x->prev = tail;
            tail = x;
            x->next = nullptr;

            if(((i + 1)% 2) == 1)
            {
                mid = mid->next;
            }


        }
        else if(input == "Middle")
        {
            Node *x = new Node;
            x->val = i + 1;
           if(i+1 == 2)
            {
                tail->next = x;
                x->prev = tail;
                x->next = nullptr;
                tail = x;
            }
           else
           {
            x->prev = mid;
            x->next = mid->next;
            mid->next->prev = x;
            mid->next = x;
           }


            if(((i + 1) % 2) == 1)
            {
                mid = x;
            }
        }
        i++;
    }

    Node *disp;
    disp = head;
    for(int i = 1; i <= q + 1; i++)
    {
        cout << disp->val << " ";
        disp = disp->next;
    }

    return 0;
}
