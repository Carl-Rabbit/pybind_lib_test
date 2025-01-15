import test_module
import numpy as np

print(f"test_module.add(1, 2) = {test_module.add(1, 2)}")

a = np.array([1, 2, 3], dtype=np.float64)
b = np.array([4, 5, 6], dtype=np.float64)
print(f'test_module.add_arrays_1d({a}, {b}) = {test_module.add_arrays_1d(a, b)}')