#include<stdio.h>
#include<stdlib.h>

int compare_file(FILE *file1_ptr, FILE *file2_ptr, int *line, int *col);

int main(int argc, char *argv[]){
	FILE *file1_ptr;
	FILE *file2_ptr;
	char path_1[100];
	char path_2[100];

	int diff, line, col;

	if(argc < 2){
		printf("Not enough arguments supplied.\n");
		exit(EXIT_FAILURE);
	}

	file1_ptr = fopen(argv[1], "r");
	file2_ptr = fopen(argv[2], "r");

	if(file1_ptr == NULL || file2_ptr == NULL){
		exit(EXIT_FAILURE);
	}

	diff = compare_file(file1_ptr, file2_ptr, &line, &col);

	if(diff == 0){
		printf("\nFile contents are the same.\n");
	}else{
		printf("File contents are different.\n");
		printf("Line : %d, Col : %d\n", line, col);
	}

	fclose(file1_ptr);
	fclose(file2_ptr);

	return 0;
}

int compare_file(FILE *file1_ptr, FILE *file2_ptr, int *line, int *col){
	char ch1, ch2;
	*line = 1;
	*col = 1;

	do{
		ch1 = fgetc(file1_ptr);
		ch2 = fgetc(file2_ptr);
		if(ch1 == '\n'){
			*line += 1;
			*col = 0;
		}

		if(ch1 != ch2){
			return -1;
		}
	}while(ch1 != EOF && ch2 != EOF);

	if(ch1 == EOF && ch2 == EOF){
		return 0;
	}else{
		return -1;
	}
}
