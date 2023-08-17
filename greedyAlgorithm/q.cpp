#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isWordPresent(string word, vector<string>& dict);
bool isSafe(int i, int j, vector<vector<bool>>& vis);
vector<string> findWords(vector<vector<char>>& board, vector<string>& dict);
void findWords(vector<vector<char>>& board, vector<vector<bool>>& vis, int i, int j, string word, vector<string>& dict, vector<string>& res) {
vis[i][j] = true;
word += board[i][j];
if (isWordPresent(word, dict)) {
res.push_back(word);
}
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
for (int k = 0; k < 8; k++) {
int new_i = i + dx[k];
int new_j = j + dy[k];
if (isSafe(new_i, new_j, vis)) {
findWords(board, vis, new_i, new_j, word, dict, res);
}
}
vis[i][j] = false;
}
int main() {
int n;
cin >> n;
vector<string> dict(n);
for (int i = 0; i < n; i++) {
cin >> dict[i];
}
int rows, cols;
cin >> rows >> cols;
vector<vector<char>> board(rows, vector<char>(cols));
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
cin >> board[i][j];
}
}
vector<string> res = findWords(board, dict);
for (string word : res) {
cout << word << " ";
}
cout << endl;
return 0;
}
bool isWordPresent(string word, vector<string>& dict) {
for (string dictWord : dict) {
if (dictWord == word) {
return true;
}
}
return false;
}
bool isSafe(int i, int j, vector<vector<bool>>& vis) {
int rows = vis.size();
int cols = vis[0].size();
return (i >= 0 && i < rows && j >= 0 && j < cols && !vis[i][j]);
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& dict) {
int rows = board.size();
int cols = board[0].size();
vector<vector<bool>> vis(rows, vector<bool>(cols, false));
vector<string> res;
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
findWords(board, vis, i, j, "", dict, res);
}
}
return res;
}