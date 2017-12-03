import numpy as np
import matplotlib.pyplot as plt 

a = np.genfromtxt("RadialVelocities.dat", delimiter=None, skip_header=0)

plt.plot(a[:,0],a[:,1])
plt.show() 
