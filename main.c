#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} persona;

typedef struct{ 
     int valores[100]; 
     int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor 
} Pila;

persona cargarPersona();
persona* crearArreglo(int validos);
int cargarArreglo(persona arreglo[], int dim);
void cargarArregloGenero (persona arr[], persona arr2[], int validos, char genero);
int cantidadGenero(persona arreglo[], int validos, char genero);
void mostrarArreglo (persona arreglo[], int validos);
void ordenarArreglo(persona arreglo[], int validos);
int posicionMenor (persona arreglo[], int posIni, int validos);

void apilar(Pila * p, int valor);
int desapilar(Pila * p);
int tope(Pila * p);
void mostrar(Pila * p);
void leer (Pila * p);
int pilavacia(Pila* p);

int main()
{

    persona arreglo[30];
    char genero;


    int validos = cargarArreglo(arreglo, 30);

    printf("\nIngresa el genero a filtrar: ");
    fflush(stdin);
    scanf("%c", &genero);

    int cantGenero = cantidadGenero(arreglo, validos, genero);

    printf("La cantidad de ese genero es: %d", cantGenero);

    persona* arregloGenero = crearArreglo(
                                          );

    printf ("\n----------ARREGLO FILTRADO----------");
    cargarArregloGenero(arreglo, arregloGenero, validos, genero);
    mostrarArreglo(arregloGenero, cantGenero);

    
    //PUNTO 2
    printf ("\n----------ARREGLO ORDENADO----------\n");
    ordenarArreglo(arreglo, validos);
    mostrarArreglo(arreglo, validos);
    
    






}

persona cargarPersona()
{

    persona aux;

    printf("\nIngresa el nombre: ");
    fflush(stdin);
    gets(aux.nombre);
    printf("\n");
    printf("Ingresa la edad: ");
    fflush(stdin);
    scanf("%d", &aux.edad);
    printf("\n");
    printf("Ingresa el g�nero (M o F): ");
    fflush(stdin);
    scanf("%c", &aux.genero);

    return aux;
}

int cargarArreglo(persona arreglo[], int dim)
{

    int i = 0;
    char letra = 's';

    while(i < dim && letra == 's')
    {
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

    while(i < validos)
    {

        if(genero == arreglo[i].genero)
        {
            cant++;
            i++;
        }
        else
        {
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
    int cant = 0;

    for(i = 0; i < validos; i++)
    {
        if(arr[i].genero == genero)
        {
            arr2[cant] = arr[i];
            cant++;
        }
    }
}

void mostrarArreglo (persona arreglo[], int validos)
{

    for(int i = 0; i < validos; i++)
    {

        printf("\n\n=================\n");
        printf("Nombre: %s\n", arreglo[i].nombre);
        printf("Genero: %c\n", arreglo[i].genero);
        printf("Edad: %d\n", arreglo[i].edad);
        printf("=================\n");

    }
}

void ordenarArreglo(persona arreglo[], int validos)
{
    int posmenor;
    persona aux;
    int i = 0;
    while(i < validos-1)
    {
        posmenor = posicionMenor(arreglo, i, validos);
        aux = arreglo[posmenor];
        arreglo[posmenor] = arreglo[i];
        arreglo[i] = aux;
        i++;
    }
}

int posicionMenor (persona arreglo[], int posIni, int validos)
{

    persona menor = arreglo[posIni];
    int posMenor = posIni;
    int i = posIni+1;

    while(i < validos)
    {
        if(menor.edad > arreglo[i].edad)
        {
            menor.edad = arreglo[i].edad;
            posMenor = i;

        }
        i++;
    }
    return posMenor;
}

void inicPila(Pila * p){

    p->posTope = 0;

}

void apilar(Pila * p, int valor){

    if(p->posTope < 100){

    p->valores[p->posTope] = valor;
    (p->posTope)++;

    }else{

        printf("\nPILA LLENA");

    }

}

int desapilar(Pila * p){
    int valor = p->valores[p->posTope-1];
    p->posTope--;

    return valor;
}

int tope(Pila * p){

    int i = p->valores[p->posTope-1];
    return i;
}

void mostrar(Pila * p)
{

    int validos = p->posTope;
    int i = 0;

        printf("...................................................\n");

    for(i = 0; i < validos; i++){

        printf(" %d", p->valores[i]);

    }

        printf("\n...................................................");
}

void leer (Pila * p){

    int i = 0;
    int num;

    printf("\n * Ingresa un valor: ");
    fflush(stdin);
    scanf("%i", &num);

    p->valores[p->posTope] = num;

    p->posTope++;

}

int pilavacia(Pila* p){
    if(p->posTope == 0){
        return 1;
    }
    else{
        return 0;
    }
}



