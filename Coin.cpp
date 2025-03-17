#include <stdio.h>
#include <stdlib.h>

struct Coin
{
    int value;
    int index;
};

int compare(const void *a, const void *b)
{
    struct Coin *c1 = (struct Coin *)a;
    struct Coin *c2 = (struct Coin *)b;
    return c2->value - c1->value; // For descending order
}

int main()
{
    int w, n, i;
    printf("Enter no of coin: ");
    scanf("%d", &n);

    int coin[n];
    printf("\nEnter coin value: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &coin[i]);
    }

    printf("\nEnter Amount: ");
    scanf("%d", &w);

    int ans = 0;
    struct Coin c[n];
    for (i = 0; i < n; i++)
    {
        c[i].value = coin[i];
        c[i].index = i;
    }

    // Sort the coins array in descending order by value
    qsort(c, n, sizeof(struct Coin), compare);

    int arr[n];
    for (i = 0; i < n; i++)
        arr[i] = 0;

    int j = 0;
    while (w != 0 && j < n)
    {
        if (w < c[j].value)
        {
            j++;
        }
        else
        {
            w -= c[j].value;
            ans++;
            arr[c[j].index]++;
        }
    }

    printf("%d\n", ans);
    for (i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
