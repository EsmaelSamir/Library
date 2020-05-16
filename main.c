#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void add_input(int add,char *g );  // to add a book
void del(int re); // to remove the book by id
void search_re (int ser,int itre);  // to search for the book by id
void search_str(char *str);    // to search for the book by name
void print_sorted();  // to print all books in sorted order
void print_arbitrary();   // to print all books in arbitrary order
void sort ();  // to sort the sec[].name

char list[20][50],temp[50];

int index_in_read = 0;
int count_line=4;


struct all
{
    int id;
    char name[100];
    int quantity;
};

struct all sec[10];

int main()
{



    FILE * fptr;  // file pointer
    if((fptr=fopen("pro.txt","r+"))==NULL)
    {
        printf("erorr");
    }
    else
    {


        char g[300];


        fscanf(fptr,"%d",&sec[index_in_read].id);
        fgets(g, sizeof(g), fptr );


        while(!feof(fptr) )
        {

            char *z = strtok(g,",");
            char *c = strtok(NULL,",");

            strcpy(sec[index_in_read].name, z);
            sec[index_in_read].quantity = atoi(c);   // to cast pointer from str to int

            index_in_read+=1;
            fscanf(fptr,"%d",&sec[index_in_read].id);
            fgets(g, sizeof(g), fptr );

        }

        char esmael;
        do
        {
            int o;


            system("cls"); // to clean console

            puts("enter 1 to add a book") ;
            puts("enter 2 to remove a book") ;
            puts("enter 3 to search for the book by id") ;
            puts("enter 4 to search for the book by name") ;
            puts("enter 5 to print books in sorted order") ;
            puts("enter 6 to  print all books") ;



            scanf("%d",&o); // to choose option


            switch(o)
            {
            // start add input
            case 1 :

                printf("enter like this : id name,quantity\n");
                int add = 0;
                scanf("%d",&add);
                fgets(g, sizeof(g), stdin );
                add_input( add, g);
                print_arbitrary();
                break;
// end add input

//start remove the book
            case 2 :
                puts("enter id to remove this book");
                int re;
                scanf("%d",&re);
                del(re);
                print_arbitrary();
                break;
//end remove the book

//start search for the book by id
            case 3 :
                puts("enter id to search for the book");
                int ser,itre=0;
                scanf("%d",&ser);
                search_re(ser,itre);
                break;
//end search for the book by id

//start search for the book by name
            case 4 :
                puts("enter your book name for search like:\" name\" without quotes");
                getchar();
                char str[200];
                gets(str);
                search_str(str);

                break;

//end search for the book by name

//start print all books in sorted order
            case 5 :
                print_sorted();
                break;
//end print all books in sorted order

//start  print all books in arbitrary order
            case 6 :

                print_arbitrary();

//end  print all books in arbitrary order

            }


//fputs("esmael samir",fptr);
            puts("\nenter y|N (continue,exit)");
            scanf(" %c",&esmael);

           if (esmael!= 'y' || esmael!= 'Y' )
           {

                  //   printf("\ncount line = %d",count_line);

                       rewind(fptr);
                     for(int i = 0 ; i<count_line ; i++)
                        {
                            //printf("8888888\n");

                            fprintf(fptr,"%d %d",i,sec[i].id);
                            fprintf(fptr,"%s,",sec[i].name);
                            fprintf(fptr,"%d\n",sec[i].quantity);


//                            printf("\n%d\t",sec[i].id);
//                            printf("%s      ",sec[i].name);
//                            printf("%d",sec[i].quantity);

                        }
                       // fputs("well.....",fptr);







           }

        }
        while( esmael== 'y' || esmael== 'Y');

        fclose(fptr);

    }




    return 0 ;
}

// start to add book
void add_input(int add,char *g )
{

    sec[index_in_read].id = add; // to append id in struct

    char *z = strtok(g,",");     // to split name of the book from  g
    char *c = strtok(NULL,",");  // to split quantity of the book from g

    strcpy(sec[index_in_read].name, z);    // to append name of the book in struct

    sec[index_in_read].quantity = atoi(c);    // to cast  quantity

    index_in_read += 1;
    count_line+=1;

}
//end to add book

//start delete the book with id

void del(int re)
{
    int i;
    for ( i =0 ; i< count_line ; i++)
    {

        if (sec[i].id==re)          // to get index the book will delete
        {
            break;
        }
    }

    for (int j =i+1 ; j< count_line ; j++)
    {
        sec[j-1].id = sec[j].id ;
        sec[j-1].quantity = sec[j].quantity ;     // delete the book
        strcpy(sec[j-1].name,sec[j].name);
    }

    count_line -= 1 ;
}
//end delete the book with id

// start  search for the book by id

void search_re (int ser,int itre)
{
    if(itre>= count_line)
    {
        puts("NOT FOUND");   // base case
        return ;
    }
    if (sec[itre].id==ser)
    {
        printf("\n\nid \t name \t\t quantity \n\n");
        printf("%d\t %s\t %d\n",sec[itre].id,sec[itre].name,sec[itre].quantity);
        return ;
    }
    search_re ( ser, itre+1 )  ;    // call itself again

}
// end  search for the book by id


// start search for the book by name

void search_str(char *str)
{

    sort ();
    int start =0,end=count_line-1,mid;

    while ( end >= start)       // start binary search
    {
        mid = (end+start)/2;
        int ans_compare = strcmp(str, list[mid]);

        if (ans_compare == 0)
        {

            for(int i = 0 ; i< count_line ; i++)
            {
                if ( strcmp( list[mid], sec[i].name )==0 )
                {
                    printf("\nid \t name \t\t quantity");
                    printf("\n\n%d\t",sec[i].id);
                    printf("%s\t",sec[i].name);
                    printf("%d\n",sec[i].quantity);
                    return ;
                }
            }
        }

        else if(ans_compare ==-1 )
        {
            end = mid-1;

        }
        else
            start = mid+1;

    }

    printf("NOT FOUND\n");
    return ;
}

// end search for the book by name

// start print in sorted order
void print_sorted()
{

    sort();   // call function sort

    printf("\nid \t name \t\t quantity\n\n");
    for (int j = 0 ; j < count_line ; j++ )
    {

        for(int i = 0 ; i< count_line ; i++)        // to print all books in sorted order
        {
            if ( strcmp( list[j], sec[i].name )==0 )
            {

                printf("%d\t",sec[i].id);
                printf("%s\t",sec[i].name);
                printf("%d\n",sec[i].quantity);
                break;
            }
        }

    }

}


// end print in sorted order

//start  print all books in arbitrary order

void  print_arbitrary()
{

    printf("\nid \t name \t\t\t quantity\n");

    for(int i = 0 ; i<count_line ; i++)
    {
        printf("\n%d\t",sec[i].id);
        printf("%s      ",sec[i].name);
        printf("%d",sec[i].quantity);

    }
}
//end  print all books in arbitrary order


// start sort the sec[].name
void sort ()
{
    for(int i = 0 ; i < count_line ; i++)
    {
        strcpy(list[i],sec[i].name);      // to assign all names  in array to sort them
    }

    for(int i = 0 ; i < count_line ; i++)
    {
        strcpy( temp, list[i]);
        int show=0 ;
        for(int k = i+1 ; k < count_line ; k++)

        {
            if(strcmp(temp, list[k] ) != -1 )
            {
                strcpy(temp,list[k] );      // to get smallest value in array
                show = k;
            }

        }

        if (show != 0)
        {
            strcpy(temp,list[i] );
            strcpy(list[i],list[show] );        // to append smallest value in array
            strcpy(list[show],temp );
        }
    }

}
// end sort the sec[].name
