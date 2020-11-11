#Example bottles are being produced with mean  151.8 and standard deviation of 2.
# Sample of 100 bottles show the mean of 152. Check whether the mean has increased or not

# H0 = 150
# H1 = HA>150


library(visualize)
zvalue = (152-151.8)/(2/sqrt(100))
zvalue
qnorm(0.95)
qnorm(0.05)
visualize.norm(stat=zvalue,mu=0,sd=1,section="upper")

