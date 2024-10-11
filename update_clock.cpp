#include <iostream>
#include <chrono>
#include <thread>

// Update routine function
void update(double deltaTime){
    // Game logic would go here
    std::cout << "Updating with deltaTime: " << deltaTime << " seconds\n";
}

int main(){
    using clock = std::chrono::steady_clock;

    auto previousTime = clock::now();
    while(true){
        auto currentTime = clock::now();
        
        // calculate elapsed time in seconds
        std::chrono::duration<double> elapsed = currentTime - previousTime;

        double deltaTime = elapsed.count();

        previousTime = currentTime;

        // call update function
        update(deltaTime);

        // sleep function to limit cpu use 
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // 60 FPS
    }
}