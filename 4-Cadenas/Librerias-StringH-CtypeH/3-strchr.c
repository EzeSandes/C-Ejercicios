char* str_chr(const char *cad, int c)
{
    while(*cad != c && *cad)
        cad++;

    return *cad == c ?  (char*)cad : NULL;
}
