#include<stdio.h>

int main()
{
    //opening files
    FILE * fr = fopen("hss_electives.csv", "r");
    if(fr == NULL)
    printf("ERROR in opening \"hss_electives.csv\"!\n");
    FILE * fw = fopen("task4b.sql", "w");

    //variables to read the information
    int sno, rno;
    char sname[50], cid[10], cname[60];

    while(!feof(fr))
    {
        fscanf(fr, "%d,%d,%49[^,],%9[^,],%59[^\n]\n", &sno, &rno, sname, cid, cname);
        fprintf(fw, "insert into hss_table03 values (%d, %d, '%s', '%s', '%s');\n", sno, rno, sname, cid, cname);
    }

    //close this input file and open the other input file
    fclose(fr);
    fr = fopen("additional_hss_course.csv", "r");
    if(fr == NULL)
    printf("ERROR in opening \"additional_hss_course.csv\"!\n");

    while(!feof(fr))
    {
        fscanf(fr, "%d,%d,%49[^,],%9[^,],%59[^\n]\n", &sno, &rno, sname, cid, cname);
        fprintf(fw, "insert into hss_table03 values (%d, %d, '%s', '%s', '%s');\n", sno, rno, sname, cid, cname);
        // printf("%d\n", sno);
    }

    //closing files
    fclose(fr);
    fclose(fw);

    return(0);
}