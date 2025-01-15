import test_module
import numpy as np

def test_func():
    print(f"test_module.add(1.0, 2.0) = {test_module.add(1.0, 2.0)}")
    print()

    a = np.array([1, 2, 3], dtype=np.float64)
    b = np.array([4, 5, 6], dtype=np.float64)
    print(f'test_module.add_arrays_1d({a}, {b}) = {test_module.add_arrays_1d(a, b)}')
    print()


def test_cls():
    pet = test_module.Dog("Molly")
    print(f"pet.name = {pet.name}")
    print(f"pet.sound() = {pet.sound()}")
    print(f'type(pet) = {type(pet)}')
    print()

    pet = test_module.mk_pet("Dog", "Molly")
    print(f"pet.name = {pet.name}")
    print(f"pet.sound() = {pet.sound()}")
    print(f'type(pet) = {type(pet)}')
    print()

    box = test_module.mk_box("RedBox", np.dtype(np.float64))
    print(f"type(box) = {type(box)}")
    print(f"box.type = {box.type()}")
    print(f"box.dtype = {box.dtype()}")
    box.put(1.2)
    print(f"box.get() = {box.get()}")
    print()

    box = test_module.mk_box("BlueBox", np.dtype(np.int32))
    print(f"type(box) = {type(box)}")
    print(f"box.type = {box.type()}")
    print(f"box.dtype = {box.dtype()}")
    box.put(2)
    print(f"box.get() = {box.get()}")
    print()


if __name__ == "__main__":
    print(f"test_module.__version__ = {test_module.__version__}")
    test_func()
    test_cls()