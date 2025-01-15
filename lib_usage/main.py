import test_module
import numpy as np

print(f"test_module.__version__ = {test_module.__version__}")

a = np.array([1, 2, 3], dtype=np.float64)
b = np.array([4, 5, 6], dtype=np.float64)
print(f'test_module.add_arrays_1d({a}, {b}) = {test_module.add_arrays_1d(a, b)}')