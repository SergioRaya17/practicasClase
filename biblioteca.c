#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    int numAutor;
    Categoria categoria;
    bool disponible;

} Libro;

void AgregarLibro(Libro* lista, int* numLibro);
void MenuGLibros(Libro* lista, int* numLibro);
void InfoLibro(Libro* lista, int* numLibro);
int getValor(int min, int max);
void Menu1(bool *opcion);
void MenuGPrestamo();
void MenuGAutores();
int getAgnoActual();
void continuar();

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
    int numLibro = 0;

    Inicio();
    printf("1. Gestión de Libros.\n2. Administración de Autores.\n3. Gestión de "
           "Préstamos y Devoluciones\n\n0. Terminar Programa\nIntroduce tu "
           "opción: ");
    int opcion = getValor(0, 3);
    switch (opcion) {
    case 1:
        MenuGLibros(listaLibros, &numLibro);
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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - //



// + + + + + + + + + + CREACION DE LIBROS + + + + + + + + + + //

void SeleccionarCategoria(Libro* lista, int* numLibro);
void disponibilidadLibro(Libro* lista, int numLibro);
void AgregandoTitulo(Libro* lista, int* numLibro);
void AgregarAutores(Libro* lista, int* numLibro);
void mostrarAutores(Libro* lista, int numLibro);
void AgregarStock(Libro* lista, int* numLibro);
void MenuGLibros(Libro* lista, int* numLibro);
void AgregarAgno(Libro* lista, int* numLibro);

void AgregarLibro(Libro* lista, int* numLibro) {
    Inicio();
    
    AgregandoTitulo(lista, numLibro);
    AgregarAutores(lista, numLibro);
    AgregarAgno(lista, numLibro);
    AgregarStock(lista, numLibro);
    SeleccionarCategoria(lista, numLibro);
    
    (*numLibro)++;
}

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

// + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + //



void continuar() {
    printf("Pulsa intro para continuar...");
    getchar();
    while (getchar() != '\n');
}

int getValor(int min, int max) {
    int numero;
    scanf("%d", &numero);

    while (numero < min || numero > max){
        printf("ERROR!\nHas introducido un valor no valido. Introduce un número "
               "(%d...%d): ",min, max);
        scanf("%d", &numero);
    }

    return numero;
}

int getAgnoActual() {
    time_t tiempoActual = time(NULL);
    struct tm *tiempoLocal = localtime(&tiempoActual);
    return tiempoLocal->tm_year + 1900;
}

void InfoLibro(Libro* lista, int* numLibro) {
    Inicio();

    for (int i = 0; i < *numLibro; i++){
        printf("Libro %d\n\nTitulo: %s", i + 1, lista[i].titulo);
        mostrarAutores(lista, i);
        printf("\nPublicado: %d\nCategoria: %d\nStock: %d", lista[i].agno, lista[i].categoria, lista[i].stock);
        disponibilidadLibro(lista, i);
    }

    continuar();
}

void mostrarAutores(Libro* lista, int numLibro) {
    for (int i = 0; i < lista[numLibro].numAutor; i++) {
        printf("\n%dº Autor: %s\nEdad: %d", i + 1, lista[numLibro].autor[i].nombre, lista[numLibro].autor[i].edad);
    }
}

void disponibilidadLibro(Libro* lista, int numLibro) {
    if (lista[numLibro].disponible) printf("\nDisponible: true");
    else printf("\nDisponible: false");
}
