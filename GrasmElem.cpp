#include "GrasmElem.h"

GrasmElem::GrasmElem():
    elems(1)
{}

GrasmElem::~GrasmElem()
{
    elems.erase(elems.begin(), elems.end());
}

GrasmElem::GrasmElem(const GrasmElem& E):
    elems(E.elems)
{}

GrasmElem& GrasmElem::operator=(const GrasmElem& E)
{
    if (this == &E) return *this; // handle self assignment
    for(unsigned int i = 0; i < this->elems.size(); ++i)
    {
        if(i < E.elems.size())
        {
          this->elems[i] = E.elems[i];
        }
        else
        {
            return *this;
        }
    }
    for(unsigned int i = this->elems.size(); i < E.elems.size(); ++i)
    {
        this->elems.push_back(E.elems[i]);
    }
    return *this;
}
GrasmElem& GrasmElem::operator+(const GrasmElem& E)
{
    int s = this->elems.size();
    bool push = true;
    for(unsigned int i = 0; i < E.elems.size(); ++i)
    {
        for(int j = 0; j < s; ++j)
        {
            if(E.elems[i].id == this->elems[j].id)
            {
                this->elems[j].x += E.elems[i].x;
                push = false;
                break;
            }
        }
        if(push == true)
        {
            this->elems.push_back(E.elems[i]);
        }
    }
    return *this;
}
GrasmElem& GrasmElem::operator*(const GrasmElem& E)
{
    GrasmElem sumtmp(E);
    GrasmElem sum;
    Grasm mult;
    for(unsigned int i = 0; i < this->elems.size(); ++i)
    {
        mult = this->elems[i];
        for(unsigned int j = 0; j < E.elems.size(); ++j)
        {
            sumtmp.elems[j] = mult * E.elems[j];
        }
        sum = sum + sumtmp;
    }
    *this = sum;
    return *this;
}
