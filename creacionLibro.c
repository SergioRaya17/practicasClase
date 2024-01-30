#include <stdio.h>
#include <time.h>
#include "Libro.h"
#include "utils.h"

void SeleccionarCategoria(Libro* lista, int* numLibro) {
    printf("\n\nCategorias . . .\n1. Ciencia_Ficcion\n2. Misterio\n3. Historico\n4. Ensayo\n5. Infantil\n6. Ciencia\n7. Educativo\n\nIntroduce el numero de la categoria: ");
    int eleccion = getValor(1,7);
    lista[*numLibro].categoria = eleccion - 1;
}

void AgregarStock(Libro* lista, int* numLibro) {
    printf("\n\nIntroduce el stock del que disponemos de este libro: ");
    int stock = getValor(1,1000);
    lista[*numLibro].stock = stock;
}

void AgregarAgno(Libro* lista, int* numLibro) {
    printf("\n\nIntroduce el año de publicacion del libro: ");
    lista[*numLibro].agno = getValor(0,getAgnoActual());
}

void AgregandoTitulo(Libro* lista, int* numLibro) {
    char titulo[50];

    printf("Agregando libro ... \n\nIntroduzca el Título: ");
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strlen(titulo) - 1] = '\0';
    strcpy(lista[*numLibro].titulo, titulo);
    while (getchar() != '\n');
}

void AgregarAutores(Libro* lista, int* numLibro) {
    int numAutores, edad;
    char nombre[50];

    printf("\nIntroduzca el numero de autores que contiene este libro: ");
    numAutores = getValor(1, 5);

    for (int i = 0; i < numAutores; i++) {
        printf("\n\nIntroduce el nombre del autor %d: ", i + 1);
        fgets(nombre, sizeof(nombre), stdin);
        nombre[strlen(nombre) -1] = '\0';
        while (getchar() != '\n');

        strcpy(lista[*numLibro].autor[i].nombre, nombre); 

        printf("Introduce la edad del autor: ");
        edad = getValor(16, 125);
        lista[*numLibro].autor[i].edad = edad;
        lista[*numLibro].numAutor++;
    }
}