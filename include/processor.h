#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  Processor();
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
  float user_;
  float nice_;
  float system_;
  float idle_;
  float iowait_;
  float irq_;
  float softirq_;
  float steal_;
  float guest_;
  float guest_nice_;
};

#endif