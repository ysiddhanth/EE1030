# Code by GVV Sharma
# September 12, 2023
# Revised July 21, 2024
# released under GNU GPL
# Point Vectors

import sys                                          # for path to external scripts
sys.path.insert(0, '/home/ysiddhanth/Documents/matgeo/codes/CoordGeo')  # path to my scripts
import numpy as np
import numpy.linalg as LA
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# local imports (not used in the provided code)
# from line.funcs import *
# from triangle.funcs import *
# from conics.funcs import circ_gen

# Given points
data = np.genfromtxt('values.dat', delimiter=' ', names=True)
xx = data['x']
yy = data['y']
zz = data['z']
A = np.array([xx[0], yy[0], zz[0]]).reshape(-1, 1)
B = np.array([xx[1], yy[1], zz[1]]).reshape(-1, 1)
C = np.array([xx[2], yy[2], zz[2]]).reshape(-1, 1)
origin = np.array([0, 0, 0]).reshape(-1, 1)

# Create a figure and a 3D Axes
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, projection='3d')

# Plot vectors
#ax.quiver(*origin, *A, color='r', arrow_length_ratio=0.1)  # Adjusted arrow length ratio
#ax.quiver(*origin, *B, color='g', arrow_length_ratio=0.1)  # Adjusted arrow length ratio
ax.quiver(*origin, *C, color='b', arrow_length_ratio=0.1)  # Adjusted arrow length ratio
ax.plot([0, xx[0]], [0, yy[0]], [0, zz[0]], 'r--', linewidth=1)
ax.plot([0, xx[1]], [0, yy[1]], [0, zz[1]], 'g--', linewidth=1)
ax.text(xx[0], yy[0], zz[0], 'A', color='red', fontsize=12)
ax.text(xx[1], yy[1], zz[1], 'B', color='green', fontsize=12)
ax.text(xx[2], yy[2], zz[2], 'C=A+B', color='blue', fontsize=12)
# Set limits and aspect ratio
ax.set_xlim(-10, 10)  # Adjust limits based on your data
ax.set_ylim(-10, 10)  # Adjust limits based on your data
ax.set_zlim(-10, 10)  # Adjust limits based on your data
ax.set_box_aspect([1, 1, 1])  # Equal aspect ratio for x, y, and z axes

# Set labels and title
ax.set_xlabel('$X$-Axis')
ax.set_ylabel('$Y$-Axis')
ax.set_zlabel('$Z$-Axis')

plt.grid(True)
plt.title('Unit Vector C in the direction of A+B ', loc='right', pad=15)
plt.show()

