#include "./lib/Task_actions/task_features.h"
#include "lib/Task/Task.h"
#include <stdio.h>
#include <stdlib.h>

void show_menu();
int get_option(int option);

int main(void) {

  Task *tasks = NULL;
  int id_counter = 1;
  int option = 0;

  do {
    show_menu();
    option = get_option(option);
    switch (option) {
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      printf("Opcion no valida, intenta de nuevo");
    }
  } while (option != 5);

  return EXIT_SUCCESS;
}

void addTask(Task *head) {

  char *task = "";
  printf("Introduzca la tarea:");
  scanf("%s", task);

  add_task(head, task);
}

void editTask(Task *head) {}

void show_menu() {

  printf("Bienvenido al menu de seleccion");
  printf("1) Crear tareas");
  printf("2) Editar tarea");
  printf("3) Eliminar tarea");
  printf("4) Ver tareas");
  printf("5) Salir");
  printf("¿Que desea realizar? (Elija una opcion)");
}

int get_option(int option) {
  scanf("%d", &option);
  return option;
}
