char* str_cpy(char *donde, const char *que)
{
    char *pInicio = donde;
    while(*que)
    {
        *donde = *que;
        que++;
        donde++;
    }

    *donde = '\0';

    return pInicio;
}
