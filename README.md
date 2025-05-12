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

## Menú principal del programa

```
========================================
                SOPTIFIND
========================================

1) Cargar canciones
2) Buscar por genero
3) Buscar por artista
4) Buscar por tempo
5) Salir
```

---

## Ejemplo de uso

### Cargar canciones

Selecciona la opción `1`. El programa cargará las primeras 10.000 canciones del archivo `song_dataset_.csv`, clasificándolas por ID, género, artista y tempo.

### Buscar por género

Selecciona la opción `2` e ingresa un género musical como "acoustic" o "pop".  
El programa mostrará todas las canciones coincidentes y cuántas hay.

### Buscar por artista

Selecciona la opción `3` e ingresa el nombre exacto del artista.  
Si una canción tiene varios artistas, será registrada para cada uno individualmente.


### Buscar por tempo

Selecciona la opción `4` y elige el rango de tempo:

- `1` → Canciones lentas (menos de 70 BPM)
- `2` → Canciones moderadas (entre 70 y 110 BPM)
- `3` → Canciones rápidas (más de 110 BPM)

Se mostrará la lista de canciones con la cantidad correspondiente al rango.

---

## Posibles errores

- **Archivo CSV no encontrado:** Asegúrate de tener `song_dataset_.csv` en el mismo directorio.
- **Errores de compilación:** Verifica que todos los archivos en la carpeta `tdas` estén presentes y correctamente enlazados.
- **Entradas inválidas del usuario:** El sistema espera entradas correctas, no ingresar géneros o artistas inexistentes podria causar un mal funcionamiento del programa.
- **Lectura de canciones con mas de un artista:** Al buscar una cancion donde haya mas de un artista, el programa solo considera el primero, complicando su busqueda. 

---