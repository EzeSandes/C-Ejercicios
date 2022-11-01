char* str_ncat(char *donde, const char *que, size_t n)
{
    char *pInicio = donde;

    while(*donde)
        donde++;

    while(*que && n)
    {
        *donde = *que;
        donde++;
        que++;
        n--;
    }

    *donde = '\0';

    return pInicio;
}
