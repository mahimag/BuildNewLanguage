#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "ultron.h"

int main(int argc, char** argv) {

	Ultron ultron;
    ultron_init(&ultron);

	int option, iflag, fflag = 0;
	int index = 0;
	int icount = 0;
	int memory[100] = {0}; //array of ints called memory

	char buf[200] = {' '};
	FILE *fp;

	while((option = getopt(argc, argv, "if:")) != -1) {
		switch(option){
			case 'i':
				icount = atoi(argv[2]);  //number of instructions
				
				for(int i=0; i<icount; i++){
					int val = 0;
					scanf("%d", &val); //1010
					memory[i] = val;
				}
				
				ultron_load(&ultron, icount, memory);
				ultron_run(&ultron);
				ultron_dump(&ultron);
				iflag = 1;
				break;
			case 'f':
				fp = fopen(argv[2], "r");
				int mem[200];
				
				while(fgets(buf, 200, fp)){
					mem[index]= atoi(buf);
					index++;
				}
				ultron_load(&ultron, index, mem);
				ultron_run(&ultron);
				ultron_dump(&ultron);
				
				printf("test");
				fflag = 1;
				break;
			default:
				printf("hi");
		}
	}

}