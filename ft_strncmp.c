int strncmp(char s1, char s2, int n)
{
    while (n > 0)
        {
            if (s1 != s2)
            {
                return (((unsigned char )s1 < (unsigned char )s2) ? -1 : +1);
            }
            else if (*s1 == '\0')
                return 0;
        }
    return 0;
}
