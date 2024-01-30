#include <stdio.h>
#include <time.h>

void continuar() {
    printf("\n\nPulsa intro para continuar...");
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