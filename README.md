# 🎫 Sistema de Turnos con Cola Enlazada

> **Materia:** Estructura de Datos · Módulo 3 – Programa 2  
> **Carrera:** Licenciatura en Tecnologías de la Información y Comunicación  
> **Lenguajes:** C · C++  
> **Paradigma:** Programación estructurada (C) + Orientada a Objetos (C++)

---

## 📋 Descripción

Implementación de una **cola (queue) con nodos enlazados dinámicamente** que simula un sistema de atención por turnos tipo ventanilla bancaria o consultorio.

Los turnos se atienden en el mismo orden en que se registraron: **FIFO** (First In, First Out — primero en llegar, primero en salir). El proyecto incluye dos versiones del mismo sistema: una en **C puro** con funciones y structs, y otra en **C++** con programación orientada a objetos.

---

## 📁 Archivos del repositorio

```
MODULO3-PROGRAMA2/
├── MODULO3-PROGRAMA2.C              # Versión en C (estructurada, malloc/free manual)
├── MODULO3-PROGRAMA2.CPP            # Versión en C++ (OOP, clase ColaTurnos, RAII)
├── PROGRAMA2.exe                    # Ejecutable compilado para Windows (MinGW)
├── AUTENTICA_MARVIN_MAYRA_compressed.pdf   # Documento académico de respaldo
└── README.md
```

---

## ⚙️ Estructura de datos

### Versión C — struct con punteros globales

```c
struct Turno {
    int numero;              /* Número de turno asignado */
    struct Turno *siguiente; /* Apuntador al siguiente nodo */
};
```

La cola se controla con dos punteros globales: `frente` (primer turno a atender) y `final` (donde se encola el siguiente turno nuevo).

### Versión C++ — clase encapsulada

```cpp
class ColaTurnos {
public:
    ColaTurnos();           // Inicializa cola vacía
    ~ColaTurnos();          // Destructor: libera nodos automáticamente (RAII)

    void agregar(int numero);   // Encola nuevo turno al final
    void atender();             // Desencola y atiende el turno del frente
    void mostrar() const;       // Muestra todos los turnos pendientes
    bool vacia() const;         // Verifica si la cola está vacía

private:
    Turno *frente;
    Turno *final_;
    void liberar();             // Limpieza interna
};
```

---

## 🔧 Funciones principales

| Función / Método        | Descripción                                                      |
|------------------------|------------------------------------------------------------------|
| `agregar(int numero)`  | Crea un nodo con `new` / `malloc` y lo enlaza al final de la cola |
| `atender()`            | Desencola el frente, imprime el turno atendido y libera memoria   |
| `mostrar()`            | Recorre la lista e imprime todos los turnos en orden de llegada   |
| `vacia()`              | Devuelve `true` si la cola no tiene elementos                    |
| `liberar()` / destructor | Libera todos los nodos restantes al cerrar el programa          |
| `leerEntero(int &val)` | Valida entradas no numéricas y limpia el buffer de `cin`         |

---

## 🖥️ Menú del programa

```
=========================================
  Sistema MARVIN - MAYRA - Turnos
=========================================

--- MENU PRINCIPAL ---
  1. Agregar turno
  2. Atender turno
  3. Mostrar cola de turnos
  0. Salir

Selecciona una opcion:
```

### Ejemplo de sesión

```
Selecciona una opcion: 1
Ingresa el numero de turno: 101
  Turno 101 registrado en la fila.

Selecciona una opcion: 1
Ingresa el numero de turno: 102
  Turno 102 registrado en la fila.

Selecciona una opcion: 3
  Turnos en espera (orden de atención): [101] [102]

Selecciona una opcion: 2
  Atendiendo turno: 101

Selecciona una opcion: 3
  Turnos en espera (orden de atención): [102]

Selecciona una opcion: 0
  Cerrando el sistema. Hasta luego.
```

---

## 🚀 Compilar y ejecutar

### Linux / macOS

```bash
# Versión C
gcc -o turnos MODULO3-PROGRAMA2.C
./turnos

# Versión C++
g++ -std=c++17 -o turnos MODULO3-PROGRAMA2.CPP
./turnos
```

### Windows (MinGW / MSYS2)

```bash
# Versión C
gcc -o turnos.exe MODULO3-PROGRAMA2.C
turnos.exe

# Versión C++
g++ -std=c++17 -o turnos.exe MODULO3-PROGRAMA2.CPP
turnos.exe
```

> También puedes ejecutar directamente el archivo `PROGRAMA2.exe` incluido (compilado para Windows 64-bit con MinGW).

### Requisitos

| Herramienta | Versión mínima |
|-------------|---------------|
| gcc / g++   | 7.x o superior |
| Estándar C  | C89 / C99      |
| Estándar C++ | C++11 o superior |

---

## 🧠 Conceptos aplicados

- **Cola enlazada dinámica (Linked List Queue)** — estructura FIFO con nodos en heap
- **Gestión dinámica de memoria** — `malloc` / `free` (C) y `new` / `delete` (C++)
- **Encapsulamiento OOP** — clase `ColaTurnos` con atributos privados y métodos públicos
- **RAII** *(Resource Acquisition Is Initialization)* — destructor libera memoria automáticamente
- **Manejo de punteros dobles** — `frente` y `final_` para encolado/desencolado O(1)
- **Validación de entrada** — `scanf` con limpieza de buffer (C) y `cin` con `numeric_limits` (C++)
- **Separación de responsabilidades** — funciones/métodos con una sola responsabilidad cada uno

---

## 📊 Comparativa de versiones

| Característica             | C (`MODULO3-PROGRAMA2.C`)      | C++ (`MODULO3-PROGRAMA2.CPP`) |
|---------------------------|-------------------------------|-------------------------------|
| Paradigma                 | Estructurado                  | Orientado a objetos           |
| Memoria                   | `malloc` / `free` manual      | `new` / `delete` con RAII     |
| Encapsulamiento           | Variables globales            | Clase `ColaTurnos` privada    |
| Liberación al salir       | `liberar_cola()` explícita    | Destructor automático         |
| Validación de entrada     | `scanf` + limpieza de buffer  | `cin` + `numeric_limits`      |
| Constructor del nodo      | `malloc` + asignación manual  | `explicit Turno(int n)`       |

---

## 📄 Documento académico

El archivo **`AUTENTICA_MARVIN_MAYRA_compressed.pdf`** contiene la documentación formal del proyecto: análisis del problema, diseño de la solución, diagramas de flujo y conclusiones académicas, elaborado bajo los lineamientos de la materia Estructura de Datos.

---

## 👨‍💻 Autores

**Marvin Valdez** · [@gessniio](https://github.com/gessniio)  
Ingeniero en Sistemas, Electrónica y Electromecánica | Redes · Ciberseguridad · IA  
*Estructura de Datos — Segundo Semestre*

**Mayra** — Colaboradora académica del proyecto

---

## 📜 Licencia

Uso académico. Sin restricciones para fines educativos.
