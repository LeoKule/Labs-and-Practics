#include <iostream>
#include <vector>
class Components {
private:
	std::string m_age;
	std::string m_mileage;
	std::string m_EngineName;
	std::string m_hp;
public:
	Components(std::string age, std::string mileage,std::string EngineName,std::string hp) {
		m_age = age;
		m_mileage = mileage;
		m_hp = hp;
		m_EngineName = EngineName;
	}
	std::string Age() {
		return m_age;
	}
	std::string Engine() {
		return m_EngineName;
	}
	std::string Mileage() {
		return m_mileage;
	}
	std::string HP() {
		return m_hp;
	}
};
class Car {
private:
	std::string m_name;
	std::string m_model;
	std::vector<Components*> m_components;
public:
	Car(std::string name, std::string model) {
		m_name = name;
		m_model = model;
	}
	void AddComponents(Components*& components) {
		m_components.push_back(components);
	}
	void PrintComponents() {
		for (size_t i = 0; i < m_components.size(); i++) {
			std::cout << "Название машины" << ": ";
			std::cout << m_name << std::endl;
			std::cout << "Модель машины" << ": ";
			std::cout << m_model << std::endl;
			std::cout << "Возраст машины" << ": ";
			std::cout << m_components[i]->Age() << std::endl;
			std::cout << "Пробег машины" << ": ";
			std::cout << m_components[i]->Mileage() << std::endl;
			std::cout << "Название двигателя" << ": ";
			std::cout << m_components[i]->Engine() << std::endl;
			std::cout << "Мощность машины в лошадиных силах" << ": ";
			std::cout << m_components[i]->HP() << std::endl;

		}
	}
};

int main() {
	setlocale(LC_ALL, "Rus");
	Car* car = new Car("Tesla", "Plaid");
	//car->PrintComponents();
	Components* components1 = new Components("12", "110 000", "Electric", "1020");
	car->AddComponents(components1);
	car->PrintComponents();
	delete car;
}