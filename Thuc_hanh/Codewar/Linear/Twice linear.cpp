#include<vector>
using namespace std;

class DoubleLinear
{
public:
    static int dblLinear(int n);
};

int DoubleLinear::dblLinear(int n) {
        int  x = 0, y = 0;
    vector<int> u = {1};
        for (int  i = 0; i < n; i++) {
            int nextX = 2 * u[x] + 1, nextY = 3 * u[y] + 1;
                if (nextX <= nextY) {
                    u.push_back(nextX);
                        x++;
                    if (nextX == nextY)
                        y++;
                }
                else {
                    u.push_back(nextY);
                        y++;
                }
        }
        return u[n];

}
