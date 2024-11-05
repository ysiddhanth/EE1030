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
xab = data['xab']
yab = data['yab']
xbc = data['xbc']
ybc = data['ybc']
xca = data['xca']
yca = data['yca']

A = np.array(([xab[0], yab[0]])).reshape(-1,1) 
B = np.array(([xbc[0], ybc[0]])).reshape(-1,1) 
C = np.array(([xca[0], yca[0]])).reshape(-1,1) 
AB = np.vstack(([xab, yab]))
BC = np.vstack(([xbc, ybc]))
CA = np.vstack(([xca, yca]))
colors = np.arange(1,4)
#Labeling the coordinates
tri_coords = np.block([A,B,C])
plt.scatter(tri_coords[0,:], tri_coords[1,:], c=colors)
plt.plot(AB[0, :], AB[1, :], label='$AB$')
plt.plot(BC[0, :], BC[1, :], label='$BC$')
plt.plot(CA[0, :], CA[1, :], label='$CA$')
vert_labels = ['A','B','C']
for i, txt in enumerate(vert_labels):
    #plt.annotate(txt, # this is the text
    plt.annotate(f'{txt}\n({tri_coords[0,i]:.2f}, {tri_coords[1,i]:.2f})',
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(-30,5), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

# use set_position
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
plt.title('Drawing triangle ABC', loc = 'right', pad = 15)
plt.show()
