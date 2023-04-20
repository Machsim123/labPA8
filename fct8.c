#include "fct8.h"

void citireverif(FILE *fis)
{
	if(fis==NULL) printf("Fisierul nu a putut fi deschis! \n");
	else printf("Fisierul a fost deschis cu succes! \n");
}

uint16_t DJB2_hash(const uint8_t *str)
{
    uint16_t hash = 5381;
    uint8_t c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

uint8_t sum_hash(const uint8_t *str)
{	
	uint8_t c;	
	uint8_t hash = 0;
	while ((c = *str++))
		hash += c;
	hash = hash % 256;
	return hash;
}

void addAtBeginning(Node **head, char v[])
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->val,v);
	newNode->next = *head;
	*head = newNode;
}

void addAtEnd(Node** head, char v[])
{
	Node *aux=*head;
	Node* newNode = (Node*)malloc(sizeof(Node)); 
	strcpy(newNode->val,v);
	if (*head == NULL) addAtBeginning(&*head, v);
	else{  
		while (aux->next!=NULL) aux = aux->next;
		aux->next = newNode;  
		newNode->next = NULL; 
	}
}

void display(Node *head)
{
	while (head!=NULL){
		printf ("%d ", head->val);
		head=head->next;
	}
	printf("\n");
}

void populare(int index, Node *v, char sir[])
{
	Node *nod=&(v[index]), *nod_nou;
	if(nod->val==NULL)
        strcpy(nod->val,sir);
    else
      {while(nod->next!=NULL)
          {nod=nod->next;}
         nod_nou=(Node*)calloc(1,sizeof(Node));
         nod->next=nod_nou;
         strcpy(nod_nou->val,sir);
      }
    
}

int nr_elem(int index, Node *v)
{
	int num;
	Node *nod=&(v[index]);
	if(nod->val!=NULL)
	    num++;
	while(nod->next!=NULL)
	{
		nod=nod->next;
		num++;
	}
	return num;
}
