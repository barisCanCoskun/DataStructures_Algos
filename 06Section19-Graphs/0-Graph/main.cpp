#include<iostream>
#include<unordered_set>
#include<unordered_map>

class Graph
{
private:
    std::unordered_map<std::string, std::unordered_set<std::string>> adjList;
public:
    void printGraph();
    bool addVertex(std::string vertex);
    bool addEdge(std::string vertex1, std::string vertex2);
    bool removeEdge(std::string vertex1, std::string vertex2);
    bool removeVertex(std::string vertex);
};

void Graph::printGraph(){
    // for(const auto &pair: adjList){
    //     std::cout << pair.first << ": [";
    //     for(const auto &s: pair.second)
    //         std::cout << s << ", ";
    //     std::cout << "]" << std::endl;
    // }
    for(const auto &[vertex, edges]: adjList){
        std::cout << vertex << ": [";
        for(const auto &s: edges)
            std::cout << s << ", ";
        std::cout << "]" << std::endl;
    }
}

bool Graph::addVertex(std::string vertex){
    if(!adjList.count(vertex)){
        adjList[vertex];
        return true;
    }
    return false;
}

bool Graph::addEdge(std::string vertex1, std::string vertex2){
    if(adjList.count(vertex1) && adjList.count(vertex2)){
        adjList[vertex1].emplace(vertex2);
        adjList[vertex2].emplace(vertex1);
        return true;
    }
    return false;
}

bool Graph::removeEdge(std::string vertex1, std::string vertex2){
    if(adjList.count(vertex1) && adjList.count(vertex2)){
        adjList[vertex1].erase(vertex2);
        adjList[vertex2].erase(vertex1);
        return true;
    }
    return false;
}

bool Graph::removeVertex(std::string vertex){
    if(!adjList.count(vertex)) return false;
    for(const auto &edge: adjList[vertex]){
        adjList[edge].erase(vertex);
    }
    adjList.erase(vertex);
    return true;
}

int main()
{
    Graph myGraph;
    if(myGraph.addVertex("A"))
        std::cout << "vertex added" << std::endl;

    if(myGraph.addVertex("B"))
        std::cout << "vertex added" << std::endl;
    
    myGraph.printGraph();

    if(myGraph.addEdge("A", "B"))
        std::cout << "Edge in btw A and B connected" << std::endl;
    myGraph.printGraph();

    if(myGraph.addVertex("C"))
        std::cout << "vertex C added" << std::endl;
    myGraph.printGraph();

    if(myGraph.addEdge("A", "C"))
        std::cout << "Edge in btw A and C connected" << std::endl;
    myGraph.printGraph();

    if(myGraph.removeEdge("A", "C"))
        std::cout << "Edge in btw A and C removed" << std::endl;
    myGraph.printGraph();
}















