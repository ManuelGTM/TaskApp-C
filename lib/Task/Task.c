#include "Task.h"
#include <stdlib.h>
#include <string.h>

Task *create_task(char *data) {

  Task *new = (Task *)malloc(sizeof(Task));

  strncpy(new->name, data, MAX);
  new->next = NULL;

  return new;
}

void free_task(Task *node) { free(node); }
