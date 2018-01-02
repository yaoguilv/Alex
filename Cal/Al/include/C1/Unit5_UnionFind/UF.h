class UF {
    private:
        int * id;
        int count;
        int initSize;
    public:
        UF(int N);
        ~UF();
        int size();
        bool connected(int p, int q);
        int find(int p);
        void unionF(int p, int q);
};
