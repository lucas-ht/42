#include <iostream>
#include <fstream>

int	replace(char **argv, std::string str)
{
    std::ofstream	f;

    f.open( (std::string(argv[1]) + ".replace").c_str() );
    if ( f.fail() )
        return (1);

    int				pos;

    for (int i = 0; i < (int) str.size(); i++) {
        pos = str.find(argv[2], i);
        if (pos != -1 && pos == i) {
            f << argv[3];
            i += std::string(argv[2]).size() - 1;
        }
        else
            f << str[i];
    }
    f.close();
    return (0);
}

int	main(int argc, char **argv) {

    if (argc != 4)
        return (1);

    std::ifstream   f;

    f.open(argv[1]);
    if ( f.fail() )
        return (1);

    char            c;
    std::string     str;

    while(!f.eof() && f >> std::noskipws >> c)
        str += c;
    f.close();
    return ( replace(argv, str) );
}
