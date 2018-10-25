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

    char filename[300],input[300],write_buffer[300],read_buffer[300];
    char unreadable_file[300]="fifo_file";

    mkfifo(unreadable_file,0666);

   /* printf("Enter filename :\n");
    scanf("%s",filename);*/

    printf("Enter string ($ for new line ) :\n");
    //scanf("%[^\n]s",input);
    fgets(input,300,stdin);

    fd = open(unreadable_file, O_CREAT|O_WRONLY);
    write(fd,input,strlen(input)+1);
    close(fd);

    fd = open(unreadable_file, O_RDONLY);
    bytes = read(fd,read_buffer,300);
    read_buffer[bytes] = '\0';

    printf("%s\n",read_buffer );

}
