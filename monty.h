#ifndef _MONTY_H_

#define _MONTY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
* struct instruction_s - opcoode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

/** FUNCTION PROTOTYPES **/
void ac_check(int ac);
void av_check(char *av);
void malloc_fail(void);
void push(stack_s **head, int data, int *flag);
instruction_t (*get_op_code(char *opcode))(stack_s **head, unsigned int num);
void instrction_caller(char *, unsigned int, stack_s **, int, int *);
/* data structure helpers  */
stack_s *add_begining(stack_s **head, int data);
stack_s *add_end(stack_s **head, int data);
void remove_top(stack_s **head);
int remove_end(stack_s **head);
stack_s *get_node_end(stack_s **head);
void print_top(stack_s **head, int num);
void print_list(stack_s **head);
void swap_tops(stack_s **head, unsigned int num);
void chr_top(stack_s **head, unsigned int num);
void str_top(stack_s **head, unsigned int num);
void add_tops(stack_s **head, unsigned int num);
void sub_tops(stack_s **head, unsigned int num);
void div_tops(stack_s **head, unsigned int num);
void mul_tops(stack_s **head, unsigned int num);
void mod_tops(stack_s **head, unsigned int num);
void rot_lft(stack_s **head, unsigned int num);
void rot_rgt(stack_s **head, unsigned int num);




#endif
