# 🧩 Problem Statement — “Packing Efficiency” (HackerRank WSDE-1 Intern)

# At an Amazon distribution center, there is a collection of n products, each with a distinct volume.
# The goal is to evaluate the packing efficiency of the collection, ensuring optimal utilization of space.

# You are given an array volumes, where volumes[i] represents the volume of the i-th product.

# Definition:

# For a subarray B = [volumes[l], volumes[l+1], ..., volumes[r]],
# the packing efficiency of B is defined as the number of indices i in the subarray that satisfy:

# For every index j such that i < j ≤ r,
# volumes[i] > volumes[j]

# In simpler terms:
# An element in a subarray contributes to the packing efficiency if it is greater than all elements to its right in that subarray.

# Task:

# Given an array volumes of size n and an integer k,
# calculate the total packing efficiency of all possible subarrays of size k.

# Input Format:
# n k
# volumes[0] volumes[1] ... volumes[n-1]

# Output Format:
# Single integer — total packing efficiency of all subarrays of size k

# Example:

# Input

# 4 3
# 4 2 1 3


# Subarrays

# [4, 2, 1] → Efficiency = 3
# (4 > 2,1), (2 > 1), (1 alone))

# [2, 1, 3] → Efficiency = 1
# (Only 3 > none to right)

# Output

# 4
from collections import deque

def total_packing_efficiency(volumes, k):
    n = len(volumes)
    total_efficiency = 0
    dq = deque()
    
    for i in range(n):
        # Remove indices that are out of current window
        while dq and dq[0] <= i - k:
            dq.popleft()
        
        # Maintain decreasing order in deque
        while dq and volumes[i] >= volumes[dq[-1]]:
            dq.pop()
        
        dq.append(i)
        
        # Once we reach at least k elements, calculate efficiency
        if i >= k - 1:
            total_efficiency += len(dq)
    
    return total_efficiency


# HackerRank Input Format
if __name__ == "__main__":
    n, k = map(int, input().split())
    volumes = list(map(int, input().split()))
    print(total_packing_efficiency(volumes, k))
