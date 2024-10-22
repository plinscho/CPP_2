#pragma once
#include <iostream>
#include <stdexcept>

class Form {
    public:
    Form();
    Form(const std::string&, int, int);
    Form(const Form &copy);
    Form &operator=(const Form &rhs);
    ~Form();

    const std::string   getName() const ;
    int                 getGradeSign() const ;
    int                 getGradeExe() const ;

    class GradeTooHighExeption : public std::range_error {
        public:
        GradeTooHighExeption(const std::string&);
    };
    class GradeTooLowExeption : public std::range_error {
        public:
        GradeTooLowExeption(const std::string&);
    };

    private:
    const std::string   _name;
    bool                _signed;
    const int           _gradeSign;
    const int           _gradeExe;
};
