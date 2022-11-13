#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//creating class Data Carrier with method to set amount of GB for our devices

class dataCarrier {
protected:
	int storageAmount;

private:
	int option;

public:
	void SetStorageAmount() {
		cout << "����i�� ����� ���'��i ���i�" << endl;
		cout << "1 - 256 ��, 2 - 512 ��, 3 - 1 ��, 4 - 2 ��" << endl;
		cin >> option;
		if (option == 1) {
			storageAmount = 256;
		}
		else if (option == 2) {
			storageAmount = 512;
		}
		else if (option == 3) {
			storageAmount = 1024;
		}
		else if (option == 4) {
			storageAmount = 2048;
		}
		else {
			cout << "����i�� ���� i� ��������� ���i�" << endl;
			exit(0);
		}
	}

	int GetStorageAmount() {
		return storageAmount;
	}


};

//creating class Hard Drive that is related to class dataCarrier and takes GB size for object of Hard Drive class

class hardDrive: public dataCarrier {
public:

	//constructor 
	hardDrive() {
		cout << "����i�� ����� �i��� �i��������: " << endl;
		cin >> hardFirm;
		cout << "����i�� �����i��� ��������� ��������: " << endl;
		cin >> rotationSpeed;	
	}

	//returning name of the firm
	string GetHardFirmName() {
		return hardFirm;
	}

	//returning amount of revolutions per minute
	int GetRotationSpeed() {
		return rotationSpeed;
	}

	//making friend function to overload >> operator
	friend istream& operator >>(istream& is, hardDrive& drive);

private:
	string hardFirm;
	int rotationSpeed;

};

//creating class Optical Disk that is related to class dataCarrier and takes GB size for object of Optical Disk class

class opticalDisk: public dataCarrier {
public:

	//constructor 
	opticalDisk() {
		cout << "����i�� ����� �i��� ��������� �����: " << endl;
		cin >> opticalFirm;
		cout << "����i�� �i���i��� ���i���i�: " << endl;
		cin >> amountOfCylinders;
	}

	//returning name of the firm
	string GetOpticalFirmName() {
		return opticalFirm;
	}

	//returning amount of cylinders in optical disk
	int GetAmountOfCylinders() {
		return amountOfCylinders;
	}

	//making friend function to overload >> operator
	friend istream& operator >>(istream& is, opticalDisk& optical);

private:
	string opticalFirm;
	int amountOfCylinders;
};

// overloading << and >> operators
ostream& operator<<(ostream& out, hardDrive& drive) {
	out << "����� �i���: " << drive.GetHardFirmName() << "\t�����i��� ��/��: " <<  drive.GetRotationSpeed() << "\t����i� ��: " << drive.GetStorageAmount();
	return out;
}

istream& operator >>(istream& input, hardDrive& drive) {
	input >> drive.hardFirm >> drive.rotationSpeed >> drive.storageAmount;
	return input;
}

ostream& operator<<(ostream& out, opticalDisk& optical) {
	out << "����� �i���: " << optical.GetOpticalFirmName() << "\t�i���i��� ���i���i�: " << optical.GetAmountOfCylinders() << "\t����i� ��: " << optical.GetStorageAmount();
	return out;
}

istream& operator >>(istream& input, opticalDisk& optical) {
	input >> optical.opticalFirm >> optical.amountOfCylinders >> optical.storageAmount;
	return input;
}





int main() {

	setlocale(LC_ALL, "Ukrainian");

	//creating class objects and setting storage amount for each of them

	hardDrive hardD;

	hardD.SetStorageAmount();

	opticalDisk opticalD;

	opticalD.SetStorageAmount();

	//creating variable that keeps info about path to the file
	//"RecordData.txt" means that our file will be created in the project folder automatically
	string path = "RecordData.txt";
	
	//using fsrteam to able to input and output info about our objects
	fstream record;

	record.open(path, fstream::in | fstream::out | fstream::app);

	//checking if the path to our file is correct
	//if it's not correct, then we output message about an error
	if (!record.is_open()) {
		cout << "�� ������� �i������ ����" << endl;
	}
	//if the path is correct, we continue working and input info about our objects into file
	else {
		cout << "����� ��i������ ���i���" << endl;
		record << "�i�������" << "\n" << hardD << endl;
		record << "�������� ����" << "\n" << opticalD << endl;
	}

	//closing file
	record.close();


	
	//end of the program
	return 0;
}