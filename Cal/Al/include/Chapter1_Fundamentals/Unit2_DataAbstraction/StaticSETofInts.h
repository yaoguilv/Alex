class StaticSETofInts
{
    private:
        int len;
        int* a;
    public:
        StaticSETofInts(int* keys, int length);
        bool contains(int key);
        int rank(int key);
};
