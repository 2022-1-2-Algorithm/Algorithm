#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int number[17];
} element;

typedef struct Node {
   int data;
   struct Node* next;
}Node;

Node* list[16] = {0,};
int temp;
int j,k,n;

int i;

void print_list(Node* plist);

int insert(int i);

int main(void) {
   element data;

   Node* plist;

   Node* curr = NULL, * prev = NULL;

   plist = NULL;

   n = sizeof(list)/sizeof(int);
//   printf("발표한 번호와 횟수를 입력해 주세요:");
//   scanf("%d %d", );
   for (int j = 1; j < 17; j++) {

      i = insert(j);

      curr = (Node*)malloc(sizeof(Node));

      curr->data = i;

      curr->next = NULL;

      if (prev == NULL)

         plist = curr; else prev->next = curr;

      prev = curr;
	list[j-1] = curr;
	printf("list[%d] = %d\n", j, curr);
   }
   for(int i = 0; i < 16; i++) {
   		printf("test: %d\n", list[i]);
   }
   for(j=n-1; j>0; j--){
   		for(k=0; k<j; k++){
   			if(list[k]->data>list[k+1]->data){
   				temp = list[k]->data;
   				list[k]->data = list[k+1]->data;
   				list[k+1]->data = temp;
			}
		}
	}
   print_list(plist);
	
   return 0;

}

void print_list(Node* plist) {

   Node* p;

   p = plist;

   while (p) {
      printf("%d\n", p->data);
      p = p->next;
   }
}

int insert(int j) {

   int num;

   printf("%d번의 발표 횟수: ", j);

   scanf("%d", &num);

   return num;
}
