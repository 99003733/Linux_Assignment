#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>

#define size 1000

int main(int argc , char *argv[])
{
    int fd, fs;
    ssize_t bytesRead, bytesWritten;
    char buffer[size];

    fs = open (argv[1], O_RDONLY);

    if(fs == -1)
    {
        perror("Source file not exist");

    }

    fd = open(argv[2],O_WRONLY | O_CREAT, 0666);
    
    if(fd == -1)
    {
        perror("File could not be opened");

    }

    while((bytesRead = read(fs, &buffer, size)) > 0)
    {
        bytesWritten = write(fd, &buffer,bytesRead);
    }

    close(fs);
    close(fd);
    return 0;




}