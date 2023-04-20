#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct Node{
	char val[30];
	struct Node *next;
}Node;

void citireverif();

uint16_t DJB2_hash();

uint8_t sum_hash();

void addAtBeginning();

void addAtEnd();

void display();

void populare();

int nr_elem();
