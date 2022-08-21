class GraphImplementation {
    private:
        int** matrix;
        int vertices;
    
    public:
        GraphImplementation(int);
        void addEdge(int, int, int);
        void print();
};
