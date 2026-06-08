/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                 ❤︎︎࣪    I N F O R M A T I O N    ❤︎︎࣪    				 
   ❤︎︎࣪ Name: 17-19.c
   ❤︎︎࣪ Purpose: 
   ❤︎︎࣪ Author: amai-aijou
   ❤︎︎࣪ Date: Sun Jun  7 07:01:40 PM CDT 2026
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
                                                                
/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                      ❤︎︎࣪    G L O B A L    ❤︎︎࣪     
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/

#include <stdio.h>



/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                  ❤︎︎࣪    P R O T O T Y P E S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void search_and_run(char *string);
void new_cmd();
void open_cmd();
void close_cmd();
void close_all_cmd();
void save_cmd();
void save_as_cmd();
void save_all_cmd();
void print_cmd();
void exit_cmd();

// Struct must be declared *after* function prototypes are declared!
struct {
	char *cmd_name;
	void (*cmd_pointer)(void);
} file_cmd[] =
 {{"new",		new_cmd},
  {"open",		open_cmd},
  {"close",		close_cmd},
  {"close all",	close_all_cmd},
  {"save",		save_cmd},
  {"save as",	save_as_cmd},
  {"save all",	save_all_cmd},
  {"print",		print_cmd},
  {"exit",		exit_cmd},
 };

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                ❤︎︎    M A I N  F U N C T I O N    ❤︎︎                
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
int main(void) {

	char *str = "new";

	search_and_run("new");

	return 0;
}

/*┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
                   ❤︎︎࣪    F U N C T I O N S    ❤︎︎࣪    
  ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛*/
void search_and_run (char *string) {

	char ch, i = 0, j = 0;


//	while (file_cmd[i].cmd_name[j] != '\0') {
//		printf("DEBUG - test: |%c|\n", file_cmd[i].cmd_name[j]);

		while (string[j] == file_cmd[i].cmd_name[j] && string[j] != '\0') {
			printf("letter match!\n");
			j++;
		}

		if (string[j] == '\0' && file_cmd[i].cmd_name[j] == '\0') {
			printf("word match!\n");
			(*file_cmd[i].cmd_pointer)();
		} else {
			printf("no match\n");
		}

}

void new_cmd() {
	printf("new_cmd()\n");
}

void open_cmd() {
	printf("open_cmd()\n");
}

void close_cmd() {
	printf("close_cmd()\n");
}

void close_all_cmd() {
	printf("close_all_cmd()\n");
}

void save_cmd() {
	printf("save_cmd()\n");
}

void save_as_cmd() {
	printf("save_as_cmd()\n");
}

void save_all_cmd() {
	printf("save_all_cmd()\n");
}

void print_cmd() {
	printf("print_cmd()\n");
}

void exit_cmd() {
	printf("exit_cmd()\n");
}
