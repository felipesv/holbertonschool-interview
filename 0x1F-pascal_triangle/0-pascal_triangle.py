#!/usr/bin/python3
"""
0. Pascal's Triangle
"""


def pascal_triangle(n):
    """
    pascal_triangle function
    """
    if n <= 0:
        return []

    triangle = []
    for i in range(0, n):
        number = pow(11, i)
        triangle.append([int(j) for j in str(number)])
    return triangle
