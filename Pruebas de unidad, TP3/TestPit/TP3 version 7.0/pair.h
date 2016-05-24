#ifndef PAIR_H
#define PAIR_H
using namespace std;
template<typename T1,typename T2>

class Pair
{
public:
    T1 first;
    T2 second;
    Pair() : first(T1()), second(T2())
    {}
    Pair(T1 x ,T2 y){
    first=x;
    second=y;
    }
};

template <typename T1,typename T2>
bool operator==(const Pair<T1, T2>& x, const Pair<T1, T2>& y)
{
    return (x.first == y.first && x.second == y.second);
}


#endif // PAIR_H
