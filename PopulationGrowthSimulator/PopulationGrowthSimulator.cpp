#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;
//Define constants
const int MAX_YEARS = 100;
//Enum for growth models
enum class GrowthModel{Exponential,Logisitic};
//Function to calculate population growth
double calculateGrowth(double population, double growthRate, double deathRate) {
	return population * (1 + growthRate);
}

//Logistic growth function
double logisticGrowth(double population, double carryingCapacity, double growthRate) {
	return growthRate * population * (1 - population / carryingCapacity);
}
//Function to simulate population growth
void simulateGrowth(double initialPopulation,double growthRate,double deathRate,GrowthModel model,int years,double carryingCapacity = 0){
	double population = initialPopulation;
	cout << "\nYear\tPopulation\n";
	for (int year = 0; year < years; year++) {
		cout << setw(4) << year+1<< "\t" << fixed << setprecision(2) << population << population << "\n";
		if (model == GrowthModel::Exponential) {
			population = calculateGrowth(population, growthRate, deathRate);
		}
		else {
			population += logisticGrowth(population, carryingCapacity, growthRate);
		}
	}

}

int main() {
	double initialPopulation, growthRate, deathRate, carryingCapacity;
	int years;
	GrowthModel model;

	//Input parameters
	cout << "Population Growth Simulator\n";
	cout << "------------------------------" << endl;
	cout << "Enter initial population: ";
	cin >> initialPopulation;
	cout << "Enter annual growth rate(%)" << endl;
	cin >> growthRate;
	cout << "Enter annual death rate(%)" << endl;
	cin >> deathRate;
	cout << "Select growth model(1=Exponential, 2=Logistic): ";
	int modelChoice;
	cin >> modelChoice;

	model = (modelChoice == 1) ?
		GrowthModel::Exponential :
		GrowthModel::Logisitic;
	if (model == GrowthModel::Logisitic) {
		cout << "Enter carryingCapacity: ";
		cin >> carryingCapacity;
	}
	else {
		cout << "Enter carryingCapacity: ";
		cin >> carryingCapacity;
	}
	cout << "Enter number of years: ";
	cin >> years;

	//Convert rates to decimals
	growthRate /= 100;
	deathRate /= 100;

	//simulate population growth
	simulateGrowth(initialPopulation, growthRate, deathRate, model, years, carryingCapacity);

	system("PAUSE");
	return 0;
}