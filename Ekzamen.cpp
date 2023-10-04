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
cout << "\n������� �������� ����  ";
cin.ignore();
getline(cin, sol.name);
mas_file[kol_file] = sol.name;
kol_file++;
cout << "\n������� ��������� ";
getline(cin, sol.prior);
cout << "\n������� ���� ";
getline(cin, sol.data);
cout << "\n������� �����  ";
getline(cin, sol.time);
cout << "\n������� �������� � ���� ";
getline(cin, sol.docum);
ofstream file("./document/" + sol.name + ".txt");
if (file) {
	file << "��������: " << sol.name;
	file << "���������: " << sol.prior;
	file << "����: " << sol.data;
	file << "�����: " << sol.time;
	file << "��������: " << sol.docum;
	cout << "���� ������� ��������� � ��������� � ������ ";
}
else cout << "EROR 404 ";
}
void doc2(Rabota sol) {
	string name2;
	cout << "������� �������� ���� ������������ ������� ";
	cin.ignore();
	getline(cin, name2);
	if (remove(("./document/" + name2 + ".txt").c_str()) != 0) {
		cout << "������ ��� �������� " << endl;
	}
	else cout << "���� ������� ������� " << endl;
}
void doc3(Rabota sol) {
	string name3;
	cout << "������� �������� ���� ����� ������ ��� ������������� ";
	cin >> name3;
	ifstream file1("./document/" + name3 + ".txt");
	if (!file1) {
		cout << "���� �� ������ ";
		exit(0);
	}
cout << "\n������� �������� ����  ";
cin.ignore();
getline(cin, sol.name);
cout << "\n������� ��������� ";
cin.ignore();
getline(cin, sol.prior);
cout << "\n������� ���� ";
getline(cin, sol.data);
cout << "\n������� �����  ";
getline(cin, sol.time);
cout << "\n������� �������� � ���� ";
getline(cin, sol.docum);
ofstream file("./document/" + name3 + ".txt");
if (file) {
	file << "��������: " << sol.name;
	file << "���������: " << sol.prior;
	file << "����: " << sol.data;
	file << "�����: " << sol.time;
	file << "��������: " << sol.docum;
	file.close();
	cout << "���� ������� ��������� � ��������� � ������ ";
}
else cout << "EROR 404 ";
}
void doc4(Rabota sol) {
	int res;
	std::cout << "�������� �� ���� ����� ���������� �����:\n[1]-�� ��������\n[2]-�� ����������\n[3]-�� ����\n[4]-�� �������\n[5]-�� ��������\n��� �����: ";
	std::cin >> res;
	switch (res) {
	case 1: {
		std::string name2;
		std::cout << "������� �������� ���� ";
		std::cin >> name2;
		ifstream file1("./document/" + name2 + ".txt", ios::in);
		if (!file1) {
			cout << "���� �� ������";
			exit(0);
		}
		cout << endl;
		cout << "\t\t\t\t\tBa�� ����";
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
		cout << "������� ��������� ";
		cin.ignore();
		cin >> name2;
		for (int a = 0; a < kol_file; a++) {
			ifstream file2("./document/" + mas_file[a] + ".txt", ios::in);
			while (file2 >> line) {
				if (line == name2) {
					char txt[256];
					cout << "��������� ��� ������ � �����" << mas_file[a];
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
			cout << "\n\n\t\t\t\t\t������ ����� ���\n�������� ��������:\n[1]�������� ����\n[2]�������\n[3]�������������\n[4]�����\n[5]����� ���� �� �����\n[6]�����\n��� �����: ";
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