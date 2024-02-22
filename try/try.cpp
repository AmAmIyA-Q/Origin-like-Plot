#include <iostream>
#include <vector>
#include <random>

// Function to initialize the spin lattice randomly
void initializeLattice(std::vector<std::vector<int>>& lattice, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < size; i++) {
        std::vector<int> row;
        for (int j = 0; j < size; j++) {
            int spin = dis(gen) == 0 ? -1 : 1;
            row.push_back(spin);
        }
        lattice.push_back(row);
    }
}

// Function to calculate the total energy of the lattice
int calculateEnergy(const std::vector<std::vector<int>>& lattice) {
    int energy = 0;
    int size = lattice.size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int spin = lattice[i][j];
            int neighborSum = lattice[(i + 1) % size][j] + lattice[i][(j + 1) % size] +
                              lattice[(i - 1 + size) % size][j] + lattice[i][(j - 1 + size) % size];
            energy += -spin * neighborSum;
        }
    }

    return energy;
}

int main() {
    int latticeSize = 10;
    std::vector<std::vector<int>> lattice;

    initializeLattice(lattice, latticeSize);
    int energy = calculateEnergy(lattice);

    std::cout << "Initial energy: " << energy << std::endl;

    return 0;
}
