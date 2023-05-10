#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

void	er(void)
{
	write(2, "error: fatal\n", 13);
	exit(0);
}

int	stlen(char *s)
{
	int i = 0;
	while(s[i])
	{
		i++;
	}
	return (i);
}

int	tablen(char **tab)
{
	int i = 0;

	while (tab[i])
	{
		i++;
	}
	return (i);
}

void	freetab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*stdup(char *s)
{
	int 	i = 0;
	char	*s2 = malloc(sizeof(char) * (stlen(s) + 1));

	if (!s2)
		er();
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

int	is_sep(char *s)
{
	if (!strcmp(s, "|") || !strcmp(s, ";"))
	{
		return (1); 
	}
	return (0);
}

void	cd(char **cmd)
{
	if (cmd && tablen(cmd) != 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		return ;
	}
	if (chdir(cmd[1]) == 0)
		return ;
	write(2, "error: cannot change directory to ", 34);
	write(2, cmd[1], stlen(cmd[1]));
	write(2, "\n", 1);
}

void	tinyshell(char **av, char **env, int in)
{
	static int	i = 1;
	int			j = 0;
	int			x = 0;
	int			next = 0;
	int			fds[2];
	char		**cmd = malloc(sizeof(char *) * 100);

	if (!cmd)
		er();
	while (av[i] && is_sep(av[i]))
		i++;
	while (av[i] && !is_sep(av[i]))
	{
		cmd[j] = stdup(av[i]);
		i++;
		j++;
	}
	cmd[j] = NULL;
	if (!strcmp(av[i], "|"))
	{
		pipe(fds);
		x = fork();
		if (x < 0)
			er();
		if (x == 0)
		{
			dup2(in, STDIN_FILENO);
			dup2(fds[1], STDOUT_FILENO);
			if (!strcmp(cmd[0], "cd"))
			{
				cd(cmd);
				exit(0);
			}
			if (execve(cmd[0], cmd, env) == -1)
			{
				write(2, "error: cannot execute", 22);
				write(2, cmd[0], stlen(cmd[0]));	
				write(2, "\n", 1);
			}
		}
		close(fds[1]);
		next = fds[0];
	}
	else
	{
		x = fork();
		if (x < 0)
			er();
		if (x == 0)
		{
			dup2(in, STDIN_FILENO);
			if (!strcmp(cmd[0], "cd"))
			{
				cd(cmd);
				exit(0);
			}
			if (execve(cmd[0], cmd, env) == -1)
			{
				write(2, "error: cannot execute", 22);
				write(2, cmd[0], stlen(cmd[0]));	
				write(2, "\n", 1);
			}
		}
	}
	if (in != STDIN_FILENO)
		close(in);
	waitpid(0, NULL, 0);
	freetab(cmd);
	if(av[i])
		tinyshell(av, env, next);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	if (ac > 1)
		tinyshell(av, env, STDIN_FILENO);
	return (0);
}