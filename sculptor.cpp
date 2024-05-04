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
