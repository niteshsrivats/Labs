# install.packages("ggplot2")
library("ggplot2")

x <- rnorm(100, mean=0, sd=1)
y <- rnorm(100, mean=0, sd=1)
ggplot() + geom_point(aes(x=x, y=y), size=3, col="blue")

boxplot(data$x, data$y, Names=c("x", "y"), xlab="x axis", ylab="y axis", col="blue")
