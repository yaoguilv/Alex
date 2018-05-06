#ifndef COMPARABLE_H
#define COMPARABLE_H
class Comparable
{
public:
    virtual int compareTo(Comparable * that) = 0;
    virtual ~Comparable() {}
};
#endif
