char* str_str(const char *donde, const char *que)
{
    char    *pDonde,
            *pQue;

    while(*donde)
    {
        pDonde = (char *)donde;
        pQue = (char *)que;

        while(*pDonde == *pQue && *pQue && *pDonde)
        {
            pDonde++;
            pQue++;
        }

        if(!*pQue)
            return (char *)donde;

        donde++;
    }

    return NULL;
}
