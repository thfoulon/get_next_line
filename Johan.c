#include "get_next_line.h"

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

int ft_check(char *str)
{
  int i = 0;
  while (str[i] != '\n' && str[i])
    i++;
  if (str[i] == '\n')
    return (1);
  return (0);
}

char *ft_strappend(char *s1, char *s2)
{
  char *new;
  int i = 0;
  int j = 0;
  if (s1 == NULL)
  {
    s1 = (char*)malloc(sizeof(*s2) * strlen(s2));
    s1 = s2;
    return(s1);
  }
  new = (char*)malloc(sizeof(*new) * (strlen(s1) + strlen(s2)) + 1);
  while (s1[i])
  {
    new[i] = s1[i];
    i++;
  }
  while (s2[j])
  {
    new[i] = s2[j];
    i++;
    j++;
  }
  new[i] = '\0';
  return(new);
}

int get_next_line(int fd, char **s)
{
  int nb_lues = 1;
  int retour = 0;
  static char buff[BUFF_SIZE + 1];
  static char *str;
  static char *new = NULL;
  printf("debut boucle\n");
  while (nb_lues > 0)
  {
    nb_lues = read(fd, buff, BUFF_SIZE);
    printf("fin read\n");
    str = ft_strappend(new, buff);
    printf("strappend\n");
    if (new)
			free(new);
    printf("memdel");
    new = (char*)malloc(sizeof(str) * strlen(str));
    printf("malloc\n");
    new = str;
    if (ft_check(new) == 1)
      break;
  }
  printf("fin boucle\n");
  s = &new;
  if (nb_lues < BUFF_SIZE)
    return (0);
  if (strlen(buff) == 0)
    return (-1);
  return (1);
}

int  main(int ac, char **av)
{
  int fd;
  char *line;
  if (ac == 2)
  {
    if ((fd = open(av[1], O_RDONLY)) == -1)
    {
      printf("open(); error\n");
      return (-1);
    }
    printf("%d\n", get_next_line(fd, &line));
  }
  else if (ac == 3)
  {
    printf("%s\n", ft_strappend(av[1], av[2]));
  }
  else
    printf("arg error\n");
  return (0);
}
