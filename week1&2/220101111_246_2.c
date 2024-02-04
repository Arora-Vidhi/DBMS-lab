#include<stdio.h>
#include<stdlib.h>
 
typedef struct date{
    int d, m, y;
}date;
 
typedef struct pdetails{
    char pname[7];
    date steps[10], copy[10];
    char reg;
    struct pdetails * next;
}pdetails;
 
int getdigit(char c)
{
    switch(c)
    {
        case '0' : return(0);
        case '1' : return(1);
        case '2' : return(2);
        case '3' : return(3);
        case '4' : return(4);
        case '5' : return(5);
        case '6' : return(6);
        case '7' : return(7);
        case '8' : return(8);
        case '9' : return(9);
    }
}
 
void sorta(date node[], int start, int num)
{
    int i, j;
    date * key = (date *)malloc(sizeof(date));
	for (i = start + 1; i < num + start; i++)
    {
        key->d = node[i].d;
        key->m = node[i].m;
        key->y = node[i].y;
		j = i - 1;
 
		while (j >= start && node[j].d > key->d)
        {
			node[j + 1].d = node[j].d;
            node[j + 1].m = node[j].m;
            node[j + 1].y = node[j].y;
			j--;
		}
        j++;
        node[j].d = key->d;
        node[j].m = key->m;
        node[j].y = key->y;
	}
    for (i = start + 1; i < num + start; i++)
    {
		key->d = node[i].d;
        key->m = node[i].m;
        key->y = node[i].y;
		j = i - 1;
 
		while (j >= start && node[j].m > key->m)
        {
			node[j + 1].d = node[j].d;
            node[j + 1].m = node[j].m;
            node[j + 1].y = node[j].y;
			j--;
		}
        j++;
		node[j].d = key->d;
        node[j].m = key->m;
        node[j].y = key->y;
	}
    for (i = start + 1; i < num + start; i++)
    {
		key->d = node[i].d;
        key->m = node[i].m;
        key->y = node[i].y;
		j = i - 1;
 
		while (j >= start && node[j].y > key->y)
        {
			node[j + 1].d = node[j].d;
            node[j + 1].m = node[j].m;
            node[j + 1].y = node[j].y;
			j--;
		}
        j++;
		node[j].d = key->d;
        node[j].m = key->m;
        node[j].y = key->y;
	}
 
    return;
}
 
void sortd(date node[], int start, int num)
{
    int i, j;
    date * key = (date *)malloc(sizeof(date));
	for (i = start + 1; i < num + start; i++)
    {
        key->d = node[i].d;
        key->m = node[i].m;
        key->y = node[i].y;
		j = i - 1;
 
		while (j >= start && node[j].d < key->d)
        {
			node[j + 1].d = node[j].d;
            node[j + 1].m = node[j].m;
            node[j + 1].y = node[j].y;
			j--;
		}
        j++;
        node[j].d = key->d;
        node[j].m = key->m;
        node[j].y = key->y;
	}
    for (i = start + 1; i < num + start; i++)
    {
		key->d = node[i].d;
        key->m = node[i].m;
        key->y = node[i].y;
		j = i - 1;
 
		while (j >= start && node[j].m < key->m)
        {
			node[j + 1].d = node[j].d;
            node[j + 1].m = node[j].m;
            node[j + 1].y = node[j].y;
			j--;
		}
        j++;
		node[j].d = key->d;
        node[j].m = key->m;
        node[j].y = key->y;
	}
    for (i = start + 1; i < num + start; i++)
    {
		key->d = node[i].d;
        key->m = node[i].m;
        key->y = node[i].y;
		j = i - 1;
 
		while (j >= start && node[j].y < key->y)
        {
			node[j + 1].d = node[j].d;
            node[j + 1].m = node[j].m;
            node[j + 1].y = node[j].y;
			j--;
		}
        j++;
		node[j].d = key->d;
        node[j].m = key->m;
        node[j].y = key->y;
	}
 
    return;
}
 
