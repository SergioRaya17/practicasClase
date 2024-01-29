#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void AgregarLibro(Libro lista[]);
void MenuGLibros(Libro lista[]);
int getValor(int min, int max);
void Menu1(bool *opcion);
void MenuGPrestamo();
void MenuGAutores();
void continuar();

int NUM_LIBRO = 0;

typedef enum Categoria {
    Ciencia_Ficcion,
    Misterio,
    Historico,
    Ensayo,
    Infantil,
    Ciencia,
    Educativo

} Categoria;

typedef struct Autor {
    char nombre[50];
    int edad;
    // Libros que ha escrito

} Autor;

typedef struct Libro {
    char titulo[50];
    Autor autor[5]; // Buscar la maner de especificar num
    int agno;
    int stock;
    bool disponible;

} Libro;

int main() {
    bool opcion = true;

    do {
        Menu1(&opcion);
    } while (opcion);
}

void Inicio() {
    system("clear");
    printf("+ + + + + + SISTEMA DE GESTIÓN BIBLIOTECARIO + + + + + + \n\n");
}

// - - - - - - - - - - // MENUS // - - - - - - - - - - //

void Menu1(bool *salir) {
    Libro listaLibros[30];

    Inicio();
    printf("1. Gestión de Libros.\n2. Administración de Autores.\n3. Gestión de "
           "Préstamos y Devoluciones\n\n0. Terminar Programa\nIntroduce tu "
           "opción: ");
    int opcion = getValor(0, 3);
    switch (opcion) {
    case 1:
        MenuGLibros(listaLibros);
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

void MenuGLibros(Libro lista[]){
    Inicio();
    printf("1. Agregar Libros\n2. Mostrar Información.\n3. Buscar Libro\n\n0. "
           "Atras\nIntroduce tu opción: ");
    int opcion = getValor(0,3);
    switch (opcion) {
    case 1:
        AgregarLibro(lista);
        break;
    case 2:

        break;
    case 3:

        break;
    case 0:

        break;
    }
    
}

void MenuGAutores()
{
    Inicio();
    printf("1. Agregar Autores\n2. Mostrar Autores\n3. Libros Autor\n\n0. "
           "Atras\nIntroduce tu opción: ");
}

void MenuGPrestamo()
{
    Inicio();
    printf("1. Ingresar Prestamo\n2. Ingresar Devolución\n3. Buscar "
           "Disponibilidad\n\n0. Atras\nIntroduce tu opción: ");
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - //

void continuar()
{
    printf("Pulsa intro para continuar...");
    getchar();
    while (getchar() != '\n');
}

int getValor(int min, int max) {
    int numero;
    scanf("%d", &numero);

    while (numero < min || numero > max){
        printf("ERROR!\nHas introducido un valor no valido. Introduce un número "
               "(%d...%d): ",
               min, max);
        scanf("%d", &numero);
    }

    return numero;
}

void AgregarLibro(Libro lista[]) {
    char titulo[30];

    Inicio();
    printf("Agregando libro ... \n\nIntroduzca el Título: ");
    fgets(titulo, sizeof(titulo), stdin);
    getchar();
    strcpy(lista[NUM_LIBRO].titulo, &titulo);
    

    NUM_LIBRO++;
}