randomRead()
{
	//Create the connection string to connect to the server and relevant database
	Mconn = lr_mysql_connect(MYSQLSERVER, MYSQLUSERNAME, MYSQLPASSWORD, MYSQLDB, atoi(MYSQLPORT));									//Connect to the MySQL server defined in ..\..\LR_Includes\MySQLSettings.h

	// Build and execute query to determine the number of rows in the parameters table
	sprintf(sqQuery, "SELECT COUNT(*) FROM loadrunner_db.parameters");
	lr_mysql_query(Mconn, sqQuery);

	//Save the returned value as a string called iNumRecords
	lr_save_string(row[0][0].cell, "sNumRecords");
//	lr_output_message( "sNumRecords #%s", lr_eval_string( "{sNumRecords}" ) ); 
			
	//Convert the string into an integer so that it can be used in the fRandInt function
	iNumRecords =atoi(lr_eval_string("{sNumRecords}"));
//	lr_output_message( "iNumRecords #%d", iNumRecords ); 

	//Choose a random row between 0 and iNumRecords
	iRand = fRandInt (1,(iNumRecords+1))-1;
	lr_output_message("Random number is : %d",iRand); 	

	//iRand=2;

	//Build an SQL query and save the query as sqQuery
	sprintf(sqQuery, "select username, password, secret from loadrunner_db.parameters LIMIT %d,1",iRand);

	//Execute the SQL query (sqQuery) against the server and database defined as Mconn
	lr_mysql_query(Mconn, sqQuery);

	//Save the values returned in the random row of the table
	//N.B. The row/cell values appear to be the "wrong way round"
	lr_save_string(row[0][0].cell, "sUsername");
	lr_save_string(row[1][0].cell, "sPassword");
	lr_save_string(row[2][0].cell, "sSecret");

	//Output the returned values
	lr_output_message(lr_eval_string("Username: {sUsername}"));
	lr_output_message(lr_eval_string("Password: {sPassword}"));
	lr_output_message(lr_eval_string("Secret: {sSecret}"));

	//Disconnect from MySQL
	lr_mysql_disconnect(Mconn);

	return 0;
}
