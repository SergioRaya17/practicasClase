#include <stdio.h>

typedef struct Empleado {
    char nombreCompleto[50];
    int numEmpl;
    float salario;

} Empleado;

typedef struct Proyecto {
    char nombre[50];
    char descripcion[80];
    int id;
    Empleado* listEmpl;
};


int main () {
    
}