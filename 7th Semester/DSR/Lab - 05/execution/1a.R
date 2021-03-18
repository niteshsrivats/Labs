employeeID <- c(1:10)
salary <- c(10000, 20000, 24000, 45000, 56000, 90000, 100000, 123000, 78000, 99000)
maritalStatus <- c("Married", "Bachelor", "Married", "Bachelor", "Bachelor", "Married", "Married", "Bachelor", "Bachelor", "Bachelor" )
frame <- data.frame(employeeID, salary, maritalStatus)

boxplot(salary ~ maritalStatus, data=frame, col='cyan')
