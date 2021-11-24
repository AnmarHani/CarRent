#include <stdio.h>

FILE* cdbPtr; //customer-database-pointer
FILE* vdbPtr; //vehicle-database-pointer

char customerFileName[] = { "Customer_Database.txt" };
char VehicleFileName[] = { "Vehicle_Database.txt" };

int customerId = 0;
char customerName[30];
int customerNumber = 0;

int vehicleModelYear, vehiclePlateNumber, vehicleRentedBy =0;
char vehicleCompanyMake[30], vehicleModelName[30];

bool loggedIn = false;
int loggedID;

bool isSeller = false;

int customerCounter = 0;

void registerCustomer();
void loginCustomer();

void searchCustomerMenu();
void searchCustomer();
void customerMenu();

void vehicleSearchMenu();
void createVehicle();
void vehicleMenu();


void mainMenu();

void sellerMenu();
void seller();


int main() {

	while (true) {
		mainMenu();
	}
}

void registerCustomer() {
	fopen_s(&cdbPtr, customerFileName, "a");
		printf("Enter the ID (Min 5 digits, Needed to login), Name (Max 30), and Phone number (Min/Max 9 digits): ");
		scanf_s("%d %s %d", &customerId, customerName, 30, &customerNumber);
		fprintf(cdbPtr, "%d %s %d\n", customerId, customerName, customerNumber);
	fclose(cdbPtr);
	loginCustomer();
}

void searchCustomerMenu() {
	printf("1: Search For One Customer\n");
	printf("2: See All Customers\n");
	printf("3: Back To Main Menu\n");
	printf("Enter the number: \n");
	int choice;
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		searchCustomer();
		break;
	case 2:
		fopen_s(&cdbPtr, customerFileName, "r");
			printf("%-10s%-13s%s\n", "ID", "Name", "Phone Number");
			fscanf_s(cdbPtr, "%d %s %d", &customerId, customerName, 30, &customerNumber);

			while (!feof(cdbPtr)) {
				printf("%-10d %-13s %d\n", customerId, customerName, customerNumber);

				fscanf_s(cdbPtr, "%d %s %d", &customerId, customerName, 30, &customerNumber);
			}
		fclose(cdbPtr);
		break;
	case 3:
	 	mainMenu();
		break;
	default:
		searchCustomerMenu();
		break;
	}

}
void searchCustomer() {
	printf("1: Search By ID\n");
	printf("2: Search By Name\n");
	printf("3: Search By Phone Number (Dont Put (0) in the Start)\n");
	printf("Enter the number: \n");
	int choice;

	scanf_s("%d", &choice);

	int ID, Number;
	char Name[30];
	switch (choice) {
	case 1:
		printf("Please Enter The ID: ");
		scanf_s("%d", &ID);
		fopen_s(&cdbPtr, customerFileName, "r");
			while (!feof(cdbPtr)) {
				if (customerId == ID) {
					printf("ID Name Number\n%d %s %d\n", customerId, customerName, customerNumber);
				}
				fscanf_s(cdbPtr, "%d %s %d", &customerId, customerName, 30, &customerNumber);
			}
		fclose(cdbPtr);
		break;
	case 2:
		printf("Please Enter The Name: ");
		scanf_s("%s", Name, 30);
		fopen_s(&cdbPtr, customerFileName, "r");
			while (!feof(cdbPtr)) {
				if (customerName == Name){
					printf("ID Name Number\n%d %s %d\n", customerId, customerName, customerNumber);
				}
				fscanf_s(cdbPtr, "%d %s %d", &customerId, customerName, 30, &customerNumber);

			}
		fclose(cdbPtr);
		break;
	case 3:
		printf("Please Enter The Number: ");
		scanf_s("%d", &Number);
		fopen_s(&cdbPtr, customerFileName, "r");
			while (!feof(cdbPtr)) {
				if (customerNumber == Number) {
					printf("ID Name Number\n%d %s %d\n", customerId, customerName, customerNumber);
				}
				fscanf_s(cdbPtr, "%d %s %d", &customerId, customerName, 30, &customerNumber);

			}
		fclose(cdbPtr);
		break;
	default:
		searchCustomer();
		break;
	}
}

void mainMenu() {
	printf("1: Register a new Customer\n");
	printf("2: Login as a Customer\n");
	printf("3: Login as a Seller\n");
	printf("Enter the number: \n");
	int choice;


	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		registerCustomer();
		break;
	case 2:
		loginCustomer();
		break;
	case 3:
		seller();
		break;
	default:
		mainMenu();
		break;
	}
}

