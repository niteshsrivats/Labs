#One sample t-test.
# Given n=55 , Mean of the sample = 11.0 g/100ml ; std deviation = 2.1 g/100ml and Mean of the population = 10.2g / 100ml
# H0 mean = 10.2g / 100ml
# Ha mean <> 10.2g/100ml

library(visualize)
zvalue = (11-10.2)/(2.1/sqrt(55))
zvalue
pnorm(zvalue)
dnorm(zvalue)
pnorm(2.825218) - pnorm(-2.825218)
qnorm(0.05)
visualize.norm(stat=zvalue,mu=0,sd=1,section="upper")
visualize.norm(stat=c(2.825218,-2.825218),mu=0,sd=1,section="tails")
