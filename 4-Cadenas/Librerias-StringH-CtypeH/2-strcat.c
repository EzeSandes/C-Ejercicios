char* str_cat(char *donde, const char *que)
{
    char *pInicio = donde;

    while(*donde)
        donde++;

    while(*que)
    {
        *donde = *que;
        donde++;
        que++;
    }

    *donde = '\0';

    return pInicio;
}
