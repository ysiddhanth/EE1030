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
x = data['x']
y = data['y']

A = np.array(([x[0], y[0]])).reshape(-1,1) 
B = np.array(([x[31], y[31]])).reshape(-1,1) 
AB = np.vstack(([x, y]))
colors = np.arange(1,3)
#Labeling the coordinates
tri_coords = np.block([A,B])
plt.scatter(tri_coords[0,:], tri_coords[1,:], c=colors)
plt.plot(AB[0, :], AB[1, :], label='$AB$')
vert_labels = ['A','B']
'''
plt.annotate(f'A\n({tri_coords[0,0]:.2f}, {tri_coords[1,0]:.2f})',
              (tri_coords[0,0], tri_coords[1,0]), # this is the point to label
              textcoords="offset points", # how to position the text
              xytext=(25,5), # distance from text to points (x,y)
              ha='center') # horizontal alignment can be left, right or center
plt.annotate(f'B\n({tri_coords[0,1]:.2f}, {tri_coords[1,1]:.2f})',
              (tri_coords[0,1], tri_coords[1,1]), # this is the point to label
              textcoords="offset points", # how to position the text
              xytext=(25,5), # distance from text to points (x,y)
              ha='center') # horizontal alignment can be left, right or center
'''

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
plt.title('Calculating the distance 2AB', loc = 'right', pad = 15)
plt.show()
