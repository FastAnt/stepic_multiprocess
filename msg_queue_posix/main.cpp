#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <istream>
#include <ostream>
#include <fstream>

using namespace std;
const char * name = "/test.mq";
#define FILE_NAME  "/home/box/message.txt"

int main()
{
	if( 0 == mq_unlink( name ) ) {
		printf( "Message queue was removed\n" );
	}
    mq_attr attr;
    attr.mq_curmsgs = 0;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 128;
    mqd_t mq  = mq_open(name,  O_CREAT | O_RDWR, 0666,&attr);

    char buffer[128] = {0};
    size_t size = mq_receive( mq, buffer, 128, 0 );
    
	ofstream myFile ;
	myFile.open(FILE_NAME);
	myFile << buffer;
	myFile.close();
mq_unlink( name ) ;
return 0;


}
