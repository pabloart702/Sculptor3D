#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

/**
 * @brief Construtor da classe sculptor3D, com parâmetros que definem as dimenções da modelagem e faz a aloação dinamica da memória de acordo com os parâmetros fornecidos
 * @param _nx Dimensão do eixo x (em voxels)
 * @param _ny Dimensão do eixo y (em voxels)
 * @param _nz Dimensão do eixo z (em voxels)
 */

Sculptor::Sculptor(int _nx, int _ny, int _nz){ // Construtor com argumentos
    if(_nx <= 0 || _ny <= 0 || _nz <= 0){
        std::cerr << "Numero de dimensoes invalidos" << std::endl;
        exit(1);
    }

    nx = _nx;
    ny = _ny;
    nz = _nz;

    //alocacao dinamica de memoria
    v = new Voxel**[nx];
    for(int i=0; i<nx; i++){
        v[i] = new Voxel*[ny];
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nz];
        }
    }
}

/**
 * @brief Destrutor da classe Sculptor3D, faz a liberação da memória alocada
 */

Sculptor::~Sculptor(){
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete[] v[i][j] ;
        }
        delete[] v[i];
    }
    delete[] v;
}

/**
 * @brief Define a cor e a opacidade dos voxel criados após a "setagem" da coloração
 * @param r Escala de 0.0 a 1.0 de vermelho
 * @param g Escala de 0.0 a 1.0 de verde
 * @param b Escala de 0.0 a 1.0 de azul
 * @param a Escala de 0.0 a 1.0 da transparência
 */

void Sculptor::setColor(float r, float g, float b, float a){
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

/**
 * @brief Cria um voxel na escultura
 * @param x Coordenada x do voxel a ser criado
 * @param y Coordenada y do voxel a ser criado
 * @param z Coordenada z do voxel a ser criado
 */

void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

/**
 * @brief Remove um voxel na escultura
 * @param x Coordenada x do voxel a ser removido
 * @param y Coordenada y do voxel a ser removido
 * @param z Coordenada z do voxel a ser removido
 */

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}

/**
 * @brief Cria um paralelepípedo na escultura
 * @param x0 Coordenada inicial em x
 * @param x1 Coordenada final em x
 * @param y0 Coordenada inicial em y
 * @param y1 Coordenada final em y
 * @param z0 Coordenada inicial em z
 * @param z1 Coordenada final em y
 */

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=x0; i<=x1; i++){
        for(int j=y0; j<=y1; j++){
            for(int k=z0; k<=z1; k++){
                Sculptor::putVoxel(i, j, k);
            }
        }
    }
}

/**
 * @brief Remove um paralelepípedo na esultura
 * @param x0 Coordenada inicial em x
 * @param x1 Coordenada final em x
 * @param y0 Coordenada inicial em y
 * @param y1 Coordenada final em y
 * @param z0 Coordenada inicial em z
 * @param z1 Coordenada final em y
 */

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for(int i=x0; i<=x1; i++){
        for(int j=y0; j<=y1; j++){
            for(int k=z0; k<=z1; k++){
                Sculptor::cutVoxel(i, j, k);
            }
        }
    }
}

/**
 * @brief Cria uma esfera na escultura
 * @param xcenter Posição do centro da esfera no eixo x
 * @param ycenter Posição do centro da esfera no eixo y
 * @param zcenter Posição do centro da esfera no eixo z
 * @param radius Raio da esfera a ser criada
 */

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
/*
    int x, y, z;
     //x² + y² + z² = r²

    for(int i=(xcenter-radius); i<=(xcenter+radius); i++){
        x = (i-xcenter)*(i-xcenter);
        for(int j=(ycenter-radius); j<=(ycenter+radius); j++){
            y = (j-ycenter)*(j-ycenter);
            for(int k=(zcenter-radius); k<=(zcenter+radius); k++){
                z = (k-zcenter)*(k-zcenter);
                if((x + y + z)<=(radius*radius)){
                    putVoxel(i, j, k);
                }
            }
        }
    }
*/
    int x, y, z;

    for(int i=(xcenter-radius); i<=(xcenter+radius); i++){
        x = (i-xcenter)*(i-xcenter);
        for(int j=(ycenter-radius); j<=(ycenter+radius); j++){
            y = (j-ycenter)*(j-ycenter);
            for(int k=(zcenter-radius); k<=(zcenter+radius); k++){
                z = (k-zcenter)*(k-zcenter);
                if(x + y + z <= (radius*radius)){
                    putVoxel(i,j,k);
                }
            }
        }
    }
}

