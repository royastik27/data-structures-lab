#include <iostream>

using namespace std;

char tree[1000] = { '\0', 'G', 'A', 'B', 'C', 'D', 'E', 'F', '\0', 'K', '\0', '\0', '\0', '\0' };
int root = 1;

bool FIND(int node, char ch)
{
    if(tree[node] == '\0') return false;

    else if(tree[node] == ch) return true;

    int left = 2*node, right= left+1;

    return FIND(left, ch) || FIND(right, ch);
}

int main()
{
    char ch;

    cout << "Enter the node: ";
    cin >> ch;

    int left = 2*root;

    if(FIND(left, ch))
        cout << "Given node exists in the left subtree of G\n";
    else cout << "Given node does not exist in the left subtree of G\n";

    return 0;
}
