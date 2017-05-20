#include <stdio.h>
#include <string.h>
int main( int argc, char *argv[] )
{
	FILE *f1, *f2;
	f1 = fopen( argv[1], "r");
	char cc[20];
	strcpy(cc, argv[1]);
	strcat(cc, "_s");
	f2 = fopen( cc, "w");
	if (f1 == NULL || f2 == NULL) {
		perror("打开文件时发生错误");
		return(-1);
	}
	char str[2][251];
	int i;
	while (fgets(str[0], 250, f1)!=NULL)
	{
		if (str[0][0]=='[' && str[0][3]==':' && str[0][9]==']')
		{
			for (i = 0; i < 10; i++)
				fputc(str[0][i], f2);
			fgets(str[1], 200, f1);
			if (str[1][0] == '\n') fgets(str[1], 200, f1);
			fputs(str[1], f2);
		}
		fputs(str[0], f2);
	}
	fclose(f1);
	fclose(f2);
	return 0;
}
