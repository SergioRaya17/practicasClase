#include <stdio.h>

void rejuvenecer(int* original, int restar);

int main(void){
  int edad, quitar;

  printf("Fuente de la juvetud\n********************\n");
  printf("¿Cuántos años tienes?: ");
  scanf("%d", &edad);

  printf("Vale, veo que tienes %d años. ¿Cuántos años quieres que te rejuvenezca?: ", edad);
  scanf("%d", &quitar);


  printf("--------------\nPreparando el hechizo...\n\n");
  rejuvenecer(&edad, quitar);
  printf("¡Después del baño en la fuente tienes %d años!\n", edad);
}

void rejuvenecer(int* original, int restar) {
  *original -= restar;
}
