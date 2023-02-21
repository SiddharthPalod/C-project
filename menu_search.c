//Aaditya Gole IMT2022087
//Used- pointers,file pointers,File I/O, dynamic memory allocation,array, string functions, array operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main() 
{

	char wrd[256], buffer[256], buffer2[256], temp[256],rev[256],rev2[256];
	int bufflen, len, i, j, l,p,q, k, line,check;
	
	FILE* fp;
	fp = fopen("restros.txt", "r");	// open file

	printf("Enter What do you want to eat : ");
	gets(wrd);

	len = strlen(wrd); // length of input word
	printf("Restros you might be interested in:\n");


	line = 0;
	// the following loop the file fp line by line
	// each line is stored in buffer
	while (fgets(buffer, 256, fp) != NULL) 
    {

		i = 0;
		bufflen = strlen(buffer);
		// the followinf loop find position of the input word in the current line and
		// print the position of the word on the screen
		// the loop basically reads each word of the file and compare it with the input word
		while (i < bufflen) 
        {

			// comparing current word with input word
			j = 0;
            
			while (i < bufflen && j < len && buffer[i] == wrd[j]) 
            {
                
				++i, ++j;
            

			}

			// the following condition implies that the current word of buffer
			// is equal to input word
			if ((i == bufflen || buffer[i] == ' ' || buffer[i] == '\n') && j == len) 
            {
				//printf("Line: %d ", line);
				for(int c= 0; c<strlen(buffer);c++)
                {
                    buffer2[c]=buffer[c];
					//printf("yo \n%c", buffer[c]);
                }


                l=i;
                k=0;
                q=0;
                p=i;
                while (buffer2[l] != '\n')
                {
                // going back and storing the line until we encounter a new line
                rev[k]=buffer2[l];
				//printf("yo \n%c", rev[k]);
                k++;
                l--;
                }

                while (buffer[p] != '\n')
                {
                    //going forward until we encounter a new line
                
                    temp[q]=buffer[p];
                    q++;
                    p++;
                //printf("hi %c\n", temp[q]);
                } 
                printf("%s", strrev(rev));
                printf("%s\n", temp); 
                //printing the combined line
                
			}

			// moving to next word
			while (i < bufflen && buffer[i] != ' ')
            {
				++i;
			}
			++i;
            //free(temp);
            //free(rev);
            
		}

		++line;
        check=0;

	}
    	


	fclose(fp);


	free(temp);
	free(rev);
	free(wrd);
	free(buffer);
	free(buffer2);
	//freeing up the memory

	



	fp = fopen("menuitems.txt", "r");	// open file

	// printf("Enter What do you want to eat : ");
	// gets(wrd);

	len = strlen(wrd); // length of input word
	printf("Dishes you might be interested in:\n");


	line = 0;
	// the following loop the file fp line by line
	// each line is stored in buffer
	while (fgets(buffer, 256, fp) != NULL) 
    {

		i = 0;
		bufflen = strlen(buffer);
		// the followinf loop find position of the input word in the current line and
		// print the position of the word on the screen
		// the loop basically reads each word of the file and compare it with the input word
		while (i < bufflen) 
        {

			// comparing current word with input word
			j = 0;
            
			while (i < bufflen && j < len && buffer[i] == wrd[j]) 
            {
                
				++i, ++j;
            

			}

			// the following condition implies that the current word of buffer
			// is equal to input word
			if ((i == bufflen || buffer[i] == ' ' || buffer[i] == '\n') && j == len) 
            {
				//printf("Line: %d ", line);
				for(int c= 0; c<strlen(buffer);c++)
                {
                    buffer2[c]=buffer[c];
					//printf("yo \n%c", buffer[c]);
                }

				check=1;
                l=i;
                k=0;
                q=0;
                p=i;
                while (buffer2[l] != '\n')
                {
                // going back and storing the line until we encounter a new line
                rev[k]=buffer2[l];
				//printf("yo \n%c", rev[k]);
                k++;
                l--;
                }

                while (buffer[p] != '\n')
                {
                    //going forward until we encounter a new line
                
                    temp[q]=buffer[p];
                    q++;
                    p++;
                //printf("hi %c\n", temp[q]);
                }
				if (check ==1)
				{
					
					printf("%s", strrev(rev));
					printf("%s\n", temp); 
					//printing the combined line
					check=0;
					
				}
				check=0;
                
			}
			check=0;

			// moving to next word
			while (i < bufflen && buffer[i] != ' ')
            {
				++i;
			}
			++i;
            //free(temp);
            //free(rev);
            //freeing up the memory

		}

		++line;
        check=0;

	}

	fclose(fp);









}