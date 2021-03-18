setwd("C:/Users/Nites/Desktop/Labs/7th Semester/DSR/Lab - 03/csv/")
data <- read.delim("indian_food_3.csv",sep=',')
head(data)
data

summary(data)

new_additional_data <- read.delim("indian_food_2.csv",sep=',')
new_additional_data
final_data <- cbind(data,price=new_additional_data$Price)
final_data

write.csv(final_data,"output.csv",row.names = FALSE)

