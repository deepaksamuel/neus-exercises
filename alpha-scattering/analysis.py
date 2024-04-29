#%%
import numpy as np 
import matplotlib.pyplot as plt
import pandas as pd
from scipy.optimize import curve_fit


headers = ['eid','pid','x','y','z','tot_E']

df = pd.read_csv("build/output_nt_simple.csv",skiprows=30,header=0,names=headers)


df = df[df['pid']==1000020000] # select alpha particles

# plt.hist(df['z'],log=True) 

# print(df['pid'].unique()[0]) # get pids

# plot angular distribution

r= np.sqrt(df['x']**2 + df['y']**2 + df['z']**2)  # Magnitude of the vector
r2= np.sqrt(df['x']**2 + df['y']**2)  # Magnitude of the vector
zenith_rad = np.arccos( df['z'] / r)   
phi_rad =  np.sign(df['y']) *np.arccos( df['x'] / r2)   
df['theta'] = zenith_rad
df['phi'] = phi_rad


plt.hist(np.degrees(df['theta']),bins=100,log=True)

#%%


# fitting cosec^4(theta/2) !!! needs updating

# def func(theta, a):
#     return a * np.power(np.sin(theta),-4)


# counts, bins, patches = plt.hist(zenith_rad , bins=25)

# bin_centers = (bins[:-1] + bins[1:]) / 2

# # Fit the function to the histogram
# popt, pcov = curve_fit(func, bin_centers, counts  )

# a = popt[0]

# plt.scatter(bin_centers, func(bin_centers, a), label='Fitted curve', color='orange')


#%%
