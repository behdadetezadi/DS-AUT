#include <iostream>
#include <list>

using namespace std;

struct element
{
    int i;
    int r;
    int l;
    int value;
    element* left_child;
    element* right_child;
    element* parent;
};

list <int> order;

void printInorder(struct element* node)
{
    if (node == nullptr)
        return;

    printInorder(node->left_child);

    order.push_back(node->i);

    printInorder(node->right_child);
}


int main()
{
    int n;

    cin >> n;

    int index, left, right;
    struct element* my_list[n + 1];

    for(int i = 1; i < n + 1; i++)
    {

        cin >> index;
        cin >> left;
        cin >> right;

        struct element* to_add = new element;
        to_add->i = index;
        to_add->l = left;
        to_add->r = right;
        to_add->parent = nullptr;
        to_add->right_child = nullptr;
        to_add->left_child = nullptr;
        my_list[index] = to_add;

    }

    for(int i = 1; i < n + 1; i++)
    {
        if(my_list[i]->l != -1)
        {
            my_list[i]->left_child = my_list[my_list[i]->l];
            my_list[i]->left_child->parent = my_list[i];
        }
        if(my_list[i]->r != -1)
        {
            my_list[i]->right_child = my_list[my_list[i]->r];
            my_list[i]->right_child->parent = my_list[i];
        }

    }

    for(int i = 1; i < n + 1; i++)
    {

        if(my_list[i]->parent == nullptr)
        {
            printInorder(my_list[i]);
            break;
        }

    }

    list <int> :: iterator it;
    int to_assign = 1;
    for(it = order.begin(); it != order.end(); ++it)
        {
            my_list[(*it)]->value = to_assign;
            to_assign++;
        }

    for(int i = 1; i < n + 1; i++)
    {
        cout << my_list[i]->value << " ";
    }



    return 0;
}
