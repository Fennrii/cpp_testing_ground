#include <chrono>
/*#include <cmath>*/
#include <iostream>
#include <thread>
// Update routine function
void update(double deltaTime) {
  // Game logic would go here
  std::cout << "Updating with deltaTime: " << deltaTime << " seconds\n";
}



#include "mymath.h"
using namespace N;
using namespace std;
int main() {
  
  /*cout << "hello";*/

  Mymath math;
  
  for (double i = 102; i < 300; i++){
    std::cout << "5 root(" << i << ") = " << math.nroot(i,5) << "\n";
  }

  /*using clock = std::chrono::steady_clock;*/
  /**/
  /*auto previousTime = clock::now();*/
  /*while (true) {*/
  /*  auto currentTime = clock::now();*/
  /**/
  /*  // calculate elapsed time in seconds*/
  /*  std::chrono::duration<double> elapsed = currentTime - previousTime;*/
  /**/
  /*  double deltaTime = elapsed.count();*/
  /**/
  /*  previousTime = currentTime;*/
  /**/
  /*  // call update function*/
  /*  update(deltaTime);*/
  /**/
  /*  // sleep function to limit cpu use*/
  /*  std::this_thread::sleep_for(std::chrono::milliseconds(16)); // 60 FPS*/
  /*}*/
}

