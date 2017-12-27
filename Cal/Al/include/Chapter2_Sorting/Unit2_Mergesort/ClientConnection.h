#include <string>
using namespace std;

class ClientConnection
{
    public:
        ClientConnection(string, int);
        int getNum();
    private:
        string name;
        int num;
};
