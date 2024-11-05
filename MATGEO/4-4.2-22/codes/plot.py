#Code by GVV Sharma
#July 22, 2024
#released under GNU GPL
#Line 


import sys                                          #for path to external scripts
sys.path.insert(0, '/home/ysiddhanth/Documents/matgeo/codes/CoordGeo')        #path to my scripts
import numpy as np
import mpmath as mp
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen

#Direction vector
#Given points

data = np.genfromtxt('values.dat', delimiter=' ', names=True)
a = data['a']
b = data['b']
c = data['c']
n1 = np.array(([a[0], b[0]])).reshape(-1,1) 
n2 = np.array(([a[1], b[1]])).reshape(-1,1) 
l1 = line_norm(n1,c[0],-3,3)
l2 = line_norm(n2,c[1],-3,3)
plt.plot(l1[0, :], l1[1, :], label='$Line 1 -> 5x + 10y + 4 = 0$', color = 'blue');
plt.plot(l2[0, :], l2[1, :], label='$Line 2 -> x + 2y + 3 = 0$',color = 'red');
ax = plt.gca()
ax.spines['top'].set_color('none')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['bottom'].set_position('zero')
'''
ax.spines['left'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['top'].set_visible(False)
ax.spines['bottom'].set_visible(False)
plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
'''

plt.xlabel('$X$-Axis')
plt.ylabel('$Y$-Axis')
plt.grid() # minor
plt.axis('equal')
plt.legend(loc='best')
plt.title('Proving the condition for parallel lines', loc = 'right', pad = 15)
plt.show()
plt.savefig('../figs/fig.pdf')
