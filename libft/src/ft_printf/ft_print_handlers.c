#include "libft.h"

int	ft_handle_s(char *string)
{
	int	returnvalue;

	returnvalue = 0;
	if (string == (char *) NULL)
		string = "(null)";
	while (*string)
	{
		ft_putcharo(*string);
		string++;
		returnvalue++;
	}
	return (returnvalue);
}

int	ft_handle_c(int whatever)
{
	ft_putcharo(whatever);
	return (1);
}

int	ft_print_percent(void)
{
	ft_putcharo('%');
	return (1);
}
