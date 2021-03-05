#ifndef FUNCTION_H
#define FUNCTION_H


template <typename R, typename P>
class Function
{
public:
    Function()
    {

    }

    virtual R calculate(const P& key) = 0;

    R operator()(const P key){
        return  calculate(key);
    }
};

#endif // FUNCTION_H
