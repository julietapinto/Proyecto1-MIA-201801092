#include <iostream>
#include <string>


using namespace std;

struct fdisk
{
    int tamano;
    string letra;
    string path;
    string tipoparti;
    string ajuste;
    string elimina;
    string nombre;
    string add;
};
fdisk *fdisc = new fdisk[20];