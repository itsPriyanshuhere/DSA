
#include <bits/stdc++.h>
using namespace std;

int ans(vector<vector<int>> collect)
{
int t = 0;
if (collect.size() == 2)
{
t = (collect[0][0] * collect[1][1] - collect[0][1] * collect[1][0]);
return t;
}
else if (collect.size() == 1)
{
return collect[0][0];
}
else
{
for (int p = 0; p < collect[0].size(); p++)
{
vector<vector<int>> collectTemp;
for (int i = 1; i < collect.size(); i++)
{
vector<int> row;
for (int j = 0; j < collect[i].size(); j++)
{
if (j != p)
{
row.push_back(collect[i][j]);
}
}

if (row.size() > 0)
{
collectTemp.push_back(row);
}
}

t = t + collect[0][p] * pow(-1, p) * ans(collectTemp);
}
return t;
}
}

int spanningTrees(vector<vector<int>> &adjoint, int first, int second)
{
int total[first] = {0};
for (int i = 0; i < first; i++)
{
for (int j = 0; j < first; j++)
{
if (adjoint[i][j] == 1)
{
total[i]++;
}
}
}

for (int i = 0; i < first; i++)
{
adjoint[i][i] = total[i];
}

for (int i = 0; i < first; i++)
{
for (int j = 0; j < first; j++)
{
if ((i != j) and adjoint[i][j] == 1)
{
adjoint[i][j] = -1;
}
}
}

vector<vector<int>> subSolve(first - 1, vector<int>(first - 1));

for (int i = 1; i < first; i++)
{
for (int j = 1; j < first; j++)
{
subSolve[i - 1][j - 1] = adjoint[i][j];
}
}

return ans(subSolve);
}

int main()
{
int first, second;
cin >> first >> second;
vector<vector<int>> adjoint(first, vector<int>(first, 0));
for (int i = 0; i < second; i++)
{
int entry1, entry2;
cin >> entry1 >> entry2;
adjoint[entry1 - 1][entry2 - 1] = 1;
adjoint[entry2 - 1][entry1 - 1] = 1;
}

cout << spanningTrees(adjoint, first, second) << endl;
}