void loginCustomer() {
	int loggingID;
	printf("Please Enter Your Registered ID To Login: ");
	scanf_s("%d", &loggingID);
	fopen_s(&cdbPtr, customerFileName, "r");
		while (!feof(cdbPtr)) {
			if (loggingID == customerId) {
				loggedIn = true;
				loggedID = loggingID;
				customerMenu();
			}
			else if(loggedIn == false){
				printf("You Are Not Registered\n");
				mainMenu();
			}
			fscanf_s(cdbPtr, "%d %s %d", &customerId, customerName, 30, &customerNumber);
		}
	fclose(cdbPtr);

}

void customerMenu() {
	printf("1: Vehicles Menu \n");
	printf("2: Back to Main Menu\n");
	printf("Enter the number: \n");
	int choice;

	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		printf("Your ID is: %d\n", loggedID);
		vehicleMenu();
		break;
	case 2:
		mainMenu();
		break;
	default:
		customerMenu();
		break;
	}
}

void sellerMenu() {
	printf("1: Vehicles Menu \n");
	printf("2: Customers Menu \n");
	printf("3: Back to Main Menu\n");
	printf("Enter the number: \n");
	int choice;

	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		vehicleMenu();
		break;
	case 2:
		searchCustomerMenu();
		break;
	case 3:
		mainMenu();
		break;	
	default:
		sellerMenu();
		break;
	}
}

void seller() {
	int password;
	printf("Enter Password To Login: ");
	scanf_s("%d", &password);
	if (password == 1111) {
		isSeller = true;
		sellerMenu();
	}
	else {
		printf("Wrong Password\n");
	}
}

