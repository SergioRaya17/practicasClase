#include <stdio.h>
#include <string.h>
#include "./estructuras.h"
#include "./utils.h"

void crearCentro (Centro centro);

int main () {
    int numCentros;
    printf("Introduce el número de centros: ");
    scanf("%d", &numCentros);

    Centro centros[numCentros];
    for (int i = 0; i < numCentros; i++) {
        crearCentro(centros[i]);
    }
}

void crearCentro (Centro centro) {
    printf("Introduce el nombre del centro: ");
    fgets(centro.nombre, sizeof(centro.nombre), stdin);
    centro.nombre[strlen(centro.nombre) - 1] = '\0';
    while (getchar() != '\n');

    for (int i = 0; i < NUMERO_CICLOS; i++) {
        printf("Dale un nombre al ciclo %d del %s\nIntroduce el nombre: ", i, centro.nombre);
        fgets(centro.ciclos[i].nombre, sizeof(centro.ciclos[i].nombre), stdin);
        centro.ciclos[i].nombre[strlen(centro.ciclos[i].nombre) - 1] = '\0';
        while (getchar() != '\n');

        
    }


}


