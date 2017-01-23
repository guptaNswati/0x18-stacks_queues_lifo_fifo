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
void invalid_instruction(int, char*);
int file_size(char *);
char **read_in(char *);
void validator(char *, int line_number);
void push(int);
/*place holders until functions are complete*/
void pall(void);
void pint(void);
void pop(void);
void swap(void);
void add(void);
void nop(void);
void sub(void);
void div(void);
void mul(void);
void mod(void);
void pchar(void);
void pstr(void);
void rotl(void);
void rotr(void);

#endif
