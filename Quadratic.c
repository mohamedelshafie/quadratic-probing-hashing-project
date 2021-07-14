#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_SIZE 10
int h[TABLE_SIZE]={NULL};
char hname[TABLE_SIZE][20]={NULL};
int hID[TABLE_SIZE]={NULL};
int hDay[TABLE_SIZE]={NULL};
int hMonth[TABLE_SIZE]={NULL};
int hYear[TABLE_SIZE]={NULL};
int hScore[TABLE_SIZE]={NULL};

void insert(char myname[],int myID,int myDay,int myMonth,int myYear,int myScore){

 int key,index,i,hkey;

 hkey=myDay%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE;i++)
    {

      index=(hkey+i*i)%TABLE_SIZE;
     if(h[index] == NULL)
     {
        h[index]=myDay;
        strcpy(hname[index],myname);
        hID[index]=myID;
        hDay[index]=myDay;
        hMonth[index]=myMonth;
        hYear[index]=myYear;
        hScore[index]=myScore;

         break;
     }

    }

    if(i == TABLE_SIZE)

     printf("\nelement cannot be inserted\n");
}
void search(int key){

int index,i,hkey;
 hkey=key%TABLE_SIZE;
 for(i=0;i<TABLE_SIZE; i++)
 {
    index=(hkey+i*i)%TABLE_SIZE;
    if(h[index]==key)
    {
      printf("value is found at index %d",index);
      printf("\nvalue =  %d",h[index]);
      printf("\nname: %s\n",hname[index]);
      printf("ID: %d \n",hID[index]);
      printf("Date of birth: %d/%d/%d \n",hDay[index],hMonth[index],hYear[index]);
      printf("Score: %d \n",hScore[index]);
      break;
    }
  }
  if(i == TABLE_SIZE)
    printf("\n value is not found\n");
}
void print(){

  int i;

  printf("\nelements in the hash table are: \n");

  for(i=0;i< TABLE_SIZE; i++){

  printf("\nat index %d \t value =  %d",i,h[i]);
  printf("\nname: %s\n",hname[i]);
  printf("ID: %d \n",hID[i]);
  printf("Date of birth: %d/%d/%d \n",hDay[i],hMonth[i],hYear[i]);
  printf("Score: %d \n",hScore[i]);
  printf("********************************\n");
  }
}
void deletee(int value){
    int i;
    for(i=0;i< TABLE_SIZE; i++){
            if(h[i] == value){
                h[i]= NULL;
                strcpy(hname[i],"");
                hID[i]=NULL;
                hDay[i]=NULL;
                hMonth[i]=NULL;
                hYear[i]=NULL;
                hScore[i]=NULL;
                printf("element deleted\n");
    }

    else
        printf("element is not there to delete\n");

    }

}


int main(){


    //test insertion:
    /*insert("mohamed",1,2,6,2000,90);
    insert("ahmed",2,12,5,1998,80);
    insert("yasser",3,22,6,1999,70);
    print();*/

    //test searching:
    /*insert("mohamed",1,2,6,2000,90);
    insert("ahmed",2,12,5,1998,80);
    insert("yasser",3,22,6,1999,70);
    search(12);*/

    //test deleting:
    insert("mohamed",1,2,6,2000,90);
    insert("ahmed",2,12,5,1998,80);
    insert("yasser",3,22,6,1999,70);
    deletee(12);
    print();

    return 0;
}
