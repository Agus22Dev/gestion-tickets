// Descripción: Sistema de gestión de tickets con prioridades (BAJO, MEDIO, ALTO).
// Este programa permite registrar tickets, asignar prioridades, mostrar tickets pendientes,

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "list.h"

typedef enum { BAJO = 0, MEDIO = 1, ALTO = 2 } Prioridad;

typedef struct {
    int id;
    char descripcion[100];
    Prioridad prioridad;
    time_t horaRegistro;
} Ticket;

List* colas[3]; // colas[0] = BAJO, colas[1] = MEDIO, colas[2] = ALTO

// Función para comparar tickets por hora de registro
int menorPorHora(void* a, void* b) {
    Ticket* t1 = (Ticket*)a;
    Ticket* t2 = (Ticket*)b;
    return t1->horaRegistro < t2->horaRegistro;
}

// Función auxiliar para mostrar prioridad como texto
const char* prioridadATexto(Prioridad p) {
    switch (p) {
        case ALTO: return "ALTO";
        case MEDIO: return "MEDIO";
        case BAJO: return "BAJO";
        default: return "DESCONOCIDA";
    }
}

// Función auxiliar para mostrar ticket
void mostrarTicket(Ticket* t) {
    char hora[26];
    struct tm* tm_info = localtime(&t->horaRegistro);
    strftime(hora, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    printf("ID: %d\\n", t->id);
    printf("Descripción: %s\\n", t->descripcion);
    printf("Prioridad: %s\\n", prioridadATexto(t->prioridad));
    printf("Hora de registro: %s\\n", hora);
    printf("--------------------------\\n");
}

// Registrar nuevo ticket (siempre prioridad BAJO)
void registrarTicket() {
    Ticket* nuevo = (Ticket*)malloc(sizeof(Ticket));
    nuevo->prioridad = BAJO;
    nuevo->horaRegistro = time(NULL);

    printf("Ingrese el ID del ticket: ");
    scanf("%d", &nuevo->id);
    getchar();

    printf("Ingrese la descripción del problema: ");
    fgets(nuevo->descripcion, sizeof(nuevo->descripcion), stdin);
    nuevo->descripcion[strcspn(nuevo->descripcion, "\\n")] = '\\0';

    list_sortedInsert(colas[BAJO], nuevo, menorPorHora);

    printf("Ticket registrado con prioridad BAJO y hora actual.\\n");
}

// Asignar nueva prioridad a un ticket
void asignarPrioridad() {
    int id, nueva;
    printf("Ingrese el ID del ticket: ");
    scanf("%d", &id);

    printf("Ingrese la nueva prioridad (2 = ALTO, 1 = MEDIO, 0 = BAJO): ");
    scanf("%d", &nueva);

    if (nueva < 0 || nueva > 2) {
        printf("Prioridad inválida.\\n");
        return;
    }

    for (int i = 0; i < 3; i++) {
        void* ptr = list_first(colas[i]);
        while (ptr != NULL) {
            Ticket* t = (Ticket*)ptr;
            if (t->id == id) {
                list_popCurrent(colas[i]);
                t->prioridad = (Prioridad)nueva;
                list_sortedInsert(colas[nueva], t, menorPorHora);
                printf("Prioridad del ticket ID %d actualizada a %s.\\n", id, prioridadATexto(t->prioridad));
                return;
            }
            ptr = list_next(colas[i]);
        }
    }
    printf("No se encontró un ticket con ese ID.\\n");
}

// Mostrar todos los tickets pendientes
void mostrarTicketsPendientes() {
    int hayTickets = 0;
    for (int i = 2; i >= 0; i--) {
        void* ptr = list_first(colas[i]);
        if (ptr != NULL) {
            printf("\\nTickets con prioridad %s:\\n", prioridadATexto(i));
            hayTickets = 1;
        }
        while (ptr != NULL) {
            Ticket* t = (Ticket*)ptr;
            mostrarTicket(t);
            ptr = list_next(colas[i]);
        }
    }
    if (!hayTickets) printf("No hay tickets pendientes.\\n");
}

// Procesar siguiente ticket
void procesarSiguienteTicket() {
    for (int i = 2; i >= 0; i--) {
        Ticket* t = (Ticket*)list_first(colas[i]);
        if (t != NULL) {
            list_popFront(colas[i]);
            printf("\\nProcesando ticket:\\n");
            mostrarTicket(t);
            free(t);
            return;
        }
    }
    printf("No hay tickets pendientes para procesar.\\n");
}

// Buscar ticket por ID
void buscarTicketPorID() {
    int id;
    printf("Ingrese el ID del ticket a buscar: ");
    scanf("%d", &id);

    for (int i = 2; i >= 0; i--) {
        void* ptr = list_first(colas[i]);
        while (ptr != NULL) {
            Ticket* t = (Ticket*)ptr;
            if (t->id == id) {
                printf("Ticket encontrado:\\n");
                mostrarTicket(t);
                return;
            }
            ptr = list_next(colas[i]);
        }
    }
    printf("No se encontró un ticket con ese ID.\\n");
}

// Función principal
int main() {
    for (int i = 0; i < 3; i++) {
        colas[i] = list_create();
    }

    int opcion;
    do {
        printf("\\n--- Sistema de Gestión de Tickets ---\\n");
        printf("1. Registrar ticket\\n");
        printf("2. Asignar prioridad a ticket\\n");
        printf("3. Mostrar tickets pendientes\\n");
        printf("4. Procesar siguiente ticket\\n");
        printf("5. Buscar ticket por ID\\n");
        printf("6. Salir\\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar();

        switch (opcion) {
            case 1: registrarTicket(); break;
            case 2: asignarPrioridad(); break;
            case 3: mostrarTicketsPendientes(); break;
            case 4: procesarSiguienteTicket(); break;
            case 5: buscarTicketPorID(); break;
            case 6: printf("Saliendo...\\n"); break;
            default: printf("Opción inválida.\\n"); break;
        }
    } while (opcion != 6);

    return 0;
}
