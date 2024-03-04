#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LONGITUD_MAXIMA 200

typedef struct{
  char nombreEmpleado[LONGITUD_MAXIMA];
  int idEmpleado;
  float salario;
} Empleado;

typedef struct{
  char nombreProyecto[LONGITUD_MAXIMA];
  char descripcionProyecto[LONGITUD_MAXIMA];
  int idProyecto;
  int numEmpleados;
  Empleado *trabajadores;
} Proyecto;

void leerCadena(char *cadena, int longitud, bool eliminarIntro);
void imprimirTodaInfo(int numProyectos, Proyecto *proyectos);
void setDatosEmpleado (Empleado *empleado);
void setDatosProyecto(Proyecto *proyecto);
int getNumProyectos();
int getNumEmpleados();

int main () {
    int numProyectos = getNumProyectos();
    Proyecto proyectos[numProyectos];
    for (int i = 0; i < numProyectos; i++) {
        setDatosProyecto(&proyectos[i]);
    }

    imprimirTodaInfo(numProyectos, proyectos);
}

void imprimirTodaInfo(int numProyectos, Proyecto *proyectos) {
    for (int i = 0; i < numProyectos ; i++) {
        printf("\nId proyecto %d: %d", i + 1, proyectos[i].idProyecto);
        printf("\nNombre: %s", proyectos[i].nombreProyecto),
        printf("\nDescripcion: %s", proyectos[i].descripcionProyecto);
        for (int j = 0; j < proyectos->numEmpleados; j++) {
            printf("\t\n\n\nEmpleado %d", j + 1);
            printf("\t\nNombre: %s", proyectos[i].trabajadores[j].nombreEmpleado);
            printf("\t\nID Empleado: %d", proyectos[i].trabajadores[j].idEmpleado);
            printf("\t\nSalario: %.2lf", proyectos[i].trabajadores[j].salario);
        }
    }
}

int getNumProyectos () {
    int numProyectos;
    printf("Introduce el número de proyectos: ");
    scanf("%d", &numProyectos);

    return numProyectos;
}

int getNumEmpleados () {
    int numEmpleados;
    printf("Introduce el número de empleados: ");
    scanf("%d", &numEmpleados);

    return numEmpleados;
}

void setDatosProyecto(Proyecto *proyecto) {
    printf("Vamos a agregar un nuevo proyecto, por favor diga el nombre del Proyecto: ");
    leerCadena(proyecto->nombreProyecto, sizeof(proyecto->nombreProyecto), true);
    printf("Por favor Introduzca el ID del proyecto: ");
    scanf("%d", &proyecto->idProyecto);
    printf("Introduce la descripcion: ");
    leerCadena(proyecto->descripcionProyecto, sizeof(proyecto->descripcionProyecto), true);

    int numEmpleados = getNumEmpleados();
    Empleado empleados[numEmpleados];
    proyecto->numEmpleados = numEmpleados;
    proyecto->trabajadores = empleados;

    for (int i = 0; i < numEmpleados; i++) {
        setDatosEmpleado(&empleados[i]);
    }
}

void setDatosEmpleado (Empleado *empleado) {
    printf("Vamos a agregar nombres de los empleados a nuestro proyecto, por favor diga el nombre del un empleado: ");
    leerCadena(empleado->nombreEmpleado, sizeof(empleado->nombreEmpleado), true);
    printf("Por favor Introduzca el ID del empleado: ");
    scanf("%d", &empleado->idEmpleado);
    printf("Por favor concrete el Sueldo del empleado: ");
    scanf("%f", &empleado->salario);
}

void leerCadena(char *cadena, int longitud, bool eliminarIntro) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  fgets(cadena, longitud, stdin);
  if (eliminarIntro) cadena[strlen(cadena)-1] = '\0';
}

//    | - - - Explicación Sergio Raya - Ignacio de Loyola - - - |