#include <syslog.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

//Errornumber
extern int errno;

int writelog(const char* file, const char* log);

int main(int argc, char **argv){
	int fd, err;
	char buffer[100];	
	if(argc < 3){
		writelog(argv[0],"There should be atleast 2 arguments");
		return 1;
	}

	//creating a file
	fd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC);
        if(fd < 0){	
		err = errno;
		sprintf(buffer, "error %d in opening file %s", err, argv[1]);
		writelog(argv[0], buffer);
		return 1;
	}
	sprintf(buffer, "Writing %s to %s", argv[2], argv[1]);
	writelog(argv[0], buffer);
	write(fd, argv[2], strlen(argv[2]));
	close(fd);
	return 0;
}

int writelog(const char* file, const char *log){
	
	openlog(file, 0, LOG_USER);
	syslog(LOG_DEBUG, "%s\n", log);
	closelog();
	return 0;
}
