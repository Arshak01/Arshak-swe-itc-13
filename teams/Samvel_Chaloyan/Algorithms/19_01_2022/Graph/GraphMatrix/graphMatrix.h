class Graph {
    private:
        int** matrix;
        int numberNode;
    public:
        Graph(int node);
        ~Graph();
        void printMatrix();
        void addLink(int row, int column, int weight);
            
};
