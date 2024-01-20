#ifndef MYtimer
#define Mytimer

class mitimer{
    private:
        double timestart;
    public:
        mitimer();
        mitimer(double);
        void reset();
        int getTime() const;
};
#endif  