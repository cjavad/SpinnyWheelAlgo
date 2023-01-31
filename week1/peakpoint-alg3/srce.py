import math

def peak3(A,i,j):
    m = math.floor((i+j)//2)
    if (m-1 < 0 or A[m] >= A[m-1]) and (m+1 >= len(A) or A[m] >= A[m+1]):
        return m

    elif A[m-1] > A[m]:
        return peak3(A,i,m-1)
    elif A[m] < A[m+1]:
        return peak3(A,m+1,j)
    else:
        return -1

if __name__ == '__main__':
    n = int(input())
    A = [int(x) for x in input().split()]

    print(peak3(A,0,n))