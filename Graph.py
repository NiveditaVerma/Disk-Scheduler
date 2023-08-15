import sys
import matplotlib.pyplot as plt
import numpy as np


if len(sys.argv) < 2:
    print("No data provided.")
    sys.exit(1)


data_string = sys.argv[1]


print("Received data string:", data_string)


data = []
for val in data_string.split(','):
    if val:
        try:
            data.append(float(val))
        except ValueError:
            print("Invalid value:", val)


print("Initial data values:")
for val in data:
    print(val)


indices = np.flip(np.arange(len(data)))


plt.plot(data, indices, 'ro-')  
plt.xlabel('Value')
plt.ylabel('Index')
plt.title('Data Plot')
plt.show()
