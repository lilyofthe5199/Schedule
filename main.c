#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int exit_flag = 0;
	FILE *fp;
	
	char name[200];
	char place[100], typeName[100];	
	size_t size;
	int month;
	int day;
	int type;
	void *list;
	void *ndPtr;
	void *schedInfo;
	int option;
	int cnt;
	
	//1. FILE pointer open & error handling
	//fill code here ----
	if ((fp = fopen("schedule.dat", "r")) == NULL)
	{
		return -1;
	}
	
	//initializing the list
	printf("Reading the data files... \n");
	list = (void*)list_genList();
	
	char *c;
	int max = 500;
	char line[max];

	fgets(line, max, fp);
	//2. read from the file
	while(!feof(fp)){
		fgets(line, max, fp);
		sscanf(line,"%s %s %d %d %d", name, place, &type, &month, &day);
		//printf("%s %s %d %d %d\n", name, place, type, month, day);
		
		//fill code here -- generate genSchedInfo structure by genSchedInfo function
		//schedInfo=sched_genSchedInfo(name, place, type, month, day);
		sched_genSchedInfo(name, place, type, month, day);
		
		//put the scheduling info instance generated by genSchedInfo function
		list_addTail(schedInfo, list);
	}

/*
	while (  fill code here -- read from the file
			(c=fgetc(fp)) != EOF
			)

	{	
		
		printf("%c", c);
		

		fill code here -- generate genSchedInfo structure by genSchedInfo function

		
		sched_genSchedInfo(name, place, type, month, day);
		
		put the scheduling info instance generated by genSchedInfo function
		list_addTail(schedInfo, list);
	}
	*/
	
	//close the file pointer
	fclose(fp);
	
	printf("Read done! %i schedules are read\n", list_len(list));
	
	
	//program starts
	while(exit_flag == 0) 
	{
		//3. menu printing
		printf("\n");
		printf("1. print all the schedules\n");
		printf("2. search for schedules in the month\n");
		printf("3. search for schedules in the place\n");
		printf("4. search for specific type schedule\n");
		printf("5. exit\n");		
		
		//4. get option from keyboard
		printf("\n select an option : ");
		scanf("%i", &option);
		
		switch(option)
		{
			case 1: //print all the schedules
				printf("printing all the schedules in the scheduler.....\n\n\n");
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print count and each scheduling info element
					printf("-------------------------");
					/*
					while(list_len(schedInfo)){
						sched_print(schedInfo);
					}
					*/
					//list_len(schedInfo);
					sched_print(schedInfo);
				
					printf(".");
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)

					//fill code this part - end
					//list_isEndNode(ndPtr) == 1;
				}
				
				break;
				
			case 2:
				printf("which month ? : ");
				scanf("%i", &month);
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print scheduling info elements matching to the month
					
					sched_getMonth(month);
					sched_print(schedInfo);
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					//fill code this part - end
					
				}
				
				break;
				
			case 3:
				printf("which place ? : ");
				scanf("%s", place);
				
				ndPtr = list;
				while (list_isEndNode(ndPtr) == 0)
				{
					//file code here -- print scheduling info elements matching to the place
					ndPtr = list_getNextNd(ndPtr); //get the next node from the list
					schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
					
					//fill code this part - end
					
				}
				
				break;
				
			case 4:
				printf("which type ?\n");
				sched_printTypes();
				printf("your choice : ");
				scanf("%s", typeName);
				
				if (/* fill code here -- convert the type and check if the type is valid */
					0 <= typeName < 7)
				{
					ndPtr = list;
					while (list_isEndNode(ndPtr) == 0)
					{
						//file code here -- print scheduling info elements matching to the place
						ndPtr = list_getNextNd(ndPtr); //get the next node from the list
						schedInfo = list_getNdObj(ndPtr); //get the object (scheduling info)
						
						//fill code this part - end
						
					}
				}
				else
				{
					printf("wrong type name!\n");
				}
				break;
				
			case 5:
				printf("Bye!\n\n");
				exit_flag = 1;
				break;
				
			default:
				printf("wrong command! input again\n");
				break;
		}
		
		
	}
	
	return 0;
}
