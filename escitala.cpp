#include <iostream>
#include <string>
#include <iomanip>

//Función para obtener las posibles combinaciones de celda
void posComb(const std::string &msg)
{

    int length = msg.length();
    int col = length / 2 + 1;
    int a = col;
    int i = 2;
    int b = a;
    std::cout << "Possible Combinations: " << std::endl;
    while (i <= b)
    {
        while ((i * b >= length))
        {
            if (i == b)
            {
                std::cout << std::right << std::setw(7)
                          << i << " x " << b << std::endl;
                --b;
            }
            else if (i * b <= length + i)
            {
                std::cout << std::right << std::setw(7)
                          << i << " x " << b << std::endl;
                std::cout << std::right << std::setw(7)
                          << b << " x " << i << std::endl;
                --b;
            }
            else
                --b;
        }
        ++i;
        --a;
    }
}

template <typename T>
T encode(T msg, int col, int row)
{
    T strCode;
    if (col * row <= msg.length())
    {
        std::cout << "Wrong size";
    }
    else
    {
        for (int i{0}; i < col; ++i)
        {
            int k = i;
            for (int j{0}; j < row; ++j)
            {
                if (k > msg.length())
                    strCode.push_back(' ');
                else
                    strCode.push_back(msg[k]);
                k = k + col;
            }
        }
    }
    return strCode;
}

template <typename T>
T decode(T code, int row, int col)
{
    T strMsg = encode(code, col, row);
    return strMsg;
}

int main()
{

    unsigned short int col, row, opt;
    std::cout << "Choose an option" << std::endl;
    std::cout << std::right << std::setw(12)
              << "Encode (1)" << std::endl;
    std::cout << std::right << std::setw(12)
              << "Decode (2)" << std::endl;
    std::cout << "Option: ";
    std::cin >> opt;
    std::cin.ignore();

    if (opt == 1)
    {
        std::string msg;
        std::cout << "Message: ";
        (void)getline(std::cin, msg);
        //posComb(msg);
        std::cout << "Columns: ";
        std::cin >> col;
        std::cout << "Rows: ";
        std::cin >> row;
        std::cout << "Code: ";
        std::string code = encode(msg, col, row);
        std::cout << code;
    }
    else if (opt == 2)
    {
        std::string code;
        std::cout << "Code: ";
        (void)getline(std::cin, code);
        //posComb(code);
        std::cout << "Columns: ";
        std::cin >> col;
        std::cout << "Rows: ";
        std::cin >> row;
        std::cout << "Message: ";
        std::string msg = decode(code, col, row);
        std::cout << msg;
    }
    return 0;
}
