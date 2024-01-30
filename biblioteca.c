#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Para organizar un poco el código las Estructuras Libro/Autor y el enum Categoria son creados en Libro.h
#include "creacionLibro.h"

void disponibilidadLibro(Libro* lista, int numLibro);
void mostrarAutores(Libro* lista, int numLibro);
void AgregarLibro(Libro* lista, int* numLibro);
void MenuGLibros(Libro* lista, int* numLibro);
void InfoLibro(Libro* lista, int* numLibro);
void Menu1(bool *opcion, int* numLibro);
void MenuGPrestamo();
void MenuGAutores();

int main() {
    bool opcion = true;
    int numLibro = 0;

    do {
        Menu1(&opcion, &numLibro);
    } while (opcion);
}

void Inicio() {
    system("clear");
    printf("+ + + + + + SISTEMA DE GESTIÓN BIBLIOTECARIO + + + + + + \n\n");
}

void Menu1(bool *salir, int* numLibro) {
    Libro listaLibros[30];

    Inicio();
    printf("1. Gestión de Libros.\n2. Administración de Autores.\n3. Gestión de "
           "Préstamos y Devoluciones\n\n0. Terminar Programa\nIntroduce tu "
           "opción: ");
    int opcion = getValor(0, 3);
    switch (opcion) {
    case 1:
        MenuGLibros(listaLibros, numLibro);
        break;
    case 2:
        MenuGAutores();
        break;
    case 3:
        MenuGPrestamo();
        break;
    case 0:
        *salir = false;
        break;
    }
}

void MenuGLibros(Libro* lista, int* numLibro){
    Inicio();
    printf("1. Agregar Libros\n2. Mostrar Información.\n3. Buscar Libro\n\n0. "
           "Atras\nIntroduce tu opción: ");
    int opcion = getValor(0,3);
    switch (opcion) {
    case 1:
        AgregarLibro(lista, numLibro);
        break;
    case 2:
        InfoLibro(lista, numLibro);
        break;
    case 3:

        break;
    case 0:

        break;
    }
    
}

void MenuGAutores(){
    Inicio();
    printf("1. Agregar Autores\n2. Mostrar Autores\n3. Libros Autor\n\n0. "
           "Atras\nIntroduce tu opción: ");
}

void MenuGPrestamo(){
    Inicio();
    printf("1. Ingresar Prestamo\n2. Ingresar Devolución\n3. Buscar "
           "Disponibilidad\n\n0. Atras\nIntroduce tu opción: ");
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
    
    *numLibro = *numLibro + 1;
}

// Mostrar los libros y su informacion

void InfoLibro(Libro* lista, int* numLibro) {
    Inicio();

    for (int i = 0; i < *numLibro; i++){
        printf("\n\nLibro %d\n\nTitulo: %s", i + 1, lista[i].titulo);
        mostrarAutores(lista, i);
        printf("\nPublicado: %d\nCategoria: %d\nStock: %d", lista[i].agno, lista[i].categoria, lista[i].stock);
        disponibilidadLibro(lista, i);
    }

    continuar();
}

void mostrarAutores(Libro* lista, int numLibro) {
    for (int i = 0; i < lista[numLibro].numAutor; i++) {
        printf("\n%dº Autor: %s\nEdad: %d\n", i + 1, lista[numLibro].autor[i].nombre, lista[numLibro].autor[i].edad);
    }
}

void disponibilidadLibro(Libro* lista, int numLibro) {
    if (lista[numLibro].disponible) printf("\nDisponible: true");
    else printf("\nDisponible: false");
}
