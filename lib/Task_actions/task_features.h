#ifndef LINKED_H
#define LINKED_H

#include "../Task/Task.h"

void add_task(Task *head, char *data);
void view_task(Task *head);
void delete_task(Task *head);
void insert_head(Task **head, char *data);
void free_task(Task *head);

#endif
