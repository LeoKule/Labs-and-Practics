#include <iostream>

class Triangle
{
private:
	double m_A = 0;
	double m_B = 0;
	double m_C = 0;
	double p = 0;
	double y = 0;
public:
	Triangle(double A, double B, double C) {
		m_A = A;
		m_B = B;
		m_C = C;
	}
	~Triangle(){}

	bool Existence() {
		if ((m_A + m_B > m_C && m_B + m_C > m_A && m_C + m_A > m_B) && ((m_A > 0) && (m_B > 0) && (m_C > 0))) {
			std::cout << "Your triangle exists!" << std::endl;
			return true;
		}
		else {
			std::cout << "Your triangle not exists!" << std::endl;
			return false;
		}


	}

	double S_Triangle() {
		p = (m_A + m_B + m_C) / 2;
		y = p * ((p - m_A) * (p - m_B) * (p - m_C));
		return pow(y,0.5);
	}
};

int main() {
	Triangle triangle(5, 7, 10);
	triangle.Existence();	
	std::cout << triangle.S_Triangle() << std::endl;
}