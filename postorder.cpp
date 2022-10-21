#include <iostream>

using namespace std;

int tree[] = { -1, 1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1 }, root = 1;

void postorder(int node)
{
    if(tree[node] == -1) return;

    int left = 2*node, right = left+1;

    postorder(left);
    postorder(right);

    cout << tree[node] << ' ';

    return;
}

int main()
{
    cout << "Postorder traversal: ";
    postorder(root);
    cout << '\n';

    return 0;
}
