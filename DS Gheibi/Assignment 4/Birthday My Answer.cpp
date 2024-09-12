#include <iostream>
using namespace std;


struct Node
{
    int value;
    int tedad;
    Node *parent, *left, *right;

    Node()
    {
        value = 0;
        tedad = 0;
        left =  nullptr;
        right =  nullptr;
        parent = nullptr;
    }
};

class BST
{
public:

    struct Node* root;
    int n;

    BST()
    {
        n = 0;
        root = nullptr;
    }


    bool add(int x)
    {
        Node *node = find(x);

        if (node != nullptr)
        {
            node->tedad++;
            return true;
        }

        Node *p = findLast(x);
        Node *q = new Node;
        q->value = x;
        q->tedad = 1;
        return addChild(p, q);
    }

    Node* findLast(int x)
    {
        Node *last = root, *prev = nullptr;
        while (last != nullptr)
        {
            prev = last;
            if (x < (last->value))
                last = last->left;
            else if (x > (last->value))
                last = last->right;
            else
                return last;
        }

        return prev;
    }




    Node* find(int x)
    {
        Node *w = root;
        while (w != nullptr)
        {

            if (x < (w->value))
                w = w->left;

            else if (x > w->value)
                w = w->right;

            else
                return w;
        }

        return nullptr;
    }



    bool addChild(Node *p, Node *u)
     {
        if (p == nullptr)
        {
            root = u;
        }
        else
        {

            if ((u->value) < (p->value))
                p->left = u;
            else if ((u->value) > (p->value))
                p->right = u;
            else
                return false;
            u->parent = p;

        }
        n++;
        return true;
    }


    void remove(int x)
    {
        Node *u = find(x);
        if (u == nullptr)
            return;

        if (u->tedad > 1)
        {
            u->tedad--;
            return;
        }

        if (u->left == nullptr || u->right == nullptr)
        {
            splice(u);
            delete u;
        }
        else
        {
            Node *w = u->right;
            while (w->left != nullptr)
            {
                w = w->left;
            }
            u->value = w->value;
            u->tedad = w->tedad;
            splice(w);
            delete w;
        }
    }

    void splice(Node *u)
     {
        Node *q, *p;
        if (u->left != nullptr)
        {
            q = u->left;
        }
        else
        {
            q = u->right;
        }
        if (u == root)
        {
            root = q;
            p = nullptr;
        }
        else
        {
            p = u->parent;
            if (p->left == u)
             {
                p->left = q;
            }
            else
            {
                p->right = q;
            }
        }

        if (q != nullptr)
        {
            q->parent = p;
        }

        n--;
    }


    int findMax()
    {
        Node *node = root;

        if (node == nullptr)
            return 0;
        while (node->right != nullptr)
        {
            node = node->right;
        }

        return node->value;
    }



};





int main()
{
    int q, in;
    cin >> q;


    BST vanet;

    string input;
    Node* result;
    for(int i = 0 ; i < q; i++)
    {
        cin >> input;

        if(input == "+")
        {
            cin >> in;

            vanet.add(in);

        }

        else if(input == "-")
        {
            cin >> in;

            vanet.remove(in);
        }

        else
        {
            int maximum = vanet.findMax();
            if(maximum == 0)
            {
                cout << "Jafar tanhast:(" << endl;

            }

            else
            {
                cout << maximum << endl;
            }

        }
    }





    return 0;
}
