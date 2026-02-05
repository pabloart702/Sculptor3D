#include "sculptor.h"

/**
 * \mainpage
 * @brief Sculptor 3D implementado em C++, tendo como objetivo criar esculturas em 3D utilizando cubos
 * @return
 */

int main(){
    //Cria um escultor cuja matriz tem 27x27x55 voxels
    Sculptor torre(25, 25, 55);
    //Muda a cor do voxel
    torre.setColor(0.22, 0.23, 0.23, 1.0); //parte sombreada da torre

    //Primeira camada da torre
    torre.putBox(0, 24, 0, 24, 0, 0);
    torre.cutBox(7, 17, 24, 24, 0, 0);
    torre.cutBox(7, 17, 0, 0, 0, 0);
    torre.cutBox(24, 24, 7, 17, 0, 0);
    torre.cutBox(0, 0, 7, 17, 0, 0);
    torre.cutBox(1, 23, 1, 23, 0, 0);

    //Segunda camada da torre
    torre.putBox(1, 23, 1, 23, 1, 1);
    torre.cutBox(6, 18, 23, 23, 1, 1);
    torre.cutBox(6, 18, 1, 1, 1, 1);
    torre.cutBox(23, 23, 6, 18, 1, 1);
    torre.cutBox(1, 1, 6, 18, 1, 1);
    torre.cutBox(2, 22, 2, 22, 1, 1);

    //Terceira camada da torre
    torre.setColor(0.79, 0.69, 0.56, 1.0); //cor da torre
    torre.putBox(2, 22, 2, 22, 2, 2);
    torre.cutBox(6, 18, 22, 22, 2, 2);
    torre.cutBox(6, 18, 2, 2, 2, 2);
    torre.cutBox(22, 22, 6, 18, 2, 2);
    torre.cutBox(2, 2, 6, 18, 2, 2);
    torre.cutBox(3, 21, 3, 21, 2, 2);

    //Quarta camada da torre
    torre.putBox(3, 21, 3, 21, 3, 3);
    torre.cutBox(6, 18, 21, 21, 3, 3);
    torre.cutBox(6, 18, 3, 3, 3, 3);
    torre.cutBox(21, 21, 6, 18, 3, 3);
    torre.cutBox(3, 3, 6, 18, 3, 3);
    torre.cutBox(4, 20, 4, 20, 3, 3);

    //Quinta camada da torre
    torre.putBox(3, 21, 3, 21, 4, 4); //Cria o quadrado completo
    torre.cutBox(7, 17, 21, 21, 4, 4); //Corta o x com y no maximo
    torre.cutBox(7, 17, 3, 3, 4, 4); //Corta o x com y no minimo
    torre.cutBox(21, 21, 7, 17, 4, 4); //Corta o y com x no maximo
    torre.cutBox(3, 3, 7, 17, 4, 4); //Corta o y com o x no minimo
    torre.cutBox(4, 20, 4, 20, 4, 4); //Corta o quadrado interno

    //Sexta camada da torre
    torre.putBox(4, 20, 4, 20, 5, 5);
    torre.cutBox(7, 17, 20, 20, 5, 5);
    torre.cutBox(7, 17, 4, 4, 5, 5);
    torre.cutBox(20, 20, 7, 17, 5, 5);
    torre.cutBox(4, 4, 7, 17, 5, 5);
    torre.cutBox(5, 19, 5, 19, 5, 5);

    //Setima camada da torre
    torre.putBox(4, 20, 4, 20, 6, 6);
    torre.cutBox(8, 16, 20, 20, 6, 6);
    torre.cutBox(8, 16, 4, 4, 6, 6);
    torre.cutBox(20, 20, 8, 16, 6, 6);
    torre.cutBox(4, 4, 8, 16, 6, 6);
    torre.cutBox(5, 19, 5, 19, 6, 6);

    //Oitava camada da torre
    torre.putBox(5, 19, 5, 19, 7, 7);
    torre.cutBox(10, 14, 19, 19, 7, 7);
    torre.cutBox(10, 14, 5, 5, 7, 7);
    torre.cutBox(19, 19, 10, 14, 7, 7);
    torre.cutBox(5, 5, 10, 14, 7, 7);
    torre.cutBox(6, 18, 6, 18, 7, 7);

    //Nona camada da torre
    torre.putBox(5, 19, 5, 19, 8, 8);
    torre.cutBox(6, 18, 6, 18, 8, 8);

    //Decima camada da torre
    torre.putBox(5, 19, 5, 19, 9, 9);
    torre.cutBox(6, 18, 6, 18, 9, 9);

    //Decima segunda camada da torre
    torre.setColor(0.22, 0.23, 0.23, 1.0); //parte sombreada da torre
    torre.putBox(4, 20, 4, 20, 10, 10);
    torre.cutBox(5, 19, 5, 19, 10, 10);

    //Decima terceira camada da torre
    torre.setColor(0.79, 0.69, 0.56, 1.0); //cor da torre
    torre.putBox(4, 20, 4, 20, 11, 11);
    torre.cutBox(7, 17, 7, 17, 11, 11);

    //Decima quarta camada da torre
    torre.putBox(7, 17, 7, 17, 12, 12);
    torre.cutBox(10, 14, 17, 17, 12, 12);
    torre.cutBox(10, 14, 7, 7, 12, 12);
    torre.cutBox(17, 17, 10, 14, 12, 12);
    torre.cutBox(7, 7, 10, 14, 12, 12);
    torre.cutBox(8, 16, 8, 16, 12, 12);

    //Decima quinta camada da torre
    torre.putBox(7, 17, 7, 17, 13, 13);
    torre.cutBox(10, 14, 17, 17, 13, 13);
    torre.cutBox(10, 14, 7, 7, 13, 13);
    torre.cutBox(17, 17, 10, 14, 13, 13);
    torre.cutBox(7, 7, 10, 14, 13, 13);
    torre.cutBox(8, 16, 8, 16, 13, 13);

    //Decima sexta camada da torre
    torre.putBox(7, 17, 7, 17, 14, 14);
    torre.cutBox(11, 13, 17, 17, 14, 14);
    torre.cutBox(11, 13, 7, 7, 14, 14);
    torre.cutBox(17, 17, 11, 13, 14, 14);
    torre.cutBox(7, 7, 11, 13, 14, 14);
    torre.cutBox(8, 16, 8, 16, 14, 14);

    //Decima setima camada da torre
    torre.putBox(8, 16, 8, 16, 15, 15);
    torre.cutBox(11, 13, 16, 16, 15, 15);
    torre.cutBox(11, 13, 8, 8, 15, 15);
    torre.cutBox(16, 16, 11, 13, 15, 15);
    torre.cutBox(8, 8, 11, 13, 15, 15);
    torre.cutBox(9, 15, 9, 15, 15, 15);

    torre.putBox(8, 16, 8, 16, 16, 16);
    torre.cutBox(11, 13, 16, 16, 16, 16);
    torre.cutBox(11, 13, 8, 8, 16, 16);
    torre.cutBox(16, 16, 11, 13, 16, 16);
    torre.cutBox(8, 8, 11, 13, 16, 16);
    torre.cutBox(9, 15, 9, 15, 16, 16);

    torre.putBox(8, 16, 8, 16, 17, 17);
    torre.cutBox(12, 12, 16, 16, 17, 17);
    torre.cutBox(12, 12, 8, 8, 17, 17);
    torre.cutBox(16, 16, 12, 12, 17, 17);
    torre.cutBox(8, 8, 12, 12, 17, 17);
    torre.cutBox(9, 15, 9, 15, 17, 17);

    //
    torre.putBox(9, 15, 9, 15, 18, 18);
    torre.cutBox(12, 12, 15, 15, 18, 18);
    torre.cutBox(12, 12, 9, 9, 18, 18);
    torre.cutBox(15, 15, 12, 12, 18, 18);
    torre.cutBox(9, 9, 12, 12, 18, 18);
    torre.cutBox(10, 14, 10, 14, 18, 18);

    torre.putBox(9, 15, 9, 15, 19, 19);
    torre.cutBox(12, 12, 15, 15, 19, 19);
    torre.cutBox(12, 12, 9, 9, 19, 19);
    torre.cutBox(15, 15, 12, 12, 19, 19);
    torre.cutBox(9, 9, 12, 12, 19, 19);
    torre.cutBox(10, 14, 10, 14, 19, 19);

    torre.putBox(9, 15, 9, 15, 20, 20);
    torre.cutBox(12, 12, 15, 15, 20, 20);
    torre.cutBox(12, 12, 9, 9, 20, 20);
    torre.cutBox(15, 15, 12, 12, 20, 20);
    torre.cutBox(9, 9, 12, 12, 20, 20);
    torre.cutBox(10, 14, 10, 14, 20, 20);

    torre.setColor(0.22, 0.23, 0.23, 1.0); //parte sombreada da torre
    torre.putBox(8, 16, 8, 16, 21, 21);
    torre.cutBox(9, 15, 9, 15, 21, 21);

    torre.setColor(0.79, 0.69, 0.56, 1.0); //cor da torre
    torre.putBox(8, 16, 8, 16, 22, 22);
    torre.cutBox(9, 15, 9, 15, 22, 22);

    torre.putBox(9, 15, 9, 15, 23, 23);
    torre.cutBox(12, 12, 15, 15, 23, 23);
    torre.cutBox(12, 12, 9, 9, 23, 23);
    torre.cutBox(15, 15, 12, 12, 23, 23);
    torre.cutBox(9, 9, 12, 12, 23, 23);
    torre.cutBox(10, 14, 10, 14, 23, 23);

    torre.putBox(10, 14, 10, 14, 24, 24);
    torre.cutBox(11, 13, 11, 13, 24, 24);

    torre.putBox(10, 14, 10, 14, 25, 25);
    torre.cutBox(11, 11, 14, 14, 25, 25);
    torre.cutBox(13, 13, 14, 14, 25, 25);
    torre.cutBox(11, 11, 10, 10, 25, 25);
    torre.cutBox(13, 13, 10, 10, 25, 25);
    torre.cutBox(10, 10, 11, 11, 25, 25);
    torre.cutBox(14, 14, 11, 11, 25, 25);
    torre.cutBox(10, 10, 13, 13, 25, 25);
    torre.cutBox(14, 14, 13, 13, 25, 25);
    torre.cutBox(11, 13, 11, 13, 25, 25);

    torre.putBox(10, 14, 10, 14, 26, 26);
    torre.cutBox(11, 11, 14, 14, 26, 26);
    torre.cutBox(13, 13, 14, 14, 26, 26);
    torre.cutBox(11, 11, 10, 10, 26, 26);
    torre.cutBox(13, 13, 10, 10, 26, 26);
    torre.cutBox(10, 10, 11, 11, 26, 26);
    torre.cutBox(14, 14, 11, 11, 26, 26);
    torre.cutBox(10, 10, 13, 13, 26, 26);
    torre.cutBox(14, 14, 13, 13, 26, 26);
    torre.cutBox(11, 13, 11, 13, 26, 26);

    torre.putBox(10, 14, 10, 14, 27, 27);
    torre.cutBox(11, 13, 11, 13, 27, 27);

    //

    torre.putBox(10, 14, 10, 14, 28, 28);
    torre.cutBox(11, 11, 14, 14, 28, 28);
    torre.cutBox(13, 13, 14, 14, 28, 28);
    torre.cutBox(11, 11, 10, 10, 28, 28);
    torre.cutBox(13, 13, 10, 10, 28, 28);
    torre.cutBox(10, 10, 11, 11, 28, 28);
    torre.cutBox(14, 14, 11, 11, 28, 28);
    torre.cutBox(10, 10, 13, 13, 28, 28);
    torre.cutBox(14, 14, 13, 13, 28, 28);
    torre.cutBox(11, 13, 11, 13, 28, 28);

    torre.putBox(10, 14, 10, 14, 29, 29);
    torre.cutBox(11, 13, 11, 13, 29, 29);

    //

    torre.putBox(10, 14, 10, 14, 30, 30);
    torre.cutBox(11, 11, 14, 14, 30, 30);
    torre.cutBox(13, 13, 14, 14, 30, 30);
    torre.cutBox(11, 11, 10, 10, 30, 30);
    torre.cutBox(13, 13, 10, 10, 30, 30);
    torre.cutBox(10, 10, 11, 11, 30, 30);
    torre.cutBox(14, 14, 11, 11, 30, 30);
    torre.cutBox(10, 10, 13, 13, 30, 30);
    torre.cutBox(14, 14, 13, 13, 30, 30);
    torre.cutBox(11, 13, 11, 13, 30, 30);

    torre.putBox(10, 14, 10, 14, 31, 31);
    torre.cutBox(11, 13, 11, 13, 31, 31);

    //

    torre.putBox(10, 14, 10, 14, 32, 32);
    torre.cutBox(11, 11, 14, 14, 32, 32);
    torre.cutBox(13, 13, 14, 14, 32, 32);
    torre.cutBox(11, 11, 10, 10, 32, 32);
    torre.cutBox(13, 13, 10, 10, 32, 32);
    torre.cutBox(10, 10, 11, 11, 32, 32);
    torre.cutBox(14, 14, 11, 11, 32, 32);
    torre.cutBox(10, 10, 13, 13, 32, 32);
    torre.cutBox(14, 14, 13, 13, 32, 32);
    torre.cutBox(11, 13, 11, 13, 32, 32);

    torre.putBox(10, 14, 10, 14, 33, 33);
    torre.cutBox(11, 13, 11, 13, 33, 33);

    torre.putBox(10, 14, 10, 14, 34, 34);
    torre.cutBox(11, 13, 11, 13, 34, 34);

    torre.putBox(10, 14, 10, 14, 35, 35);
    torre.cutBox(11, 13, 11, 13, 35, 35);

    //1
    torre.putBox(11, 13, 11, 13, 36, 36);
    torre.cutBox(12, 12, 12, 12, 36, 36);

    torre.putBox(11, 13, 11, 13, 37, 37);
    torre.cutBox(12, 12, 11, 11, 37, 37);
    torre.cutBox(12, 12, 13, 13, 37, 37);
    torre.cutBox(13, 13, 12, 12, 37, 37);
    torre.cutBox(11, 11, 12, 12, 37, 37);
    torre.cutBox(12, 12, 12, 12, 37, 37);

    //2
    torre.putBox(11, 13, 11, 13, 38, 38);
    torre.cutBox(12, 12, 12, 12, 38, 38);

    torre.putBox(11, 13, 11, 13, 39, 39);
    torre.cutBox(12, 12, 11, 11, 39, 39);
    torre.cutBox(12, 12, 13, 13, 39, 39);
    torre.cutBox(13, 13, 12, 12, 39, 39);
    torre.cutBox(11, 11, 12, 12, 39, 39);
    torre.cutBox(12, 12, 12, 12, 39, 39);

    //3
    torre.putBox(11, 13, 11, 13, 40, 40);
    torre.cutBox(12, 12, 12, 12, 40, 40);

    torre.putBox(11, 13, 11, 13, 41, 41);
    torre.cutBox(12, 12, 11, 11, 41, 41);
    torre.cutBox(12, 12, 13, 13, 41, 41);
    torre.cutBox(13, 13, 12, 12, 41, 41);
    torre.cutBox(11, 11, 12, 12, 41, 41);
    torre.cutBox(12, 12, 12, 12, 41, 41);

    //4
    torre.putBox(11, 13, 11, 13, 42, 42);
    torre.cutBox(12, 12, 12, 12, 42, 42);

    torre.putBox(11, 13, 11, 13, 43, 43);
    torre.cutBox(12, 12, 11, 11, 43, 43);
    torre.cutBox(12, 12, 13, 13, 43, 43);
    torre.cutBox(13, 13, 12, 12, 43, 43);
    torre.cutBox(11, 11, 12, 12, 43, 43);
    torre.cutBox(12, 12, 12, 12, 43, 43);

    //5
    torre.putBox(11, 13, 11, 13, 44, 44);
    torre.cutBox(12, 12, 12, 12, 44, 44);

    torre.putBox(11, 13, 11, 13, 45, 45);
    torre.cutBox(12, 12, 11, 11, 45, 45);
    torre.cutBox(12, 12, 13, 13, 45, 45);
    torre.cutBox(13, 13, 12, 12, 45, 45);
    torre.cutBox(11, 11, 12, 12, 45, 45);
    torre.cutBox(12, 12, 12, 12, 45, 45);

    torre.putBox(11, 13, 11, 13, 46, 46);
    torre.cutBox(12, 12, 12, 12, 46, 46);

    torre.setColor(0.22, 0.23, 0.23, 0.5); //parte sombreada da torre
    torre.putBox(10, 14, 10, 14, 47, 47);
    torre.cutBox(11, 13, 11, 13, 47, 47);

    torre.setColor(0.79, 0.69, 0.56, 1.0);
    torre.putBox(10, 14, 10, 14, 48, 48);
    torre.cutBox(11, 13, 11, 13, 48, 48);

    torre.setColor(0.22, 0.23, 0.23, 0.5);


    torre.putBox(11, 13, 11, 13, 49, 49);
    torre.cutBox(12, 12, 12, 12, 49, 49);

    torre.putBox(12, 12, 12, 12, 50, 50);

    //Lua
    torre.setColor(0.86, 0.86, 0.85, 1.0);
    torre.putSphere(3, 21, 45, 3);

    // grava a escultura digital no arquivo "torre.off"
    torre.writeOFF("torre.off");

    return 0;
}
