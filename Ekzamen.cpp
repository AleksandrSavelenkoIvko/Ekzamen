#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Rabota {
	string name;
	string prior;
	string data;
	string time;
	string docum;
};

string* mas_file = new string[99];
int kol_file = 0;

void doc(Rabota sol) {
cout << "\nВведите название дела  ";
cin.ignore();
getline(cin, sol.name);
mas_file[kol_file] = sol.name;
kol_file++;
cout << "\nВведите приоритет ";
getline(cin, sol.prior);
cout << "\nВведите дату ";
getline(cin, sol.data);
cout << "\nВведите время  ";
getline(cin, sol.time);
cout << "\nВведите описание к делу ";
getline(cin, sol.docum);
ofstream file("./document/" + sol.name + ".txt");
if (file) {
	file << "Название: " << sol.name;
	file << "Приоритет: " << sol.prior;
	file << "Дата: " << sol.data;
	file << "Время: " << sol.time;
	file << "Описание: " << sol.docum;
	cout << "Дело успешно добавлено и сохранено в список ";
}
else cout << "EROR 404 ";
}
void doc2(Rabota sol) {
	string name2;
	cout << "Введите название дела котороенужно удалить ";
	cin.ignore();
	getline(cin, name2);
	if (remove(("./document/" + name2 + ".txt").c_str()) != 0) {
		cout << "Ошибка при удалении " << endl;
	}
	else cout << "Дело успешно удалено " << endl;
}
void doc3(Rabota sol) {
	string name3;
	cout << "Введите название дела чтобы начать его редактировать ";
	cin >> name3;
	ifstream file1("./document/" + name3 + ".txt");
	if (!file1) {
		cout << "Файл не найден ";
		exit(0);
	}
cout << "\nВведите название дела  ";
cin.ignore();
getline(cin, sol.name);
cout << "\nВведите приоритет ";
cin.ignore();
getline(cin, sol.prior);
cout << "\nВведите дату ";
getline(cin, sol.data);
cout << "\nВведите время  ";
getline(cin, sol.time);
cout << "\nВведите описание к делу ";
getline(cin, sol.docum);
ofstream file("./document/" + name3 + ".txt");
if (file) {
	file << "Название: " << sol.name;
	file << "Приоритет: " << sol.prior;
	file << "Дата: " << sol.data;
	file << "Время: " << sol.time;
	file << "Описание: " << sol.docum;
	file.close();
	cout << "Дело успешно добавлено и сохранено в список ";
}
else cout << "EROR 404 ";
}
void doc4(Rabota sol) {
	int res;
	std::cout << "Выберите по чему будет произведен поиск:\n[1]-По названию\n[2]-По приоритету\n[3]-По дате\n[4]-По времени\n[5]-По описанию\nВаш выбор: ";
	std::cin >> res;
	switch (res) {
	case 1: {
		std::string name2;
		std::cout << "Введите название дела ";
		std::cin >> name2;
		ifstream file1("./document/" + name2 + ".txt", ios::in);
		if (!file1) {
			cout << "Файл не найден";
			exit(0);
		}
		cout << endl;
		cout << "\t\t\t\t\tBaше дело";
		cout << endl;
		char txt[256];
		while (!file1.eof()) {
			file1.getline(txt, 256);
			if (file1) {
				cout << txt << endl;
			}
		}
		break;
	}
	case 2: {
		string name2, line;
		cout << "Введите приоритет ";
		cin.ignore();
		cin >> name2;
		for (int a = 0; a < kol_file; a++) {
			ifstream file2("./document/" + mas_file[a] + ".txt", ios::in);
			while (file2 >> line) {
				if (line == name2) {
					char txt[256];
					cout << "Приоритет был найден в файле" << mas_file[a];
					file2.close();
					file2.open(". / document / " + mas_file[a] + ".txt", ios::in);
					while (!file2.eof()) {
						file2.getline(txt, 256);
						if (file2) {
							cout << endl;
							cout << txt << endl;
						}
					}
				}
			}
		}
		break;
	}
	}
}
	int main(){
		setlocale(LC_ALL, "RUS");
		Rabota sol;
		int res;
		do {
			string mas[99];
			cout << "\n\n\t\t\t\t\tСписок ваших дел\nВыберите действие:\n[1]Добавить дело\n[2]Удалить\n[3]Редактировать\n[4]Поиск\n[5]Вывод дела на экран\n[6]Выход\nВаш выбор: ";
			cin >> res;
			switch (res) {
			case 1: {
				doc(sol);
				break;
			}
			case 2: {
				doc2(sol);
				break;
			}
			case 3: {
				doc3(sol);
				break;
			}
			case 4: {
				doc4(sol);
				break;
			}
			/*case 5:*/
			}
		} while (res != 6);
	}