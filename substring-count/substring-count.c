#include <stdio.h>
#include <stdlib.h>

int NumofStr(char* source, char* substr);

int main()
{
	char* source = "this_is_ishrat_car";
	char* substr = "is";

	int output = output = NumofStr(source, substr);
	printf("Number of \"%s\" in \"%s\" is %d\n", substr, source, output);

	return 0;
}

int NumofStr(char* source, char* substr)
{
	int count=0, match, len;
	int i, j;

	len = 0;
	for (i = 0; substr[i] != '\0'; i++)
	{
		len++;
	}
	for (i = 0; source[i + len - 1] != '\0'; i++)
	{
		match = 0;
		for (j = 0; substr[j] != '\0'; j++)
		{
			if (source[i + j] == substr[j])
			{
				match++;
			}

		}
        // printf("match: %d\n", match);
        
        if (match == len)
        {
            count++;
            i = i + len - 1;
        }
		
	}

	return count;
}
