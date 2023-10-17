fndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 *  * struct liststr - singly linked list
 *   * @num: the number field
 *    * @str: a string
 *     * @next: points to the next node
 *      */
typedef struct liststr
{
		int num;
			char *str;
				struct liststr *next;
} list_t;

/**
 *  * struct passinfo - contains pseudo-arguements to pass into a function,
 *   * allowing uniform prototype for function pointer struct
 *    * @arg: a string generated from getline containing arguements
 *     * @argv:an array of strings generated from arg
 *      * @path: a string path for the current command
 *       * @argc: the argument count
 *        * @line_count: the error count
 *         * @err_num: the error code for exit()s
 *          * @linecount_flag: if on count this line of input
 *           * @fname: the program filename
 *            * @env: linked list local copy of environ
 *             * @environ: custom modified copy of environ from LL env
 *              * @history: the history node
 *               * @alias: the alias node
 *                * @env_changed: on if environ was changed
 *                 * @status: the return status of the last exec'd command
 *                  * @cmd_buf: address of pointer to cmd_buf, on if chaining
 *                   * @cmd_buf_type: CMD_type ||, &&, ;
 *                    * @readfd: the fd from which to read line input
 *                     * @histcount: the history line number count
 *                      */
typedef struct passinfo
{
		char *arg;
			char **argv;
				char *path;
					int argc;
						unsigned int line_count;
							int err_num;
								int linecount_flag;
									char *fname;
										list_t *env;
											list_t *history;
												list_t *alias;
													char **environ;
														int env_changed;
															int status;

																char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
																	int cmd_buf_type; /* CMD_type ||, &&, ; */
																		int readfd;
																			int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
			0, 0, 0}

/**
 *  * struct builtin - contains a builtin string and related function
 *   * @type: the builtin command flag
 *    * @func: the function
 *     */
typedef struct builtin
{
		char *type;
			int (*func)(info_t *);
} builtin_table;


/* toem_ato.c */
int interactive(info_t *);
int is_lim(char, char *);
int _isalph(int);
int _ato(char *);
nt _myexiting(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin.c */
int _myexiting(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin_1.c */
int _my_history(info_t *);
int _myaliases(info_t *);

/* toem_environment.c */
char *_getenvi(info_t *, const char *);
int _myenvi(info_t *);
int _mysetenvi(info_t *);
int _myunsetenvi(info_t *);
int populate_env_list(info_t *);
/* toem_error.c */
void _eputses(char *);
int _eputchars(char);
int _putfds(char c, int fd);
int _putsfds(char *str, int fd);
nt _errato(char *);
void print_errors(info_t *, char *);
int print_d(int, int);
char *convert_numbers(long int, int, int);
void remove_comment(char *);
/* toem_exitting.c */
char *_strncpying(char *, char *, int);
char *_strncating(char *, char *, int);
char *_strchrs(char *, char);

/* toem_getenvi.c */
char **get_environs(info_t *);
int _unsetenves(info_t *, char *);
int _setenves(info_t *, char *, char *);
lear_infos(info_t *);
void set_infos(info_t *, char **);
void free_infos(info_t *, int);

/* toem_get_info.c */
void clear_infos(info_t *);
void set_infos(info_t *, char **);
void free_infos(info_t *, int);


/* toem_history.c */
char *get_history_files(info_t *info);
int write_histories(info_t *info);
int read_histories(info_t *info);
int build_history_lists(info_t *info, char *buf, int linecount);
int renumber_histories(info_t *info);

/* toem_list.c */
list_t *add_nodes(list_t **, const char *, int);
list_t *add_node_ends(list_t **, const char *, int);
size_t print_list_strs(const list_t *);
int delete_node_at_indexes(list_t **, unsigned int);
void free_lists(list_t **);

