/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:26:58 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/07/22 17:41:48 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

void	mini_env(t_env *env_l);
void	get_key_and_value(char *env, char **key, char **value);
void	mini_unset(t_env **env_l , char *key);
// void	mini_export(t_env **env_l, char *key);
t_env	*env_last(t_env *node);
t_env	*env_new_node(char *key, char *value);
void	env_add_back(t_env **head, t_env *new);
void	env_delone(t_env **head, t_env *node);

#endif