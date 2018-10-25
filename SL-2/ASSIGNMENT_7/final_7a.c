#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main()
{
     char filename[20]="data";
     int file_pipe1[2],file_pipe2[2],count=0;
     char parent_read_buffer[1024],child_read_buffer[1024],child_write_buffer[1024];
     FILE *fp;

     pipe(file_pipe1);
     pipe(file_pipe2);

     pid_t pid=fork();

     if(pid > 0)
     {
        write(file_pipe1[1],filename,strlen(filename));

        int bytes = read(file_pipe2[0],parent_read_buffer,1024);
        parent_read_buffer[bytes]='\0';

        printf("File contents : \n");
        printf("%s\n",parent_read_buffer );
     }

     if(pid == 0)
     {
        int bytes = read(file_pipe1[0],child_read_buffer,1024);
        child_read_buffer[bytes]='\0';

        fp = fopen(child_read_buffer,"r");

        while(!feof(fp))
        {
            child_write_buffer[count++] = fgetc(fp);
        }
        fclose(fp);

        write(file_pipe2[1],child_write_buffer,count);
     }

     return 0;
 }

