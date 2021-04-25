#include<stdio.h>
#include<errno.h>
long count_characters(FILE *);

void main()
{
    int i;
    long cnt;
    char ch, ch1;
    FILE *fp1, *fp2;

    if (fp1 = fopen("File_1.txt", "r"))
    {
        fp2 = fopen("File_2.txt", "w");
        cnt = count_characters(fp1);
        fseek(fp1, -1L, 2);
       
        while (cnt)
        {
            ch = fgetc(fp1);
            fputc(ch, fp2);
            fseek(fp1, -2L, 1);
            cnt--;
        }
    }
    else
    {
        perror("Error occured\n");
    }
    fclose(fp1);
    fclose(fp2);
}
long count_characters(FILE *f)
{
    fseek(f, -1L, 2);
    long last_pos = ftell(f);
    last_pos++;
    return last_pos;
}
