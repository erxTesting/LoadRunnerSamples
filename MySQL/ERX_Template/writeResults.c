writeResults()
{
	lr_start_transaction("0001_Example");

		lr_think_time(1);
		dDuration=lr_get_transaction_duration("0001_Example"); 	
		
	lr_end_transaction("0001_Example",LR_AUTO);

	
	lr_save_datetime("%H:%M:%S", TIME_NOW, "sTime"); 
	iRand = fRandInt (1,1000000);

	//Create the connection string to connect to the server and relevant database
	Mconn = lr_mysql_connect(MYSQLSERVER, MYSQLUSERNAME, MYSQLPASSWORD, MYSQLDB, atoi(MYSQLPORT));									//Connect to the MySQL server defined in ..\..\LR_Includes\MySQLSettings.h

	//Build an SQL query and save the query as sqQuery
	sprintf(sqQuery, "insert into loadrunner_db.results (time, duration, returned_data)"
			"values (\"%s\",\"%f\",\"%i\")",
			lr_eval_string("{sTime}"),
			dDuration,
			iRand);


	//Execute the SQL query (sqQuery) against the server and database defined as Mconn
	lr_mysql_query(Mconn, sqQuery);

	lr_output_message("This SQL statement executed - [%s]",sqQuery); 	

	//Disconnect from MySQL
	lr_mysql_disconnect(Mconn);

	return 0;
}
