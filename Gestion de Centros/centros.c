#include <stdio.h>
#include <string.h>
#include "./estructuras.h"
#include "./utils.h"

int menuInicial();
void menuCompleto();
void crearCentro(Centro centro);
void crearCliclos(Centro centro);
void creacionAlumnos(Centro centro);

int main () {
    int numCentros = 0;

    if (!(numCentros)) {
        int opcion = 0;
        do {
            opcion = menuInicial();
            switch (opcion) {
            case 1:
                
                break;
            case 2:
                
                break;
            case 0:
                
                break;
            default:
                break;
            }
        } while (opcion =! 0);
        
        printf("\nIntroduce el número de centros: ");
        scanf("%d", &numCentros);

        Centro centros[numCentros];
        for (int i = 0; i < numCentros; i++) {
            crearCentro(centros[i]);
            crearCliclos(centros[i]);
        }

    } else {

    }
    
}

void crearCentro (Centro centro) {
    printf("\nIntroduce el nombre del centro: ");
    fgets(centro.nombre, sizeof(centro.nombre), stdin);
    centro.nombre[strlen(centro.nombre) - 1] = '\0';
    while (getchar() != '\n');
}

void crearCliclos (Centro centro) {
    for (int i = 0; i < NUMERO_CICLOS; i++) {
        printf("\nDale un nombre al ciclo %d del %s\nIntroduce el nombre: ", i + 1, centro.nombre);
        fgets(centro.ciclos[i].nombre, sizeof(centro.ciclos[i].nombre), stdin);
        centro.ciclos[i].nombre[strlen(centro.ciclos[i].nombre) - 1] = '\0';
        while (getchar() != '\n');

        printf("\nIntroduce la duración del ciclo en años: ");
        scanf("%d", &centro.ciclos[i].duracion);

        printf("\nSelecciona si el ciclo es de grado:\n\t1. Basico\n\t2. Medio\n\t3. Superior\n\nIntroduce tu opcion: ");
        centro.ciclos[i].grado = getValor(1,3) - 1;

        printf("\nSelecciona la especialidad del ciclo:\n\t1. Informatica\n\t2. Electricidad\n\t3. Deportes\n\t4. Social\n\t5. Otras\n\nIntroduce tu opcion: ");
        centro.ciclos[i].especialidad = getValor(1,5) - 1;

        creacionAlumnos(centro);
    }
}

void creacionAlumnos (Centro centro) {
    int numAlumnos;
    printf("\nIntroduce el número de alumnos con el que cuenta este ciclo: ");
    scanf("%d", &numAlumnos);

    Alumno alumnos[numAlumnos];
    for (int i = 0; i < numAlumnos; i++) {
        printf("\nIntroduce el nombre del alumno: ");
        fgets(alumnos[i].datos.nombre, sizeof(alumnos[i].datos.nombre), stdin);
        alumnos[i].datos.nombre[strlen(alumnos[i].datos.nombre) - 1] = '\0';
        while (getchar() != '\n');

        printf("\nIntroduce la edad del alumno: ");
        scanf("%d", &alumnos[i].datos.edad);

        printf("\nCursos\n\n1. Primero\n\n2. Segundo: \n\nIntroduce la opcion:");
        alumnos[i].curso = getValor(1,2) - 1;
    }

    centro.ciclos->alumnos = alumnos;
    centro.ciclos->numAlumnos = numAlumnos;
}

int menuInicial () {
    system("clear");
    printf("+ + + + + | SISTEMA DE GESTION DE CENTROS | + + + + +\n\n1. Creación de centros\n\n2. Ayuda\n\n\n0. Terminar programa\nIntroduce la opción: ");
    return getValor(0,2);
}

void menuCompleto () {
    system("clear");
    printf("+ + + + + | SISTEMA DE GESTION DE CENTROS | + + + + +\n\n1. Añadir Centro\n\n2. Añadir Alumnos\n\n3. Ayuda\n\n\n0. Terminar programa\nIntroduce la opción: ");
    return getValor(0,3);
}

void si () {
    return "Tus muertos";
}