int eq(date date1, date date2)
{
    return(date1.d == date2.d && date1.m == date2.m && date1.y == date2.y);
}
 
void printmonth(int a, FILE * fp)
{
    switch(a)
    {
        case 1 : fprintf(fp, "Jan"); break;
        case 2 : fprintf(fp, "Feb"); break;
        case 3 : fprintf(fp, "Mar"); break;
        case 4 : fprintf(fp, "Apr"); break;
        case 5 : fprintf(fp, "May"); break;
        case 6 : fprintf(fp, "Jun"); break;
        case 7 : fprintf(fp, "Jul"); break;
        case 8 : fprintf(fp, "Aug"); break;
        case 9 : fprintf(fp, "Sep"); break;
        case 10 : fprintf(fp, "Oct"); break;
        case 11 : fprintf(fp, "Nov"); break;
        case 12 : fprintf(fp, "Dec"); break;
    }
    return;
}
 
void printmonth2(int a)
{
    switch(a)
    {
        case 1 : printf("Jan"); break;
        case 2 : printf("Feb"); break;
        case 3 : printf("Mar"); break;
        case 4 : printf("Apr"); break;
        case 5 : printf("May"); break;
        case 6 : printf("Jun"); break;
        case 7 : printf("Jul"); break;
        case 8 : printf("Aug"); break;
        case 9 : printf("Sep"); break;
        case 10 : printf("Oct"); break;
        case 11 : printf("Nov"); break;
        case 12 : printf("Dec"); break;
    }
    return;
}
 
void search(char input[], pdetails * head)
{
    //base case
    if(head == NULL)
    {
        printf("Invalid product number\n");
        return;
    }
    
    int i = 0;
    do
    {
        //not matching --> go to next node
        if(input[i] != head->pname[i])
        {
            search(input, head->next);
            return;
        }
        else
        i++;
    }while (input[i] != '\0');
    
    if(head->pname[i] != '\0')
    {
    	printf("Invalid product number\n");
        return;
    }
 
    //current node is the required node
    printf("PRODUCT NUMBER:	%s\nREGION:	", input);
    //region
    switch(head->reg)
    {
        case 'N' : printf("North\n"); break;
        case 'S' : printf("South\n"); break;
        case 'E' : printf("East\n"); break;
        case 'W' : printf("West\n"); break;
    }    
    
    printf("Before Task 02\n");
    for(i = 0; i < 10; i++)
    {
    	//step number
    	printf("Step %d: ", (i + 1));
        //date
        printf("%d-", head->copy[i].d);
        //month
        printmonth2(head->copy[i].m);
        //year
        printf("-%d\n", head->copy[i].y);
    }
    
    printf("After Task 02\n");
    for(i = 0; i < 10; i++)
    {
    	//step number
    	printf("Step %d: ", (i + 1));
        //date
        printf("%d-", head->steps[i].d);
        //month
        printmonth2(head->steps[i].m);
        //year
        printf("-%d\n", head->steps[i].y);
    }
    return;
}
 
