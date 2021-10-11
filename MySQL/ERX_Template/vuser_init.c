#define MYSQLSERVER 	"127.0.0.1"//"eberg-media"
#define MYSQLUSERNAME 	"root"
#define MYSQLPASSWORD 	""
#define MYSQLDB			"loadrunner_db"
#define MYSQLPORT 		"3306"
#include "Ptt_MySQL.h"

//Declare MySQL Elements
char sqQuery[512];			// The MySQL query to be executed
MYSQL *Mconn; 				// The MySQL connection string
							 
//Declare variables used to choose a random row.
int iNumRecords;            // The number of records in the parameter table
int iMIN, IMAX;				// The minimum and maximum values for the random number function
int iRand;					// The random number generated by the fRandInt function 
double dDuration;

vuser_init()
{
	lr_load_dll("libmysql.dll"); 

	return 0;
}


int fRandInt( int iMIN, int iMAX )
{
	return (iMIN + (int) ((iMAX-iMIN+1) * (((float)rand())/(float)32768)));
}
