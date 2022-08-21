#include <iostream>
#include <queue>
#include <vector>

bool isVisited(int v, std::vector<int> &path);
void printpath(std::vector<int> &path);

void findPathsUsingBFS(std::vector<std::vector<int>> &graph, int src, int dst) {
    std::queue<std::vector<int>> queue;

    std::vector<int> currentPath;
    currentPath.push_back(src);
    queue.push(currentPath);

    while (!queue.empty()) {
        currentPath = queue.front();
        queue.pop();
        int last = currentPath[currentPath.size() - 1];

        if (last == dst) {
            printpath(currentPath);
        }

        for (int i = 0; i < graph[last].size(); i++) {
            if (!isVisited(graph[last][i], currentPath)) {
                std::vector<int> newPath(currentPath);
                newPath.push_back(graph[last][i]);
                queue.push(newPath);
            }
        }
    }
}

void printpath(std::vector<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        std::cout << path[i] << " ";
    }
    std::cout << std::endl;
}

bool isVisited(int v, std::vector<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        if (v == path[i]) {
            return true;
        }
    }
    return false;
}