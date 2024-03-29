#include "../inc/ft_ssl.h"

static void	s_to_upper(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
}

static void	display_input(t_handler *handler, char *input, bool with_brackets)
{
	if (!handler->reversed)
	{
		s_to_upper(handler->hash_name);
		ft_putstr(handler->hash_name);
		ft_putstr(" (");
	}
	else
		ft_putchar(' ');
	if (with_brackets)
		ft_putchar('\"');
	ft_putstr(input);
	if (with_brackets)
		ft_putchar('\"');
	if (!handler->reversed)
		ft_putstr(") = ");
}

void		display(t_handler *h, t_process *p, char *ha, t_content to_display)
{
	if (h->verbose && p->type == H_STDIN)
		write(1, to_display.content, to_display.size);
	if (!h->quiet && p->type != H_STDIN)
	{
		if (!h->reversed)
			display_input(h, p->input, p->type == H_STRING);
	}
	ft_putstr(ha);
	if (!h->quiet && p->type != H_STDIN)
	{
		if (h->reversed)
			display_input(h, p->input, p->type == H_STRING);
	}
	ft_putchar('\n');
}
