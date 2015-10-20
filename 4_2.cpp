//
//  4_2.cpp
//  
//
//  Created by Pengyan Qin on 6/26/15.
//
//

#include <iostream>
#include <queue>
#include <cstdlib>
#include <fstream>

using namespace std;

// graph traversal
const int MAX = 100;
int graph[MAX][MAX] = {};

// BFS
// pay attention; check visited, start == end
bool is_route_bfs(int start, int end, int num_pt){
    if(start == end)
        return true;
    queue<int> q;
    int visited[MAX] = {};  // not visited = 0, visited = 1
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i = 0; i < num_pt; ++i){
            if(graph[tmp][i] && !visited[i]){
                q.push(i);
                visited[i] = 1;
                if(i == end)
                    return true;
            }
        }
    }
    return false;
}

// DFS
// difficult to implement
void is_route_dfs(int start, int end, int num_pt, bool &found, int visited[]){
    if(start == end){
        found = true;
        return;
    }
    visited[start] = 1;
    for(int i = 0; i < num_pt; ++i){
        if(graph[start][i] && !visited[i]){
            is_route_dfs(i, end, num_pt, found, visited);
        }
    }
}

int main(){
    ifstream fin;
    string filename = "4_2.in";
    fin.open(filename.c_str());

    if(!fin.is_open()){
        cout << "open failed" << endl;
        exit(1);
    }
    
    int lines = 0;
    int num_pt = 0;
    fin >> num_pt >> lines;
    
    int pstart = 0;
    int pend = 0;
    for(int i = 0; i < lines; ++i){
        fin >> pstart >> pend;
        graph[pstart][pend] = 1;
    }
   /*
    for(int i = 0; i < num_pt; ++i){
        for(int j = 0; j < num_pt; ++j)
            cout << graph[i][j] << " ";
        cout << endl;                     // the matrix representation of the graph
    }
    */
    cout << is_route_bfs(0, 4, num_pt) << endl;
    
    bool found = false;
    int visited[MAX] = {};
    is_route_dfs(0, 4, num_pt, found, visited);
    cout << found << endl;
}
