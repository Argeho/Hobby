// char	**ft_strs_push_back(char **strs, const char *str)
// {
// 	int		i;
// 	char	**result;

// 	result = malloc(sizeof(char *) * (ft_strslen(strs) + 2));
// 	if (!result)
// 		return (0);
// 	i = 0;
// 	while (strs[i])
// 	{
// 		result[i] = ft_strdup(strs[i]);
// 		i++;
// 	}
// 	result[i++] = ft_strdup(str);
// 	result[i] = 0;
// 	return (result);
// }

// void	ft_envp_update(char ***envp, const char *key_value)
// {
// 	char	**new_envp;

// 	new_envp = ft_strs_push_back(*envp, key_value);
// 	ft_strsfree(*envp);
// 	*envp = new_envp;
// }

// void	ft_envp_add(char ***envp, const char *key_value)
// {
// 	int	exists_index;

// 	exists_index = ft_find_key(*envp, key_value);
// 	if (exists_index != -1)
// 		ft_envp_replace(*envp + exists_index, key_value);
// 	else
// 		ft_envp_update(envp, key_value);
// }

// void	ft_export(t_node *node, t_env *env)
// {
// 	int		i;

// 	if (!node->args)
// 		env->last_status = ft_export_print(env->envp);
// 	else
// 	{
// 		i = -1;
// 		while (node->args[++i])
// 		{
// 			if (!ft_is_correct_import(node->args[i]))
// 			{
// 				env->last_status = 1;
// 				return ;
// 			}
// 		}
// 		i = -1;
// 		while (node->args[++i])
// 			ft_envp_add(&(env->envp), node->args[i]);
// 		env->last_status = 0;
// 	}
// }

// int	ft_export_print(char **strs)
// {
// 	int		i;
// 	char	**strs_copy;

// 	i = 0;
// 	strs_copy = ft_strscopy(strs);
// 	if (!strs_copy)
// 		return (1);
// 	ft_strssort(strs_copy);
// 	while (strs_copy[i])
// 	{
// 		ft_print_declare(strs_copy[i]);
// 		free(strs_copy[i]);
// 		i++;
// 	}
// 	free(strs_copy);
// 	return (0);
// }

// void	ft_envp_replace(char **old_address, const char *key_value)
// {
// 	char	*new_kv;

// 	new_kv = ft_strdup(key_value);
// 	free(*old_address);
// 	*old_address = new_kv;
// }