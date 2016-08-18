#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
  
  char cmd[3] = " "; //incase user wants to go more than once
  char filename[500];
  FILE *filepointer;
  
  //declaring tasks and new variables
  int tp;
  char taskname[500];
  struct Task *theTask;
  
  int testing = 0;
  
  DynArr* mainList = createDynArr(10);

  printf("\n\n** TO-DO LIST APPLICATION **\n\n");

  do
    {
      printf("Press:\n"
             "'l' to load to-do list from a file\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
      /* get input command (from the keyboard) */
      //cmd = getchar();
	  scanf("%s", cmd); //reads the string user input
      

      /* Fixme:  Your logic goes here! */
	  if(cmd[0] == 'l'){ //start with loading
		printf("Name of file loading: ");
		scanf("%s", filename);//scans the file
		filepointer = fopen(filename, "r"); //opens the file
		loadList(mainList, filepointer);  
	  }
	  
	  else if(cmd[0] == 's'){
		printf("Name of file saving: ");
		scanf("%s", filename);//scans the file
		filepointer = fopen(filename, "w");
		saveList(mainList,filepointer);
	  }
	  
	  else if(cmd[0] == 'a'){
		printf("Name of new task: ");
		scanf("%s", taskname);//scans the file
		printf("priority of task: ");
		scanf("%d", &tp);
		theTask = createTask(tp, taskname);
		if(testing == 1){
			addDynArrOrd(mainList,theTask,compare);
		}
		else{
		addHeap(mainList,theTask,compare);
		}
	  }
	  
	  else if(cmd[0] == 'g'){
		  if(testing == 1){
			  theTask = getDynArr(mainList, 0);
		  }
		  else{
		  theTask = getMinHeap(mainList);
		  }
		  
		  printf("First task is: %s \n", theTask->description);
	  }
	  
	  else if(cmd[0] == 'r'){
		  if(testing == 1){
			  theTask = getDynArr(mainList, 0);
		  }
		  else{
		  theTask = getMinHeap(mainList);
		  }
		  
		  if(testing == 1){
			  removeAtDynArr(mainList, 0);
		  }
		  else{
			  
		  removeMinHeap(mainList, compare);
		  }

		  printf("first task has been removed");
	  }
	  
	  else if(cmd[0] == 'p'){
		  printDynArr(mainList, print_type);
	  }
		
		  

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
   while(cmd[0] != 'e');
  /* delete the list */
  deleteDynArr(mainList);

  return 0;
}
