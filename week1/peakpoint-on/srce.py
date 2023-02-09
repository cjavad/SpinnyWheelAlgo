# Construct random 2D n x n matrix
import numpy as np
import matplotlib.pyplot as plt
import timeit

def peakpoint_logn(A):
    n = len(A)
    if n == 1:
        return A[0][0]
    else:
        B = A[:,n//2]
        j = np.argmax(B)
        if A[j][n//2] >= A[j][n//2-1] and A[j][n//2] >= A[j][n//2+1]:
            return A[j][n//2]
        elif A[j][n//2] < A[j][n//2-1]:
            return peakpoint_logn(A[:,0:n//2])
        else:
            return peakpoint_logn(A[:,n//2:n])

def peakpoint_on_4quads(A):
    # Split into 4 quadrants
    n = len(A)
    if n == 1:
        return A[0][0]
    else:
        # Split into 4 quadrants and recursively find peakpoint
        B = A[0:n//2,0:n//2]
        C = A[0:n//2,n//2:n]
        D = A[n//2:n,0:n//2]
        E = A[n//2:n,n//2:n]
        
def random_matrix(n):
    return np.random.randint(0, 100, size=(n, n))

def main():
    n = 1_000
    A = random_matrix(10_000)
    # n iterations
    print(timeit.timeit('peakpoint_logn(A)', number=n, globals={'peakpoint_logn': peakpoint_logn, 'A': A}))
    print(timeit.timeit('peakpoint_on_4quads(A)', number=n, globals={'peakpoint_on_4quads': peakpoint_on_4quads, 'A': A}))

if __name__ == '__main__':
    main()