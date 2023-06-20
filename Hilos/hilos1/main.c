#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct nodo
{	
	int dato;
	struct nodo* sig;
}Nodo;

typedef Nodo * Lista;

void insertar(Lista *l, int x){
	Nodo * nuevonodo = (Nodo*) malloc(sizeof(Nodo));
	nuevonodo ->dato = x;
  nuevonodo-> sig = *l;
  *l = nuevonodo;
}

void * suma (void *data){
	int *sume = (int*) malloc(sizeof(int));
	*sume =0;
	Lista l;
	l = (Nodo *) data;
	for(int i=0;i<3;i++){
		*sume += l->dato;
		l = l->sig;
	}
  printf("El valor de la suma es %d\n", *sume);
	//return (void *) sumita;
	pthread_exit(sume);
}

int main(void) {
	int sume = 0;
	int *resultado_parcial;
  int *resultado2;
  int *resultado3;
	Lista miLista = NULL;
  Lista miLista2 = NULL;
  Lista miLista3 = NULL;
  //Ingreso numeros a mi primera lista
  insertar(&miLista, 4);
	insertar(&miLista, 5);
	insertar(&miLista, 6);

	//Ingreso numeros a mi segunda lista
  insertar(&miLista2, 7);
  insertar(&miLista2, 1);
  insertar(&miLista2, 11);
  //Ingreso numeros a mi tercer lista
  insertar(&miLista3, 2);
  insertar(&miLista3, 2);
  insertar(&miLista3, 2);
  
  pthread_t hilo, hilo2, hilo3;
  pthread_create(&hilo, NULL, suma, (void *) miLista);//Creacion del primer hilo
  	pthread_join(hilo, (void**)&resultado_parcial); // Espera a la ejecucion del primer hilo
  
  pthread_create(&hilo2, NULL, suma, (void *) miLista2);//Creacion del segundo hilo
    pthread_join(hilo2, (void**)&resultado2); //Espera a la ejecucion del segundo hilo
  
  pthread_create(&hilo3, NULL, suma, (void *) miLista3);//Creacion del tercer hilo
    pthread_join(hilo3, (void**)&resultado3); //Espera a la ejecucion del tercer hilo



  
	sume += *resultado_parcial + *resultado2 + *resultado3; //Esto lo suma bien.
  free(resultado_parcial);
  free(resultado2);
  free(resultado3);

	printf("La suma total es: %d\n", sume);

  
  return 0;
}