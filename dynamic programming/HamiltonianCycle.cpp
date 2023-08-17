#include <iostream>
using namespace std;

const int psy = 10;
int graph[psy][psy]; 
bool alreadyVisit[psy]; 
int route[psy]; 


bool visit(int node, int pos, int psy);

void showResult(int psy) {
for (int i = 0; i < psy; i++) {
cout << route[i] << " ";
}
cout << route[0] << endl; 
}

bool hamiltonianCycle(int pos, int psy);

int main() {
int psy, vaL; 
cin >> psy >> vaL;
for (int i = 0; i < vaL; i++) {
int u, node;
cin >> u >> node;
graph[u][node] = 1;
graph[node][u] = 1;
}
route[0] = 0; 
alreadyVisit[0] = true;
if (!hamiltonianCycle(1, psy)) {
cout << "No Hamiltonian cycle exists." << endl;
}
return 0;
}

bool hamiltonianCycle(int pos, int psy) {
if (pos == psy) {
if (graph[route[pos-1]][route[0]]) {
  
showResult(psy);
return true;
}
else {
return false;
}
}
for (int node = 1; node < psy; node++) {
if (visit(node, pos, psy)) {
route[pos] = node;
alreadyVisit[node] = true;
if (hamiltonianCycle(pos+1, psy)) {
return true;
}
alreadyVisit[node] = false;
}
}
return false;
}

bool visit(int node, int pos, int psy) {
if (!graph[route[pos-1]][node]) {
return false;
}
for (int i = 0; i < pos; i++) {
if (route[i] == node) {
return false; 
}
}
return true;
}
