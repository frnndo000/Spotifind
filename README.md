# Soptifind - Sistema de Búsqueda Musical

## Descripción

**Soptifind** es un sistema desarrollado en lenguaje C que permite gestionar un conjunto de canciones. Facilita la carga de datos desde un archivo CSV y permite realizar búsquedas por **género**, **artista** o **tempo**, mostrando los resultados en pantalla con detalles y cantidad de coincidencias encontradas.

## Funcionalidades principales

- Cargar canciones desde un archivo `.csv`.
- Buscar canciones por género.
- Buscar canciones por artista.
- Buscar canciones por rango de tempo (lento, moderado, rápido).
- Mostrar la cantidad de canciones encontradas en cada búsqueda (segun artista o genero).

---

## Cómo compilar y ejecutar

### Requisitos previos:

- Tener instalado [Visual Studio Code].
- Instalar la extensión **C/C++ (Microsoft)**.
- Tener instalado un compilador de C (como `gcc`).  
  En Windows se recomienda instalar [MinGW].
- En caso de falla, puedes descargar la base de datos desde aqui: https://drive.google.com/file/d/1zdgxHMaXpqgYaBrtNRUUAN56AN5rRGEy/view
---

### Pasos para compilar y ejecutar:

1. **Descarga el proyecto** y descomprímelo en una carpeta en tu computador.

2. **Abre el proyecto en Visual Studio Code:**
   - Ve a `Archivo > Abrir carpeta...` y selecciona la carpeta del proyecto.

3. **Compila el código:**
   - Abre el archivo principal `soptifind.c`.
   - Abre la terminal integrada (`Terminal > Nueva terminal`).
   - Escribe el siguiente comando para compilar:

     ```
     gcc tdas/*.c soptifind.c -Wno-unused-result -o soptifind
     ```

4. **Ejecuta el programa:**

   ```
   ./soptifind
   ```

---