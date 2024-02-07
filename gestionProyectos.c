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

void agregarEmpleadoAProyecto(Proyecto* proyecto, int empleado);
void mostrarEquipoProyecto(Proyecto* proyecto);
void mostrarDatosEmpleados(Proyecto* proyecto);
void mostrarDatosProyecto(Proyecto* proyecto);

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

    for (int i = 0; i < sizeof(proyecto.listEmpl)/sizeof(Empleado); i++) {
        agregarEmpleadoAProyecto(&proyecto, i);
    }

    mostrarEquipoProyecto(&proyecto);
}

void agregarEmpleadoAProyecto(Proyecto* proyecto, int empleado) {

    printf("Introduce el nombre del empleado %d:", empleado + 1);
    fgets(proyecto->listEmpl[empleado].nombreCompleto,sizeof(proyecto->listEmpl[empleado].nombreCompleto),stdin);
    proyecto->listEmpl[empleado].nombreCompleto[strlen(proyecto->listEmpl[empleado].nombreCompleto) - 1] = '\0';
    getchar();

    printf("Introduce el numero de empleado: ");
    scanf("%d", proyecto->listEmpl[empleado].numEmpl);

    printf("Introduce el numero de empleado: ");
    scanf("%lf", proyecto->listEmpl[empleado].salario);
}

void mostrarEquipoProyecto(Proyecto* proyecto) {
    mostrarDatosProyecto(proyecto);
    mostrarDatosEmpleados(proyecto);
}

void mostrarDatosProyecto(Proyecto* proyecto) {
    printf("\nNombre del proyecto: %s", proyecto->nombre);
    printf("\nDescripcion: %s", proyecto->descripcion);
    printf("\nID: %d", proyecto->id);
}

void mostrarDatosEmpleados(Proyecto* proyecto) {
    for (int i = 0; i < sizeof(proyecto->listEmpl)/sizeof(Empleado); i++) {
        printf("\nNombre del empleado: %s", proyecto->listEmpl[i].nombreCompleto);
        printf("\nNumero de empleado: %d", proyecto->listEmpl[i].numEmpl);
        printf("\nID: %.2lf", proyecto->listEmpl[i].salario);
    }
}