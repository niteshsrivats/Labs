library("ggplot2")
mtcars
str(mtcars)
dotchart(mtcars$mpg, labels=row.names(mtcars), xlab="MPG", 
         main="Miles Per Gallan of Car")
