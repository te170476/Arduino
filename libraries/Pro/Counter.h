#ifndef Counter_h
#define Counter_h

class Counter {
  public:
    static Counter FromStepSize(int start, int end, int stepSize);
    static Counter FromStepSize(int start, int end, int stepSize, bool rotation);
    Counter(int start, int end, int stepLength);
    Counter(int start, int end, int stepLength, bool rotation);
    void inc();
    void dec();
    void step(int value);
    double state;
    
  private:
    int m_start;
    int m_end;
    int m_stepLength;
    int m_step;
    bool m_rotation;
    double setState();
};

#endif

