#include <iostream>
#include <memory>
#include "figure.h"
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"
#include "dynamicArray.h"

int main() {
    try {
        DynamicArray<Figure<double>*> figures;

        std::cout << "=== Interactive Figure Creation ===" << std::endl;
        
        // Pentagon
        std::cout << "\nCreating Pentagon (enter 5 points as x y):" << std::endl;
        Pentagon<double>* pentagon = new Pentagon<double>();
        pentagon->read_vertices(std::cin);
        figures.add(pentagon);

        // Hexagon  
        std::cout << "\nCreating Hexagon (enter 6 points as x y):" << std::endl;
        Hexagon<double>* hexagon = new Hexagon<double>();
        hexagon->read_vertices(std::cin);
        figures.add(hexagon);

        // Octagon
        std::cout << "\nCreating Octagon (enter 8 points as x y):" << std::endl;
        Octagon<double>* octagon = new Octagon<double>();
        octagon->read_vertices(std::cin);
        figures.add(octagon);

        std::cout << "\n=== All Created Shapes ===" << std::endl;
        figures.PrintFigures();

        std::cout << "Total Area of all figures: " << figures.TotalArea() << std::endl;

        std::cout << "\n=== Figure Deletion ===" << std::endl;
        std::cout << "Enter index of figure to delete (0-" << figures.getSize()-1 << "): ";
        size_t index;
        std::cin >> index;
        
        if (index < figures.getSize()) {
            figures.DeleteFigure(index);
            std::cout << "Figure at index " << index << " deleted." << std::endl;
            
            std::cout << "\n=== Remaining Shapes ===" << std::endl;
            figures.PrintFigures();
            std::cout << "Total Area after deletion: " << figures.TotalArea() << std::endl;
        } else {
            std::cout << "Invalid index!" << std::endl;
        }

        for (size_t i = 0; i < figures.getSize(); ++i) {
            delete figures[i];
        }

        return 0;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}