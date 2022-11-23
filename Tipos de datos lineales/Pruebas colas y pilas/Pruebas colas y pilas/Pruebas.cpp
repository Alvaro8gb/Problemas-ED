#include <iostream>
#include <queue>
#include <stack>

using namespace std;
double aplicar(char x, double op1, double op2) {
	if (x == '+')return op1 + op2;
	else if (x == '-')return op1 - op2;
	else if (x == '*') return op1 * op2;
	else if (x == '/') return op1 / op2;
}
double evaluar(string const& expresion) { // "853-/72+*"
	stack<int> pila;
	for (char c : expresion) {
		if (isdigit(c))
			pila.push(c - '0');
		else {
			double op2 = pila.top(); pila.pop();
			double op1 = pila.top(); pila.pop();
			pila.push(aplicar(c, op1, op2));
		}
	}
	return pila.top();
}
void probandoPila() {
	stack <int> pila;
	for (int i = 0; i < 5; i++) pila.push(i);

	while (!pila.empty()) {
		cout << pila.top() << " ";
		pila.pop();
	}
	cout << endl;
}
void probandoCola() {
	queue <int> cola;

	for (int i = 0; i < 5; i++) cola.push(i);


	while (!cola.empty()) {
		cout << cola.front() << " ";
		cola.pop();
	}
	cout << endl;
}

int main() {
	
	string  cad = "824*/23+*51*-",cad2 = "853-/72+*";
	cout << evaluar(cad) << endl;


	return 0;
}