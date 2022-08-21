#include <unordered_map>
#include <list>

class GraphHashMap {
    private:
        std::unordered_map < std::string, std::list < std::pair < std::string, int > > > l;
    public:
        void addEdge(std::string, std::string, int);
        void printGraph();
};

