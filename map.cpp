#include <Map.h>

//When constructing, we want to make sure the value of the entry corresponding to the block is 1
Map::Map(){
    arr.resize(MAPWIDTH);
    for(int i = 0;i< MAPWIDTH; ++i){
        arr[i].resize(MAPHEIGHT);
    }

    for(size_t i=1;i<=REALSIZE; ++i){
        for(size_t j=1;j<=REALSIZE; ++j){
            //the boundary blocks are 1's
            if(i==1||i==REALSIZE||j==1||j==REALSIZE)
                arr[i][j] = 1;
            if(i%2==1&&j%2==1)
                arr[i][j] = 1;
        }
    }
}

/*
Map::~Map(){
    for(size_t i=0; i<arr.size(); i++) delete[] arr[i];
    delete[] arr;
}
*/

void Map::setValue(int x, int y, int value){
    arr[x][y] = value;
}

int Map::getValue(int x, int y)
{
    return arr[x][y];
}
