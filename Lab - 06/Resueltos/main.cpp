#include <thread>
#include <vector>
#include <chrono>
#include <iostream>

// Función de procesamiento secuencial
void FindPrimes(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {

    for (unsigned int x = start; x <= end; x += 2) {
        for (unsigned int y = 2; y < x; y++) {
            if ((x % y) == 0) {
                break;
            }
            else if ((y + 1) == x) {
                vect.push_back(x);
            }
        }
    }
}

// Función de procesamiento paralelo
void FindPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numThreads) {
    std::vector<std::thread> threadVect;
    unsigned int threadSpread = (end - start + 1) / numThreads;
    unsigned int newEnd = start + threadSpread - 1;

    // Crear lista de números primos para cada hilo
    for (unsigned int x = 0; x < numThreads; x++) {
        threadVect.emplace_back(FindPrimes, start, newEnd, std::ref(primVect));
        start += threadSpread;
        newEnd += threadSpread;
    }

    // Esperar a que todos los hilos terminen
    for (auto& t : threadVect) {
        t.join();
    }
}

int main(int argc, char *argv[]) {
    // Sin hilos
    std::vector<unsigned int> primVect;
    auto startTime = std::chrono::high_resolution_clock::now();
    FindPrimes(1, 1000000, primVect);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count();
    std::cout << "Execution Time (sin hilos): " << duration << " segundos" << std::endl;

    // Con hilos
    primVect.clear();
    startTime = std::chrono::high_resolution_clock::now();
    FindPrimesWithThreads(1, 1000000, 8);
    endTime = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count();
    std::cout << "Execution Time (con hilos): " << duration << " segundos" << std::endl;

    return 0;
}