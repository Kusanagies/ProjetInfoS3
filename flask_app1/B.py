import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation
import random


def bubble_sort_animation(data):
    # Create initial plot
    fig, ax = plt.subplots()
    bars = ax.bar(np.arange(len(data)), data)

    # Function to update the bar plot and perform sorting step
    def update(frame):
        nonlocal data
        for i in range(len(data)-1):
            if data[i] > data[i+1]:
                # Swap if the element found is greater than the next element
                data[i], data[i+1] = data[i+1], data[i]

        # Update the bar plot with the current state of the array
        for i, bar in enumerate(bars):
            if i in (frame, frame+1):  # Highlight bars being swapped
                bar.set_color('red')
            else:
                bar.set_color('black')

            bar.set_height(data[i])
        return bars

    # Create the animation
    animation = FuncAnimation(fig, update, frames=len(data)-1, interval=500, repeat=False)

    plt.show()

# Example usage:
my_list = []
for i in range(100):
    my_list.append(random.randint(0,100))

bubble_sort_animation(my_list)



