#include <iostream>
#define N 8
#define M 8
#define WALL -1
#define WAY -2

int px[N * M], py[N * M];
int len;
int **map;

bool findPath(int i1, int j1, int i2, int j2) {
    bool stop = true;
    int di[4] = {1, 0, -1, 0};
    int dj[4] = {0, 1, 0, -1};
    
    if (map[i1][j1] == WALL || map[i2][j2] == WALL) {
        return false;
    }
    int d = 0;
    
    map[i1][j1] = 0;
    int countIter = 0;
    
    do {
        countIter++;
        stop = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == d) {
                    for (int k = 0; k < 4; k++) {
                        int ix = i + di[k], jy = j + dj[k];
                        
                        if (ix < N && ix >= 0 && jy < M && jy >= 0 && map[ix][jy] == WAY) {
                            stop = false;
                            map[ix][jy] = d + 1;
                        }
                    }
                }
            }
        }
        d++;
    } while (!stop && map[i2][j2] == WAY);
    if (map[i2][j2] == WAY) {
        return false;
    }
    len = map[i2][j2];
    int i = i2;
    int j = j2;
    
    d = len;
    
    while (d > 0) {
        px[d] = i;
        py[d] = j;
        d--;
        for (int k = 0; k < 4; k++) {
            int ix = i + di[k], jy = j + dj[k];
            
            if (ix < N && ix >= 0 && jy < M && jy >= 0 && map[ix][jy] == d) {
                i = ix;
                j = jy;
                break;
            }
        }
    }
    px[0] = i1;
    py[0] = j1;
    std::cout << countIter;
    
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
    for (int i = 0; i < len + 1; i++) {
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
    if (findPath(1, 5, 4, 5)) {
        printWay();
    } else {
        std::cout << "Way not found" << std::endl;
    }
    printMap(map);
    for (int i = 0; i < N; i++) {
        delete map[i];
    }
    delete[] map;
    
    return 0;
}
