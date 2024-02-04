#include<stdio.h>

int main()
{
    //opening files
    FILE * fr = fopen("hss_electives.csv", "r");
    if(fr == NULL)
    printf("ERROR in opening \"hss_electives.csv\"!\n");
    FILE * fw = fopen("task3b.sql", "w");

    //variables to read the information
    int sno, rno;
    char sname[50], cid[10], cname[60];

    while(!feof(fr))
    {
        fscanf(fr, "%d,%d,%49[^,],%9[^,],%59[^\n]\n", &sno, &rno, sname, cid, cname);
        fprintf(fw, "insert into hss_table02 values (%d, %d, '%s', '%s', '%s');\n", sno, rno, sname, cid, cname);
    }

    //closing files
    fclose(fr);
    fclose(fw);

    return(0);
}