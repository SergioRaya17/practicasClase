#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LONGITUD_MAXIMA 100
#define NUMERO_CICLOS 3

typedef struct {
  char nombre[LONGITUD_MAXIMA];
  enum Especialidad {
    INFORMATICA,
    ELECTRICIDAD,
    DEPORTES,
    SOCIAL,
    OTRAS
  } especialidad;
  int duracion;
  enum Grado {
    MEDIO,
    SUPERIOR
  } grado;
} Ciclo;

typedef struct {
  char nombre[LONGITUD_MAXIMA];
  Ciclo ciclos[NUMERO_CICLOS];
} Centro;

typedef struct {
  char nombre[LONGITUD_MAXIMA];
  int edad;
} Persona;

typedef struct {
  Persona datos;
  Ciclo ciclo;
  enum Curso {
    PRIMERO,
    SEGUNDO
  } curso;
} Alumno;

void leer_cadena(char *cadena, int longitud, bool eliminar_intro);

int main() {
  int numero_centros;
  printf("¿Cuántos centros supervisas?: ");
  scanf("%d", &numero_centros);
  Centro centros[numero_centros];
  for(int i = 0; i < numero_centros; i++) {
    printf("CENTRO %d\n--------\n\tNombre: ", i+1);
    leer_cadena(centros[i].nombre, sizeof(centros[i].nombre), true);
    for(int j = 0; j < NUMERO_CICLOS; j++) {
      printf("Ciclo %d\n-----\n\tNombre:", j+1);
      leer_cadena(centros[i].ciclos[j].nombre, sizeof(centros[i].ciclos[j].nombre), true);
    }
  }

    return EXIT_SUCCESS;
}


/**
 * Lee una cadena de caracteres desde la entrada estándar y la almacena en un vector de chars.
 *
 * @param cadena        Puntero al vector de chars donde se almacenará la cadena leída.
 * @param longitud      Longitud máxima del vector 'cadena'.
 * @param eliminarIntro Indica si se debe eliminar el salto de línea al final de la cadena leída (true o false).
 *
 * @return              Esta función no devuelve ningún valor explícito.
 *
 * Esta función limpia el buffer de entrada, lee una cadena de caracteres desde la entrada estándar (stdin)
 * utilizando la función fgets, y la almacena en el arreglo 'cadena'. La lectura se detiene cuando se alcanza
 * la longitud máxima especificada o cuando se encuentra un salto de línea, el cual también se puede eliminar
 * de la cadena si se establece la opción 'eliminarIntro' como true.
 */
void leer_cadena(char *cadena, int longitud, bool eliminar_intro) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  fgets(cadena, longitud, stdin);
  if (eliminar_intro) {
    cadena[strlen(cadena)-1] = '\0';
  }
}
