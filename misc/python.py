import os
import sys

# Add the directory containing mymodule.so to the Python module search path
module_dir = os.path.abspath('mymodule')
sys.path.append(module_dir)

# import mylib

# print(mylib())

import mylib

result = mylib.add(2, 3, 5667)
print(result)
