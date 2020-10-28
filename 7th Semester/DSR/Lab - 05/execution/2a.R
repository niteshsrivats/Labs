# install.packages("ggplot2")
library("ggplot2")

x <- rnorm(100)
y <- x + rnorm(100, mean=0, sd=1)
data <- as.data.frame(cbind(x, y))
ggplot() + geom_point(data=data, aes(x=x, y=y), size=3, col="blue")

boxplot(data$x, data$y, Names=c("x", "y"), xlab="x", ylab="y", col="blue")
