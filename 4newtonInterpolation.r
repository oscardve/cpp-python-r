X11()

inter <- function(file){
    #input:
    df1 <- read.table(file, col.names=c("x", "y"))

    #finite divided differences:
    n <- length(df1$x)
    M <- matrix(0, nrow=n, ncol=n)
    M[,1] <- df1$y
    for(j in 1:(n-1))
        for(i in 0:(n-j-1))
            M[i+1,j+1] = (M[i+2,j] - M[i+1,j]) /
                (df1$x[i+j+1] - df1$x[i+1]);

   #interpolation:
   x <- seq(df1$x[1], df1$x[n], by=0.01)
   y <- M[1,1]
   factor <- 1
   for(j in 1:(n-1)){
       factor <- factor * (x-df1$x[j])
       y <- y + factor * M[1,j+1]
   }

   #output:
   write.table(data.frame(x, y),
    file="out2.txt", sep='\t', row.names=F, col.names=F)

   plot(df1, main="Newton interpolation", xlab="X", ylab="Y")
   lines(x, y)
}

inter("data.txt")

readLines("stdin", 1)
