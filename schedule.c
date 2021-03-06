#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "schedule.h"

#define MAX_TYPE		7

//strings for printing the name of each enum element
//enum type's name
char type_string[MAX_TYPE][20] = 
{
	"drama",
	"movie",
	"advertisement",
	"entertainment",
	"meeting",
	"fitness",
	"privacy"
};

//month's name
char month_string[13][4] = 
{
	"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
};

//enum definitions
typedef enum scheduleType {
	drama=0, 		//드라마 
	movie, 			//영화 
	advertisement, 	//광고 
	entertainment, 	//예능 
	meeting,		//회의 
	fitness,		//운동 
	privacy			//개인사 
} scheduleType_e;

//structure definition for a schedule info.
typedef struct schedInfo
{
	char name[200];			//schedule name
	scheduleType_e type;	//schedule type
	int month;				//when : month
	int day;				//when : day
	char place[100];		//where
} schedInfo_t;


void sched_printTypes(void) 
{
	int i;
	
	for (i=0;i<MAX_TYPE;i++) {
		printf("- %s\n", i, type_string[i]);
	}
}

void sched_print(void* obj) 
{
	schedInfo_t* schedPtr = (schedInfo_t*)obj;
	
	if (schedPtr == NULL) {
		printf("[ERROR] failed to print the schedule Info! (object is NULL)\n");
	}
	
	printf("Schedule Name : %s (%s)\n", schedPtr->name, type_string[schedPtr->type]);
	printf("When : %s. %i\n", month_string[schedPtr->month], schedPtr->day);
	printf("Where : %s\n", schedPtr->place);
	
	return;
}

//generating a structure of scheduling information
void* sched_genSchedInfo(char* name, char* place, int type, int month, int day)
{
	schedInfo_t* schedPtr;

	//allocate memory
	schedPtr = malloc(sizeof(schedInfo_t));
	
	//error handler
	if (schedPtr == NULL) {
		printf("[ERROR] 메모리 할당 오류\n");
		return;
	}	
	
	//set the member variables
	strcpy(schedPtr->name, name);
	strcpy(schedPtr->place, place);
	schedPtr->type = type;
	schedPtr->month = month;
	schedPtr->day = day;
	
	free(schedPtr);

	return (void*)schedPtr;
}



//get month information from the scheduler info structure
float sched_getMonth(void* obj)
{
	
}


//get type information from the scheduler info structure
int sched_getType(void* obj)
{

}



//get place string information from the scheduler info structure
char* sched_getPlace(void* obj)
{

}

//convert the name of the type into the enum(integer) value
int sched_convertType(char* typeName)
{

	if(typeName == "drama") 		// 드라마 
	{
		int typeName = 0;
	}
	if(typeName == "movie")			//영화
	{
		int typeName = 1;
	}
	if(typeName == "advertisement")	//광고
	{
		int typeName = 2;
	}
	if(typeName == "entertainment")	//예능
	{
		int typeName = 3;
	}
	if(typeName == "meeting")		//회의
	{
		int typeName = 4;
	}
	if(typeName == "fitness")		//운동 
	{
		int typeName = 5;
	}
	if(typeName == "privacy")		//개인사  
	{
		int typeName = 6;
	}
	return typeName;
}

