/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskhairi <mskhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:38:02 by mskhairi          #+#    #+#             */
/*   Updated: 2024/07/09 13:01:35 by mskhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_after(t_item *tmp, int *after)
{
	while (tmp)
	{
		if (tmp->next && !is_empty(tmp->next->content))
		{
			*after = 1;
			break;
		}
		tmp = tmp->next;
	}
}
void	check_before(t_item *tmp, int *before)
{
	while (tmp)
	{
		if (tmp->prev && !is_empty(tmp->prev->content))
		{
			*before = 1;
			break;
		}
		tmp = tmp->prev;
	}
}

int is_alone(t_item *lst)
{
	t_item *tmp;
	int after;
	int before;
	
	after = 0;
	before = 0;
	tmp = lst;
	check_before(tmp, &before);
	tmp = lst;
	check_after(tmp, &after);
	if (is_redirection(tmp->content) && ((!after && !before) || (before && !after)))
		return (0);
	else if (*(tmp->content) == '|' && ((!after && !before) || (!before && after)))
			return (0);
	return (1);
}

