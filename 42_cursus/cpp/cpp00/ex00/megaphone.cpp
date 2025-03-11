#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i = 0;
    int j = 1;
    if(argc > 1)
    {
        while(j < argc)
        {
            i=0;
            while(argv[j][i])
            {
                std::cout << (char)std::toupper(argv[j][i]);
                i++;
            }
            j++;
        }
        std::cout << "\n";
    }
    else
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
}