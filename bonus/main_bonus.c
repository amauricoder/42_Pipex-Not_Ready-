/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconceic <aconceic@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:07:39 by aconceic          #+#    #+#             */
/*   Updated: 2024/04/02 18:12:40 by aconceic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

//./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
//< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

// ./pipex here_doc LIMITER cmd cmd1 file
// cmd << LIMITER | cmd1 >> file
int main(int argc, char **argv, char **envp)
{
	t_pipexbn *bonus_data;
	int	i;

	if (!arg_isvalid_bonus(argc, argv) || !envp || envp[0][0] == '\0')
	{
		write(2, "Error\nInvalid arguments or not envp", 36);
		exit(EXIT_FAILURE);
	}
	bonus_data = init_bonus_struct(argc, argv);
	create_pipes(bonus_data);
	
	i = 0;
	while(i < bonus_data->processes - 1)
	{
		ft_printf("pipe %i -> fd in %i out %i \n", 
			i, bonus_data->pipesfd_arr[i][0],
			 	bonus_data->pipesfd_arr[i][1]);
		i ++;
	}

	i = 0;
	while (i < bonus_data->processes - 1)
	{
		ft_printf("pid %i value %i \n", i, bonus_data->pid_arr[i]);
		i ++;
	}
	//we need to create a pipe (a pair of file descriptors) 
	//for each child process.
	

	(void)envp;
}
