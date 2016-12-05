import numpy as np

def newton(Function, o0, dx=1e-6, tolerance=1e-6, steps=1000):
    def F(x):
        return eval(Function)
    def out(s1, s2, s3):
        print("{:>15}".format(s1), "{:>15}".format(s2), "{:>15}".format(s3))
    out("iterations", "optimum", "%rel. error")
    out(0, o0, 100)
    for i in range(1, steps):
        first = (F(o0+dx) - F(o0-dx)) / (2*dx)
        second = (F(o0+dx) - 2*F(o0) + F(o0-dx)) / (dx**2)
        o = o0 - first/second
        error = abs((o-o0)/o)*100
        out(i, round(o,6), round(error))
        o0 = o
        if(error < tolerance):
            break
    return o

o = newton("np.log(np.exp(x+3) + np.exp(-2*x+2))", 0)
