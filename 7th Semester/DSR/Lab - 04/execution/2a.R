setwd("C:/Users/Nites/Desktop/Labs/7th Semester/DSR/Lab - 04/csv/")
data <- read.csv('./Churn_Modelling.csv')
summary(data)
data$EstimatedSalary
min(data$EstimatedSalary)
max(data$EstimatedSalary)
income_group<-vector(mode="character",length=length(data$EstimatedSalary))
income_group[data$EstimatedSalary<10000]<-"Low"
income_group[data$EstimatedSalary>=10000 & data$EstimatedSalary < 100000]<-"middle"
income_group[data$EstimatedSalary>100000]<-"High"
income_level<-factor(income_group,levels=c("Low","middle","High"),ordered=TRUE)
income_level
data<-cbind(data, income_level)
data
write.csv(data,'output.csv',row.names = FALSE)
