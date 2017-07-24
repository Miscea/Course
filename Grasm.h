#ifndef GRASM_H
#define GRASM_H

class Grasm
{
    public:
        double x;
        double id;
        int deg[6];
        Grasm();
        virtual ~Grasm();
        Grasm(const Grasm& other);
        Grasm(double N_x, double N_id, int N_deg[6]);
        Grasm& operator=(const Grasm& g);
        Grasm& operator*(const Grasm& g);
};

#endif // GRASM_H
