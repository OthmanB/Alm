'''
    Module to interpret and visualise the filter function file generated by Filter_Alm
    and used in the Alm function
'''
import numpy as np
import matplotlib.pyplot as plt

def read_data(file):
    '''
        A function to read and interpret the ascii data created by Filter_Alm (C++)
         - Copy / Paste in a file the graphical output from Filter_Alm and,
         - Execute this code to read it
    '''
    f=open(file)
    data=f.read().split('\n')
    f.close()
    params={}
    theta=[]
    F=[]
    for d in data:
        print(d)
        if d != "":
            line=d.strip()
            if line[0] == "#":
                passed=False
                key=line[1:].split('=')[0].strip()
                if key == "ftype":
                    params[key]=line[1:].split('=')[1].strip() # The value is put in a dictionary
                    passed=True
                if key == "delta" or key == "theta0":
                    params[key]=float(line[1:].split('=')[1])  # The value is converted in double and then put in the dictionary
                if passed == False:
                    params["header"]= line # If this is something we did not recognize, it is put in the header
            else:
                theta.append(float(d.split()[0]))
                F.append(float(d.split()[1]))
    theta=np.asarray(theta, dtype=float)
    F=np.asarray(F, dtype=float)
    return theta, F, params

def show_filter(file):
    '''
        A function that visualise the outputs of the Filter_Alm
        It allows to check that the filter is behaviing as expected
    '''
    theta, F, params=read_data(file)
    plt.plot(theta/np.pi, F)
    plt.axvline(x=0.5, linestyle='--', color='red')
    plt.axhline(y=1, linestyle='--', color='red')
    plt.axhline(y=0, linestyle='--', color='red')
    plt.axvline(x=params["theta0"]/np.pi, color='green', linestyle='-.')
    plt.axvline(x=1 - params["theta0"]/np.pi, color='green', linestyle='-.')
    plt.xlabel('co-latitude (in Pi units)')
    plt.xlim(0, 1.)
    plt.show()
