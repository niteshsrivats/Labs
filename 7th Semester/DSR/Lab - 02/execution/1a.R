setwd("C:/Users/Nites/Desktop/Labs/7th Semester/DSR/Lab - 02/csv/")
data <- read.csv("indian_food.csv")
data
summary(data)
ncol(data)
nrow(data)
plot(x=data$prep_time,y=data$cook_time)
