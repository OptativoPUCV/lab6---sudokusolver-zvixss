#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n)
{
   int fila [10]; 
   int columna [10]; 
   int aux [10];

   for (int i = 0; i < 9; i++)
      {
         for (int k = 0; k < 10; k++)
            {
               fila[k] = 0;
               columna [k] = 0;
            }
         
         for (int k = 0; k < 9; k++)
            {
               int num_fila = n -> sudo [i][k];
               
               if (num_fila != 0)
               {
                  if (fila[num_fila] == 1)
                  {
                     return 0;
                  }
                  else
                  {
                     fila [num_fila] = 1;
                  }
               }

               int nColumna = n -> sudo[k][i];

               if (nColumna != 0)
               {
                  if (columna[nColumna] == 1);
                  {
                     return 0;
                  }
                  else
                  {
                     columna[nColumna] = 1;
                  }
               }
            }
      }

   for (int i = 0; i < 9; i++)
      {
         for (int k = 0; k < 10; k++)
            {
               aux[k] = 0;
            }

         for (int k = 0; k < 9; k++)
            {
               int q = 3 * (i / 3) + (k / 3);
               int w = 3 * (i % 3) + (k % 3);
               int nAux = n -> sudo[q][w];

               if (nAux != 0)
               {
                  if (aux[nAux] == 1)
                  {
                     return 0;
                  }
                  else
                  {
                     aux[nAux] = 1;
                  }
               }
            }
      }

    return 1;
}


List* get_adj_nodes(Node* n)
{
    List* list=createList();

   for (int i = 0; i < 9; i++)
      {
         for (int k = 0; k < 9; k++)
            {
               if (n -> sudo[i][k] == 0)
               {
                  for (int j = 1; j <= 9; j++)
                     {
                        Node* adj = copy(n);
                        adj -> sudo[i][k] = j;
                        
                        if (is_valid(adj))
                        {
                           pushBack(list, adj);
                        }
                        else
                        {
                           free(adj);
                        }
                     }
               }
            }
      }
   
    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/