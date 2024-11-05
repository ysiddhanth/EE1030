import ctypes
import numpy as np

# Load the shared library
lib = ctypes.CDLL('./customcom.so')

# Define the argument and return types of the C function
lib.calculateRank.argtypes = [ctypes.POINTER(ctypes.POINTER(ctypes.c_float)), ctypes.c_int, ctypes.c_int]
lib.calculateRank.restype = ctypes.c_int

# Example matrix (3x4)
matrix = np.array([
    [0.0, -14.0],
    [3.0, 1.0]
], dtype=np.float32)

m, n = matrix.shape

# Convert the numpy array to ctypes format
MatrixType = ctypes.POINTER(ctypes.c_float) * m
c_matrix = MatrixType(*[row.ctypes.data_as(ctypes.POINTER(ctypes.c_float)) for row in matrix])

# Call the C function to calculate the rank
rank = lib.calculateRank(c_matrix, m, n)
area = lib.triarea(0,5,0,-9,3,6)


print(f"The rank of the matrix is: {rank}")
print("Area of triangle ABC is ", area)



