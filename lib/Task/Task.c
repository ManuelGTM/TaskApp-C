#include "Task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Task *create_task(char *data) {
  Task *new = (Task *)malloc(sizeof(Task));
  if (new == NULL) {
    printf("Error al asignar memoria.\n");
    exit(EXIT_FAILURE);
  }

  strncpy(new->name, data, MAX);
  new->next = NULL;
  return new;
}

void add_task(Task **head, char *data) {
  Task *new_task = create_task(data);

  if (*head == NULL) {
    *head = new_task;
    return;
  }

  Task *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new_task;
}

void delete_task(Task **head, char *name) {
  if (*head == NULL) {
    printf("La lista de tareas está vacía.\n");
    return;
  }

  Task *current = *head;
  Task *prev = NULL;

  while (current != NULL && strcmp(current->name, name) != 0) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("No se encontró la tarea: %s\n", name);
    return;
  }

  if (prev == NULL) {
    *head = current->next;
  } else {
    prev->next = current->next;
  }

  free(current);
  printf("Tarea eliminada: %s\n", name);
}

void view_task(Task *head) {
  if (head == NULL) {
    printf("La lista de tareas está vacía.\n");
    return;
  }

  printf("Lista de Tareas:\n");
  Task *current = head;
  while (current != NULL) {
    printf("- %s\n", current->name);
    current = current->next;
  }
}

void free_task(Task *head) {
  Task *current = head;
  while (current != NULL) {
    Task *temp = current;
    current = current->next;
    free(temp);
  }
}
