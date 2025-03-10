import random
import time

def insertion_sort(arr):
    steps = 0
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
            steps += 2  # Increment steps for comparison and assignment
        arr[j + 1] = key
        steps += 1  # Increment step for the final assignment
    return arr, steps

# Parameters
n = 1000  # Size of the array
iterations = 10000  # Number of runs

# Generate random array
original_arr = [random.randint(1, 10000) for _ in range(n)]

total_time = 0
total_steps = 0

for _ in range(iterations):
    # Make a copy of the original array for each iteration
    arr = original_arr[:]
    
    start = time.time()
    _, steps = insertion_sort(arr)
    end = time.time()
    
    total_time += (end - start)
    total_steps += steps

# Calculate average time and steps
average_time = total_time / iterations
average_steps = total_steps / iterations

print(f"Average time taken by Insertion Sort in Python over {iterations} runs: {average_time:.6f} seconds")
print(f"Average steps taken by Insertion Sort over {iterations} runs: {average_steps:.2f}")
