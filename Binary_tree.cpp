#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Node
{
public:
    int v;
    Node *left;
    Node *right;

    Node(int v)
    {
        this->v = v;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input_tree()
{
    int v;
    cin >> v;
    Node *root;
    if (v == -1)
        root = NULL;
    else
        root = new Node(v);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        Node *myleft;
        Node *myright;
        if (l == -1)
            myleft = NULL;
        else
            myleft = new Node(l);
        if (r == -1)
            myright = NULL;
        else
            myright = new Node(r);
        p->left = myleft;
        p->right = myright;
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
void print(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        cout << p->v << " ";
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
}
bool leaf(Node *p)
{
    return (p->left == NULL && p->right == NULL); // true return hobe
}
void print_leaf(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    vector<int> v;
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        if (leaf(p))
        {
            v.push_back(p->v);
        }
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int x : v)
    {
        cout << x << " ";
    }
}
int level_counting(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int level = 0;
    while (!q.empty())
    {
        pair<Node *, int> pr = q.front();
        Node *node = pr.first;
        int l = pr.second;
        q.pop();
        level = l;
        if (node->left)
            q.push({node->left, l + 1});
        if (node->right)
            q.push({node->right, l + 1});
    }
    return level;
}
void print_outerNode(Node *root)
{
    stack<int> st;
    if (root == NULL)
        return;
    print_outerNode(root->left);
    if (root->left == NULL)
    {
        print_outerNode(root->right);
        st.push(root->v);
    }
    else
        st.push(root->v);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
void printRightBoundary(Node* node) {
    if (!node) return;

    if (node->right) {
        cout << node->v << " ";
        printRightBoundary(node->right);
    } else if (node->left) {
        cout << node->v << " ";
        printRightBoundary(node->left);
    }
    else cout << node->v << " ";
}
void print_outerNode1(Node *root)
{
    stack<int>  v; 
    if (root == NULL)
        return;
    if (root->right)
    {
        print_outerNode1(root->right);
        v.push(root->v);
        
    }
    else if(root->left ){
        print_outerNode1(root->left);        
        v.push(root->v);
    }
    else{
        v.push(root->v);
        
    }
    while (!v.empty())
    {
        cout << v.top() << " ";
        v.pop();
    }
}
int main()
{
    Node *root = input_tree();
    if(root) print_outerNode(root);
    if(root->right ) print_outerNode1(root->right);
}