#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;


Process::Process(int pid, std::string user, std::string command, float cpuUtil, std::string ram, long int upTime)
 : pid_(pid), user_(user), command_(command), cpuUtil_(cpuUtil), ram_(ram), upTime_(upTime)
{
}

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { return cpuUtil_; }

// TODO: Return the command that generated this process
string Process::Command() { return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return ram_; }

// TODO: Return the user (name) that generated this process
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return upTime_; }

// TODO: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const { return cpuUtil_ < a.cpuUtil_; }