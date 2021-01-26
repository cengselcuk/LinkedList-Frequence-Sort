#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

typedef struct node{

    int freq;
    char word[30];
    struct node *next;

}n;

n* start = NULL;
n* temp = NULL;
int count = 0;

void addToEnd(char *a){

    n *node = (n*)malloc(sizeof(n));
    strcpy(node->word, a);
    node->freq = 0;
    node->freq = node->freq+1;
    node->next = NULL;

        if(start==NULL){
            start = node;
        }
        else{
            temp = start;
            while(temp->next != NULL){

                temp = temp->next;
            }
            temp->next = node;

        }

}

void printList(){

    int i = 1;
    temp = start;

    while(temp->next != NULL){
        printf(" %d.",i);
        printf("word: %s --- Frequence:%d \n", temp->word, temp->freq);
        temp = temp->next;
        i++;
    }
    printf(" %d.", i);
    printf("word: %s --- Frequence:%d  \n", temp->word, temp->freq);

}

void searchAndAdd(char *info){

    n *node =(n*)malloc(sizeof(n));
    node->freq = 0;

    strcpy(node->word, info);

        if(count == 0){
            addToEnd(node->word);
            count++;
        }

        else{
            temp = start;

            while(1)
            {
                if(strcmp(temp->word, node->word) == 0){
                temp->freq++;
                break;
                }
                else{
                    if(temp->next == NULL){addToEnd(node->word);
                    break;}
                    temp = temp->next;

                }
            }
        }

}

int listLength()
{
    int len = 0;
    n* first = start;
    while (first != NULL)
    {
        first = first->next;
        len++;
    }
    return len;
}


void sort(n** first)
{
    n** iter;
    n* temp;
    n* n1;
    n* n2;
    bool didChange;
    int len = listLength(), i=0;

    while(i <= len){

        didChange = false;
        iter = first;

        for (int j=0; j<len-i-1; j++){

            n1 = *iter;
            n2 = (*iter)->next;

            if (n1->freq < n2->freq){
                temp = n2->next;
                n2->next = n1;
                n1->next = temp;
                *iter = n2;

                didChange = true;
            }

            iter = &((*iter)->next);
        }

        i++;

        if (didChange == false){
            break;
        }
    }
}


int main()
{

    setlocale(LC_ALL, "Turkish");

    FILE *fp = fopen("file.txt","r");
    char *word[30];

    if(fp == NULL){printf("No such file");}
    else{
        while(!feof(fp)){
            fscanf(fp, "%s", &word);

            searchAndAdd(word);

        }
    }

    sort(&start);
    printList();

    return 0;
}
