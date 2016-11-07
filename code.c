#include<stdio.h>
#include<string.h>
char per[30][5];                	//a 2D array to store permutations
int k=0;                        	//indices for the permutation array
int permute(char[],int,int);    	//permute function
void lexisort();                	//alphabetical order sort function
void swap(char*,char*);         	//swapping function

int main()
{
    FILE *fp;                   	//file pointer for file operations
    char c,str[5],fname[20];    	//fname for file name
    int i=0,len=0;              	//i is index for string str
    printf("Enter filename");   	//entering a file name
    gets(fname);
    fp=fopen(fname,"r");        	//opening file in read mode
    while((c=getc(fp))!='.')    	//read till . is not encountered
    {
        if(c!='\n')             	//till c is not enter
        {
                str[i]=c;       	//put the character in str index
                i++;            		//incrementing indexes
        }
        else                    		//as soon as enter is encountered
        {
	 int f=1;           	//for permutation count
            	str[i]='\0';        	//put null at the index of enter
            	len=strlen(str);   	//find the string length
       	for(i=1;i<=len;i++)      //finding the no of arrangements
        	{
            		f=f*i;
        	}

/*calling permute and passing string,strlen and the total permuations possible */

	printf("\nPermutation for : %s :\n",str);
        	permute(str,len,f);

/* sorting function for sorting elements in alphabetical order*/

	 lexisort();

/* As now the function has sorted the array print output */

        	for(i=0;i<k;i++)
        		printf(",%s",per[i]);
        	printf("\n");
        	k=0;            	//reinitializing per index to zero
        	i=0;            	//reinitializing string index to zero
        	f=1;		//reinitializing f to 1
    }
}
}



void swap(char *p1,char *p2)    //swap function
{   char temp;                  	//a temporary character pointer
    temp = *p1;                 	//swapping the contents passed
    *p1 = *p2;
    *p2 = temp;
}



/* Definition of function permute  */

int permute(char a[],int noofterms,int f)
{
    int x,y;
    int i=0,c=0;
    while(c<f)                      	//continuing till all permutations
    {
        for(y=0;y<noofterms-1;y++)
        {
            swap(&a[y],&a[y+1]);    	//swapping first and last element
            strcpy(per[k],a);      	//putting in perm string
            k++;                    	//increment per index
            c++;                    	//increment count of permutations
        }

        swap(&a[0],&a[1]);         	//now swap first and second element
        strcpy(per[k],a);           	//put in per string
        k++;                        	//increment its index
        c++;                        	//increment count of permutations

        for(y=noofterms-1;y>0;y--)  //now switch loop from behind
        {
            swap(&a[y],&a[y-1]); 	//swap last and first element again
            strcpy(per[k],a);    	//put in per string
            k++;                 	//increment index
            c++;                 	//increment count of permutations
        }
                                    	//swap last and second last element
        swap(&a[noofterms-1],&a[noofterms-2]);

        strcpy(per[k],a);           	//put in per folder
        k++;                        	//increment index
        c++;                       	//increment count of permutations
    }
}

/* Lexical sort function that uses bubble sort to sort different strings as per alphabetical order */

void lexisort()
{
    int i=0,j=0;                	//variables for loops
    char t[8];                  	//a temporary string
    for(i=1;i<k;i++)            	//starting loop for total passes
        for(j=1;j<k;j++)        	//loop for comparing
        {

/*
Here we are comparing value at index j-1 with value at j
comparing the previous string with the next one if the next string is smaller then swap i.e if { bca,abc then swap them as abc,bca}
*/
            if(strcmp(per[j-1],per[j])>0)
            {
                strcpy(t,per[j-1]);
                strcpy(per[j-1],per[j]);
                strcpy(per[j],t);
            }

        }
}

