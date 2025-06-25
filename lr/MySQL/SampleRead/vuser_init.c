
/***********************************************************************************************
//
//  This sample script was created in LoadRunner 9.52
//	Author: 	Richard Bishop
//	Date: 		5th August 2010
//	Contact:	I can be contacted via my website www.bish.co.uk
//
//*********************************************************************************************/


	#include "Ptt_MySQL.h"

	vuser_init()
	{
		lr_load_dll("libmysql.dll"); 

        #define MYSQLSERVER 	"127.0.0.1"
		#define MYSQLUSERNAME 	"root"
		#define MYSQLPASSWORD 	"root"
		#define MYSQLDB			"loadrunner_db"
		#define MYSQLPORT 		"3306"

		return 0;
	}



