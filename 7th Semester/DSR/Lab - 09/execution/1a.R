temp <- c(50, 53, 54, 55, 56, 59, 62, 65, 65, 71, 72, 74, 75, 76, 79)
yield <- c(122, 118, 128, 121, 125, 136, 144, 142, 149, 161, 167, 168, 172, 171, 175)

cor(temp, yield)

df <- data.frame(temp,yield)
head(df)

linear <- lm (yield~temp, data=df)

summary(linear)
names(linear)
linear$coefficients

newypred <- fitted(linear)
newypred

plot(df$temp, df$yield, col="red")
abline(linear, col="red")
