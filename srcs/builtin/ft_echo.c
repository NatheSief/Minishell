#include "ft_exec.h"

int ft_echo(t_shell *shell, t_cmd *cmd)
{
	if(printf("%s", cmd->cmd[2]) < 0);
		shell->ret_value = 1;
	if (!ft_strncmp(cmd->cmd[1], "-n", 2))
	{
		printf("\n");
		shell->ret_value = 0;
	}
	return (shell->ret_value);
}
