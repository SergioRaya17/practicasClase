#include <stdio.h>

int main () {
    int num;
    printf("Introduce un número: ");
    scanf("%d", &num);

    int* ptrNum = &num;

    if (*ptrNum == num) {
        printf("El valor es igual, %d en el puntero y %d en la variable.", *ptrNum, num);
    } else {
        printf("El valor es distinto.");
    }

    //Incrementamos el valor desde el puntero.
    (*ptrNum)++;
    printf("\n\nValor del numero tras incrementar el puntero: %d.\n", num);

    char mensaje[40] = "Este es el mesaje inicial. ;)";
    char* ptrMensaje = mensaje;

    printf("\n\nLa variable mensaje tiene almacenado: \"%s\"\n", ptrMensaje);

    int numerosRacionales[5] = {1, 2, 3, 4, 5};
    ptrNum = numerosRacionales;
    for (int i = 0; i < 5; i++) {
        printf("\n%d", ptrNum[i]);
    }
}