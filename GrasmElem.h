#ifndef GRASMELEM_H
#define GRASMELEM_H
#include "Grasm.h"
#include<vector>

using namespace std;


class GrasmElem
{
    public:
        vector<Grasm> elems;
        GrasmElem();
        virtual ~GrasmElem();
        GrasmElem(const GrasmElem& E);
        GrasmElem& operator=(const GrasmElem& E);
        GrasmElem& operator+(const GrasmElem& E);
        GrasmElem& operator*(const GrasmElem& E);
    protected:
    private:
};

#endif // GRASMELEM_H
