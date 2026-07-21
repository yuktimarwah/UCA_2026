#include <stdio.h>

int find_substring(const char *haystack, const char *needle)
{
    int i, j;

    // If needle is empty, return 0
    if (needle[0] == '\0')
        return 0;

    for (i = 0; haystack[i] != '\0'; i++)
    {
        j = 0;

        while (needle[j] != '\0' && haystack[i + j] == needle[j])
        {
            j++;
        }

        // If end of needle is reached, match found
        if (needle[j] == '\0')
            return i;
    }

    return -1; // Not found
}

int main()
{
    char haystack[] = "Embedded Systems";
    char needle[] = "bed";

    int index = find_substring(haystack, needle);

    if (index != -1)
        printf("Substring found at index %d\n", index);
    else
        printf("Substring not found\n");

    return 0;
}
