#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LONGITUD_MAXIMA 500

typedef struct{
  char nombreEmpleado[50];
  int idEmpleado;
  float salario;
} Empleado;

typedef struct{
  char nombreProyecto[150];
  int idProyecto;
  char descripcionProyecto[550];
  Empleado *trabajador;
} Proyectos;

void leerCadena(char *cadena, int longitud, bool eliminarIntro);
int main(){
  int numeroTrabajadores;
  int numeroProyectos;
  printf("Vamos a ingresar proyectos, cuántos proyectos quiere agregar a continuación: ");
  scanf("%d", &numeroProyectos);
  Proyectos proyecto[numeroProyectos];
  printf("Vamos a ingresar empleados, cuántos empleados quiere agregar en cada proyecto a continuación: ");
  scanf("%d", &numeroTrabajadores);
  Empleado trabajador[numeroTrabajadores];
  // Matriz de Proyectos-Empleados
  for (int i = 0; i < numeroProyectos; i++)
  {
    // Registro de proyectos
    printf("Vamos a agregar un nuevo proyecto, por favor diga el nombre del Proyecto: ");
    leerCadena(proyecto[i].nombreProyecto, sizeof(proyecto[i].nombreProyecto), true);
    printf("Por favor Introduzca el ID del proyecto: ");
    scanf("%d", &proyecto[i].idProyecto);
    leerCadena(proyecto[i].descripcionProyecto, sizeof(proyecto[i].descripcionProyecto), true);
    for (int j = 0; j < numeroTrabajadores; j++)
    {
      // Registro de Empleados
      printf("Vamos a agregar nombres de los empleados a nuestro proyecto, por favor diga el nombre del un empleado: ");
      leerCadena(trabajador[j].nombreEmpleado, sizeof(trabajador[j].nombreEmpleado), true);
      printf("Por favor Introduzca el ID del empleado: ");
      scanf("%d", &trabajador[j].idEmpleado);
      printf("Por favor concrete el Sueldo del empleado: ");
      scanf("%f", &trabajador[j].salario);
    }
  }
  for (int i = 0; i < numeroProyectos; i++)
  {
    for (int j = 0; j < numeroTrabajadores; j++)
    {
      printf("%s, con ID de proyecto: %d, Descripcion:  %s \n", proyecto[i].nombreProyecto, proyecto[i].idProyecto, proyecto[i].descripcionProyecto);
      printf("%s, con ID: %d, cobra %f \n", trabajador[j].nombreEmpleado, trabajador[j].idEmpleado, trabajador[j].salario);
    }
  }
}
void leerCadena(char *cadena, int longitud, bool eliminarIntro) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  fgets(cadena, longitud, stdin);
  if (eliminarIntro) cadena[strlen(cadena)-1] = '\0';
}