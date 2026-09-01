# Advanced SQL 

![](assets/documents/CS3043%20-%20Advanced%20SQL.pdf)

## JDBC

If the database is busy and the connection fails, retry with degradation. Ex: after 1 sec, 5 sec, 10 sec, 30 sec etc. Also catch error to see what the problem is and notify admins if necessary.

We can refer by attribute name or position after receiving the result in JDBC. Better to access with name since it is easier to update and understand the code.

When using update command, we do not get a result set. Instead, we get whether the operation was successful or not.

### Prepared Statements

Prepared statements protect against [SQLi](../../../../../../Cybersecurity/hacking/attacks%20and%20vulnerabilities/webapp/SQLi/SQLi.md) by treating the dynamic values as literals. Also the query is optimized and cached beforehand, providing a performance boost.