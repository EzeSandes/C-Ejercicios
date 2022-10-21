int str_ncmp(const char *cad1, const char *cad2, size_t n)
{
    while(*cad1 == *cad2 && *cad1 && n)
    {
        cad1++;
        cad2++;
        n--;
    }

    return *(unsigned char*)cad1 - *(unsigned char*)cad2;
}
