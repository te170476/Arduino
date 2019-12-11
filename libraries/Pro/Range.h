#ifndef Range_h
#define Range_h

class Range{
  public:
    Range(int start, int end);
    void inc();
    void dec();
    void step(int value);
    int state;
    int length;
    
  private:
    int m_start;
    int m_end;
};

#endif

