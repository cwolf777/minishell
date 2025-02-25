/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbcollec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwolf <cwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:05:17 by cwolf             #+#    #+#             */
/*   Updated: 2025/02/25 13:01:56 by cwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void *gc_alloc(t_gc_manager *gc, int size, gc_type type)
{
    void *ptr;
    t_gc_node *node;

	ptr = malloc(size);
    if (!ptr)
	{
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
	node = malloc(sizeof(t_gc_node));
    if (!node) 
	{
        perror("malloc failed");
        free(ptr);	
        exit(EXIT_FAILURE);
    }

    node->ptr = ptr;
    node->type = type;
    node->next = gc->head;
    gc->head = node;

    return (ptr);
}

static void free_char_array(char **array) 
{
    int i;

    i = 0;
    if (array == NULL)
        return;
    while (array[i] != NULL)
    {
        free(array[i]);
        i++;
    }
    free(array);
}

void gc_free_all(t_gc_manager *gc) 
{
    t_gc_node *node;
	t_gc_node *next;
 
	node = gc->head;
    while (node) 
	{
        next = node->next;
        if (node->type == GC_ARRAY)
			free_char_array((char **)node);
        //else if andere type
        free(node->ptr);
        free(node);
        node = next;
    }
    gc->head = NULL;
}