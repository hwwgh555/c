#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum NUM_TYPE {
	LIST = 1,
	ADD,
	MODIFY,
	DELETE,
	QUIT
};


char * student_file_name = "students_data.txt";
struct Student {
	// 代码中如何定义的？
	//char* name = (char *)malloc(sizeof(char) * 20);
	char name[100];
	int age;
	int class;
	double height;
};

struct Student students[10000];
int students_count = 0;
int read_from_file() {
	int count = 0;
	FILE *fp = fopen(student_file_name, "r");
	if(fp == NULL) perror("failed to open file!");
	// 重点
	while(fscanf(fp, "%s", students[count].name) != EOF){
		fscanf(
				fp,
				"%d%d%lf",
				&students[count].age,
				&students[count].class,
				&students[count].height
		);
		count++;
	}

	fclose(fp);
	return count;
}

void list_students() {
	int char_nums = printf("%6s|%18s|%6s|%6s|%10s|\n", "id", "name", "age", "class", "height");
	for(int i = 0; i < char_nums; i++) {
		printf("=");
	}
	printf("\n");

	for(int i = 0; i < students_count; i++){
			printf(
					"%6d|%18s|%6d|%6d|%10.2lf|\n",
					i,
					students[i].name,
					students[i].age,
					students[i].class,
					students[i].height
			);
	}

	return ;
}

void output_to_file(struct Student *students, int n) {
	FILE *fp = fopen(student_file_name, "a");
	for(int i = 0; i < n; i++) {
		fprintf(fp, "%s %d %d %lf\n",
				students[i].name,
				students[i].age,
				students[i].class,
				students[i].height
			   );
	}

	fclose(fp);

	return;
}

void add_a_student() {
	printf("add new item : (name, age, class, heihgt)\n");
	scanf(
			"%s%d%d%lf",
			students[students_count].name,
			&students[students_count].age,
			&students[students_count].class,
			&students[students_count].height
	);
	// 这里利用了指针偏移
	output_to_file(students + students_count, 1);
	students_count++;

	printf("add a student successfully!\n");
	return ;
}

void clear_file() {
	FILE *fp = fopen(student_file_name, "w");
	fclose(fp);

	return;
}
void restore_to_file() {
	clear_file();
	output_to_file(students, students_count);
	return;
}

void modify_a_student() {
	int id;
	do{
		printf("modify id: ");
		scanf("%d", &id);
	} while(id < 0 || id >= students_count);

	printf("add new item : (name, age, class, heihgt)\n");
	printf("mysql >");
	scanf(
			"%s%d%d%lf",
			students[id].name,
			&students[id].age,
			&students[id].class,
			&students[id].height
	);

	restore_to_file();

	return;
}

void delete_a_student() {
	if(students_count == 0) {
		perror("there is no student!");
		return;
	}

	list_students();
	int id;
	do {
		printf("delete id: ");
		scanf("%d", &id);
	} while(id < 0 || id >= students_count);

	printf("confirm: (y / n)");
	char choose[100];
	// 防止有其它字符
	fflush(stdin);
	scanf("%[^\n]", choose);
	if(choose[0] != 'y') return;

	for(int i = id + 1; i < students_count; i++) {
		/*
		strcpy(students[i - 1].name, students[i].name);
		students[i - 1].age = students[i].age;
		students[i - 1].class = students[i].class;
		students[i - 1].height = students[i].height;
		*/
		students[i - 1] = students[i];
	}
	students_count--;
	restore_to_file();

	return;
}

int usage() {
	int num;
	do {
		printf("%d : list students\n", LIST);
		printf("%d : add a student\n", ADD);
		printf("%d : modify a student\n", MODIFY);
		printf("%d : delete a student\n", DELETE);
		printf("%d : quit\n", QUIT);
		// 影响大吗？
		printf("mysql > ");
		scanf("%d", &num);
	} while (num < 0 || num > 5);

	return num;
}

int main() {
	students_count = read_from_file();
	while(1) {
		printf("while----------\n");
		int num = usage();
		switch(num){
			case LIST: {
						   list_students();
						   break;
					   };
			case ADD: {
						  add_a_student();
						  break;
					  };
			case MODIFY: {
							 modify_a_student();
							 break;
						 };
			case DELETE: {
							 delete_a_student();
							 break;
						 };
			case QUIT: exit(0); break;
		}
	}

	return 0;
}
