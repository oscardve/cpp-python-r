X11()

df1 <- read.table("data.txt")
x <- df1[,1]
y <- df1[,2]

n <- length(x)
model <- lm(y ~ poly(x, n-1, raw=TRUE))
xf <- seq(x[1], x[n], by =0.01)
yf <- predict(model, data.frame(x=xf))

summary(model)
plot(x, y)
lines(xf, yf)
write.table(data.frame(xf,yf),
    file="out.txt", sep='\t', row.names=F, col.names=F)

readLines("stdin", 1)
