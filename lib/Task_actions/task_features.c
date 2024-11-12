#include "../Task/Task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_task(Task **head, char *data) {

  Task *new_task = create_task(data);

  if (*head == NULL) {
    new_task->next = *head;
    *head = new_task;
  }

  Task *current = *head;

  while (current->next != NULL) {
    current = current->next;
  }

  new_task->next = current->next;
  current->next = new_task;
}

void delete_task(Task **head, char *name) {

  if (*head == NULL) {
    printf("Task list is empty.\n");
    return;
  }

  Task *current = *head;
  Task *prev = NULL;

  while (current != NULL && strcmp(current->name, name) != 0) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) {
    printf("Task not found: %s\n", name);
    return;
  }

  if (prev == NULL) {
    *head = current->next;

  } else {
    prev->next = current->next;
  }

  free(current);
  printf("Deleted task: %s\n", name);
};

void view_task(Task *head) {

  if (head == NULL) {

    printf("Task list is empty.\n");
    return;
  }

  printf("Task List: \n");
  Task *current = head;

  while (current != NULL) {
    printf("Name: %s, \n", current->name);
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
