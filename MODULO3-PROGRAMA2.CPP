

#include <iostream>
#include <limits>   // numeric_limits

// ─────────────────────────────────────────────
//  Nodo interno de la cola
// ─────────────────────────────────────────────
struct Turno {
    int    numero;
    Turno *siguiente;

    explicit Turno(int n) : numero(n), siguiente(nullptr) {}
};

// ─────────────────────────────────────────────
//  Clase Cola de turnos (FIFO con punteros)
// ─────────────────────────────────────────────
class ColaTurnos {
public:
    ColaTurnos() : frente(nullptr), final_(nullptr) {}

    // Destructor: libera todos los nodos que queden
    ~ColaTurnos() { liberar(); }

    // Encola un nuevo turno al final
    void agregar(int numero) {
        Turno *nuevo = new Turno(numero);

        if (final_ == nullptr) {
            // Cola vacía: el nodo es frente y final al mismo tiempo
            frente = final_ = nuevo;
        } else {
            final_->siguiente = nuevo;
            final_            = nuevo;
        }
        std::cout << "  Turno " << numero << " registrado en la fila.\n";
    }

    // Desencola el turno del frente (FIFO)
    void atender() {
        if (frente == nullptr) {
            std::cout << "  No hay turnos en espera. La cola está vacía.\n";
            return;
        }
        Turno *temp = frente;
        std::cout << "  Atendiendo turno: " << frente->numero << "\n";
        frente = frente->siguiente;

        if (frente == nullptr) {
            final_ = nullptr;   // La cola quedó vacía
        }
        delete temp;            // RAII: libera el nodo atendido
    }

    // Muestra todos los turnos pendientes (sin modificar la cola)
    void mostrar() const {
        if (frente == nullptr) {
            std::cout << "  La cola está vacía. No hay turnos pendientes.\n";
            return;
        }
        std::cout << "  Turnos en espera (orden de atención): ";
        for (Turno *actual = frente; actual != nullptr; actual = actual->siguiente) {
            std::cout << "[" << actual->numero << "] ";
        }
        std::cout << "\n";
    }

    // Indica si la cola no tiene elementos
    bool vacia() const { return frente == nullptr; }

private:
    Turno *frente;
    Turno *final_;

    // Libera todos los nodos (llamado por el destructor)
    void liberar() {
        while (frente != nullptr) {
            Turno *temp = frente;
            frente      = frente->siguiente;
            delete temp;
        }
        final_ = nullptr;
    }
};

// ─────────────────────────────────────────────
//  Utilidad: leer un entero limpiando el buffer
// ─────────────────────────────────────────────
bool leerEntero(int &valor) {
    if (std::cin >> valor) {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}

// ─────────────────────────────────────────────
//  Programa principal
// ─────────────────────────────────────────────
int main() {
    ColaTurnos cola;
    int opcion = -1;

    std::cout << "=========================================\n";
    std::cout << "  Sistema MARVIN - MAYRA - Turnos        \n";
    std::cout << "=========================================\n";

    while (opcion != 0) {
        std::cout << "\n--- MENU PRINCIPAL ---\n"
                  << "  1. Agregar turno\n"
                  << "  2. Atender turno\n"
                  << "  3. Mostrar cola de turnos\n"
                  << "  0. Salir\n"
                  << "Selecciona una opcion: ";

        if (!leerEntero(opcion)) {
            std::cout << "  Entrada no válida. Intenta de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                int numero;
                std::cout << "Ingresa el numero de turno: ";
                if (leerEntero(numero)) {
                    cola.agregar(numero);
                } else {
                    std::cout << "  Entrada no válida.\n";
                }
                break;
            }
            case 2:
                cola.atender();
                break;

            case 3:
                cola.mostrar();
                break;

            case 0:
                std::cout << "\nCerrando el sistema. Hasta luego.\n";
                break;

            default:
                std::cout << "  Opcion no valida. Intenta de nuevo.\n";
        }
    }

    // El destructor de ColaTurnos libera automáticamente los nodos restantes
    return 0;
}
