#include "processor.h"
#include <string>
#include <vector>

#include "linux_parser.h"

Processor::Processor()
{
  std::vector<std::string> cpuVector = LinuxParser::CpuUtilization();
  user_ = std::stof(cpuVector[0]);
  nice_ = std::stof(cpuVector[1]);
  system_ = std::stof(cpuVector[2]);
  idle_ = std::stof(cpuVector[3]);
  iowait_ = std::stof(cpuVector[4]);
  irq_ = std::stof(cpuVector[5]);
  softirq_ = std::stof(cpuVector[6]);
  steal_ = std::stof(cpuVector[7]);
  guest_ = std::stof(cpuVector[8]);
  guest_nice_ = std::stof(cpuVector[9]);
}

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  std::vector<std::string> cpuVector = LinuxParser::CpuUtilization();
  float user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
  user = std::stof(cpuVector[0]);
  nice = std::stof(cpuVector[1]);
  system = std::stof(cpuVector[2]);
  idle = std::stof(cpuVector[3]);
  iowait = std::stof(cpuVector[4]);
  irq = std::stof(cpuVector[5]);
  softirq = std::stof(cpuVector[6]);
  steal = std::stof(cpuVector[7]);
  guest = std::stof(cpuVector[8]);
  guest_nice = std::stof(cpuVector[9]);
  
  float PrevIdle = idle_ + iowait_;
  float Idle = idle + iowait;

  float PrevNonIdle = user_ + nice_ + system_ + irq_ + softirq_ + steal_;
  float NonIdle = user + nice + system + irq + softirq + steal;

  float PrevTotal = PrevIdle + PrevNonIdle;
  float Total = Idle + NonIdle;

  float totald = Total - PrevTotal;
  float idled = Idle - PrevIdle;

  float CPU_Percentage = (totald - idled)/totald;
  
  
  return CPU_Percentage; 
}