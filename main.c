#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} persona;

typedef struct
{
    int valores[100];
    int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;

const int dim = 10;

persona cargarPersona();
persona* crearArreglo(int validos);
int cargarArreglo(persona arreglo[], int dim);
void cargarArregloGenero (persona arr[], persona arr2[], int validos, char genero);
int cantidadGenero(persona arreglo[], int validos, char genero);
void mostrarArreglo (persona arreglo[], int validos);
void ordenarArreglo(persona arreglo[], int validos);
void mostrarArregloEnteros (int arreglo[], int validos);
void insercion (int arreglo[], int validos);
int posicionMenor (persona arreglo[], int posIni, int validos);
void insertarDato(int arreglo[], int inicioBusqueda, int dato);
int eliminarDato(int arreglo[], int validos, int pos, int f, int r);

void apilar(Pila * p, int valor);
int desapilar(Pila * p);
int tope(Pila * p);
void mostrar(Pila * p);
void leer (Pila * p);
int pilavacia(Pila* p);
void cargarPila (Pila *p);
Pila intercalarPilas (Pila *pila1, Pila *pila2);


int main()
{

    persona arreglo[30];
    int enteros[5];
    char genero;
    int eleccion;
    int validos;
    int dato;
    int pos;
    int var = 0;

    Pila p, p2;

    printf("Ingrese el ejercicio: ");
    fflush(stdin);
    scanf("%i",&eleccion);
    switch(eleccion)
    {
    case 1:

        printf("*** Ejercicio 1***\n");
        validos = cargarArreglo(arreglo, 30);

        printf("\nIngresa el genero a filtrar: ");
        fflush(stdin);
        scanf("%c", &genero);

        int cantGenero = cantidadGenero(arreglo, validos, genero);

        printf("La cantidad de ese genero es: %d", cantGenero);

        persona* arregloGenero = crearArreglo(validos);


        printf ("\n----------ARREGLO FILTRADO----------");
        cargarArregloGenero(arreglo, arregloGenero, validos, genero);
        mostrarArreglo(arregloGenero, cantGenero);
        break;

    case 2:
        printf("*** Ejercicio 2***\n");
        printf ("\n----------ARREGLO ORDENADO----------\n");
        ordenarArreglo(arreglo, validos);
        mostrarArreglo(arreglo, validos);
        break;

    case 3:

        //PRUEBA DE FUNCIONES//
        printf("*** Ejercicio 3***\n");
        inicPila(&p);
        inicPila(&p2);
        apilar(&p, 5);
        printf("\n");
        mostrar(&p);
        printf("\n");
        leer(&p);
        printf("\n");
        mostrar(&p);
        desapilar(&p);
        printf("\n");
        mostrar(&p);

        while(!pilavacia(&p))
        {
            apilar(&p2, desapilar(&p));
        }
        printf("\nPILA UNO: \n");
        mostrar(&p);
        printf("\nPILA DOS: \n");
        mostrar(&p2);


        break;

    case 4:

        printf("*** Ejercicio 4***\n");
        cargarPila(&p);
        cargarPila(&p2);

        intercalarPilas(&p, &p2);

        break;

    case 5:

        printf("*** Ejercicio 5 y 6 ***\n");

        validos = cargarArregloEnteros(arreglo, dim, dato);

        insercion(arreglo, validos);
        mostrarArregloEnteros(arreglo, validos);

        break;

    case 7:

        validos = cargarArregloEnteros(enteros, 5);
        mostrarArregloEnteros(enteros, validos);
        printf("Que pos quieres eliminar?:  ");
        fflush(stdin);
        scanf("%d", &pos);

        var = eliminarDato(enteros, validos, pos, 0, 0);
        mostrarArregloEnteros(enteros, var);
        printf("\nRES = %d\n", var);


    }
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

int cargarArregloEnteros(int arreglo[], int dim)
{

    int i = 0;
    int dato;
    char letra = 's';

    while(i < dim && letra == 's')
    {

        printf("Ingresa un dato: ");
        fflush(stdin);
        scanf("%i", &dato);

        arreglo[i] = dato;


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
void mostrarArregloEnteros (int arreglo[], int validos)
{

    for(int i = 0; i < validos; i++)
    {

        printf("| %d |", arreglo[i]);

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

void inicPila(Pila * p)
{

    p->posTope = 0;

}

void apilar(Pila * p, int valor)
{

    if(p->posTope < 100)
    {

        p->valores[p->posTope] = valor;
        p->posTope++;

    }
    else
    {

        printf("\nPILA LLENA");

    }

}

int desapilar(Pila * p)
{
    int pos = p->posTope-1;
    int valor = p->valores[pos];
    if(p->posTope > 0)
    {
        p->posTope = p->posTope-1;
    }
    return valor;
}

int tope(Pila * p)
{

    int i = p->valores[p->posTope-1];
    return i;
}

void mostrar(Pila * p)
{

    int validos = p->posTope;
    int i = 0;

    printf("...................................................\n");

    for(i = 0; i < validos; i++)
    {

        printf(" %d", p->valores[i]);

    }

    printf("\n...................................................");
}

void leer (Pila * p)
{

    int num;

    printf("\n * Ingresa un valor: ");
    fflush(stdin);
    scanf("%i", &num);

    apilar(p, num);


}

int pilavacia(Pila* p)
{
    if(p->posTope == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



void cargarPila (Pila *pila1)
{

    char letra = 's';

    do
    {

        leer(pila1);

        printf("Ingresa 's' para poner mas datos: ");
        fflush(stdin);
        scanf("%c", &letra);

    }
    while(letra == 's');

}

Pila intercalarPilas (Pila *pila1, Pila *pila2)
{

    Pila aux;
    inicPila(&aux);

    while(!pilavacia(pila1) || !pilavacia(pila2))
    {
        if(!pilavacia(pila1))
        {
            apilar(&aux, desapilar(pila1));
        }
        if(!pilavacia(pila2))
        {
            apilar(&aux, desapilar(pila2));
        }
    }

    mostrar(&aux);

}

void insercion (int arreglo[], int validos)
{

    int indiceActual = 0;
    while(indiceActual < validos-1){

        insertarDato(arreglo, indiceActual, arreglo[indiceActual+1]);
        indiceActual++;

    }
}

void insertarDato(int arreglo[], int inicioBusqueda, int dato)
{
    int i = inicioBusqueda;
    while(i >= 0 && dato < arreglo[i]){

        arreglo[i+1] = arreglo[i];
        i--;

    }
    arreglo[i+1] = dato;
}

/*int eliminarArreglo(int arreglo[], int validos, int pos, int i){
    int aux = 0;
    if(pos <= arreglo[i]){
        eliminarArreglo(arreglo, validos, pos, i+1);
    }
    else if(pos < validos){
        arreglo[i-1] = arreglo[i];
        i++;
    }
}*/

/**void eliminarDato(int arreglo[], int validos, int pos){

    int i = 0;

    while(i < validos-1){

        if(pos == i){

            while(i < validos){

                arreglo[i] = arreglo[i+1];
                i++;
            }
        }
        i++;
    }
    validos--;
    mostrarArregloEnteros(arreglo, validos);
}**/


int eliminarDato(int arreglo[], int validos, int pos, int f, int r){

    r = 0;
    f = 0;
    int var = 0;
    if(validos == pos+1){
        f = 1;
    }
    else{
        eliminarDato(arreglo, validos-1, pos, f, r+1);
    }
    arreglo[validos-1] = arreglo[validos];
    var = validos + r;
    return var-1;
}






}


