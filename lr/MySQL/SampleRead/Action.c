	//Declare MySQL Elements
	char sqQuery[512];			// The MySQL query to be executed
	MYSQL *Mconn; 				// The MySQL connection string
	int MyRC;					// The MySQL return code

	Action()
	{
		//Create the connection string to connect to the server and relevant database
		Mconn = lr_mysql_connect(MYSQLSERVER, MYSQLUSERNAME, MYSQLPASSWORD, MYSQLDB, atoi(MYSQLPORT));									//Connect to the MySQL server defined in ..\..\LR_Includes\MySQLSettings.h

		//Build an SQL query and save the query as sqQuery
        sprintf(sqQuery, "select username, password, secret from loadrunner_db.parameters");

		//Execute the SQL query (sqQuery) against the server and database defined as Mconn
        lr_mysql_query(Mconn, sqQuery);

		//Save the values returned in the first row of the table
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
