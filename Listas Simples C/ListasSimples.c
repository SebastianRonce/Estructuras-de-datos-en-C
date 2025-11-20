#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void insertarInicio(struct Nodo** lista, int valor) {
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *lista;
    *lista = nuevo;
}

void mostrarLista(struct Nodo* lista) {
    struct Nodo* actual = lista;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void eliminarNodo(struct Nodo** lista, int valor) {
    if (*lista == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    struct Nodo* actual = *lista;
    struct Nodo* anterior = NULL;

    // Buscar el nodo con el valor
    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Elemento no encontrado.\n");
        return;
    }

    // Caso 1: eliminar el primer nodo
    if (anterior == NULL) {
        *lista = actual->siguiente;
    }
    // Caso 2: eliminar nodo en medio o final
    else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Elemento %d eliminado.\n", valor);
}

int main() {
    struct Nodo* lista = NULL;

    insertarInicio(&lista, 10);
    insertarInicio(&lista, 20);
    insertarInicio(&lista, 30);

    printf("Lista actual: ");
    mostrarLista(lista);

    eliminarNodo(&lista, 20);

    printf("Lista después de eliminar: ");
    mostrarLista(lista);

    // Liberar memoria restante
    struct Nodo* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->siguiente;
        free(temp);
    }

    return 0;
}