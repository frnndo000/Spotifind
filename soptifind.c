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
  puts("2) Buscar por genero");
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

void mostrar_canciones(List *lista) {
  Song* cancion = list_first(lista) ;
  while (cancion != NULL) {
    printf("ID: %s | Artista: %s | Álbum: %s | Canción: %s | Género: %s | Tempo: %.1f\n",
           cancion->id, cancion->artists, cancion->album_name,
           cancion->track_name, cancion->track_genre, cancion->tempo) ;
    cancion = list_next(lista) ;
  }
}

void cargar_canciones(Map *by_id, Map *by_genre, Map *by_artist, List *tempo_lentas, List *tempo_moderadas, List *tempo_rapidas) {
  FILE *archivo = fopen("song_dataset_.csv", "r");
  if (archivo == NULL) {
    perror(
        "Error al abrir el archivo"); // Informa si el archivo no puede abrirse
    return;
  }

  int total = 0 ;
  char **campos = leer_linea_csv(archivo, ',') ;

  while ((campos = leer_linea_csv(archivo, ',')) != NULL) {
    total++ ;  
    if (total>999) break ;

    Song *cancion = malloc(sizeof(Song)) ;
    strcpy(cancion->id, campos[0]) ;
    strcpy(cancion->artists, campos[2]) ;
    strcpy(cancion->album_name, campos[3]) ;
    strcpy(cancion->track_name, campos[4]) ;
    cancion->tempo = atof(campos[18]) ;
    strcpy(cancion->track_genre, campos[20]) ;

    map_insert(by_id, cancion->id, cancion) ;

    MapPair* genre_pair = map_search(by_genre, cancion->track_genre) ;
    if (genre_pair == NULL) {
      List * list = list_create() ;
      list_pushBack(list, cancion) ;
      map_insert(by_genre, cancion->track_genre, list) ;
    } else {
      List* list = genre_pair->value ;
      list_pushBack(list, cancion) ;
    }

    MapPair* artist_pair = map_search(by_artist, cancion->artists) ;
    if (artist_pair == NULL) {
      List* list = list_create() ;
      list_pushBack(list, cancion) ;
      map_insert(by_artist, cancion->artists, list) ;
    } else {
      List* list = artist_pair->value ;
      list_pushBack(list, cancion) ;
    }
  }

  printf("Se cargaron %d canciones correctamente.\n", total) ;
  fclose(archivo) ;
}

void buscar_por_genero(Map *by_genre) {
  char genero[100] ;

  printf("Ingrese el genero: ") ;
  scanf(" %[^\n]", genero) ;

  MapPair * pair = map_search(by_genre, genero) ;


  if (pair == NULL) {
    printf("No se encontraron canciones del genero '%s'.\n", genero) ; return ;
  }

  mostrar_canciones(pair->value);
}

void buscar_por_artista(Map *by_artist) {
  char artista[300] ;

  printf("Ingrese el nombre del artista: ") ;
  scanf(" %[^\n]", artista) ;

  MapPair *pair = map_search(by_artist, artista) ;

  if (pair == NULL) {
    printf("No se encontraron canciones del artista '%s'.\n", artista) ;
    return ;
  }

  mostrar_canciones(pair->value);
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
    printf("Ingrese su opcion: ");
    scanf(" %c", &opcion);

    switch (opcion) {
    case '1': cargar_canciones(by_id, by_genre, by_artist, tempo_lentas, tempo_moderadas, tempo_rapidas) ;
      break;
    case '2': buscar_por_genero(by_genre) ;
      break;
    case '3': buscar_por_artista(by_artist) ;
      break;
    case '4':
      break;
    }

    if (opcion != '5') presioneTeclaParaContinuar();

  } while (opcion != '5');

  return 0;
}