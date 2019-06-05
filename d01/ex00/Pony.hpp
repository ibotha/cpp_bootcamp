#ifndef PONY_HPP
# define PONY_HPP
# include <string>

class Pony {
public:
    Pony(std::string name);
    void BeUsefull();
    ~Pony();
private:
    std::string m_Name;
	int m_Num;
};

#endif