#include <iostream>
#include <cmath>
#include <queue>
#define N 8
#define M 8
#define WALL -1
#define WAY -2
#define WEIGHT_CELL 10

int px[N * M], py[N * M];
int openList[N][M];
int closeList[N][M];
int parentList[N][M];
int dirMap[N][M];
int length = 0;
int countDir = 4;
int len;
int **map;

struct Node {
    int _x;
    int _y;
    int _G;
    int _F;
    
    Node(int x, int y, int G, int F);
    void updateF(int x, int y);
    int estimate(int x, int y);
    void nextLevel();
};

Node::Node(int x, int y, int G, int F):
    _x(x),
    _y(y),
    _G(G),
    _F(F)
{}

void Node::updateF(int x, int y) {
    _F = estimate(x, y) * WEIGHT_CELL + _G;
}

int Node::estimate(int x, int y) {
    return sqrt((x - _x) * (x - _x)) + sqrt((y- _y) * (y - _y));
}

void Node::nextLevel() {
    _G += WEIGHT_CELL;
}

bool operator < (const Node &_x, const Node &_y) {
    return _x._F < _y._F;
}

bool findPath(int i1, int j1, int i2, int j2) {
    std::priority_queue<Node> listNode;
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};
    int x = 0, y = 0;
    
    if (map[i1][j1] == WALL || map[i2][j2] == WALL) {
        return false;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            openList[i][j] = 0;
            closeList[i][j] = 0;
        }
    }
    Node n0(i1, j1, 0, 0);
    n0.updateF(i2, j2);
    listNode.push(n0);
    openList[i1][j1] = n0._F;
    
    while (!listNode.empty()) {
        x = listNode.top()._x;
        y = listNode.top()._y;
        listNode.pop();
        openList[x][y] = 0;
        closeList[x][y] = 1;
        
        if (x == i2 && y == j2) {
            while (!(x == i1 && y == j1)) {
                int j = dirMap[x][y];
                
                px[length] = x;
                py[length] = y;
                length++;
                x += di[j];
                y += dj[j];
            }
            px[length] = i1;
            py[length] = j1;
        }
        
        for (int k = 0; k < countDir; k++) {
            int ix = x + di[k], jy = y + dj[k];
            
            if (ix < N && ix >= 0 && jy < M && jy >= 0 && map[ix][jy] == WAY && closeList[ix][jy] != 1) {
                Node m0(ix, jy, 0, 0);
                m0.nextLevel();
                m0.updateF(i2, j2);
                
                if (openList[ix][jy] == 0) {
                    openList[ix][jy] = m0._F;
                    listNode.push(m0);
                    dirMap[ix][jy] = (k + countDir / 2) % countDir;
                } else if (openList[ix][jy] > m0._F) {
                    openList[ix][jy] = m0._F;
                    dirMap[ix][jy] = (k + countDir / 2) % countDir;
                }
            }
        }
    }
    if (x != i2 && y != j2) {
        return false;
    }
    
    return true;
}

void initMap(int **map) {
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (rand() % 4 == 0) {
                map[i][j] = WALL;
            } else {
                map[i][j] = WAY;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        map[i][0] = WALL;
        map[0][i] = WALL;
        map[i][N - 1] = WALL;
        map[N - 1][i] = WALL;
    }
}

void printMap(int **map) {
    std::cout << "MAP" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printWay() {
    std::cout << "WAY" << std::endl;
    for (int i = length; i > 0; i--) {
        std::cout << px[i] << " " << py[i] << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    map = new int*[N];
    
    for (int i = 0; i < M; i++) {
        map[i] = new int[M];
    }
    
    initMap(map);
    printMap(map);
    findPath(1, 5, 4, 5);
    printWay();
    for (int i = 0; i < N; i++) {
        delete map[i];
    }
    delete[] map;
    
    return 0;
}
