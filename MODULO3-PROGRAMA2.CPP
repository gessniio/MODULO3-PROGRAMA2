
#include <stdio.h>
#include <stdlib.h>

struct Turno {
    int numero;              /* Número de turno asignado */
    struct Turno *siguiente; /* Apuntador al siguiente nodo */
};

struct Turno *frente = NULL;
struct Turno *final  = NULL;

void agregar_turno(int numero) {
    /* Se reserva espacio en memoria para el nuevo nodo */
    struct Turno *nuevo = (struct Turno *)malloc(sizeof(struct Turno));
    if (nuevo == NULL) {
        printf("Error: no se pudo reservar memoria para el turno.\n");
        return;
    }

    nuevo->numero    = numero;
    nuevo->siguiente = NULL; /* El nuevo nodo siempre va al final */

    if (final == NULL) {
        /* Cola vacía: el nodo es al mismo tiempo frente y final */
        frente = nuevo;
        final  = nuevo;
    } else {
        /* Se enlaza el nodo actual al nuevo y se mueve el apuntador final */
        final->siguiente = nuevo;
        final = nuevo;
    }

    printf("  Turno %d registrado en la fila.\n", numero);
}


void atender_turno(void) {
    if (frente == NULL) {
        /* Validación: no se puede atender si la cola está vacía */
        printf("  No hay turnos en espera. La cola está vacía.\n");
        return;
    }

    struct Turno *temp = frente;          /* Guarda referencia temporal */
    printf("  Atendiendo turno: %d\n", frente->numero);

    frente = frente->siguiente;           /* El frente avanza al siguiente nodo */

    if (frente == NULL) {
        /* Si ya no hay más nodos, el final también queda en NULL */
        final = NULL;
    }

    free(temp); /* Se libera la memoria del nodo que ya fue atendido */
}


void mostrar_cola(void) {
    if (frente == NULL) {
        printf("  La cola está vacía. No hay turnos pendientes.\n");
        return;
    }

    struct Turno *actual = frente; /* Se empieza desde el frente */
    printf("  Turnos en espera (orden de atención): ");

    while (actual != NULL) {
        printf("[%d] ", actual->numero);
        actual = actual->siguiente; /* Se avanza al siguiente nodo */
    }
    printf("\n");
}


void liberar_cola(void) {
    struct Turno *temp;
    while (frente != NULL) {
        temp   = frente;
        frente = frente->siguiente;
        free(temp);
    }
    final = NULL;
}


int main(void) {
    int opcion = -1;
    int numero;

    printf("=========================================\n");
    printf("  Sistema MARVIN - MAYRA -Turnos         \n");
    printf("=========================================\n");

    while (opcion != 0) {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("  1. Agregar turno\n");
        printf("  2. Atender turno\n");
        printf("  3. Mostrar cola de turnos\n");
        printf("  0. Salir\n");
        printf("Selecciona una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            /* Limpia buffer en caso de entrada no válida */
            while (getchar() != '\n');
            opcion = -1;
        }

        switch (opcion) {
            case 1:
                printf("Ingresa el numero de turno: ");
                if (scanf("%d", &numero) == 1) {
                    agregar_turno(numero);
                } else {
                    printf("  Entrada no válida.\n");
                    while (getchar() != '\n');
                }
                break;

            case 2:
                atender_turno();
                break;

            case 3:
                mostrar_cola();
                break;

            case 0:
                printf("\nCerrando el sistema. Hasta luego.\n");
                break;

            default:
                printf("  Opcion no valida. Intenta de nuevo.\n");
        }
    }

    liberar_cola(); /* Se libera cualquier nodo restante antes de salir */
    return 0;
}