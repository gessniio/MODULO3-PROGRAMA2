[README.md](https://github.com/user-attachments/files/28226394/README.md)
# Sistema de Turnos con Cola Enlazada — C

Proyecto académico que implementa una **cola (queue)** usando nodos enlazados en C puro. Simula un sistema de turnos tipo ventanilla: los turnos se atienden en el mismo orden en que llegaron (FIFO).

---

## ¿Qué hace el programa?

- Agrega turnos al final de la cola
- Atiende el turno del frente (FIFO — primero en llegar, primero en salir)
- Muestra todos los turnos pendientes
- Libera la memoria al salir (sin leaks)
- Valida entradas no numéricas para que el programa no se rompa

---

## Estructura de datos

```c
struct Turno {
    int numero;              /* Número de turno asignado */
    struct Turno *siguiente; /* Apuntador al siguiente nodo */
};
```

La cola se maneja con dos punteros globales: `frente` y `final`. El primero apunta al nodo que se atiende próximo; el segundo es donde se encolan los nuevos turnos.

---

## Funciones principales

| Función | Qué hace |
|---|---|
| `agregar_turno(int)` | Crea un nodo con `malloc` y lo enlaza al final |
| `atender_turno()` | Elimina el nodo del frente y libera su memoria |
| `mostrar_cola()` | Recorre la lista e imprime los turnos en orden |
| `liberar_cola()` | Limpia todos los nodos restantes al cerrar |

---

## Cómo compilar y ejecutar

Requiere cualquier compilador de C compatible con C89/C99 (`gcc`, `clang`, `cc`).

```bash
# Compilar
gcc -o turnos turnos.c

# Ejecutar
./turnos
```

En Windows con MinGW:

```bash
gcc -o turnos.exe turnos.c
turnos.exe
```

---

## Menú del programa

```
=========================================
  Sistema MARVIN - MAYRA - Turnos
=========================================

--- MENU PRINCIPAL ---
  1. Agregar turno
  2. Atender turno
  3. Mostrar cola de turnos
  0. Salir
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
```

---

## Organización del repositorio

```
.
└── turnos.c      # Código fuente completo
└── README.md
```

---

## Conceptos aplicados

- Colas con nodos enlazados (linked list queue)
- Gestión dinámica de memoria: `malloc` / `free`
- Manejo de punteros dobles (`frente` y `final`)
- Validación de entrada con `scanf` y limpieza de buffer
- Separación en funciones para mantener el código legible

---

## Autores

**Marvin & Mayra** — Proyecto académico  
Estructuras de Datos · C  

---

## Licencia

Uso académico. Sin restricciones para fines educativos.
