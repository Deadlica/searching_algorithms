from matplotlib import pyplot as plt
import numpy as np

filenames = ["Linear search.csv", "Binary search.csv", "Binary tree search.csv", "Hashtable search.csv"]
#filename = filesnames[0]
tm_cmplx = ""
x_values, y_values, y2_values, std_dev = [], [], [], []
figure, axis = plt.subplots(2, 2)
x, y = 0, 0

def get_measurements(filename):
    x_max, y_max = 0, 0
    file = open(filename)
    row = file.readline()
    #x_values.append(0)
    #y_values.append(0)
    while(row != ""):
        row = row.split()
        x_values.append(float(row[0]))
        y_values.append(float(row[1]))
        std_dev.append(float(row[2]))
        x_max = float(row[0])
        y_max = float(row[1])
        row = file.readline()
    file.close()

    if(filename == "Linear search.csv"):
        tm_cmplx = "O(N)"
        k = y_max / x_max
        for n in x_values:
            y2_values.append(n * k)

    elif(filename == "Binary search.csv"):
        tm_cmplx = "O(log(N))"
        k = y_max / np.log(x_max)
        for n in x_values:
            y2_values.append(np.log(n) * k)
        
    elif(filename == "Binary tree search.csv"):
        tm_cmplx = "O(log(h))"
        k = y_max / np.log(x_max)
        for n in x_values:
            y2_values.append(np.log(n) * k)
        
    elif(filename == "Hashtable search.csv"):
        tm_cmplx = "O(1)"
        k = y_max
        for n in x_values:
            y2_values.append(1 * k)


def plot(x, y):
   axis[x, y].set_title(filename.split(".")[0])
   axis[x, y].plot(x_values, y2_values, label=tm_cmplx)
   axis[x, y].errorbar(x_values, y_values, yerr=std_dev, fmt="o", label=filename.split(".")[0])
   axis[x, y].set_ylabel("t [s]")
   axis[x, y].set_xlabel("N elements")
   axis[x, y].legend(loc="best")



for filename in filenames:
    get_measurements(filename)
    if(filename == "Linear search.csv"):
        plot(0, 0)

    elif(filename == "Binary search.csv"):
        plot(0, 1)
        
    elif(filename == "Binary tree search.csv"):
        plot(1, 0)
        
    elif(filename == "Hashtable search.csv"):
        plot(1, 1)
        axis[1, 1].set_ylim(0, 0.0000001)

    x_values, y_values, y2_values, std_dev = [], [], [], []


plt.show()
