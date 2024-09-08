import ctypes
import numpy as np

lib = ctypes.CDLL('./customcom.so')

lib.ndimdis.argtypes = [ctypes.POINTER(ctypes.POINTER(ctypes.c_double)), 
                        ctypes.POINTER(ctypes.POINTER(ctypes.c_double)), 
                        ctypes.c_int]
lib.ndimdis.restype = ctypes.c_double

A = np.array([[-6], [7]], dtype=np.float64)
B = np.array([[-1], [-5]], dtype=np.float64)

def to_ctypes_double_pointer(matrix):
    pointer_type = ctypes.POINTER(ctypes.c_double)
    return (pointer_type * len(matrix))(*[row.ctypes.data_as(pointer_type) for row in matrix])

a_matrix = to_ctypes_double_pointer(A)
b_matrix = to_ctypes_double_pointer(B)

n = A.shape[0]
distance = lib.ndimdis(a_matrix, b_matrix, n)

print(f"The n-dimensional distance is: {distance}")

