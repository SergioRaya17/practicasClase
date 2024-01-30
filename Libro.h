#include <stdbool.h>
#include <stdio.h>

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