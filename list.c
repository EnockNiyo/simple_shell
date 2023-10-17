#include "shell.h"

/**
 *  * add_nodes - adds a node to the start of the list
 *   * @head: address of pointer to head node
 *    * @str: str field of node
 *     * @num: node index used by history
 *      *
 *       * Return: size of list
 *        */
list_t *add_nodes(list_t **head, const char *str, int num)
{
		list_t *new_head;

			if (!head)
						return (NULL);
				new_head = malloc(sizeof(list_t));
					if (!new_head)
								return (NULL);
						_memset((void *)new_head, 0, sizeof(list_t));
							new_head->num = num;
								if (str)
										{
													new_head->str = _strdup(str);
															if (!new_head->str)
																		{
																						free(new_head);
																									return (NULL);
																											}
																}
									new_head->next = *head;
										*head = new_head;
											return (new_head);
}

/**
 *  * add_node_ends - adds a node to the end of the list
 *   * @head: address of pointer to head node
 *    * @str: str field of node
 *     * @num: node index used by history
 *      *
 *       * Return: size of list
 *        */
list_t *add_node_ends(list_t **head, const char *str, int num)
{
		list_t *new_nodes, *node;

			if (!head)
						return (NULL);

				nodes = *head;
					new_nodes = malloc(sizeof(list_t));
						if (!new_nodes)
									return (NULL);
							_memsets((void *)new_nodes, 0, sizeof(list_t));
								new_nodes->num = num;
									if (str)
											{
														new_nodes->str = _strdup(str);
																if (!new_nodes->str)
																			{
																							free(new_nodes);
																										return (NULL);
																												}
																	}
										if (nodes)
												{
															while (nodes->next)
																			nodes = nodes->next;
																	nodes->next = new_nodes;
																		}
											else
														*head = new_nodes;
												return (new_nodes);
}

/**
 *  * print_list_strs - prints only the str element of a list_t linked list
 *   * @h: pointer to first node
 *    *
 *     * Return: size of list
 *      */
size_t print_list_strs(const list_t *h)
{
		size_t i = 0;

			while (h)
					{
								_puts(h->str ? h->str : "(nil)");
										_puts("\n");
												h = h->next;
														i++;
															}
				return (i);
}

/**
 *  * delete_node_at_indexes - deletes node at given index
 *   * @head: address of pointer to first node
 *    * @index: index of node to delete
 *     *
 *      * Return: 1 on success, 0 on failure
 *       */
int delete_node_at_indexes(list_t **head, unsigned int index)
{
		list_t *nodes, *prev_nodes;
			unsigned int i = 0;

				if (!head || !*head)
							return (0);

					if (!index)
							{
										nodes = *head;
												*head = (*head)->next;
														free(nodes->str);
																free(nodes);
																		return (1);
																			}
						nodes = *head;
							while (nodes)
									{
												if (i == index)
															{
																			prev_nodes->next = nodes->next;
																						free(nodes->str);
																									free(nodes);
																												return (1);
																														}
														i++;
																prev_nodes = nodes;
																		nodes = nodes->next;
																			}
								return (0);
}

/**
 *  * free_lists - frees all nodes of a list
 *   * @head_ptr: address of pointer to head node
 *    *
 *     * Return: void
 *      */
void free_lists(list_t **head_ptr)
{
		list_t *nodes, *next_nodes, *head;

			if (!head_ptr || !*head_ptr)
						return;
				head = *head_ptr;
					nodes = head;
						while (nodes)
								{
											next_nodes = nodes->next;
													free(nodes->str);
															free(nodes);
																	node = next_nodes;
																		}
							*head_ptr = NULL;
}

