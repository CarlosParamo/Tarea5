import numpy as np
import matplotlib.pyplot as plt 

a= np.genfromtxt("RadialVelocities.dat", delimiter=None, skip_header=0)
#b= np.genfromtxt("dataout.dat", delimiter=None)

plt.plot(a[:,0],a[:,1], label='Datos')
#plt.plot(a[:,0],b[:,0], label='Modelo')
plt.legend(loc = 1) 
plt.ylabel("$Velocidad[km/s]$")
plt.xlabel("$Radio[Kpc]$")
plt.savefig("plots.png") 
