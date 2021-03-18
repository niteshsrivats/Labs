
#Import the data using read.delim() and use cbind() to add column.

data <- read.delim("indian_food_3.csv",sep=',')
data

summary(data)

getwd()
new_additional_data <- read.delim("indian_food_2.csv",sep=',')
new_additional_data
cbind(data,new_additional_data$Price...kg)
