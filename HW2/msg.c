#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int checkFile(FILE *name) {
	if (name == NULL) {
		printf("Unable to open file\n");
		exit(-1);
	}
}


/* Function: foo
*-------------------------------------------------
*
* Function that Verifies input strigns starting with 'E'
*
*stri: the string to be processed
* 
* returns: 0 if the input is not valid, 1 if the input is valid
*/

int foo(char *stri) {
	char cS = '1';
	char fS ='f';
   
	//run checks to verify 
   for (int i = 0 ; i < strlen(stri) ; ++i) {
		if (stri[i] == 'E' && cS == '1') {
       cS = '2';
	}else if ((stri[i] == '0' || stri[i] == '1' || stri[i] == '2') && cS == '2') {
       cS = '3';
	}else if ((stri[i] == '0' || stri[i] == '1' || stri[i] == '2')  && cS == '3') {
	continue; 
}else if (stri[i] == 'F' && cS == '3') {
   cS = 'f'; 
}else { return 0; }
	}

if (cS == fS){
return 1;
}
return 0;
}

/* Function: eep
*-------------------------------------------------
*
* Function that Verifies input strigns starting with 'P'
*
*stri: the string to be processed
* 
* returns: 0 if the input is not valid, 1 if the input is valid
*/

int eep(char *stri){
	char cS = '1';
	char fS ='f';
   
	//run checks to verify 
   for (int i = 0 ; i < strlen(stri) ; ++i) {
		if (stri[i] == 'P' && cS == '1') {
       cS = 'f';
	}else if (stri[i] == 'B' && cS == 'f') {
       cS = '3';
	}else if (stri[i] == 'C'  && cS == '3') {
       cS = 'f'; 
}else { return 0; }
	}
if (cS == fS ){
	return 1; }

	return 0;
}

/* Function: op
*-------------------------------------------------
*
* Function that Verifies input strigns starting with 'Q'
*
*stri: the string to be processed
* 
* returns: 0 if the input is not valid, 1 if the input is valid
*/

int op(char *stri){
	char cS = '1';
	char fS ='f';
//run checks to verify 
   for (int i = 0 ; i < strlen(stri) ; ++i) {
		if (stri[i] == 'Q' && cS == '1') {
       cS = '2';
	}else if (stri[i] == '6' && (cS == '2' || cS =='f' )) {
             continue;	
	}else if (stri[i] == '7'  && cS == '2') {
       cS = 'f'; 
} else if (stri[i] =='7' && cS == 'f'){
	cS ='2';
	}else { return 0; }
	}
if (cS == fS ){
	return 1;
} 
	return 0;
}


/* Function: ork
*-------------------------------------------------
*
* Function that Verifies input strigns starting with 'M'
*
*stri: the string to be processed
* 
* returns: 0 if the input is not valid, 1 if the input is valid
*/


int ork(char *stri){

char *cS = malloc(8192);
strcpy(cS,"1");
 
char *temp = malloc(8192);
	
   for (int i = 0; i < strlen(stri) ; ++i){		 
    if (stri[i] == 'M' && cS[0] == '1') {
       cS[0] = '2';

}else if ( isdigit(stri[i] - 0) && cS[0] == '2' && (stri[i-1] == 'M' || stri[i-2] == 'M') ) {
             continue;	
	}else if (stri[i] == 'E' && cS[0] == '2' && isdigit(stri[i-1]) && isdigit(stri[i-2]) && stri[i-3] == 'M' ) {
       strcpy(temp,stri+i);
		 if (foo(temp) ) { 
			strcpy(cS,"ff");
			break;
			}
} else if (stri[i] == 'P' && cS[0] == '2' && isdigit(stri[i-1]) && isdigit(stri[i-2]) && stri[i-3] == 'M') {
      //printf("%s\n",stri+i); 
		 strcpy(temp,stri+i);
		 if (eep(temp) ) { 
			strcpy(cS,"ef");
			break;
			} 
	}else { return 0; }
	}
if (!strcmp(cS,"ff") || !strcmp(cS,"ef") ){
 free(cS);
 free(temp);
	return 1;
	
}

return 0;
}

/*Function: checks
*-------------------------------------------------
*
* Function that checks the first character of the string and then sends to the correct processing function
*
*stri: the string to be processed
* 
* returns: 0 if the input is not valid, 1 if the input is valid
*/

int checks(char *stri) {
   int returns;	
	switch (stri[0]){
   case 'E': returns = foo(stri); break;
case 'P': returns = eep(stri); break;
case 'Q': returns = op(stri); break;
case 'M': returns = ork(stri); break;
default : returns = 0; break;

}
return returns;
}

void main(int argc, char *argv[]) {
   
   FILE *testData;
   char *buff = malloc(8192);
	size_t len = 8192;
	size_t characters;
   

	if (argc > 1) {
		testData = fopen(argv[1],"r");
		checkFile(testData);
     while ((characters=getline(&buff,&len,testData)) !=-1) {	
      //printf("Made it here");
      buff[ strlen(buff) - 1 ] = '\0';	
      int res =  checks(buff);
     if (res == 1) {
printf("%s OK\n",buff);
	  }else{
printf("%s FAIL\n",buff);
	}
	  }
	  }else {
		while( getline( &buff, &len, stdin ) > 1 )
        {
buff[ strlen(buff) - 1 ] = '\0';	

		//printf("%s", buff);
		int res = checks(buff);
		//run functions on each line and append to one string
if (res == 1) {
printf("%s OK\n",buff);
	  }else{
printf("%s FAIL\n",buff);
	}

}	
	}
free(buff);
}
