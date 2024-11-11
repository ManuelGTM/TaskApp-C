#ifndef TASK_H
#define TASK_H

#define MAX 100

typedef struct Task {
  char name[MAX];
  struct Task *next;
} Task;

Task *create_task(char *data);
void add_task(Task **head, char *data);
void delete_task(Task **head, char *name);
void view_task(Task *head);
void free_task(Task *head);

#endif // TASK_H

