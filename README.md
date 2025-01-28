# Push Swap

## Descripción
El proyecto **push_swap** es un desafío del programa 42 que consiste en ordenar una lista de números utilizando dos pilas y un conjunto limitado de instrucciones. Este proyecto pone a prueba tus habilidades en algoritmos y optimización, desafiándote a ordenar la lista en el menor número de movimientos posible.

---

## Uso
### Compilación
Para compilar el programa, ejecuta:
```bash
make
```
Esto generará el ejecutable `push_swap`.

### Ejecución
Para ejecutar el programa, utiliza:
```bash
./push_swap <numeros>
```
Ejemplo:
```bash
./push_swap 4 67 3 87 23
```

---

## Objetivo
El objetivo principal del programa es ordenar una lista de números con las siguientes restricciones:
- Usar solo las operaciones permitidas: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- Minimizar la cantidad total de movimientos necesarios para lograr la ordenación.

---

## Operaciones Disponibles
| Operación | Descripción |
|-----------|-------------|
| `sa`      | Intercambia los dos primeros elementos de la pila `a`. |
| `sb`      | Intercambia los dos primeros elementos de la pila `b`. |
| `ss`      | Ejecuta `sa` y `sb` simultáneamente. |
| `pa`      | Pasa el primer elemento de la pila `b` a la pila `a`. |
| `pb`      | Pasa el primer elemento de la pila `a` a la pila `b`. |
| `ra`      | Rota todos los elementos de la pila `a` hacia arriba. |
| `rb`      | Rota todos los elementos de la pila `b` hacia arriba. |
| `rr`      | Ejecuta `ra` y `rb` simultáneamente. |
| `rra`     | Rota todos los elementos de la pila `a` hacia abajo. |
| `rrb`     | Rota todos los elementos de la pila `b` hacia abajo. |
| `rrr`     | Ejecuta `rra` y `rrb` simultáneamente. |

---

## Evaluación
### Argumentos inválidos
El programa debe manejar correctamente los errores, mostrando un mensaje de error si:
- Se reciben argumentos no numéricos.
- Hay números duplicados.
- Se excede el rango de un entero.

### Ejemplo de salida:
```bash
./push_swap 3 2 1
sa
ra
```

---
