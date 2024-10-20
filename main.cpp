#include <iostream>
#include <string>

class Logger {
public:
    static void log(const std::string& message) {
        std::cout << message << std::endl;
    }
};

struct Car {
    std::string make;
    std::string model;
    int year;
    double mileage;

  
    Car() : make("Unknown"), model("Unknown"), year(0), mileage(0.0) {
        Logger::log("Default constructor called");
    }

    
    Car(const std::string& make, const std::string& model, int year, double mileage)
        : make(make), model(model), year(year), mileage(mileage) {
        Logger::log("Parameterized constructor called");
    }


    Car(const Car& other)
        : make(other.make), model(other.model), year(other.year), mileage(other.mileage) {
        Logger::log("Copy constructor called");
    }


    ~Car() {
        Logger::log("Destructor called");
    }


    void setMake(const std::string& make) {
        this->make = make;
    }

    void setModel(const std::string& model) {
        this->model = model;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setMileage(double mileage) {
        this->mileage = mileage;
    }


    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    int getYear() const {
        return year;
    }

    double getMileage() const {
        return mileage;
    }


    void displayDetails() const {
        Logger::log("Car Details:");
        Logger::log("Make: " + make);
        Logger::log("Model: " + model);
        Logger::log("Year: " + std::to_string(year));
        Logger::log("Mileage: " + std::to_string(mileage));
    }


    void drive(double distance) {
        mileage += distance;
        Logger::log("Car driven for " + std::to_string(distance) + " miles. New mileage: " + std::to_string(mileage));
    }
};

int main() {
    Car car1;
    car1.displayDetails();

    Car car2("Toyota", "Camry", 2020, 15000.0);
    car2.displayDetails();

    Car car3 = car2;
    car3.displayDetails();

    car2.drive(100.0);
    car2.displayDetails();

    return 0;
}
