unsigned str_len(const char *cad)
{
    unsigned cantChars = 0;

    while(*cad)
    {
        cantChars++;
        cad++;
    }

    return cantChars;
}
