#include "Grasm.h"

Grasm::Grasm():
    x(0.),
    id(0)
{
    for(int i = 0; i < 6; ++i)
    {
        deg[i] = 0;
    }
}

Grasm::~Grasm()
{
    delete[] deg;
}
Grasm::Grasm(double N_x, double N_id, int N_deg[6]):
    x(N_x),
    id(N_id)
{
    for(int i = 0; i < 6; ++i)
    {
        deg[i]=N_deg[i];
    }
}

Grasm::Grasm(const Grasm& g):
    x(g.x),
    id(g.id)
{
    for(int i = 0; i < 6; ++i)
    {
        deg[i] = g.deg[i];
    }
}

Grasm& Grasm::operator=(const Grasm& g)
{
    if (this == &g) return *this; // handle self assignment
    this->x = g.x;
    this->id = g.id;
    for(int i = 0; i < 6; ++i)
    {
        this->deg[i] = g.deg[i];
    }
    return *this;
}

Grasm& Grasm::operator*(const Grasm& g)
{
    bool nul = false;
    int signPow = 0;
    int shift = 0;
    int i =0;
    for(i = 0; i < 6; ++i)
    {
        shift += this->deg[i];
    }
    for(i = 0; i < 6; ++i)
    {
        if((this->deg[i]!=g.deg[i]) && (g.deg[i]!=0))
        {
            signPow += shift;
        }
        if(shift > 0)
        {
            --shift;
        }
    }
    for(i = 0; i < 6; ++i)
    {
        this->deg[i] += g.deg[i];
        if(this->deg[i] > 1)
        {
            nul = true;
        }
    }
    if(nul == true)
    {
        this->x = 0.;
    }
    else
    {
        this->x *= g.x;
        if(signPow % 2 ==1)
        {
            this->x = -this->x;
        }
        this->id += g.id;
    }
    return *this;
}
