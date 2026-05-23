# EEPROM Counter - PIC16F887

Sistema embebido desarrollado en PIC16F887 utilizando EEPROM interna, teclado matricial 4x4 y pantalla LCD 16x2.

---

# Descripción

El programa implementa un contador automático de 0 a 99 con almacenamiento persistente mediante EEPROM.

El usuario puede:

- Configurar la velocidad de conteo.
- Guardar el valor actual en EEPROM.
- Recuperar el último valor almacenado.
- Visualizar toda la información en LCD.

---

# Funciones principales

- Contador automático 00–99.
- Configuración de velocidad mediante keypad.
- Persistencia de datos usando EEPROM interna.
- Lectura y escritura de memoria no volátil.
- Interfaz de usuario mediante LCD 16x2.

---

# Hardware utilizado

- PIC16F887
- LCD 16x2
- Keypad matricial 4x4
- EEPROM interna del microcontrolador
- CCS C Compiler
- Proteus Design Suite

---

# Flujo del programa

## 1. Configuración de velocidad

Al iniciar, el sistema solicita una velocidad de conteo.

El usuario debe ingresar 3 dígitos usando el teclado matricial.

Ejemplo:

250

Esto configura un retardo de:

250 ms

entre incrementos del contador.

---

## 2. Iniciar contador

Presionar la tecla:

A

para iniciar el conteo.

---

## 3. Conteo automático

El sistema realiza un conteo:

00 → 99

Cuando llega a 99:

99 → 00

El valor actual se muestra continuamente en la LCD.

---

# Guardar valor en EEPROM

Durante el conteo, presionar:

A

para almacenar el valor actual en EEPROM.

La pantalla mostrará:

VALOR GUARDADO

El dato permanece almacenado incluso después de reiniciar la simulación.

---

# Leer último valor almacenado

Presionar:

D

para visualizar el último valor guardado en EEPROM.

La LCD mostrará:

ULTIMO GUARDADO
XX

---

# Teclas utilizadas

| Tecla | Función |
|---|---|
| 0–9 | Ingreso de velocidad |
| A | Confirmar / guardar EEPROM |
| D | Leer último valor guardado |

---

# Archivos del proyecto

## firmware/

Contiene:

- Código fuente principal `.c`
- Librería LCD

## proteus/

Contiene:

- Archivo de simulación Proteus
- Archivo `.hex`
- Diseño del circuito

## media/

Contiene:

- Capturas de simulación
- Videos de funcionamiento

---

# Simulación en Proteus

1. Abrir el archivo `.pdsprj`
2. Ejecutar la simulación
3. Ingresar velocidad usando keypad
4. Presionar `A` para iniciar
5. Presionar `A` nuevamente para guardar
6. Presionar `D` para leer EEPROM

---

# Características técnicas

- Manejo de teclado matricial mediante barrido.
- Uso de EEPROM interna del PIC16F887.
- Persistencia de datos no volátil.
- Interfaz LCD 16x2.
- Programación en C embebido.
- Control de flujo mediante estados.
