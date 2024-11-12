#ifndef NODE_H
#define NODE_H

#define MAX 100

typedef struct Task {
  char name[MAX];
  struct Task *next;
} Task;

Task *create_task(char *data);
void free_task(Task *node);

#endif // ! NODE_H
