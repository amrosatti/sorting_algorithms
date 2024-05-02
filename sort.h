#ifndef __SORT_H__
#define __SORT_H__



/** Header Files **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>



/** Data Structures **/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Node value
 * @prev: ...
 * @next: ...
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;



/** Functions Prototypes **/

void print_list(const listint_t *);
void print_array(const int *, size_t);
listint_t *create_dlist(const int *, size_t);
void free_list(listint_t *);
void swap(int *, int *);
void bubble_sort(int *, size_t);
void insertion_sort_list(listint_t **);
void insert_sort(listint_t **, listint_t *);



#endif /** __SORT_H__ **/
