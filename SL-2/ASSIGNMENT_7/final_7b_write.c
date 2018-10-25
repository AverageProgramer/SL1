#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

int main()
{
    int fd,bytes;
    char unreadable_file[300]="fifo_file";
    char readbale_file[300] = "out_file";
    char read_buffer[300],write_buffer[300];

    mkfifo(unreadable_file,0666);

    fd = open(unreadable_file,O_RDONLY);
    bytes = read(fd,read_buffer,300);
    read_buffer[bytes]='\0';

    printf("%s\n",read_buffer );

    close(fd);

    int words=1,lines=1;

    for(int i=0;i<bytes;i++)
    {
        if(read_buffer[i]==' ')
            words++;

        else if(read_buffer[i]=='$')
            lines++;
    }

    printf("No of words : %d\n",words);
    printf("No of lines : %d\n",lines);
    printf("No of characters : %d\n",bytes-1);

    FILE * fp;

    fp = fopen(readbale_file,"w+");

    fprintf(fp,"No of words : %d\n",words);
    fprintf(fp,"No of lines : %d\n",lines);
    fprintf(fp,"No of characters : %d\n",bytes-1);

    fclose(fp);

    fp = fopen(readbale_file,"r+");
    fread(write_buffer,300,1,fp);
    fclose(fp);

   // printf("%s\n",write_buffer );

    fd = open(unreadable_file,O_WRONLY);
    write(fd,write_buffer,strlen(write_buffer)+1);

    close(fd);

}
