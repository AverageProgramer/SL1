#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

char file[20] = "data";

typedef struct student
{
    int roll;
    char name[20];
}student;

void insert()
{
    student s,s1;
    int fd = open(file,O_CREAT|O_WRONLY|O_APPEND,S_IWUSR|S_IRUSR);

    for(int i=0;i<3;i++)
    {
        printf("Roll\n");
        scanf("%d",&s.roll);

        printf("Name\n");
        scanf("%s",s.name);

        write(fd,(student *)&s,sizeof(s));

    }

    close(fd);

}

void view()
{
    student s;
    int fd = open(file,O_RDONLY,S_IRUSR|S_IWUSR);

    while(read(fd,&s,sizeof(s)) > 0)
        printf("%s\t%d\n", s.name, s.roll);

    close(fd);
}

void delete()
{
    student s;
    int fd = open(file,O_RDONLY,S_IRUSR|S_IWUSR);
    int temp = open("temp",O_CREAT|O_WRONLY,S_IWUSR|S_IRUSR);

    while(read(fd,&s,sizeof(s)) > 0)
    {
        if(s.roll != 6)
            write(temp,(student *)&s,sizeof(s));
    }

    close(fd);
    close(temp);

    remove(file);
    rename("temp",file);
    //remove("temp");
}

void update()
{
    student s;
    int fd = open(file,O_RDONLY,S_IRUSR|S_IWUSR);
    int temp = open("temp",O_CREAT|O_WRONLY,S_IWUSR|S_IRUSR);

    while(read(fd,&s,sizeof(s)) > 0)
    {
        if(s.roll == 3)
        {
            s.roll = 0;
            strcpy(s.name,"zzzzz");
        }

        write(temp,(student *)&s,sizeof(s));

    }

    close(fd);
    close(temp);

    remove(file);
    rename("temp",file);
}

int main()
{

    student s,s1;

   //insert();
    view();
   delete();
    update();
    view();


}
