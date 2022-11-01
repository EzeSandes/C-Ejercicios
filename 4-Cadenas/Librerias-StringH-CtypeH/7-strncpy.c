char* str_ncpy(char *donde, const char *que, size_t n)
{
    char *pInicio = donde;

    while(*que && n)
    {
        *donde = *que;
        que++;
        donde++;
        n--;
    }

    if(!n)
        *donde = '\0';

    while(n && *donde)
    {
        *donde = '\0';
        donde++;
        n--;
    }

    return pInicio;
}