/**
 * @brief Remove uma esfera da escultura
 * @param xcenter Posição do centro da esfera no eixo x
 * @param ycenter Posição do centro da esfera no eixo y
 * @param zcenter Posição do centro da esfera no eixo z
 * @param radius Raio da esfera a ser removida
 */

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    int x, y, z;
     //x² + y² + z² = r²

    for(int i=(xcenter-radius); i<=(xcenter+radius); i++){
        x = (i-xcenter)*(i-xcenter);
        for(int j=(ycenter-radius); j<=(ycenter+radius); j++){
            y = (j-ycenter)*(j-ycenter);
            for(int k=(zcenter-radius); k<=(zcenter+radius); k++){
                z = (k-zcenter)*(k-zcenter);
                if(x + y + z <= (radius*radius)){
                    cutVoxel(i,j,k);
                }
            }
        }
    }
}

/**
 * @brief Escreve a matriz 3D de voxels no arquivo OFF
 * @param filename Nome do arquivo que ira ser criado para que possa ser visualizado em um software 3d
 */

void Sculptor::writeOFF(const char *filename){
    int nVoxel = 0;
    for(int x=0;x<nx;x++){
        for(int y=0;y<ny;y++){
            for(int z=0;z<nz;z++){
                if(v[x][y][z].show == true){
                    nVoxel++;
                }
            }
        }
    }
    // abre o arquivo
    std::ofstream fout;
    fout.open(filename);
    if (!fout.is_open()) {
        std::cerr << ("Erro ao abrir o arquivo ") << std::endl;
        exit(2);
    }

    fout << "OFF\n";
    fout << 8 * nVoxel << " " << 6 * nVoxel << " " << 0 << "\n";

    fout << std::fixed;
    fout << std::setprecision(2);

    for(int x = 0; x < nx; x++){
        for(int y = 0; y < ny; y++){
            for(int z = 0; z < nz; z++){
                if(v[x][y][z].show == true){
                    fout << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl; //P0
                    fout << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl; //P1
                    fout << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << std::endl; //P2
                    fout << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << std::endl; //P3
                    fout << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl; //P4
                    fout << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl; //P5
                    fout << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << std::endl; //P6
                    fout << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << std::endl; //P7
                }
            }
        }
    }
    int indiceVortex = 0;
    for(int x = 0; x < nx; x++){
        for(int y = 0; y < ny; y++){
            for(int z = 0; z < nz; z++){
                if(v[x][y][z].show == true){

                    fout << "4 " << 0 + indiceVortex << " "
                         << 3 + indiceVortex << " "
                         << 2 + indiceVortex << " "
                         << 1 + indiceVortex << " "
                         << (float)v[x][y][z].r << " " << (float)v[x][y][z].g << " "
                         << (float)v[x][y][z].b << " " << (float)v[x][y][z].a << " " << std::endl;

                    fout << "4 " << 4 + indiceVortex << " "
                         << 5 + indiceVortex << " "
                         << 6 + indiceVortex << " "
                         << 7 + indiceVortex << " "
                         << (float)v[x][y][z].r << " " << (float)v[x][y][z].g << " "
                         << (float)v[x][y][z].b << " " << (float)v[x][y][z].a << " " << std::endl;

                    fout << "4 " << 0 + indiceVortex << " "
                         << 1 + indiceVortex << " "
                         << 5 + indiceVortex << " "
                         << 4 + indiceVortex << " "
                         << (float)v[x][y][z].r << " " << (float)v[x][y][z].g << " "
                         << (float)v[x][y][z].b << " " << (float)v[x][y][z].a << " " << std::endl;

                    fout << "4 " << 0 + indiceVortex << " "
                         << 4 + indiceVortex << " "
                         << 7 + indiceVortex << " "
                         << 3 + indiceVortex << " "
                         << (float)v[x][y][z].r << " " << (float)v[x][y][z].g << " "
                         << (float)v[x][y][z].b << " " << (float)v[x][y][z].a << " " << std::endl;

                    fout << "4 " << 3 + indiceVortex << " "
                         << 7 + indiceVortex << " "
                         << 6 + indiceVortex << " "
                         << 2 + indiceVortex << " "
                         << (float)v[x][y][z].r << " " << (float)v[x][y][z].g << " "
                         << (float)v[x][y][z].b << " " << (float)v[x][y][z].a << " " << std::endl;

                    fout << "4 " << 1 + indiceVortex << " "
                         << 2 + indiceVortex << " "
                         << 6 + indiceVortex << " "
                         << 5 + indiceVortex << " "
                         << (float)v[x][y][z].r << " " << (float)v[x][y][z].g << " "
                         << (float)v[x][y][z].b << " " << (float)v[x][y][z].a << " " << std::endl;

                    indiceVortex += 8;
                }
            }
        }
    }
    std::cout << "Salvo" << std::endl;
    fout.close();
}
