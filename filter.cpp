#include "filter.h"

std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void readAllPool(std::vector<strVector> &pool)
{
    for(std::string line; std::getline(std::cin, line);)
    {
        std::vector<std::string> v = split(line, '\t');
        pool.push_back(split(v.at(0), '.'));
    }
}

void writeAllPool(std::vector<strVector> &pool)
{
    for(std::vector<std::vector<std::string> >::const_iterator ip = pool.cbegin(); ip != pool.cend(); ++ip)
    {
        for(std::vector<std::string>::const_iterator ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part)
        {
            if (ip_part != ip->cbegin())
            {
                std::cout << ".";

            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

void writeIpToConsole(strVector& tmp)
{
    std::cout << tmp.at(0) << "."
              << tmp.at(1) << "."
              << tmp.at(2) << "."
              << tmp.at(3) << std::endl;
}

void filter(uint8_t firstByte, std::vector<strVector> &pool)
{
    std::string str = std::to_string(firstByte);
    std::for_each(pool.begin(), pool.end(),
                      [=](strVector tmp)
                        {
                            if(tmp.at(0)==str)
                                 writeIpToConsole(tmp);
                        });

}

void filter(uint8_t firstByte, uint8_t secondByte, std::vector<strVector> &pool)
{
    std::string str = std::to_string(firstByte);
    std::string str2 = std::to_string(secondByte);
    std::for_each(pool.begin(), pool.end(),
                      [=](strVector tmp)
                       {
                           if(tmp.at(0)==str && tmp.at(1)==str2)
                                writeIpToConsole(tmp);
                       });
}

void filterAny(uint8_t anyByte, std::vector<strVector> &pool)
{
    std::string str = std::to_string(anyByte);
    std::for_each(pool.begin(), pool.end(),
                      [=](strVector tmp)
                       {
                           if(tmp.at(0)==str ||
                              tmp.at(1)==str ||
                              tmp.at(2)==str ||
                              tmp.at(3)==str   )
                                writeIpToConsole(tmp);
                       });
}

void reverseIpSort(std::vector<strVector> &pool)
{
    sort(pool.begin(), pool.end(),
            [](strVector tmp, strVector tmp2)  {
                if(atoi(tmp.at(0).c_str()) > atoi(tmp2.at(0).c_str()))
                    return true;
                else if(atoi(tmp.at(0).c_str()) == atoi(tmp2.at(0).c_str())
                        && atoi(tmp.at(1).c_str()) > atoi(tmp2.at(1).c_str()))
                {
                    return true;
                }
                else if(atoi(tmp.at(1).c_str()) == atoi(tmp2.at(1).c_str())
                        && atoi(tmp.at(2).c_str()) > atoi(tmp2.at(2).c_str()))
                {
                    return true;
                }
                else if(atoi(tmp.at(2).c_str()) == atoi(tmp2.at(2).c_str())
                        && atoi(tmp.at(3).c_str()) > atoi(tmp2.at(3).c_str()))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            });
    writeAllPool(pool);
}
