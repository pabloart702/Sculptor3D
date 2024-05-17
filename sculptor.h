#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel {
    float r,g,b; // Cores
    float a; // Trasnparencia
    bool show; // Incluido ou nao
};

class Sculptor {
private:
    Voxel ***v; // 3D matrix
    int nx,ny,nz; // Dimensões
    float r,g,b,a; // Cor do desenho atual
public:
    Sculptor(int _nx, int _ny, int _nz); //Construtor
    ~Sculptor(); //Destrutor
    void setColor(float r, float g, float b, float a); //Define a cor atual do desenho
    void putVoxel(int x, int y, int z); //Ativa o voxel na posição (x,y,z) fazendo show = true e atribuindo a cor atual
    void cutVoxel(int x, int y, int z); //Desativa o voxel na posição (x,y,z) fazendo show = false
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1); //Ativa todos os voxels no intervalo x[x0,x1], y, z e atribui aos mesmos a cor de desenho atual
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1); //Desativa todos os voxels no intervalo x[x0,x1], y, z
    void putSphere(int xcenter, int ycenter, int zcenter, int radius); //Ativa todos os vexels que satisfazem á equação da esfera e atribui aos mesmos a cor atual de desenho
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius); //Desativa todos os vexels que satisfazem á equação da esfera
    //void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); //Ativa todos os voxels que satisfazem à equção do elipsoide e atribui aos mesmos a cor atual de desenho
    //void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz); //Desativa todos os voxels que satisfazem à equção do elipsoide
    void writeOFF(const char* filename); //Grava a escultura no formato OFF no arquivo filename
};


#endif // SCULPTOR_H
