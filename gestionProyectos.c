#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Empleado {
    char nombreCompleto[50];
    int numEmpl;
    float salario;

} Empleado;

typedef struct Proyecto {
    char nombre[50];
    char descripcion[80];
    int id;
    Empleado listEmpl[5];
} Proyecto;

void mostrarEquipoProyecto(Proyecto* proyecto);

int main () {
    Proyecto proyecto;

    printf("Introduce el nombre del proyecto: ");
    fgets(proyecto.nombre,sizeof(proyecto.nombre),stdin);
    proyecto.nombre[strlen(proyecto.nombre) - 1] = '\0';
    getchar();

    printf("Introduce la descripción");
    fgets(proyecto.descripcion,sizeof(proyecto.descripcion),stdin);
    proyecto.descripcion[strlen(proyecto.descripcion) - 1] = '\0';
    getchar();

    printf("Introduce la id: ");
    scanf("%d", proyecto.id);
    getchar();
    
}

void agregarEmpleadoAProyecto() {

}

void mostrarEquipoProyecto(Proyecto* proyecto) {

}