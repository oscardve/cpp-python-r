import numpy as np

def newtonRaphson(Function, r0, dr=1e-8, tolerance=1e-8, steps=1000):
    def F(x):
        return eval(Function)
    def out(s1, s2, s3):
        print("{:>15}".format(s1),
              "{:>15}".format(s2),
              "{:>15}".format(s3))
    out("iteration", "root", "% rel. error");
    out(0, r0, 100);
    for i in range(1, steps):
        slope = (F(r0+dr) - F(r0-dr)) / (2*dr)
        r = r0 - F(r0) / slope
        error = abs((r - r0) / r)
        out(i, round(r,6), round(error,6))
        if(error < tolerance):
            break
        r0 = r;
    return r

r = newtonRaphson("np.exp(-x)*x + 10", r0=0)