int main()
{
    //TASK 01
    //storing file name
    char * filename = "week02.csv";
 
    //open input file
    FILE * fp = fopen(filename, "r");
 
    //reading and storing the first line
    char heading[150];
    fscanf(fp, "%s\n", heading);
 
    //looping variable
    int i;
 
    //declaring head and current pointers
    pdetails * head = NULL;
    pdetails * curr = NULL;
    pdetails * node;
 
    //loop to read whole file line by line
    char a[150];
    while(fscanf(fp, "%s\n", a) == 1)
    {
        //declaring a new node
        node = (pdetails *)malloc(sizeof(pdetails));
        node->next = NULL;
 
        //storing the read data into this node
        //product id
        i = 0;
        while(a[i] != ',')
        {
            node->pname[i] = a[i];
            i++;
        }
        node->pname[i] = '\0';
        i++;
        //dates
        for(int j = 0; j < 10; j++)
        {
            //date
            node->steps[j].d = 0;
            while(a[i] != '-')
            {
                node->steps[j].d = node->steps[j].d * 10 + getdigit(a[i]);
                i++;
            }
            i++;
            //month
            if(a[i] == 'D')
            node->steps[j].m = 12;
            else if(a[i] == 'N')
            node->steps[j].m = 11;
            else if(a[i] == 'O')
            node->steps[j].m = 10;
            else if(a[i] == 'S')
            node->steps[j].m = 9;
            else if(a[i] == 'F')
            node->steps[j].m = 2;
            else if(a[i + 1] == 'p')
            node->steps[j].m = 4;
            else if(a[i + 2] == 'g')
            node->steps[j].m = 8;
            else if(a[i + 2] == 'y')
            node->steps[j].m = 5;
            else if(a[i + 2] == 'r')
            node->steps[j].m = 3;
            else if(a[i + 2] == 'l')
            node->steps[j].m = 7;
            else if(a[i + 1] == 'a')
            node->steps[j].m = 1;
            else if(a[i + 1] == 'u')
            node->steps[j].m = 6;
            else
            {
                printf("Error...\n");
                return(-1);
            }
            i += 4;
            //year
            node->steps[j].y = 0;
            int temp = 1000;
            while(temp > 0)
            {
                node->steps[j].y += temp * getdigit(a[i]);
                temp /= 10;
                i++;
            }
            i++;
 
            //making a copy of the dates so as to store both sorted and given steps
            node->copy[j].d = node->steps[j].d;
            node->copy[j].m = node->steps[j].m;
            node->copy[j].y = node->steps[j].y;
        }
 
        //region
        node->reg = a[i];
 
 
        //adding this node to the end
        if(head == NULL)
        head = node;
        else
        curr->next = node;
        curr = node;
    }
    curr->next = NULL;
 
    //close input file
    fclose(fp);
 
 
    //TASK 02
    //North - ascending --- South - descending --- East - ascending descending --- West - descending ascending
    curr = head;
    while(curr != NULL)
    {
        switch(curr->reg)
        {
            case 'N' : sorta(curr->steps, 0, 10); break;
            case 'S' : sortd(curr->steps, 0, 10); break;
            case 'E' : 
                sorta(curr->steps, 0, 10);
                i = 5;
                while(eq(curr->steps[i - 1], curr->steps[i]) == 1)
                i++;
                if(i < 9)
                sortd(curr->steps, i, 10 - i);
                break;
            case 'W' :
                sortd(curr->steps, 0, 10);
                i = 5;
                while(eq(curr->steps[i - 1], curr->steps[i]) == 1)
                i++;
                if(i < 9)
                sorta(curr->steps, i, 10 - i);
                break;
            default : printf("Error...\n"); return(-1);
        }
        curr = curr->next;
    }
 
    //TASK 03
    //creating new file
    filename = "CorrectedDates.csv";
 
    //opening the new file
    fp = fopen(filename, "w");
 
    //printing the heading in new file
    fprintf(fp, "%s\n", heading);
 
    //printing the corrected data
    curr = head;
    while(curr != NULL)
    {
        //product name
        fprintf(fp, "%s,", curr->pname);
        //dates
        for(i = 0; i < 10; i++)
        {
            fprintf(fp, "%d-", curr->steps[i].d);
            printmonth(curr->steps[i].m, fp);
            fprintf(fp, "-%d,", curr->steps[i].y);
        }
        //region
        switch(curr->reg)
        {
            case 'N' : fprintf(fp, "North\n"); break;
            case 'S' : fprintf(fp, "South\n"); break;
            case 'E' : fprintf(fp, "East\n"); break;
            case 'W' : fprintf(fp, "West\n"); break;
        }
        curr = curr->next;
    }
 
    //closing file
    fclose(fp);
 
    //TASK 04
    // ****** USING quit TO END TAKING INPUTS (CASE-SENSITIVE) *****
    char input[7];
    while(1)
    {
        scanf("%s", input);
        if(input[0] == 'q' && input[1] == 'u' && input[2] == 'i' && input[3] == 't' && input[4] == '\0')
        return(0);
        search(input, head);
    }
 
    return(0);
}
