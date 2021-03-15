# XML_PARSER
xml_parser module, parses single line xml tags, with multiple props.
# Dependencies
`base` module
# Headers
`xml_parser.h` in `includes` directory
# Functions
```C
t_xml_data  *ft_read_xml(char *filename);
void        *ft_xml_free_data(t_xml_data *data);
char        *ft_xml_error(char *error, char *near);
```
# Demo
```C
#include <stdio.h>
#include "libft.h"
#include "xml_parser.h"

int main(void)
{
    char        *error;
    t_xml_data  *data;

    data = ft_read_xml("test.xml");
    if (!data)
    {
        error = ft_xml_error(NULL, NULL);
        write(2, "PARSE ERROR : ", 14);
        if (error)
            write(2, error, ft_strlen(error));
        else
            ft_putstr_fd("Invalid file", 2);
        write(2, "\n", 1);
        return(1);
    }
    t_xml_tag   *tag;
    t_xml_prop  *prop;

    tag = data->tags;
    while (tag)
    {
        printf("%s :\n", tag->name);
        prop = tag->props;
        while (prop)
        {
            printf("\t%s = %s\n", prop->name, prop->value);
            prop = prop->next;
        }
        tag = tag->next;
    }
    return (0);
}
```