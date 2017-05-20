#include <stdio.h>
long length, size=0;
void filelensize(FILE *fp)
{
    if (NULL==fp)
        perror("Error opening file");
    else
    {
        fseek(fp, 0, SEEK_END);
        length=ftell(fp);
        fseek(fp, 0, SEEK_SET);
        unsigned char c;
        while (1)
        {
            c = fgetc(fp);
            if (feof(fp)) break;
            if (c>127) c = fgetc(fp);
            size++;
        }
    }
    return;
}
void fpshift(FILE *fp, int size)
{
    if (NULL!=fp)
    {
        unsigned char c;
        long t=0;
        int i;
        for (i = 0; i < size; i++)
        {
            c = fgetc(fp);
            if (c>127) c = fgetc(fp);
        }
    }
    return;
}
void outone(FILE *fp)
{
    unsigned char c;
    c = fgetc(fp);
    if (c == '=') return;
    putchar(c);
    if (c>127)
    {
        c = fgetc(fp);
        putchar(c);
    }
    return;
}
int main( int argc, char *argv[] )
{
    FILE *f1, *f2, *f3, *f4;
    f1 = fopen( argv[1], "r");
    f2 = fopen( argv[1], "r");
    f3 = fopen( argv[1], "r");
    f4 = fopen( argv[1], "r");
    if (NULL==f1||NULL==f2||NULL==f3||NULL==f4)
        perror("Error opening file");
    else
    {
        filelensize(f1);
        long g1, g2, g3, tmp=0;
        g2 = size/2;
        g1 = (g2+2)/2;
        g3 = (size-1+g2)/2;
        fseek(f1, 1, SEEK_SET);
        fpshift(f2, g1);
        fpshift(f3, g2);
        fpshift(f4, g3);
        if (size % 4 == 2)
        {
            while (tmp<(size-2)/4)
            {
                outone(f2);
                outone(f1);
                outone(f4);
                outone(f3);
                tmp++;
            }
        }
        else
        {
            while (tmp<(size-2)/4)
            {
                outone(f4);
                outone(f1);
                outone(f2);
                outone(f3);
                tmp++;
            }
            outone(f4);
            outone(f1);
        }
        fclose(f1);
        fclose(f2);
        fclose(f3);
        fclose(f4);
        //printf("%ld %ld %ld %ld", size, g1, g2, g3);
    }
	return 0;
}
