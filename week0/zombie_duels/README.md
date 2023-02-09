# 6. Zombie Duels

You have an army of n brainless zombies. You want to find the strongest and the weakest zombie
in the army. By pairing up two zombies in a cage with a big chunk of brain matter you can quickly determine which of
the two are the strongest. Unfortunately, zombies wear out in this process, so you want to minimize the number of duels
needed. Solve the following exercises.

## Solution 1 O(n - 1)

Maximize strongest by comparing the strongest of the two pairs. Loop over n + 1 (By skipping the first element) to find the strongest zombie.

```c++
int strongest = 0;
for (int i = 1; i < n; i += 2)
{
    if (zombies[i] > zombies[i + 1])
    {
        if (zombies[i] > strongest)
        {
            strongest = zombies[i];
        }
    }
    else
    {
        if (zombies[i + 1] > strongest)
        {
            strongest = zombies[i + 1];
        }
    }
}
```

## Solution 2 O(3n/2)

We can find both the strongest and the weakest zombie in one loop. We can do this by comparing the strongest and weakest of the two pairs. We can also compare the strongest and weakest of the whole army.
