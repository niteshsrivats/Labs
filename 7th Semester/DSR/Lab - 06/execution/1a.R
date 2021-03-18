library("gcookbook")
library("ggplot2")
cabbage_exp
str(cabbage_exp)
ggplot(cabbage_exp, aes(fill=Cultivar, y=Weight, x=Date)) + 
  geom_bar(position="dodge", stat="identity") +
  geom_text(aes(label=Weight), position=position_dodge(0.9),
            vjust=1.6, size=3.5, color="white")
