#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct words{
char word[100];
int freq;
struct words *next;
}Words;
Words *addWord(Words *head, char* newWord);
void printWords(Words *head);
void deleteList(Words *head);

int main(){
  char s[100];
  Words* head=NULL;
  while ((scanf("%s", s))==1){
    head = addWord(head, s);
    if (head == NULL){
      return 1;
      }
  }
  printWords(head);
  deleteList(head);
return 0;
}

Words * addWord(Words * head, char  * newWord){
  Words * wrd = malloc(sizeof(Words));
  if (wrd == NULL){
    printf("malloc fail");
    return NULL;
  }
  strcpy(wrd->word,newWord);
  wrd->freq = 1;
  wrd->next = NULL;
  Words* temp = head;
  if (temp == NULL){
    head = wrd;
  }
  else if(temp->next == NULL){
    int equality = strcmp(temp->word, wrd->word);
    if (equality < 0){
      head->next = wrd;
    }
    else if (equality > 0){
      wrd->next = temp;
      head = wrd;
    }
    else {
      head->freq++;
    }
  }
  else {
    Words *nxt = temp->next;
    int equality1,equality2;
    while (temp!=NULL){
      if (nxt==NULL){
        temp->next=wrd;
        break;
      }
      equality1 = strcmp(temp->word, wrd->word);
      equality2 = strcmp(nxt->word, wrd->word);
      if (equality1 < 0 && equality2 > 0){
        temp->next = wrd;
        wrd->next = nxt;
        break;
      }
      else if (equality1 > 0){
        wrd->next=temp;
        head=wrd;
        break;
      }
      else if ( equality1 == 0){
        temp->freq++;
        break;
      }
      else {
        if (equality2 == 0){
          nxt->freq++;
          break;
        }
      }
      nxt = nxt->next;
      temp = temp->next;
      }
    }
    //printf("%sthis is head\n\n", head->word);
    return head;
}

void printWords(Words *head){
  Words * temp = head;
  while (temp!=NULL){
    printf("%s: %d\n",temp->word, temp->freq);
    temp = temp->next;
  }
}

void deleteList(Words *head){
  Words* nxt = head->next;
  while (nxt!=NULL){
  free(head);
  head = nxt;
  nxt = nxt->next;
}
free(head);
}
