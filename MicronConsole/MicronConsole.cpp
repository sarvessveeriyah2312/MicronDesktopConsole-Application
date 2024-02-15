#include <iostream>
#include <vector>
#include <string>
#include <list>

class Recipe;

class Machine {
public:
    std::string name;
    int id;
    std::string area;
    std::string status;
    std::list<std::string> recipe;

    Machine(const std::string& name, int id, const std::string& area, const std::string& status, const std::list<std::string>& recipe)
        : name(name), id(id), area(area), status(status), recipe(recipe) {}
};

class MachineManager {
private:
    std::vector<Machine> machines;

public:
    void addMachine(const Machine& machine) {
        machines.push_back(machine);
    }

    std::vector<Machine> queryByArea(const std::string& targetArea) const {
        std::vector<Machine> result;
        for (const auto& machine : machines) {
            if (machine.area == targetArea) {
                result.push_back(machine);
            }
        }
        return result;
    }

    std::vector<Machine> queryByStatusAndArea(const std::string& targetArea, const std::string& targetStatus) const {
        std::vector<Machine> result;
        for (const auto& machine : machines) {
            if (machine.area == targetArea && machine.status == targetStatus) {
                result.push_back(machine);
            }
        }
        return result;
    }

    std::vector<Machine> queryRecipesByMachine(const std::string& targetMachine) const {
        std::vector<Machine> result;
        for (const auto& machine : machines) {
            if (machine.name == targetMachine) {
                result.push_back(machine);
            }
        }
        return result;
    }
};

void displayMenu() {
    std::cout << "\nSelect Your Queries\n";
    std::cout << "1. Query machines by area\n";
    std::cout << "2. Query machines by status in an area\n";
    std::cout << "3. Query recipes in a machine\n";
    std::cout << "4. Exit\n\n";
    std::cout << "Enter your choice: ";
}

int main() {
    MachineManager machineManager;

    machineManager.addMachine(Machine("Machine1", 1, "Assembly", "up", { "RecipeA", "RecipeB" }));
    machineManager.addMachine(Machine("Machine2", 2, "Test", "down", { "RecipeB ", "RecipeC" }));
    machineManager.addMachine(Machine("Machine3", 3, "Production", "maintenance", { "RecipeB ", "RecipeC" }));
    machineManager.addMachine(Machine("Machine4", 4, "Assembly", "up", { "RecipeB ", "RecipeC" }));
    machineManager.addMachine(Machine("Machine5", 5, "Test", "down", { "RecipeB ", "RecipeC" }));
    machineManager.addMachine(Machine("Machine6", 6, "Production", "maintenance", { "RecipeC", "RecipeD" }));
    machineManager.addMachine(Machine("Machine7", 7, "Assembly", "up", { "RecipeB ", "RecipeC" }));
    machineManager.addMachine(Machine("Machine8", 8, "Test", "down", { "RecipeB ", "RecipeC" }));
    machineManager.addMachine(Machine("Machine9", 9, "Production", "up", { "RecipeF", "RecipeG" }));
    machineManager.addMachine(Machine("Machine10", 10, "Assembly", "up", { "RecipeB ", "RecipeC" }));

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string targetArea;
            std::cout << "Enter the target area: ";
            std::cin >> targetArea;

            auto machinesByArea = machineManager.queryByArea(targetArea);
            if (machinesByArea.empty()) {
                std::cout << "Record Not Found\n\n";
            }
            else {
                for (const auto& machine : machinesByArea) {
                    std::cout << "Area: " << machine.area << ", Machine: " << machine.name << ", ID: " << machine.id << "\n";
                }
            }
            break;
        }

        case 2: {
            std::string targetArea, targetStatus;
            std::cout << "Enter the target area: ";
            std::cin >> targetArea;
            std::cout << "Enter the target status: ";
            std::cin >> targetStatus;

            auto machinesByStatusAndArea = machineManager.queryByStatusAndArea(targetArea, targetStatus);
            if (machinesByStatusAndArea.empty()) {
                std::cout << "Record Not Found\n\n";
            }
            else {
                for (const auto& machine : machinesByStatusAndArea) {
                    std::cout << "Area: " << machine.area << ", Machine: " << machine.name << ", Status: " << machine.status << "\n";
                }
            }
            break;
        }

        case 3: {
            std::string targetMachine;
            std::cout << "Enter the target machine: ";
            std::cin >> targetMachine;

            auto recipesByMachine = machineManager.queryRecipesByMachine(targetMachine);
            if (recipesByMachine.empty()) {
                std::cout << "Record Not Found\n\n";
            }
            else {
                for (const auto& machine : recipesByMachine) {
                    std::cout << "Machine: " << machine.name << ", ID: " << machine.id << ", Recipes:\n";
                    for (const auto& recipe : machine.recipe) {
                        std::cout << "  " << recipe << "\n";
                    }
                }
            }
            break;
        }

        case 4:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 4);

    return 0;
}