void vehicleMenu() {
	printf("1: Create a New Vehicle (For Seller Only)\n");
	printf("2: Delete All Cars (For Seller Only)\n");
	printf("3: Search For One Vehicle To Rent It\n");
	printf("4: See All Vehicles \n");
	printf("5: Back to Main Menu\n");

	printf("Enter the number: \n");
	int choice;

	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		if (isSeller == true) {
			createVehicle();
		}
		else {
			printf("You are Not A Seller\n");
		}
		break;
	case 2:
		if (isSeller == true) {
			fopen_s(&vdbPtr, VehicleFileName, "w");
			fclose(vdbPtr);
		}
		else {
			printf("You are Not A Seller\n");
		}
		break;
	case 3:
		vehicleSearchMenu();
		break;
	case 4:
		fopen_s(&vdbPtr, VehicleFileName, "r");
			printf("%-15s %s %15s %15s %15s\n", "Model Year", "Company Make Name", "Model Name", "Plate Number", "Rented By (ID)");
			fscanf_s(vdbPtr, "%d %s %s %d %d", &vehicleModelYear, vehicleCompanyMake,30,vehicleModelName, 30, &vehiclePlateNumber, &vehicleRentedBy);

			while (!feof(vdbPtr)) {
				printf("%-15d %s %20s %15d %15d\n", vehicleModelYear, vehicleCompanyMake,vehicleModelName, vehiclePlateNumber, vehicleRentedBy);

				fscanf_s(vdbPtr, "%d %s %s %d %d", &vehicleModelYear, vehicleCompanyMake,30,vehicleModelName, 30, &vehiclePlateNumber, &vehicleRentedBy);
			}
		fclose(vdbPtr);
		break;
	default:
		sellerMenu();
		break;
	}
}
void vehicleSearchMenu() {
	printf("1: Search by Model Year\n");
	printf("2: Search by Company Make Name\n");
	printf("3: Search by Model Name \n");
	printf("4: Search by Plate Number\n");
	printf("5: Search by Rented Customer ID (0 Means Not Rented | You Will Not Rent A Car By This Search)\n");
	printf("6: Back to Main Menu\n");

	printf("Enter the number (After The Search You Will Rent All Cars Searched): \n");
	int choice;
	int year, plate, id;
	char make[30], name[30];
	scanf_s("%d", &choice);

	switch (choice) {
	case 1:
		printf("Please Enter Model Year: ");
		scanf_s("%d", &year);
		fopen_s(&vdbPtr, VehicleFileName, "r");
			while (!feof(vdbPtr)) {
				if (vehicleModelYear == year) {
					printf("%-15d %s %20s %15d %15d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, vehicleRentedBy);
				}
				fscanf_s(vdbPtr, "%d %s %s %d %d", &vehicleModelYear, vehicleCompanyMake, 30, vehicleModelName, 30, &vehiclePlateNumber, &vehicleRentedBy);
			}
			printf("You Have Succesfully Rented This Car\n");
		fclose(vdbPtr);		
		fopen_s(&vdbPtr, VehicleFileName, "a");
			fprintf(vdbPtr, "%d %s %s %d %d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, loggedID);
		fclose(vdbPtr);
		break;
	case 2:
		printf("Please Enter Company Make Name (Max 30): ");
		scanf_s("%s", make, 30);
		fopen_s(&vdbPtr, VehicleFileName, "r");
			while (!feof(vdbPtr)) {
				if (vehicleCompanyMake == make) {
					printf("%-15d %s %20s %15d %15d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, vehicleRentedBy);
				}
				fscanf_s(vdbPtr, "%d %s %s %d %d", &vehicleModelYear, vehicleCompanyMake, 30, vehicleModelName, 30, &vehiclePlateNumber, &vehicleRentedBy);
			}
			printf("You Have Succesfully Rented This Car\n");
		fclose(vdbPtr);
		fopen_s(&vdbPtr, VehicleFileName, "a");
			fprintf(vdbPtr, "%d %s %s %d %d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, loggedID);
		fclose(vdbPtr);
		break;
	case 3:
		printf("Please Enter Model Name (Max 30): ");
		scanf_s("%s", name, 30);
		fopen_s(&vdbPtr, VehicleFileName, "r");
			while (!feof(vdbPtr)) {
				if (vehicleModelName == name) {
					printf("%-15d %s %20s %15d %15d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, vehicleRentedBy);
				}
				fscanf_s(vdbPtr, "%d %s %s %d %d", &vehicleModelYear, vehicleCompanyMake, 30, vehicleModelName, 30, &vehiclePlateNumber, &vehicleRentedBy);
			}
			printf("You Have Succesfully Rented This Car\n");
		fclose(vdbPtr);
		fopen_s(&vdbPtr, VehicleFileName, "a");
			fprintf(vdbPtr, "%d %s %s %d %d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, loggedID);
		fclose(vdbPtr);
		break;
	case 4:
		printf("Please Enter Plate Number: ");
		scanf_s("%d", &plate);
		fopen_s(&vdbPtr, VehicleFileName, "r");
		while (!feof(vdbPtr)) {
			if (vehiclePlateNumber == plate) {
				printf("%-15d %s %20s %15d %15d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, vehicleRentedBy);
			}
			fscanf_s(vdbPtr, "%d %s %s %d %d", &vehicleModelYear, vehicleCompanyMake, 30, vehicleModelName, 30, &vehiclePlateNumber, &vehicleRentedBy);
		}
		printf("You Have Succesfully Rented This Car\n");
		fclose(vdbPtr);
		fopen_s(&vdbPtr, VehicleFileName, "a");
			fprintf(vdbPtr, "%d %s %s %d %d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, loggedID);
		fclose(vdbPtr);
		break;
	case 5:
		printf("Please Enter The Customer ID That Rented: ");
		scanf_s("%d", &id);
		fopen_s(&vdbPtr, VehicleFileName, "r");
		while (!feof(vdbPtr)) {
			if (vehicleRentedBy == id) {
				printf("%-15d %s %20s %15d %15d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, vehicleRentedBy);
			}
			fscanf_s(vdbPtr, "%d %s %s %d %d", &vehicleModelYear, vehicleCompanyMake, 30, vehicleModelName, 30, &vehiclePlateNumber, &vehicleRentedBy);
		}
		fclose(vdbPtr);
		break;
	case 6:
		mainMenu();
		break;
	default:
		sellerMenu();
		break;
	}
}
void createVehicle() {
	fopen_s(&vdbPtr, VehicleFileName, "a");
		printf("Enter the Model Year (Min 4 digits), Company Make Name (Max 30), Model Name (Max 30), Plate Number (Max 4 digits), Rented By (Put 0): ");
		scanf_s("%d %s %s %d %d", &vehicleModelYear, vehicleCompanyMake, 30 ,vehicleModelName, 30, &vehiclePlateNumber, &vehicleRentedBy);
		fprintf(vdbPtr, "%d %s %s %d %d\n", vehicleModelYear, vehicleCompanyMake, vehicleModelName, vehiclePlateNumber, vehicleRentedBy);
	fclose(vdbPtr);
}