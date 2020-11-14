#include <bits/stdc++.h>
#include <iostream>
#include <thread>
#include <memory>
#include <vector>

using namespace std;

vector<string> split_string(string);

void print(std::vector<bool> vec){
    for(auto val : vec){
        std::cout << val << " ";
    }
    std::cout << "\n";
}
void print(std::vector<int> vec){
    for(auto val : vec){
        std::cout << val << " ";
    }
    std::cout << "\n";
}

void fill_queue(std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>> >& pq, 
                int current_node, std::vector<std::vector<int>> edges, std::vector<bool> visited,
                std::vector<int>& v){
for(const auto& edge : edges){
    if(edge[0] == current_node && visited[edge[1]-1] == false && v[edge[1]-1] > edge[2]){
        pq.push(std::make_pair(edge[2], edge[1]));  
        v[edge[1]-1] = edge[2];
        std::cout << "updated weight is \n";
        print(v);
        std::cout << "current node is " << edge[0] << " filling queue with " << edge[1] << " " << " weiight " << edge[2] << "\n"; }
    else if(edge[1] == current_node&& visited[edge[0]-1] == false && v[edge[0]-1] > edge[2]){
        pq.push(std::make_pair(edge[2], edge[0]));
        v[edge[0]-1] = edge[2];
        std::cout << "updated weight is \n";
    std::cout << "current node is " << edge[1] << " filling queue with " << edge[0] << " " << " weiight " << edge[2] << "\n"; }
}
}

/* void remove_extra_edges(std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>> >& pq, 
                int current_node, std::vector<std::vector<int>> edges, std::vector<bool> visited){
for(const auto& edge : edges){
   if(visited[edge[0]-1] == true && visited[edge[1] - 1] == true){
       edges.erase(edge);
   } 
}
} */


#define INF 9999999
int prims(int n, vector<vector<int>> edges, int current_node) {
    std::vector<bool> visited(n, false);
    std::vector<int> number_existing;
    std::pair<int,int> pi;
    std::vector<int> updated_weights(n, 999999);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>> > pq; 
    visited[current_node-1] = true;
    updated_weights[current_node-1] = 0;
    number_existing.push_back(current_node);
    pq.push(std::make_pair(0, current_node));
    std::vector<int> result;

    while(!pq.empty()){
        int u = pq.top().second;
        std::cout << "vertex: " << u << " weight " << pq.top().first << "\n";
        result.push_back(pq.top().first);
        pq.top();
        visited[u-1] = true;
        print(visited);
        pq.pop();
        std::cout << "filling queue\n";
        fill_queue(pq, u, edges, visited, updated_weights);
       // remove_extra_edges(pq, u, edges, visited);
    }
    return std::accumulate(updated_weights.begin(), updated_weights.end(), 0);

}

/*     5 7

    1 2 20

    1 3 50

    1 4 70

    1 5 90

    2 3 30

    3 4 40

    4 5 60

    2 */

int n{5};
std::vector<std::vector<int>> edges{{1,2,20},{1,3,50},{1,4,70},{1,5,90},{2,3,30},{3,4,40},{4,5,60}};
int start{2};
int main()
{
    int result = prims(n, edges, start);
    std::cout << result << "\n";
    return 0;
}