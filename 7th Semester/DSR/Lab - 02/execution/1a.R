 # Import a CSV File , summarize the file  and plot any 2 numeric columns of the file.

getwd()
data <- read.csv("indian_food.csv")
data
summary(data)
ncol(data)
nrow(data)
plot(x=data$prep_time,y=data$cook_time)
