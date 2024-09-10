#Code by GVV Sharma
#September 12, 2023
#Revised July 21, 2024
#released under GNU GPL
#Point Vectors


import sys                                          #for path to external scripts
sys.path.insert(0, '/home/ysiddhanth/Documents/matgeo/codes/CoordGeo')        #path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
from mpl_toolkits.mplot3d import Axes3D

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen
data = np.genfromtxt('values.dat', delimiter=' ', names=True)
xab = data['xab']
yab = data['yab']
zab = data['zab']
xbc = data['xbc']
ybc = data['ybc']
zbc = data['zbc']
xca = data['xca']
yca = data['yca']
zca = data['zca']
#Given points
A = np.array(([xab[0], yab[0],zab[0]])).reshape(-1,1) 
B = np.array(([xbc[0], ybc[0],zbc[0]])).reshape(-1,1) 
C = np.array(([xca[0], yca[0],zca[0]])).reshape(-1,1) 
ABmid = np.vstack(([xab, yab,zab]))
BCmid = np.vstack(([xbc, ybc,zbc]))
ACmid = np.vstack(([xca, yca,zca]))

# Create a figure and a 3D Axes
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')


# Scatter plot
colors = np.arange(1, 4)  # Example colors
tri_coords = np.block([A, B, C])  # Stack A, B, C vertically
ax.scatter(tri_coords[0, :], tri_coords[1, :], tri_coords[2, :], c=colors)
ax.plot(BCmid[0, :], BCmid[1, :], BCmid[2, :], label='$BC$')
ax.plot(ACmid[0, :], ACmid[1, :], ACmid[2, :], label = '$AC$')
vert_labels = ['A', 'B', 'C']

for i, txt in enumerate(vert_labels):
    # Annotate each point with its label and coordinates
    ax.text(tri_coords[0, i], tri_coords[1, i], tri_coords[2, i], f'{txt}\n({tri_coords[0, i]:.02f}, {tri_coords[1, i]:.02f}, {tri_coords[2, i]:.02f})',
             fontsize=12, ha='center', va='bottom')

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
plt.title('Showing that A,B,C are collinear', loc = 'right', pad = 15)
plt.show()
