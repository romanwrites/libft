#include "libft.h"
#include <stdio.h>

int		main()
{
	t_list lst;
	t_list *ptr;
	t_list	second;

	t_list *kek;

	lst.content = ft_strdup("Hello");
	lst.next = &second;
	second.content = ft_strdup("World");
	second.next = NULL;
	ptr = &lst;
	kek = &lst;

	while (kek)
	{
		printf("%s ", kek->content);
		kek = kek->next;
	}
	printf("\n");

	ft_lstrev(&ptr);
	kek = ptr;
	while (kek)
	{
		printf("%s ", kek->content);
		kek = kek->next;
	}
	printf("\n");
	return (0);
}