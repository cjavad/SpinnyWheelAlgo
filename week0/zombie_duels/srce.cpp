#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void o_3n_2(int zombies[], int n)
{
    int loopCount = 0;
    int strongest = zombies[0];
    int weakest = zombies[0];

    for (int i = 1; i < n; i += 2)
    {
        if (zombies[i] > zombies[i + 1])
        {
            if (zombies[i] > strongest)
            {
                strongest = zombies[i];
            }
            if (i + 1 < n && zombies[i + 1] < weakest)
            {
                weakest = zombies[i + 1];
            }
        }
        else
        {
            if (i + 1 < n && zombies[i + 1] > strongest)
            {
                strongest = zombies[i + 1];
            }
            if (zombies[i] < weakest)
            {
                weakest = zombies[i];
            }
        }
    }

    cout << endl;
    cout << strongest << " " << weakest << endl;
    cout << loopCount << endl;
}

void n_funny(int zombies[], int n) {
    int strongest = max(zombies[0], zombies[1]);
    int nextStrongest = min(zombies[0], zombies[1]);

    for (int i = 2; i < n; i++)
    {
        if (zombies[i] > strongest)
        {
            nextStrongest = strongest;
            strongest = zombies[i];
        }
        else if (zombies[i] > nextStrongest)
        {
            nextStrongest = zombies[i];
        }
    }

    cout << endl;
    cout << strongest << " " << nextStrongest << endl;
}

void nlogn(int zombies[], int n) {
    qsort(zombies, n, sizeof(int), compare);
    cout << zombies[0] << " " << zombies[1] << endl;
}

int main()
{
    int n;
    cin >> n;

    int zombies[n];

    for (int i = 0; i < n; i++)
    {
        cin >> zombies[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << zombies[i] << " ";
    }

    n_funny(zombies, n);
    return 0;
}