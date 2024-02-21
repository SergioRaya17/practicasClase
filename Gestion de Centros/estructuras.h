#include <stdio.h>
#include <string.h>

#define LONGITUD_MAXIMA 70
#define NUMERO_CICLOS 3

typedef struct Ciclo {
  char nombre[LONGITUD_MAXIMA];
  int duracion;

  enum Especialidad {
    INFORMATICA,
    ELECTRICIDAD,
    DEPORTES,
    SOCIAL,
    OTRAS
  } especialidad;

  enum Grado {
    BASICO,
    MEDIO,
    SUPERIOR
  } grado;

} Ciclo;
 
typedef struct Centro {
  char nombre[LONGITUD_MAXIMA];
  Ciclo ciclos[NUMERO_CICLOS];
} Centro;

typedef struct InfoAlumno {
  char nombre[LONGITUD_MAXIMA];
  int edad;
} InfoAlumno;

typedef struct Alumno {
  InfoAlumno datos;
  Ciclo ciclo;
  enum Curso {
    PRIMERO,
    SEGUNDO
  } curso;
} Alumno;
