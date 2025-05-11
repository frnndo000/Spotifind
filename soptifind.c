#include "tdas/extra.h"
#include "tdas/list.h"
#include "tdas/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char id[100] ;
  char track_name[100] ;
  char album_name[100] ;
  char artists[300] ;
  char track_genre[100] ;
  float tempo;
} Song;

// Menú principal
void mostrarMenuPrincipal() {
  limpiarPantalla();
  puts("========================================");
  puts("                SOPTIFIND");
  puts("========================================");

  puts("1) Cargar canciones");
  puts("2) Buscar por género");
  puts("3) Buscar por artista");
  puts("4) Buscar por tempo");
  puts("5) Salir");
}

/**
 * Compara dos claves de tipo string para determinar si son iguales.
 * Esta función se utiliza para inicializar mapas con claves de tipo string.
 *
 * @param key1 Primer puntero a la clave string.
 * @param key2 Segundo puntero a la clave string.
 * @return Retorna 1 si las claves son iguales, 0 de lo contrario.
 */
int is_equal_str(void *key1, void *key2) {
  return strcmp((char *)key1, (char *)key2) == 0;
}

/**
 * Compara dos claves de tipo entero para determinar si son iguales.
 * Esta función se utiliza para inicializar mapas con claves de tipo entero.
 *
 * @param key1 Primer puntero a la clave entera.
 * @param key2 Segundo puntero a la clave entera.
 * @return Retorna 1 si las claves son iguales, 0 de lo contrario.
 */
int is_equal_int(void *key1, void *key2) {
  return *(int *)key1 == *(int *)key2; // Compara valores enteros directamente
}

void cargar_canciones(Map *by_id, Map *by_genre, Map *by_artist, List *tempo_lentas, List *tempo_moderadas, List *tempo_rapidas) {
  FILE *archivo = fopen("data/song_dataset_.csv", "r");
  if (archivo == NULL) {
    perror(
        "Error al abrir el archivo"); // Informa si el archivo no puede abrirse
    return;
  }

  char **campos = leer_linea_csv(archivo, ',') ;

  while ((campos = leer_linea_csv(archivo, ',')) != NULL) {
    Song *cancion = malloc(sizeof(Song)) ;
    strcpy(cancion->id, campos[0]) ;
    strcpy(cancion->artists, campos[1]) ;
    strcpy(cancion->album_name, campos[2]) ;
    strcpy(cancion->track_name, campos[3]) ;
    cancion->tempo = atof(campos[4]) ;
    strcpy(cancion->track_genre, campos[5]) ;

    map_insert(by_id, cancion->id, cancion) ;
  }


}

int main() {
  Map* by_id = map_create(is_equal_str);
  Map* by_genre = map_create(is_equal_str);
  Map* by_artist = map_create(is_equal_str);
  List* tempo_lentas = list_create();
  List* tempo_moderadas = list_create();
  List* tempo_rapidas = list_create();

  char opcion;
  do {
    mostrarMenuPrincipal();
    printf("Ingrese su opción: ");
    scanf(" %c", &opcion);

    switch (opcion) {
    case '1':
    cargar_canciones(by_id, by_genre, by_artist, tempo_lentas, tempo_moderadas, tempo_rapidas);
      break;
    case '2':
      break;
    case '3':
      break;
    case '4':
      break;
    }

    if (opcion != '5') presioneTeclaParaContinuar();

  } while (opcion != '5');

  return 0;
}
