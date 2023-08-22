#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
      char nombre[30];
      char genero;
      int edad;
}persona;

persona cargarPersona();
persona* crearArreglo(int validos);
int cargarArreglo(persona arreglo[], int dim);
void cargarArregloGenero (persona arr[], persona arr2[], int validos, char genero);
int cantidadGenero(persona arreglo[], int validos, char genero);
void mostrarArreglo (persona arreglo[], int validos);

int main(){

    persona arreglo[30];
    char genero;


    int validos = cargarArreglo(arreglo, 30);

    printf("Ingresa el genero: ");
    fflush(stdin);
    scanf("%c", &genero);

    int cantGenero = cantidadGenero(arreglo, validos, genero);

    printf("La cantidad de ese genero es: %d", cantGenero);

    persona* arregloGenero = crearArreglo(cantGenero);

    cargarArregloGenero(arreglo, arregloGenero, cantGenero, genero);
    mostrarArreglo(arregloGenero, cantGenero);




}

persona cargarPersona(){

    persona aux;

    printf("\nIngresa el nombre: ");
    fflush(stdin);
    gets(aux.nombre);
    printf("\n");
    printf("Ingresa la edad: ");
    fflush(stdin);
    scanf("%d", &aux.edad);
    printf("\n");
    printf("Ingresa el género (M o F): ");
    fflush(stdin);
    scanf("%c", &aux.genero);

    return aux;
}

int cargarArreglo(persona arreglo[], int dim)
{

    int i = 0;
    char letra = 's';

    while(i < dim && letra == 's'){
        arreglo[i] = cargarPersona();
        printf("\nIngresa 's' para continuar: ");
        fflush(stdin);
        scanf("%c", &letra);
        i++;
    }

    return i;
}

int cantidadGenero(persona arreglo[], int validos, char genero)
{

    int i = 0;
    int cant = 0;

    while(i < validos){

        if(genero == arreglo[i].genero){
            cant = cant + 1;

            i++;
        }else{

            i++;
        }
    }

    return cant;
}

persona* crearArreglo(int validos)
{

    persona* arreglo = malloc(sizeof(persona) * validos);

    return arreglo;
}


void cargarArregloGenero (persona arr[], persona arr2[], int validos, char genero)
{

    int i = 0;

    for(i = 0; i < validos; i++){

        if(arr[i].genero == genero){

            arr2[i] = arr[i];

        }
    }
}

void mostrarArreglo (persona arreglo[], int validos)
{

    for(int i = 0; i < validos; i++){

        printf("\n\n=================\n");
        printf("Nombre: %s\n", arreglo[i].nombre);
        printf("Genero: %c\n", arreglo[i].genero);
        printf("Edad: %d\n", arreglo[i].edad);
        printf("=================\n");

    }
}
