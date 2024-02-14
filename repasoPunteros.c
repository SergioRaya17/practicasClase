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

}