#include <iostream>


int main(int argc, char **argv)
{
	int i = 1;
	int j = 0;
	if(argc > 1)
	{
		while(i <= argc - 1)
		{
			while (argv[i][j])
			{
				if(argv[i][j] >= 'a' && argv[i][j] <= 'z')
				{
					std::cout << (char)(argv[i][j] - 32);
				}
				else
					std::cout << argv[i][j];
				j++;
			}
			j = 0;
			i++;
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
}