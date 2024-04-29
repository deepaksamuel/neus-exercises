#%%
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
headers = ["binx","biny","binz",'eDep-MeV','total','entries']
df = pd.read_csv("build/eDep.txt",skiprows = 3,header=None,names=headers)
plt.scatter(df["binz"],df["eDep-MeV"]) 

