#include "sculptor.h"
#include <stdlib.h>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
    //Copia as dimensões
    nx = _nx;
    ny = _ny;
    nz = _nz;
    v = new Voxel**[nx];
    for(int i=0; i<nx; i++){
        v[i] = new Voxel*[ny];
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
}

Sculptor::~Sculptor(){
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            free(v[i][j]) ;
        }
        free(v[i]);
    }
    free(v) ;
}

void Sculptor::setColor(float r, float g, float b, float a){
    r = r;
    g = g;
    b = b;
    a = a;
}

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}



//Grava a escultura no formato OFF no arquivo filename
void Sculptor::writeOFF(const char *filename){

}

















