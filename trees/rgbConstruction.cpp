#include <iostream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, g, b;
        cin >> r >> g >> b;

        if (r + g < b)
        {
            cout << -1 << "\n";
            continue;
        }

        string nodes = "BRG";
        b--;
        r--;
        g--;
        int posOfR = 2, posOfG = 3;
        int currentNode = 3;

        vector<pair<int, int>> edges;
        edges.push_back(make_pair(1, 2));
        edges.push_back(make_pair(2, 3));

        if (b)
        {
            nodes += "B";
            b--;
            edges.push_back(make_pair(currentNode, currentNode + 1));
            currentNode++;
        }

        while (b && r)
        {
            nodes += "RB";
            edges.push_back(make_pair(posOfG, currentNode + 1));
            edges.push_back(make_pair(currentNode + 1, currentNode + 2));
            b--;
            r--;
            currentNode += 2;
        }

        while (b && g)
        {
            nodes += "GB";
            edges.push_back(make_pair(posOfR, currentNode + 1));
            edges.push_back(make_pair(currentNode + 1, currentNode + 2));
            b--;
            g--;
            currentNode += 2;
        }

        while (r--)
        {
            nodes += "R";
            edges.push_back(make_pair(currentNode, currentNode + 1));
            currentNode++;
        }

        while (g--)
        {
            nodes += "G";
            edges.push_back(make_pair(currentNode, currentNode + 1));
            currentNode++;
        }

        cout << nodes << "\n";

        for (auto p : edges)
            cout << p.first << " " << p.second << "\n";
    }
    return 0;
}