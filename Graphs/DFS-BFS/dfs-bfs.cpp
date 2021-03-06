#include <bits/stdc++.h>

using namespace std;

#define fore(i, s, e) for(int i = s; i < e; i++)
#define pb push_back
#define fst first
#define snd second

const int N = 100000;
const int M = 1000;

int n, m;

// Tree //

vector<int> tree[N];
bool visitedTree[N];

void dfsTree(int node, int father = -1) {
    for(int child : tree[node]) if(child != father) {
        dfsTree(child, node);
    }
}

void dfsTreeStack(int node) {
    stack<int> s;
    s.push(node);
    while(!s.empty()) {
        int v = s.top(); s.pop();
        visitedTree[v] = true;
        for(int child : tree[node]) if(!visitedTree[child]) s.push(child);
    }
}

void bfsTree(int node) {
    queue<int> q;
    q.push(node);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        visitedTree[v] = true;
        for(int child : tree[node]) if(!visitedTree[child]) q.push(child);
    }
}

// Graph //

vector<int> graph[N];
bool visitedGraph[N];

void dfsGraph(int node) {
    visitedGraph[node] = true;
    for(int child : graph[node]) if(!visitedGraph[child]) {
        dfsGraph(child);
    }
}

void dfsGraphStack(int node) {
    // Complete
}

void bfsGraph(int node) {
    // Complete
}

// Grid //

char grid[M][M];
bool visitedGrid[M][M];

typedef pair<int, int> state;

state operator+(state a, state b) {
    return {a.fst + b.fst, a.snd + b.snd};
}

state moves[4] = {
    /* UP */ {0, 1},
    /* RIGHT */ {1, 0},
    /* DOWN */ {0, -1},
    /* LEFT */ {-1, 0}
};

void visit(state s) {
    visitedGrid[s.fst][s.snd] = true;
}

bool valid(state s) {
    return 0 <= s.fst && s.fst < n && 0 <= s.snd && s.snd < m; 
}

bool visited(state s) {
    return visitedGrid[s.fst][s.snd];
}

bool obstacle(state s) {
    return grid[s.fst][s.snd] == '#';
}

void dfsGrid(state current) {
    visit(current);
    for(state move : moves) {
        state next = current + move;
        if(valid(next) && !visited(next) && !obstacle(next)) dfsGrid(next);
    }
}

void dfsGridStack(state current) {
    // Complete
}

void bfsGrid(state current) {
    // Complete
}



int main() {
    // Tree //
    cin >> n;
    fore(i, 0, n - 1) {
        int a, b; cin >> a >> b; a--, b--;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfsTree(0);
    dfsTreeStack(0);

    // Graph //
    cin >> n >> m;
    fore(i, 0, m) {
        int a, b; cin >> a >> b; a--, b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dfsGraph(0);
    dfsGraphStack(0);

   // Grid //
   cin >> n >> m;
   fore(i, 0, n) cin >> grid[i];

   dfsGrid({0, 0});
   dfsGridStack({0, 0});

    return 0;
}