#include <stdio.h>
#include <string.h>

#define LONGITUD_MAXIMA 100

// Definición de enumeraciones y estructuras.
typedef enum Especialidad { 
    INFORMATICA, 
    ELECTRONICA, 
    ENERGIAS_RENOVABLES 
    
} Especialidad;
 
typedef enum Grado { 
    BASICO, 
    MEDIO, 
    SUPERIOR 

} Grado;

typedef enum Curso { 
    PRIMERO, 
    SEGUNDO, 
    TERCERO 

} Curso;

typedef struct Alumno {
    char nombre[50];
    int edad;
    Curso curso;

} Alumno;

typedef struct Ciclo {
    Especialidad especialidad;
    Grado grado;
    int duracion;
    Alumno alumnos[30]; 
    int numAlumnos; 

} Ciclo;

typedef struct centro {
    char nombre[LONGITUD_MAXIMA];
    Ciclo ciclos[3]; 

} Centro;

void leerCentro(Centro *centro);
void leerCiclo(Ciclo *ciclo);
void leerAlumno(Alumno *alumno);
void imprimirCentros(Centro centros[], int numCentros);

int main() {
    int numCentros;
    printf("Ingrese el número de centros: ");
    scanf("%d", &numCentros);
    getchar(); 
    Centro centros[numCentros];

    for (int i = 0; i < numCentros; i++) {
        leerCentro(&centros[i]);
    }

    imprimirCentros(centros, numCentros);

    return 0;
}

void leerCentro(Centro *centro) {
    printf("Ingrese el nombre del centro: ");
    fgets(centro->nombre, 100, stdin);
    centro->nombre[strcspn(centro->nombre, "\n")] = 0; // Elimina el salto de línea

    for (int i = 0; i < 3; i++) {
        printf("Ciclo %d:\n", i + 1);
        leerCiclo(&centro->ciclos[i]);
    }
}

void leerCiclo(Ciclo *ciclo) {
    int especialidad, grado;

    printf("\nEspecialidad \n1. Informatica \n2. Electronica \n3. Energías Renovables\nSelecciona: ");
    scanf("%d", &especialidad);
    ciclo->especialidad = (Especialidad)especialidad - 1;

    printf("\nGrado \n1. Basico \n2. Medio \n3. Superior\nSelecciona: ");
    scanf("%d", &grado);
    ciclo->grado = (Grado)grado - 1;

    printf("\nIntroduce los años que dura el ciclo: ");
    scanf("%d", &ciclo->duracion);

    printf("\nIntroduce el número de alumnos: ");
    scanf("%d", &ciclo->numAlumnos);
    getchar(); // Limpia el buffer de entrada

    for (int i = 0; i < ciclo->numAlumnos; i++) {
        leerAlumno(&ciclo->alumnos[i]);
    }
}

void leerAlumno(Alumno *alumno) {
    printf("Nombre del alumno: ");
    fgets(alumno->nombre, 50, stdin);
    alumno->nombre[strcspn(alumno->nombre, "\n")] = 0; // Elimina el salto de línea

    printf("Edad del alumno: ");
    scanf("%d", &alumno->edad);
    getchar(); // Limpia el buffer de entrada

    int curso;
    printf("\nCurso \n1. Primero \n2. Segundo \n3. Tercero \nSelecciona: ");
    scanf("%d", &curso);
    alumno->curso = (Curso)curso - 1;
    getchar(); // Limpia el buffer de entrada
}

void imprimirCentros(Centro centros[], int numCentros) {
    for (int i = 0; i < numCentros; i++) {
        printf("\nCentro: %s\n", centros[i].nombre);
        for (int j = 0; j < 3; j++) {
            Ciclo ciclo = centros[i].ciclos[j];
            printf("\n\tCiclo %d: Especialidad %d, Grado %d, Duración %d años, Alumnos %d\n", j + 1, ciclo.especialidad, ciclo.grado, ciclo.duracion, ciclo.numAlumnos);
            for (int k = 0; k < ciclo.numAlumnos; k++) {
                Alumno alumno = ciclo.alumnos[j];
                printf("\t\tAlumno %d: \n\t\tNombre: %s, Edad: %d, Curso: %d\n", k + 1, alumno.nombre, alumno.edad, alumno.curso);
            }
        }
    }
}
