#include "./lib/Colors/colors.h"
#include "./lib/Task/Task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_menu();
void clear();
void addTask(Task **head);
void pauseConsole();
int get_option(int option);

int main(void) {
  Task *tasks = NULL;
  int option = 0;

  do {
    clear();
    show_menu();
    option = get_option(option);
    switch (option) {
    case 1:
      addTask(&tasks);
      break;
    case 2:
      clear();
      view_task(tasks);
      break;
    case 3:
      /*deleteTask(&tasks);*/
      break;
    default:
      printf("Opción no válida, intenta de nuevo\n");
    }
    pauseConsole();
  } while (option != 5);

  return EXIT_SUCCESS;
}

void addTask(Task **head) {
  clear();
  char task[MAX];
  printf("Introduce la tarea: ");
  scanf(" %[^\n]", task);

  add_task(head, task);
}

void pauseConsole() {
  printf("Presiona Enter para continuar . . . ");
  getchar();
}

void show_menu() {
  printf(BOLD BLUE "===== Menú Principal =====\n" NORMAL);
  printf(GREEN "1) Add task\n");
  printf("2) View tasks\n");
  printf(RED "Salir\n" NORMAL);
  printf("\nElige una opción: ");
}

int get_option(int option) {
  scanf("%d", &option);
  getchar(); // Para consumir el salto de línea
  return option;
}

void clear() { system("clear"); }
