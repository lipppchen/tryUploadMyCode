#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <thread>

using namespace std::chrono_literals;

void refreshForecast(std::map<std::string, int> forecastMap) {
  while (true) {
    for (auto &item : forecastMap) {
      item.second++;
      std::cout << item.first << "-" << item.second << std::endl;
    }
    std::this_thread::sleep_for(2000ms);
  }
}

int main(int argc, char *argv[]) {
  std::map<std::string, int> forecastMap{
      {"chongQin", 16}, {"shangHai", 13}, {"kunMing", 23}};
  std::thread bgWorker(refreshForecast, forecastMap);
  bgWorker.join();
  return 0;
}
