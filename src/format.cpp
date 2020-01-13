#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) {
  long hours, minutes;
  string hr, min ,sec;
  minutes = seconds / 60;
  seconds = seconds % 60;
  sec = (seconds < 10) ? ("0" + std::to_string(seconds)) : std::to_string(seconds);
  hours = minutes / 60;
  minutes = minutes % 60;
  min = (minutes < 10) ? ("0" + std::to_string(minutes)) : std::to_string(minutes);
  hr = (hours < 10) ? ("0" + std::to_string(hours)) : std::to_string(hours);

  return hr + ":" + min + ":" + sec;
}