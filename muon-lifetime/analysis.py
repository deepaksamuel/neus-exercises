#%%
import numpy as np 
import matplotlib.pyplot as plt
import pandas as pd
from scipy.optimize import curve_fit
#column double eid
#column double pid
#column string detectorId
#column double globTime
#column double tot_E


def exp_func(x, a, b):
    return a * np.exp(-x/b)

headers = ['eid','pid','detector','globTime',"tot_E"]

df = pd.read_csv("build/output_nt_simple.csv",skiprows=30,header=0,names=headers)

df= df[df['pid']==-11]
# df = df[df['detector']=='DetectorB']


plt.hist(df['globTime'],bins=100)



## Fitting an exponential
counts, bin_edges, _ = plt.hist(df['globTime'],bins=100)

bin_centers = (bin_edges[:-1] + bin_edges[1:]) / 2 
popt, _ = curve_fit(exp_func, bin_centers, counts,[5000,25000])
a, b = popt  # Extract fitted parameters
x_fit = np.linspace(min(bin_edges), max(bin_edges), 100)
fitted_curve = exp_func(x_fit, a, b )


plt.plot(bin_centers, counts, 'bo', label='Histogram')
plt.plot(x_fit, fitted_curve, 'r-', label='Fitted Exponential')
plt.xlabel('Data Values')
plt.ylabel('Probability Density')
plt.legend()
plt.show()
print("Lifetime: {} us".format(b/1000))



#%%