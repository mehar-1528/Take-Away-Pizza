/* Name of the project: Takeaway Pizza!!
   Authors: Mukti Bhansali  (01fe19bcs203)
            Manisha Belagal (01fe19bcs207)
            Mehar Anjum     (01fe19bcs208)
            Akashini Koppad (01fe19bcs210)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int match(char name[],FILE *fp);
void construct_lps(char pat[],int lps[],int m);

struct Takeorder
{
    char userid[30];
    char order[10];
};
int main()
{
    int e, i, r, f,flag=0;
    char name[100],line[100],userid[100], number;
    FILE *fp, *fp1;
    struct Takeorder *take=(struct Takeorder*)malloc(sizeof(struct Takeorder));
    printf("WELCOME TO PIZZA STORE!!\n");
    printf("Are you new to our store?\nPress 1 for 'yes' and 0 for 'no':\n");
    scanf("%d",&e);
    char filename[30];
    if(e==1)                                                                            //First time user
    {
        printf("Please enter your first name:\n");
        scanf("%s",name);
        fp=fopen("pizza.txt","r");
        int m=match(name,fp);
        sprintf(userid,"%d",m+1);
        strcat(name,userid);
        fclose(fp);
        fp = fopen("pizza.txt","a");
        int i = 0;
        for(i = 0; name[i] != '\0'; i++){
            filename[i] = name[i];
        }
        strcat(userid, filename);
        filename[i++] = '.'; filename[i++] = 't';
        filename[i++] = 'x'; filename[i++] = 't'; filename[i] = '\0';
        for(i=0; i<strlen(name); i++)
        {
            take->userid[i]=name[i];
        }
        take->userid[i] = '\0';
        fprintf(fp,"\n%s",take->userid);
        printf("Your new userid is %s\n",name);
        fclose(fp);
    }
    else                                                                                 //Existing User
    {   int f;
        char name1[100];
        char name2[100];
        char line[100];
        printf("Please enter your userid:\n");
        scanf("%s",name1);
        fp=fopen("pizza.txt","r");
        while(fgets(line,sizeof(line),fp))
        {
            fscanf(fp,"%s",name2);
            f=strcmp(name2,name1);
            if(f==0)
                break;
        }

        fclose(fp);
        if(f!=0)                                                                      // Invalid UserId
        {
            printf("Userid not found, please enter a valid userid\n");
            return 0;

        }
        else
        {
            int n = strlen(name1);
        name1[n++] = '.'; name1[n++] = 't';
        name1[n++] = 'x'; name1[n++] = 't'; name1[n++] = '\0';
        for(i = 0; name1[i] != '\0'; i++)
        {
            filename[i] = name1[i];
        }
        filename[i] = '\0';

        }
    }
    printf("\nMenu\n");
    printf("1.Double Cheese Margherita Pizza\n");
    printf("2.Peppy Paneer Pizza\n");
    printf("3.Barbecue Chicken Pizza\n");
    printf("4.Chicken Fiesta\n");
    printf("5.Veg Extravaganza\n");
    printf("6.French Fries\n");
    printf("7.Coca Cola\n");
    printf("8.Sprite\n");
    if(e != 1)
    {
        int count[9];
        for(i = 0; i < 9; i++) count[i] = 0;
        fp1 = fopen(filename, "r");
        char c; int z;
        while (1)
        {
         c = fgetc (fp1) ;
         if ( c == EOF )
         break ;
         if(c != ' ')
         {
            z = c - '0';
            count[z] = count[z] + 1;
         }
        }
   printf("\nOur Recommendation\n");
   int j;
   for(i=1;i<=3;i++)
    {
        int max = i;
        for(j=i+1;j<9;j++)
        {
            if(count[j]>count[max])
                max = j;
        }
        switch(max)
        {
            case 1: printf("Double Cheese Margherita Pizza\n"); break;
            case 2: printf("Peppy Paneer Pizza\n"); break;
            case 3: printf("Barbecue Chicken Pizza\n"); break;
            case 4: printf("Chicken Fiesta\n"); break;
            case 5: printf("Veg Extravaganza\n"); break;
            case 6: printf("French Fries\n"); break;
            case 7: printf("Coca Cola\n"); break;
            case 8: printf("Sprite\n"); break;
        }
        count[max] = -1;
    }
    fclose(fp1);
    }
   else
    {
       printf("\nPIZZA STORE SPECIAL\n");
       printf("Peppy Paneer Pizza\n");
       printf("French Fries\n");
       printf("Coca Cola\n");
    }
    fp1=fopen(filename,"a");
    int choice = 1;
    i = 0;
    char item;
    while(choice!=2)
    {
        printf("Enter 1 to place order and 2 to exit:");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:printf("Enter item number from menu: ");
               scanf("%s", &take->order[i]);
               i++;
               break;
        case 2:break;
        default:break;
        }
    }
    take->order[i] = '\0';
    fprintf(fp1, take->order);
    fclose(fp1);
    fp1=fopen(filename,"r");
    printf("Successful\nYour order summary is:\n");
    while(r=fgetc(fp1)!=EOF)
    {
        fscanf(fp1, "%c", &number);
        switch(number)
        {
            case '1': printf("Double Cheese Margherita Pizza\n");
                    break;
            case '2':printf("Peppy Paneer Pizza\n");
                    break;
            case '3': printf("Barbecue Chicken Pizza\n");
                    break;
            case '4': printf("Chicken Fiesta\n");
                     break;
            case '5':printf("Veg Extravaganza\n");
                   break;
            case '6': printf("French Fries\n");
                    break;
            case '7': printf("Coca Cola\n");
                    break;
            case '8': printf("Sprite\n");
                    break;
            default:break;
        }
    }
    printf("\n----------THANK YOU FOR ORDERING-----------\n");
    printf("\n\tDo Visit Again! :)\n");
    fclose(fp1);
}

int match(char name[],FILE *fp)                                         //String Matching
{
    char line[100];
    int count=0;
    while(fgets(line,sizeof(line),fp))
    {
        int m=strlen(name);
        int n=strlen(line);
        int lps[m];
        construct_lps(name,lps,m);
        int i=0;
        int j=0;
        while(i<n)
        {
            if(line[i]==name[j])
            {
                i++;
                j++;
            }
            if(j==m)
            {
                count++;
                j=lps[j-1];
            }
            else if(line[i]!=name[j])
            {
                if(j!=0)
                    j=lps[j-1];

                else
                    i++;
            }
        }
    }
    return count;
}
void construct_lps(char pat[],int lps[],int m)
{
    lps[0]=0;
    int i=1;
    int len=0;

    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                len=lps[len-1];
            }
        }
    }
}
