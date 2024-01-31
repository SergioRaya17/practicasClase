#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Para organizar un poco el código las Estructuras Libro/Autor y el enum Categoria son creados en Libro.h
#include "creacionLibro.h"

void ComprovarDisponibilidad(Libro* lista, int* numLibro);
void IngresarDevolucion(Libro* lista, int* numLibro);
void disponibilidadLibro(Libro* lista, int numLibro);
void IngresarPrestamo(Libro* lista, int* numLibro);
void BuscarPorAutor(Libro* lista, int* numLibro);
void mostrarAutores(Libro* lista, int numLibro);
void MenuGPrestamo(Libro* lista, int* numLibro);
void AgregarLibro(Libro* lista, int* numLibro);
int BuscarTitulo(Libro* lista, int* numLibro);
void MenuGAutores(Libro* lista, int* numLibro);
void MenuGLibros(Libro* lista, int* numLibro);
void InfoLibro(Libro* lista, int* numLibro);
void InfoLibroNum(Libro* lista, int num);
void Menu1();
void Inicio();

//No me gusta que el Main sea tan chico pero en este caso no veo otra solución.
int main() {
    Libro listaLibros[30];
    bool opcion = true;
    int numLibro = 0;

    do {
        Menu1();
        int eleccion = getValor(0, 2);
        switch (eleccion) {
            case 1:
                MenuGLibros(listaLibros, &numLibro);
                break;
            case 2:
                MenuGPrestamo(listaLibros, &numLibro);
                break;
            case 0:
                opcion = false;
                break;
        }
    } while (opcion);
}

void Menu1() {
    Inicio();
    printf("1. Gestión de Libros.\n2. Gestión de "
           "Préstamos y Devoluciones\n\n0. Terminar Programa\nIntroduce tu "
           "opción: ");
}

void MenuGLibros(Libro* lista, int* numLibro){
    Inicio();
    printf("1. Agregar Libros\n2. Mostrar Información.\n3. Buscar Libro\n4. Mostrar Autores\n\n0. "
           "Atras\nIntroduce tu opción: ");
    int opcion = getValor(0,4);
    switch (opcion) {
    case 1:
        AgregarLibro(lista, numLibro);
        break;
    case 2:
        InfoLibro(lista, numLibro);
        break;
    case 3:
        BuscarTitulo(lista, numLibro);
        break;
    case 4:
        for (int i = 0; i < *numLibro; i++) {
            mostrarAutores(lista, i);
        }
        continuar();
    break;
    }
    
}

void MenuGPrestamo(Libro* lista, int* numLibro){
    Inicio();
    printf("1. Ingresar Prestamo\n2. Ingresar Devolución\n3. Buscar "
           "Disponibilidad\n\n0. Atras\nIntroduce tu opción: ");

    int opcion = getValor(0,3);
    switch (opcion) {
        case 1:
            IngresarPrestamo(lista, numLibro);
            break;
        case 2:
            IngresarDevolucion(lista, numLibro);
            break;
        case 3:
            ComprovarDisponibilidad(lista, numLibro);
            break;
    }
}

void Inicio() {
    system("clear");
    printf("+ + + + + + SISTEMA DE GESTIÓN BIBLIOTECARIO + + + + + + \n\n");
}

// CREACION DE LIBROS

void AgregarLibro(Libro* lista, int* numLibro) {
    Inicio();
    
    AgregandoTitulo(lista, numLibro);
    lista[*numLibro].numAutor = 0;
    AgregarAutores(lista, numLibro);
    AgregarAgno(lista, numLibro);
    AgregarStock(lista, numLibro);
    SeleccionarCategoria(lista, numLibro);
    
    (*numLibro)++;
}

// Mostrar los libros y su informacion

void InfoLibro(Libro* lista, int* numLibro) {
    Inicio();
    for (int i = 0; i < *numLibro; i++) InfoLibroNum(lista, i);
    continuar();
}

void InfoLibroNum(Libro* lista, int num) {
    printf("\n\nLibro %d\n\nTitulo: %s", num + 1, lista[num].titulo);
    mostrarAutores(lista, num);
    printf("\nPublicado: %d\nCategoria: %d\nStock: %d", lista[num].agno, lista[num].categoria, lista[num].stock);
    disponibilidadLibro(lista, num);
}

void mostrarAutores(Libro* lista, int numLibro) {
    for (int i = 0; i < lista[numLibro].numAutor; i++) {
        printf("\n\nAutor: %s\nEdad: %d\n", lista[numLibro].autor[i].nombre, lista[numLibro].autor[i].edad);
    }
}

void disponibilidadLibro(Libro* lista, int numLibro) {
    if (lista[numLibro].disponible) printf("\nDisponible: true");
    else printf("\nDisponible: false");
}

// Buscar Libro introduciendo el titulo
int BuscarTitulo(Libro* lista, int* numLibro) {
    char titulo[50];
    int numLibroBuscado = -1;

    Inicio();
    printf("\nBusca por titulo: ");
    getchar();
    fgets(titulo, sizeof(titulo), stdin);
    titulo[strlen(titulo) - 1] = '\0';

    for(int i = 0; i < *numLibro; i++) {
        if (!(strcmp(lista[i].titulo, titulo))) numLibroBuscado = i;
    }

    if (!(numLibroBuscado == -1)) {
        InfoLibroNum(lista, numLibroBuscado);
        continuar();
        return numLibroBuscado;
    } else { 
        printf("\n\nLibro no encontrado");
        continuar();
        return -1;
    }
}

void IngresarPrestamo(Libro* lista, int* numLibro) {
    int num = BuscarTitulo(lista, numLibro);
    printf("\n\nPrestamo registrado ... ");
    (lista[num].disponible)--;
}

void IngresarDevolucion(Libro* lista, int* numLibro) {
    int num = BuscarTitulo(lista, numLibro);
    printf("\n\nPrestamo registrado ... ");
    (lista[num].disponible)++;
}

void ComprovarDisponibilidad(Libro* lista, int* numLibro) {
    BuscarTitulo(lista, numLibro);
}