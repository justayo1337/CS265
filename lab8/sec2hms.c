#include <stdio.h>
#include <stdlib.h>


struct time
{
	int hr;
	int min;
	int sec;

};



struct time sec2hms( int secs) {
    struct time fin; 
	int  rem;
	
	fin.hr = secs / 3600;
   rem = secs % 3600;
	fin.min = rem / 60;
	fin.sec = rem % 60;
return fin;
}

int main(int argc, char *argv[] ){
 

  int secs = atoi(argv[1]);
  struct time conv = sec2hms( secs );

  printf("%02d:%02d:%02d\n", conv.hr,conv.min,conv.sec);
return 0;
}
