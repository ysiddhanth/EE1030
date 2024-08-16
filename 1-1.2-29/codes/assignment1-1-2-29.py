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

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen




theta = 60
#Given points
A = np.array(([-2, 8])).reshape(-1,1) 
B = np.array(([-1, 7])).reshape(-1,1)  
C = np.array(([0, -5/4])).reshape(-1,1)  
D = np.array(([1, 3])).reshape(-1,1)  
E = np.array(([3, -1])).reshape(-1,1)  



#Labeling the coordinates
colors = np.arange(1,6)
quin_coords = np.block([[A,B,C,D,E]])
plt.scatter(quin_coords[0,:], quin_coords[1,:], c=colors)
vert_labels = ['A','B','C','D','E']
for i, txt in enumerate(vert_labels):
    #plt.annotate(txt, # this is the text
    plt.annotate(f'{txt}\n({quin_coords[0,i]:.2f}, {quin_coords[1,i]:.2f})',
                 (quin_coords[0,i], quin_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(25,5), # distance from text to points (x,y)
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
plt.grid() # minor
plt.axis('equal')

plt.savefig('fig1.png')
plt.show()
