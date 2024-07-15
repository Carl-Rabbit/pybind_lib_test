import my_test
import numpy as np

print(my_test.add(1, 2))

a = np.array([1, 2, 3], dtype=np.float64)
b = np.array([4, 5, 6], dtype=np.float64)
print(my_test.add_arrays_1d(a, b))