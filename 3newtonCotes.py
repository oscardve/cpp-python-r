def trapezoidal(file):
    fin = open(file)
    line = fin.readline()
    x0, y0 = [float(v) for v in line.split()]
    I = 0
    for line in fin:
        x, y = [float(v) for v in line.split()]
        I += (x-x0)*(y+y0)/2
        x0 = x
        y0 = y
    return I

I = trapezoidal("data.txt")
print("Integral =", round(I,5))
