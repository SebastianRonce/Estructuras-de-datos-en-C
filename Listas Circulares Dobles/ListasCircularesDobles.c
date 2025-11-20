#include <stdlib.h>
#include <stdio.h>

// type define la estructura del nodo
typedef struct nodo {
    int dato;
    struct nodo* siguiente;
    struct nodo* atras;
} nodo;

nodo* primero = NULL;
nodo* ultimo = NULL;

void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarListaPU(); //mostrar de primero a ultimo


int main() {
    int opcionMenu = 0;
    do {
        printf("\n|----------------------------------------|");
        printf("\n|        Listas Circulares Dobles        |");
        printf("\n|-------------------|--------------------|");
        printf("\n| 1. Insertar       | 4. Eliminar        |");
        printf("\n| 2. Buscar         | 5. Desplegar de P.U|");
        printf("\n| 3. Modificar      | 6. Salir           |");
        printf("\n|----------------------------------------|");
        printf("\n\nIngrese una opcion: ");
        scanf("%d", &opcionMenu);
        switch (opcionMenu) {
        case 1:
            insertarNodo();
            break;
        case 2:
            buscarNodo();
            break;
        case 3:
            modificarNodo();
            break;
        case 4:
            eliminarNodo();
            break;
        case 5:
            desplegarListaPU();
            break;
        case 6:
            printf("\nSaliendo del programa...\n");
            break;
        default:
        printf("\nOpcion no valida. Intente de nuevo.\n");
        }
    } while(opcionMenu != 6);
    return 0;
}

// primero = null    ultimo = null   nuevo = 12

// Lista circular doble --   12 <- 12 -> 12      12,4,6,7
// primero = 12      ultimo = 12     nuevo = 4
//                            12 <- 12 -> <- 4 -> 12
// primero = 12      ultimo = 4      nuevo = 6
//                            12 <- 12 -> <- 4 -> <- 6 -> 12
// primero = 12      ultimo = 6      nuevo = 7
//                            12 <- 12 -> <- 4 -> <- 6 -> <- 7 -> 12
void insertarNodo(){
    nodo* nuevo = (nodo*) malloc(sizeof(nodo)); // Se crea un nuevo nodo
    printf("Ingrese el dato que contendra el nuevo nodo: ");
    scanf("%d", &nuevo->dato); // Se lee el dato del nuevo nodo

        if (primero == NULL){
            primero = nuevo; // Si la lista esta vacia, el nuevo nodo es el primero
            primero->siguiente = primero; // El primero esta apuntando a si mismo
            ultimo = primero; // El ultimo nodo es el primero
            primero->atras = primero; // El primero apunta atras a si mismo
        } else {
            ultimo->siguiente = nuevo; // El ultimo nodo apunta al nuevo nodo
            nuevo->siguiente = primero; // El nuevo nodo apunta al primero
            nuevo->atras = ultimo; // El nuevo nodo apunta atras al ultimo
            ultimo = nuevo; // El ultimo nodo ahora es el nuevo nodo
            primero->atras = ultimo; // El primer nodo apunta atras al ultimo
        }
        printf("\nNodo ingresado correctamente.\n");
}

void desplegarListaPU(){
    // una forma  --->   // nodo* actual = (nodo*) malloc(sizeof(nodo));
    //                      actual = primero; // Se inicia en el primer nodo
    if (primero != NULL) {
        // nodo* actual = primero;   Se inicia en el primer nodo (sin malloc)
        nodo* actual = primero; // Se inicia el actual en el primer nodo
        do {
            printf("\n-> %d", actual->dato); // Se muestra el dato del nodo actual   actual->dato   
            actual = actual->siguiente; // Se mueve al siguiente nodo
        }while (actual != primero); // mientras actual sea diferente al primero
    }else {
        printf("\n La lista esta vacia. \n\n");
    }
}

void buscarNodo(){
    int nodoBuscado = 0, encontrado = 0;
    printf("\n Ingrese el valor del nodo a buscar: ");
    scanf("%d", &nodoBuscado);
    if (primero != NULL) {
        nodo* actual = primero;
        do {
            if(actual -> dato == nodoBuscado) { // Si actual -> dato es igual al nodoBuscado
                printf("\n El nodo (%d) ha sido encontrado. \n", nodoBuscado);
                encontrado = 1;  // Se marca como encontrado  1
            }
             // Si no es igual, sigue buscando
            actual = actual->siguiente; // Se mueve al siguiente nodo
        }while (actual != primero && encontrado == 0);
        if(encontrado == 0) {
            printf("\n El nodo (%d) no se ha encontrado. \n", nodoBuscado);
        }
    }else {
        printf("\n La lista esta vacia. \n\n");
    }
}

void modificarNodo(){
    int nodoBuscado = 0, encontrado = 0;
    printf("\n Ingrese el valor del nodo a buscar para Modificar: ");
    scanf("%d", &nodoBuscado);
    if (primero != NULL) {
        nodo* actual = primero;
        do {
            if(actual -> dato == nodoBuscado) { // Se compara el dato del nodo actual con el valor buscado
                printf("\n El nodo (%d) ha sido encontrado. \n", nodoBuscado);
                printf("\n Ingrese el nuevo dato para modificarlo: ");
                scanf("%d", &actual->dato);
                printf("\n Nodo modificado correctamente. \n");
                encontrado = 1;
            }
             // Si no es igual, sigue buscando
            actual = actual->siguiente; // Se mueve al siguiente nodo
        }while (actual != primero && encontrado == 0);
        if(encontrado == 0) {
            printf("\n El nodo (%d) no se ha encontrado. \n", nodoBuscado);
        }
    }else {
        printf("\n La lista esta vacia. \n\n");
    }
}

void eliminarNodo(){
    int nodoBuscado = 0, encontrado = 0;
    printf("\n Ingrese el valor del nodo a buscar para ELIMINARLO: ");
    scanf("%d", &nodoBuscado);
    if (primero != NULL) {
        nodo* actual = primero;
        nodo* anterior = NULL; // Nodo anterior para enlazar al eliminar
        do {
            if(actual -> dato == nodoBuscado) { // Se compara el dato del nodo actual con el valor buscado
                printf("\n El nodo (%d) ha sido encontrado.", nodoBuscado);
                // Si el nodo es el primero
                if(actual == primero){
                    primero = primero->siguiente; // El primero es el siguiente nodo
                    primero->atras = ultimo; // El atras del primero es el ultimo
                    ultimo->siguiente = primero; // El siguiente del ultimo es el primero
                }else if(actual == ultimo) { // Si el nodo es el ultimo
                    ultimo = anterior; // El ultimo es el nodo anterior
                    ultimo->siguiente = primero; // El siguiente del ultimo es el primero
                    primero->atras = ultimo; // El atras del primero es el ultimo
                }else { // Ni es el primero ni el ultimo
                    anterior->siguiente = actual->siguiente; // El siguiente del anterior es el siguiente del actual
                    actual->siguiente->atras = anterior; // El atras del siguiente del actual es el anterior
                }
                printf("\n Nodo eliminado correctamente. \n");
                encontrado = 1;
            }
            // Si no es igual, sigue buscando
            anterior = actual;
            actual = actual->siguiente; // Se mueve al siguiente nodo
        }while (actual != primero && encontrado == 0);
        if(encontrado == 0) {
            printf("\n El nodo (%d) no se ha encontrado. \n", nodoBuscado);
        }else{
            free(anterior);
        }
    }else {
        printf("\n La lista esta vacia. \n\n");
    }
}
