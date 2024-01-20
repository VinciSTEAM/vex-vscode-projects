#ifndef FUZZ_F_
#define FUZZ_F_

#include "vex.hpp"
#include "mitimer.hpp"
#include "vector"


class Fuzzbuzz
{
    protected:
        float plant;
        float ce;//control error
        float ci;//control error integral
        float D;//derivative
        float Ti;//time or sample time, sample size
        float k;//input of the function
        std::vector<float> input;
        bool first;
    public:
        Fuzzbuzz();
        bool firstime();
        virtual void combine();
        float fuzzier();
        float defuzz();
        std::vector<float> sorted(const std::vector<float> sorti);

        mitimer thyme;

        
};

#endif