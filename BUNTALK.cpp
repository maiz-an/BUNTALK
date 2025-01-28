 
// Basic Billing system for Bun Talk bakery for FIP Assigment by م"

#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include <limits>
#include <ctime>
using namespace std;

// Structure to bakery item
struct BakeryItem {
	string code;
	string name;
	string description;
	double price;
	int quantity;
};

const string itemFileName = "bakery_items.txt";
BakeryItem BakeryItems[100];
int numBakeryItems = 0;

// Structure to add item to sell
struct CartItem {
	string code;
	string name;
	double price;
	int quantity;
};

CartItem ShoppingCart[100];
int numCartItems = 0;
#define _CRT_SECURE_NO_WARNINGS

//to get curent date in bill.
std::string getCurrentDate() {
    std::time_t now = std::time(0);
    std::tm* currentTime = std::localtime(&now);  // Use localtime instead of localtime_r

    char dateBuffer[80];
    std::strftime(dateBuffer, sizeof(dateBuffer), "%Y-%m-%d", currentTime);
    return std::string(dateBuffer);
}

std::string getCurrentTime() {
    std::time_t now = std::time(0);
    std::tm* currentTime = std::localtime(&now);  // Use localtime instead of localtime_r

    char timeBuffer[80];
    std::strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", currentTime);
    return std::string(timeBuffer);
}

//Structure for Billing History
struct BillingHistory {
	string customerName;
	string date;
	string time;
	double subth;
	double discb;
	double totalAmount;
};



// Void Function prototypes
void mainDisplay();
void mainMenu();
void loginMenu();
void aboutUs();
void contactUs();
void mainExit();

void adminLogin();
void viewBakeryItemsAdmin();
void manageBakeryItems();
void addBakeryItems();
void viewBakeryItemsManage();
void updateStockLevel();
void changeItemPrice();
void deleteItem();
void sellItems();

void cashierLogin();
void cashierMenu();
void viewBakeryItemsCashier();
void adminMenu();
void generateBill();
void updateBillingHistory(const BillingHistory& history);
void viewBillingHistory();



int main() {


	mainDisplay();
	mainMenu();
	
	system("pause");
	return 0;
}


// *******************//  * MAIN MENU FUNTIONS * // ******************

// Funtion to Operate main display
void mainDisplay() {
	cout << "\n\t\t\t----------------------------------------------- BUN TALK BAKERY ------------------------------------------------" << endl
		<< "\t\t\t\t\t\t\t\t      - Taste Of Heaven -" << endl
		<< "\t\t\t\t\t\t\t      -  You deserve to taste the best  -" << endl << endl
		<< "\t\t\t\t\t\t--------------------------------------------------------------- ^^/ " << endl << endl << endl;

}

//Funtion to handle Main menu
void mainMenu() {
	int opt1;
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl;
	mainDisplay();
	cout << "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl <<
		"\t\t\t\t\t\t\t |---------------- MAIN MENU ----------------| " << endl <<
		"\t\t\t\t\t\t\t |-------------------------------------------| " << endl <<
		"\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t 1. Login \t\t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t 2. About Us \t\t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t 3. Contact us\t\t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t 4. Exit \t\t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl <<
		"\t\t\t\t\t\t\t +-------------------------------------------+ " << endl;
	cout << "\t\t\t\t\t\t\t\t * Select an option : ";

	if (!(cin >> opt1)) {

		system("CLS");
		cout << endl << endl << endl; mainDisplay();
		cout << endl << endl << "\t\t\t\t\t\t Invalid input. Please enter a valid option and press Enter.";
		cin.clear(); // Clear error state
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
		cin.get(); // Wait for Enter key
		mainMenu(); // Re-display the main menu
	}
	else {
		cout << endl << endl;
		if (opt1 == 1) {
			loginMenu();
		}
		else if (opt1 == 2) {
			aboutUs();
		}
		else if (opt1 == 3) {
			contactUs();
		}
		else if (opt1 == 4) {
			mainExit();
		}
		else {
			cout << "\t\t\t\t\t\t\t0ops! Invalid option. Please select a valid option and press Enter." << endl;
			cin.clear(); // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
			cin.get(); // Wait for Enter key
			mainMenu(); // Re-display the main menu
		}
	}
}

// Funtion for handle login menu
void loginMenu() {
	int op1;
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	mainDisplay();
	cout << "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl <<
		"\t\t\t\t\t\t\t |---------------- LOGIN MENU ---------------| " << endl <<
		"\t\t\t\t\t\t\t |-------------------------------------------| " << endl <<
		"\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t 1. Admin Login \t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t 2. Cashier Login  \t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t 3. Go Previous Menu \t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t 4. Exit \t\t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t \t\t\t     |" << endl <<
		"\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl <<
		"\t\t\t\t\t\t\t +-------------------------------------------+ " << endl <<
		endl << endl << "\t\t\t\t\t\t\t\t"; cout << " * Select an Option : "; cin >> op1; cout << endl <<
		endl <<
		endl;
	switch (op1) {
	case 1:
		adminLogin();
		break;
	case 2:
		cashierLogin();
		break;

	case 3:
		mainMenu();
		break;

	case 4:
		mainExit();
		break;

	default:
		cout << "\t\t\t\t\t\t\t 0ops! Invalid option. Please select a valid option and press Enter. ^^/ " << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
		cin.get(); // Wait for Enter keymainErrorLogin();
		break;
	}


}

//Function to handle About us
void aboutUs() {
	system("CLS");
	mainDisplay(); cout << endl << endl << endl;
	cout << "\t\tBUN Talk Bakery - Where Innovation Meets Artisanal Excellence. ^^/" << endl << endl

		<< "\t\tIntroducing BUN Talk Bakery, a distinguished establishment that has reimagined" << endl << "\t\tthe art of baking since its inception.Founded with a commitment to excellence in 2005, we've earned" << endl << "\t\trecognition for our unique approach to crafting delectable treats that bridge tradition and innovation." << endl

		<< endl << "\t\tOur Signature Creations :" << endl << endl

		<< "\t\tAt BUN Talk Bakery, we blend the charm of traditional recipes from Eastern Europe" << endl << "\t\t with a dash of creative flair.Our menu boasts an array of artisanal rye breads and patisserie" << endl << "\t\t masterpieces that are a feast for both the eyes and the taste buds." << endl
		<< endl << "\t\tDiscover Our Treasures :"

		<< endl << "\t\tArtisan Rye Breads : " << endl << "\t\tImmerse yourself in the rich, earthy flavours of our authentic rye breads," << endl << "\t\t each crafted with a touch of tradition and a sprinkle of innovation." << endl

		<< endl << "\t\tPatisserie Perfection :" << endl << "\t\t Indulge in a world of sweetness with our patisserie creations." << endl << "\t\tFrom delicate pastries to divine cakes, our confections are designed to delight and inspire." << endl

		<< endl << "\t\tA Widespread Culinary Journey :" << endl << endl

		<< "\t\tOur commitment to quality knows no bounds. BUN Talk Bakery proudly supplies our artisanal " << endl << "\t\twonders to over 160 distinguished shops across London, the Home Counties, and numerous major " << endl << "\t\tcities throughout the United Kingdom.We're on a mission to bring the joy of exceptional baked goods to every corner of the UK." << endl

		<< endl << "\t\tBaking with Passion and Purpose :" << endl << endl

		<< "\t\tAt BUN Talk Bakery, our passion for baking is infused with purpose.We've redefined the baking experience," << endl << "\t\t seamlessly marrying time-honoured traditions with innovative techniques. " << endl << "\t\tEach bite is a testament to our dedication to the craft." << endl

		<< "\t\tJoin Us on a Flavourful Adventure :" << endl << endl
		<< "\t\tWe invite you to embark on a flavour - filled adventure with BUN Talk Bakery.Whether you seek the warmth of traditional rye " << endl << "\t\tbread or the excitement of cutting - edge patisserie, our bakery is a destination for those who appreciate the perfect balance of heritage and creativity." << endl

		<< "\t\tVisit Us Today :" << endl << endl

		<< "\t\tCome and explore the world of BUN Talk Bakery, where every bite tells a story of innovation, tradition, and a relentless " << endl << "\t\tpursuit of culinary excellence.Experience baking reimagined – only at BUN Talk Bakery." << endl

		<< endl;
	cin.ignore();
	cout << endl << "\t\t\t  \t\t\t\t\tPress Enter to go main menu ^^/ " << endl;
	cin.get(); // Wait for user to press Enter
	cout << endl << endl; mainMenu();

}

// Funtion to handle contact us
void contactUs() {
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	cout << "\n\n\n\t\t\t----------------------------------------------- BUN TALK BAKERY ------------------------------------------------" << endl
		<< "\t\t\t\t\t\t\t\t      - Taste Of Heaven -" << endl
		<< "\t\t\t\t\t\t\t      -  You deserve to taste the best  -"
		<< "\n\n\n\t\t\t\t------------------------------------------ CONTACT US --------------------------------------------\n" << endl
		<< "\t\t\t\t  Phone" << "\t\t\t\t\t    Address" << "\t\t\t\t\tE-mail"
		<< "\n\n\t\t\t    +94 75 335 7777" << "\t\t   402/B/1 , Thaikka road, Kalmunai," << "\t      mohamedmaizanmunas@gmail.com"
		<< "\n\t\t\t    +94 67 222 0267" << "\t\t     Ampare , Eastern, Srilanka"
		<< "\n\n\t\t\t\t--------------------------------------------------------------------------------------------------\n" << endl;

	cin.ignore();
	cout << "\t\t\t  \t\t\t\t\tPress Enter to go main menu ^^/ " << endl;
	cin.get(); // Wait for user to press Enter
	cout << endl << endl; mainMenu();
}

// Function to handle Main Exit
void mainExit() {
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl; mainDisplay();
	cout << "\t\t\t\t\t\t\t   ------------- System Closed. -------------" << endl
		<< "\t\t\t\t\t\t\t   ------------- See you again ^^/ . -------------" 
		<< endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< endl << endl << endl << endl << endl << endl << endl << endl;
	exit(0);
}





// ***************** // * LOGIN MENU FUNTIONS * // *******************

// Function to handle admin login
void adminLogin() {

	string pws;
	int loginAttempts = 0;

	while (loginAttempts < 3) {

		system("CLS");
		cout << endl << endl;
		mainDisplay();
		cout << "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl <<
			"\t\t\t\t\t\t\t |---------------- ADMIN LOGIN --------------| " << endl <<
			"\t\t\t\t\t\t\t |-------------------------------------------| " << endl <<
			"\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl <<
			"\t\t\t\t\t\t\t |\t\t \t \t\t     |" << endl <<
			"\t\t\t\t\t\t\t |\t\t User Name : Admin" << endl;
		cout << "\t\t\t\t\t\t\t | \t\t Password  : ";  cin >> pws; cout << "  ";
		cout << "\t\t\t\t\t\t\t |\t\t \t\t\t     |" << endl <<
			"\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl <<
			"\t\t\t\t\t\t\t +-------------------------------------------+ " << endl <<
			endl <<
			endl;

		if (pws == "password") {

			cout << endl;
			cout << "\t\t\t\t\t\t\t\t\tLogin successful! ^^/ " << endl;
			cin.ignore();
			cout << endl << "\t\t\t  \t\t\t\t\t   Press Enter to go Admin menu" << endl;
			cin.get(); // Wait for user to press Enter
			cout << endl << endl; adminMenu();
			return;

		}
		else {
			cout << "\t\t\t\t\t\t\t\t\t0ops! Login failed!" << endl;
			cout << "\t\t\t\t\t\t\t\t\tInvalid Username or password!" << endl;
			cin.ignore();
			cout << endl << "\t\t\t  \t\t\t\t\t   Press Enter to Contiue" << endl;
			cin.get(); // Wait for user to press Enter
			cout << endl << endl;
			loginAttempts++;
		}
	}

	cout << "\t\t\t\t\t\t\t0ops! Too many incorrect login attempts. Exiting the program! ^^/ " << endl;
	exit(1);
}

// Function to handle cashier login
void cashierLogin() {
	system("CLS");
	string pws;
	int loginAttempts = 0;

	while (loginAttempts < 4) {
		system("CLS");
		cout << endl << endl;
		mainDisplay();
		cout << endl << endl;
		cout << "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl <<
			"\t\t\t\t\t\t\t |-------------- CASHIER LOGIN --------------| " << endl <<
			"\t\t\t\t\t\t\t |-------------------------------------------| " << endl <<
			"\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl <<
			"\t\t\t\t\t\t\t |\t\t \t \t\t     |" << endl <<
			"\t\t\t\t\t\t\t |\t\t User Name : Cashier" << endl;
		cout << "\t\t\t\t\t\t\t | \t\t Password : "; cin >> pws; cout << "  ";
		cout << "\t\t\t\t\t\t\t |\t\t \t\t\t     |" << endl <<
			"\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl <<
			"\t\t\t\t\t\t\t +-------------------------------------------+ " << endl <<
			endl <<
			endl;


		if (pws == "password") {

			cout << endl;
			cout << "\t\t\t\t\t\t\t\t\tLogin successful! ^^/ " << endl;
			cin.ignore();
			cout << endl << "\t\t\t  \t\t\t\t\t   Press Enter to go Cashier menu" << endl;
			cin.get(); // Wait for user to press Enter
			cout << endl << endl; cashierMenu();
			return;

			return;

		}
		else {
			cout << "\t\t\t\t\t\t\t\t\t0ops! Login failed! ^^/ " << endl;
			cout << "\t\t\t\t\t\t\t\t\tInvalid Username or password!" << endl;
			cin.ignore();
			cout << endl << "\t\t\t  \t\t\t\t\t   Press Enter to Contiue" << endl;
			cin.get(); // Wait for user to press Enter
			cout << endl << endl;
			loginAttempts++;
		}
	}

	cout << "\t\t\t\t\t\t\t0ops! Too many incorrect login attempts. Exiting the program! ^^/ " << endl;
	exit(1);
}




// **************** // * ADMIN FUNTIONS * // *****************

// Function to handle Admin menu
void adminMenu() {
	int op3;
	bool validOption = false; // Flag to track if a valid option was selected

	do {
		system("CLS");
		mainDisplay();
		cout << endl;
		cout << "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl
			<< "\t\t\t\t\t\t\t |---------------- ADMIN MENU ---------------| " << endl
			<< "\t\t\t\t\t\t\t |-------------------------------------------| " << endl
			<< "\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 1. View Items \t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 2. Manage Items \t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 3. Bill History \t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 4. Logout \t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 5. Exit \t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t \t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl;
		cout << endl << endl << "\t\t\t\t\t\t\t\t  * Select an option : ";

		if (!(cin >> op3)) {
			// Input was not a  int
			cout << "\t\t\t\t\t\t\t Invalid input. Please enter a valid option and press Enter. ^^/ " << endl;
			cin.clear(); // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
			cin.get(); // Wait for Enter key
		}
		else {
			cout << endl << endl;
			switch (op3) {
			case 1:
				viewBakeryItemsAdmin();
				break;
			case 2:
				manageBakeryItems();
				break;
			case 3:
				viewBillingHistory();
				break;
			case 4:
				cout << "\t\t\t\t\t\t\t\t *** System Successfully logged out. ^^/ *** " << endl << endl;
				loginMenu();
				break;
			case 5:
				mainExit();
				break;
			default:
				cout << "\t\t\t\t\t\t\t Invalid option. Please select a valid option and press Enter. ^^/ " << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
				cin.get(); // Wait for Enter key
				break;
			}
		}
	} while (!validOption); // Continue until a valid option is selected
}

//show up item in admin menu
void viewBakeryItemsAdmin() {
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	mainDisplay();

	ifstream file("BakeryItem.txt");
	if (file.is_open())
	{
		BakeryItem BakeryItem;;
		cout << "\t\t\t  Code \t\t Item Name \t\t\t Discription \t\t\t Price(Rs.) \t\t Quantity" << endl;
		cout << "\t\t\t----------------------------------------------------------------------------------------------------------" << endl;
		while (file >> BakeryItem.code >> BakeryItem.name >> BakeryItem.description >> BakeryItem.price >> BakeryItem.quantity)
		{
			cout << "\t\t\t    " << BakeryItem.code << "\t\t " << BakeryItem.name << "\t\t\t\t" << BakeryItem.description << "\t\t\t   " << BakeryItem.price << " \t\t  " << BakeryItem.quantity << endl;
		}
	}
	else
	{
		cout << "Error opening file" << endl;
	}
	file.close();
	cout << endl;
	cout << "\t\t\t----------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t Press Enter to go back to the Admin menu... ^^/ " << endl << endl;
	cin.ignore();
	cin.get(); // Wait for user to press Enter
	cout << endl << endl; adminMenu();


}

//funtion for Manage bakery items
void manageBakeryItems() {
	int op2;
	bool validOption = false; // Flag to track if a valid option was selected

	do {
		system("CLS");
		cout << endl << endl << endl;
		mainDisplay();
		cout << "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl
			<< "\t\t\t\t\t\t\t |------------ Manage Bakery Items ----------| " << endl
			<< "\t\t\t\t\t\t\t |-------------------------------------------| " << endl
			<< "\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t | \t     1. Add New Items  \t\t     |" << endl
			<< "\t\t\t\t\t\t\t | \t     2. Update Stock Level \t     |" << endl
			<< "\t\t\t\t\t\t\t | \t     3. Change Item Price   \t     |" << endl
			<< "\t\t\t\t\t\t\t | \t     4. View Bakery items \t     |" << endl
			<< "\t\t\t\t\t\t\t | \t     5. Delete Item \t\t     |" << endl
			<< "\t\t\t\t\t\t\t | \t     6. Back to Admin Menu \t     |" << endl
			<< "\t\t\t\t\t\t\t | \t     7. Back to Main Menu \t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t \t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl;
		cout << endl << endl << "\t\t\t\t\t\t\t\t  * Select an option : ";

		if (!(cin >> op2)) {
			// Input  not  int
			cout << "\t\t\t\t\t\t\t Invalid input. Please press Enter to input a valid option. ^^/ " << endl;
			cin.clear(); // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
			cin.get(); // Wait for Enter key
		}
		else {
			cout << endl << endl;
			switch (op2) {
			case 1:
				addBakeryItems();
				break;

			case 2:
				updateStockLevel();
				break;

			case 3:
				changeItemPrice();
				break;

			case 4:
				viewBakeryItemsManage();
				break;

			case 5:
				deleteItem();
				break;

			case 6:
				adminMenu();
				break;

			case 7:
				mainMenu();
				break;

			default:
				cout << "\t\t\t\t\t\t\t Invalid option. Please press Enter to input a valid option. ^^/ "  << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
				cin.get(); // Wait for Enter key
				break;
			}
		}
	} while (!validOption); // Continue until a valid option is selected
}

//Funtion for add items
void addBakeryItems() {
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	mainDisplay();
	while (numBakeryItems < 100) {
		ofstream file("BakeryItem.txt", ios::app);
		if (file.is_open())
		{
			BakeryItem BakeryItem;
			cout << "\t\t\tEnter code for the bakery item: ";
			cin >> BakeryItem.code;
			cout << "\t\t\tEnter Name for the bakery item : ";
			cin >> BakeryItem.name;
			cout << "\t\t\tEnter description for the bakery item : ";
			cin >> BakeryItem.description;
			cout << "\t\t\tEnter price for the bakery item : Rs.";
			cin >> BakeryItem.price;
			cout << "\t\t\tEnter quantity for bakery item : ";
			cin >> BakeryItem.quantity;
			file << BakeryItem.code << " " <<endl<< BakeryItem.name << " " <<endl
				<< BakeryItem.description << " " <<endl<< BakeryItem.price 
				<< " " <<endl<< BakeryItem.quantity << endl;
			cout << "\t\t\t Bakery Item added successfully" << endl;
			cout << " " << endl;
		}
		else
		{
			cout << "Error opening file" << endl;
		}
		file.close();

		numBakeryItems++;

		if (numBakeryItems >= 100) {
			cout << "\t\t\t\t\t\t\tMaximum number of items reached. ^^/ " << endl;
			break;
		}

		cout << "\t\t\t\t\t\t\tDo you want to add another item? (yes/no): ";
		string choice;
		cin >> choice;

		if (choice != "yes") {
			cout << "\t\t\t\t\t\t\tPress Enter to go back to the Manage Item menu... ^^/ ";
			cin.ignore();
			cin.get(); // Wait for Enter key
			cout << endl << endl; manageBakeryItems();
			break; // Exit the loop if the user doesn't want to add more items
		}
	}
}

//show up item in manage bakery iitems
void viewBakeryItemsManage() {
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	mainDisplay();

	ifstream file("BakeryItem.txt");
	if (file.is_open())
	{
		BakeryItem BakeryItem;;
		cout << "\t\t\t  Code \t\t Item Name \t\t\t Discription \t\t\t Price(Rs.) \t\t Quantity" << endl;
		cout << "\t\t\t------------------------------------------------------------------------------------------------------------------" << endl;
		while (file >> BakeryItem.code >> BakeryItem.name >> BakeryItem.description >> BakeryItem.price >> BakeryItem.quantity)
		{
			cout << "\t\t\t    " << BakeryItem.code << "\t\t " << BakeryItem.name << "\t\t\t\t" << BakeryItem.description << "\t\t\t   " << BakeryItem.price << " \t\t\t  " << BakeryItem.quantity << endl;
		}
	}
	else
	{
		cout << "Error opening file" << endl;
	}
	file.close();
	cout << endl;
	cout << "\t\t\t------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t Press Enter to go back to the Manage bakery item menu... ^^/ " << endl << endl;
	cin.ignore();
	cin.get(); // Wait for user to press Enter
	cout << endl << endl; manageBakeryItems();


}

//Funtion for update stock level in bakaery item
void updateStockLevel() {
	while (true) { // Loop until the user decides to exit
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		mainDisplay();

		ifstream inFile("BakeryItem.txt");
		ofstream outFile("BakeryItem_temp.txt", ios::out);

		if (!inFile.is_open() || !outFile.is_open()) {
			cout << "\t\t\tError opening files." << endl;
			return;
		}

		cout << "\t\t\t\tEnter the item code to update stock level: ";
		string itemCode;
		cin >> itemCode;
		bool itemFound = false;

		while (!inFile.eof()) {
			BakeryItem item;
			inFile >> item.code >> item.name >> item.description >> item.price >> item.quantity;

			if (inFile.eof()) break;

			if (item.code == itemCode) {
				itemFound = true;
				cout << "\t\t\t\tCurrent Stock Level: " << item.quantity << endl;
				cout << "\t\t\t\tEnter the new stock level: ";
				cin >> item.quantity;
			}

			outFile << item.code << " " << item.name << " " << item.description << " " << item.price << " " << item.quantity << endl;
		}

		inFile.close();
		outFile.close();

		if (itemFound) {
			remove("BakeryItem.txt");
			rename("BakeryItem_temp.txt", "BakeryItem.txt");
			cout << endl << "\t\t\t\t Stock level updated successfully." << endl;
			cout << "\t\t\t\t----------------------------------" << endl<<endl;
		}
		else {
			cout << "\t\t\tItem not found." << endl;
		}

		cout << "\t\t\t\tDo you want to update another item? (yes/no): ";
		string choice;
		cin >> choice;

		if (choice != "yes") {
			cout << "\t\t\t\tPress Enter to go back to the Manage Bakery Items menu... ^^/ " << endl << endl;
			cin.ignore();
			cin.get(); // Wait for Enter key
			manageBakeryItems();
			break; // Exit the loop if the user doesn't want to update another item
		}
	}
}

//Funtion to change item's price
void changeItemPrice() {
	while (true) { // Loop until user say no
		system("CLS");
		cout << endl << endl << endl << endl << endl;
		mainDisplay();

		ifstream inFile("BakeryItem.txt");
		ofstream outFile("BakeryItem_temp.txt", ios::out);

		if (!inFile.is_open() || !outFile.is_open()) {
			cout << "\t\t\t\tError opening files." << endl;
			return;
		}

		cout << "\t\t\t\tEnter the item code to change the price: ";
		string itemCode;
		cin >> itemCode;
		bool itemFound = false;

		while (!inFile.eof()) {
			BakeryItem item;
			inFile >> item.code >> item.name >> item.description >> item.price >> item.quantity;

			if (inFile.eof()) break;

			if (item.code == itemCode) {
				itemFound = true;
				cout << "\t\t\t\tCurrent Price: Rs." << item.price << endl;
				cout << "\t\t\t\tEnter the new price: Rs.";
				cin >> item.price;
			}

			outFile << item.code << " " << item.name << " " << item.description << " " << item.price << " " << item.quantity << endl;
		}

		inFile.close();
		outFile.close();

		if (itemFound) {
			remove("BakeryItem.txt");
			rename("BakeryItem_temp.txt", "BakeryItem.txt");
			cout << "\t\t\t\tPrice changed successfully." << endl;
		}
		else {
			cout << "\t\t\t\tItem not found.^^/ " << endl;
		}

		cout << "\t\t\t\tDo you want to change the price of another item? (yes/no): ";
		string choice;
		cin >> choice;

		if (choice != "yes") {
			cout << "\t\t\t\tPress Enter to go back to the Manage Bakery Items menu... ^^/ " << endl << endl;
			cin.ignore();
			cin.get(); //  Enter key
			manageBakeryItems();
			break; // Exit user doesn't want to change the price.
		}
	}
}

//Funtion for delete items
void deleteItem() {
	while (true) { // Loop until the user  exit
		system("CLS");
		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		mainDisplay();

		ifstream inFile("BakeryItem.txt");
		ofstream outFile("BakeryItem_temp.txt", ios::out);

		if (!inFile.is_open() || !outFile.is_open()) {
			cout << "\t\t\t\tError opening files. ^^/ " << endl;
			return;
		}

		cout << "\t\t\t\tEnter the item code to delete: ";
		string itemCode;
		cin >> itemCode;
		bool itemFound = false;

		while (!inFile.eof()) {
			BakeryItem item;
			inFile >> item.code >> item.name >> item.description >> item.price >> item.quantity;

			if (inFile.eof()) break;

			if (item.code == itemCode) {
				itemFound = true;
				cout << "\t\t\t\tItem deleted successfully. ^^/ " << endl;
			}
			else {
				outFile << item.code << " " << item.name << " " << item.description << " " << item.price << " " << item.quantity << endl;
			}
		}

		inFile.close();
		outFile.close();

		if (!itemFound) {
			cout << "\t\t\t\tItem not found." << endl;
		}
		else {
			remove("BakeryItem.txt");
			rename("BakeryItem_temp.txt", "BakeryItem.txt");
		}

		cout << "\t\t\t\tDo you want to delete another item? (yes/no): ";
		string choice;
		cin >> choice;

		if (choice != "yes") {
			cout << "\t\t\t\tPress Enter to go back to the Manage Bakery Items menu... ^^/ " << endl << endl;
			cin.ignore();
			cin.get(); // Wait for Enter key
			manageBakeryItems();
			break; // Exit  user doesn't want to delete 
		}
	}
}




//***************** // * CASHIER FUNTIONS * // ****************

// Function to handle Cashier menu
void cashierMenu() {
	int op2;
	bool validOption = false; // to make sure  a valid option is  selected

	do {
		system("CLS");
		mainDisplay();
		BillingHistory history; //Declere and define history veriable
		cout << endl;
		cout << "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl
			<< "\t\t\t\t\t\t\t |--------------- CASHIER MENU --------------| " << endl
			<< "\t\t\t\t\t\t\t |-------------------------------------------| " << endl
			<< "\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 1. View Items \t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 2. Select items to sell     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 3. Generate Bill \t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 4. Bill History  \t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 5. Logout \t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t 6. Exit \t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t \t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t |\t\t\t\t\t     |" << endl
			<< "\t\t\t\t\t\t\t +-------------------------------------------+ " << endl;
		cout << endl << endl << "\t\t\t\t\t\t\t\t  * Select an option : ";

		if (!(cin >> op2)) {
			// Input not a int
			cout << "\t\t\t\t\t\t\t Invalid input. Please press Enter to input a valid option. ^^/ " << endl;
			cin.clear(); // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
			cin.get(); // Wait for Enter key
		}
		else {
			cout << endl << endl;
			switch (op2) {
			case 1:
				viewBakeryItemsCashier();
				break;
			case 2:
				sellItems();
				break;
			case 3:
				generateBill();
				break;
			case 4:
				viewBillingHistory();
				break;
			case 5:
				loginMenu();
				break;
			case 6:
				mainExit();
				break;
			default:
				cout << "\t\t\t\t\t\t\t Invalid option. Please press Enter to input a valid option. ^^/ " << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input lag
				cin.get(); // Wait for Enter key
				break;
			}
		}
	} while (!validOption); // Continue until a valid option is selected
}

//show up items in cashier view
void viewBakeryItemsCashier() {
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	mainDisplay();

	ifstream file("BakeryItem.txt");
	if (file.is_open())
	{
		BakeryItem BakeryItem;;
		cout << "\t\t\t  Code \t\t Item Name \t\t\t Discription \t\t\t Price(Rs.) \t\t Quantity" << endl;
		cout << "\t\t\t------------------------------------------------------------------------------------------------------------------" << endl;
		while (file >> BakeryItem.code >> BakeryItem.name >> BakeryItem.description >> BakeryItem.price >> BakeryItem.quantity)
		{
			cout << "\t\t\t    " << BakeryItem.code << "\t\t " << BakeryItem.name << "\t\t\t\t" << BakeryItem.description << "\t\t\t   " << BakeryItem.price << " \t\t\t  " << BakeryItem.quantity << endl;
		}
	}
	else
	{
		cout << "Error opening file" << endl;
	}
	file.close();
	cout << endl;
	cout << "\t\t\t-------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t\t\t Press Enter to go back to the Cashier menu... ^^/ " << endl << endl;
	cin.ignore();
	cin.get(); // Wait for user to press Enter
	cout << endl << endl; cashierMenu();


}

//Function for add item to sell cart
void sellItems() {
	system("CLS");
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	mainDisplay();

	// Load bakery items from the file
	ifstream file("BakeryItem.txt");
	if (!file.is_open()) {
		cout << "\t\t\t\t\t\t\tError opening file. ^^/ " << endl;
		return;
	}

	// Check if the file is empty
	if (file.peek() == ifstream::traits_type::eof()) {
		cout << "\t\t\t\t\t\t\tNo bakery items available to sell. ^^/ " << endl;
		file.close();
		return;
	}

	// Read the bakery items from the file
	numBakeryItems = 0;
	while (numBakeryItems < 100 && file >> BakeryItems[numBakeryItems].code >> BakeryItems[numBakeryItems].name >> BakeryItems[numBakeryItems].description >> BakeryItems[numBakeryItems].price >> BakeryItems[numBakeryItems].quantity) {
		numBakeryItems++;
	}
	file.close();

	cout << "\t\t\t\t\t\t\tEnter the item code to sell (or '0' to finish): ";
	string itemCode;
	cin >> itemCode;

	while (itemCode != "0") {
		bool found = false;
		for (int i = 0; i < numBakeryItems; ++i) {
			if (BakeryItems[i].code == itemCode) {
				found = true;
				int quantity;
				cout << "\t\t\t\t\t\t\tEnter the quantity to sell: ";
				cin >> quantity;
				if (quantity > 0 && quantity <= BakeryItems[i].quantity) {
					// Add the item to the shopping cart
					ShoppingCart[numCartItems].code = BakeryItems[i].code;
					ShoppingCart[numCartItems].name = BakeryItems[i].name;
					ShoppingCart[numCartItems].price = BakeryItems[i].price;
					ShoppingCart[numCartItems].quantity = quantity;
					numCartItems++;
					// Update the quantity of the item in memory
					BakeryItems[i].quantity -= quantity;
				}
				else {
					cout << "\t\t\t\t\t\t\tInvalid quantity. Please enter a valid quantity. ^^/ " << endl;
				}
				break;
			}
		}

		if (!found) {
			cout << "\t\t\t\t\t\t\tItem not found. Please enter a valid item code. ^^/ " << endl << endl;
		}

		cout << "\t\t\t\t\t\t\tEnter the item code to sell (or '0' to finish): ";
		cin >> itemCode;
	}

	// Save the updated bakery items back to the file
	ofstream outFile("BakeryItem.txt");
	if (outFile.is_open()) {
		for (int i = 0; i < numBakeryItems; ++i) {
			outFile << BakeryItems[i].code << " " << BakeryItems[i].name << " " << BakeryItems[i].description << " " << BakeryItems[i].price << " " << BakeryItems[i].quantity << endl;
		}
		outFile.close();
	}
	else {
		cout << "\t\t\t\t\t\t\tError opening file for writing. ^^/ " << endl;
	}

	cout << "\t\t\t\t\t\t\tPress Enter to go back to the user menu... ^^/ " << endl << endl;
	cin.ignore();
	cin.get(); // Wait for Enter key
	cout << endl << endl;
	cashierMenu();
}

//Upateing bill history to file
void updateBillingHistory(const BillingHistory& history) {
	ofstream outFile("billinghistory.txt", ios::app);
	if (outFile.is_open()) {
		outFile << endl;
		outFile << "    Customer Name     : " << history.customerName << endl;
		outFile << "    Date              : " << history.date << endl;
		outFile << "    Time              : " << history.time << endl;
		outFile << "    Sub total Amount  : Rs." << history.subth << endl;
		outFile << "    Discound          : Rs." << history.discb << endl;
		outFile << "    Total Amount      : Rs." << history.totalAmount << endl;
		outFile << "------------------------------- ^^/ \n";
		outFile.close();
	}
	else {
		cout << "\t\t\t\t\t\t\tError opening billing history file. ^^/ " << endl;
	}
}

//funtion to genarate bill
void generateBill() {
    system("CLS");
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;

    if (numCartItems == 0) {
        mainDisplay();
        cout << "\t\t\t\t\t\t\tNo items in the shopping cart." << endl;
        cout << "\t\t\t\t\t\t\tPress Enter to go back to the Cashier menu... ^^/ " << endl << endl;
        cin.ignore();
        cin.get(); // Wait for Enter key
        cout << endl << endl;
        cashierMenu();
        return; // Exit the function
    }

    mainDisplay();
    string cnm, ordn;
    cout << "\t\t\t\t\tEnter Customer Name : "; cin >> cnm; cout << endl;
    cout << "\t\t\t\t\tEnter Order Number  : "; cin >> ordn; cout << endl;

    std::string currentDate = getCurrentDate();
    std::string currentTime = getCurrentTime(); 
    double stotal = 0.0;
    double total = 0.0;
    double dis = 0.0;
    system("CLS");
    cout << endl << endl << endl;

    // Print the bill header only once
    cout << "\t\t\t\t-----------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t          BUN TALK BAKERY\n";
    cout << "\t\t\t\t\t\t\t\t          Sales Receipt\n";
    cout << "\t\t\t\t-----------------------------------------------------------------------------------------------\n"; cout << endl;
    cout << "\t\t\t\t\t\t\t\t Customer Name : " << cnm << endl;
    cout << "\t\t\t\t\t\t\t\t Order Number  : " << ordn << endl;
    cout << "\t\t\t\t\t\t\t\t Date          : " << currentDate << endl;
    cout << "\t\t\t\t\t\t\t\t Time          : " << currentTime << endl;
    cout << "\t\t\t\t-----------------------------------------------------------------------------------------------\n" << endl;

    cout << "\t\t\t\t-----------------------------------------------------------------------------------------------\n";
    cout << "\t\t\t\t" << "\t" << setw(10) << "Quantity" << setw(20) << "Item" << setw(20) << "Price" << setw(15) << "Total\n";
    cout << "\t\t\t\t-----------------------------------------------------------------------------------------------\n";
    cout << endl;

    // Loop through the cart and print item details
    for (int i = 0; i < numCartItems; ++i) {
        double itemTotal = ShoppingCart[i].price * ShoppingCart[i].quantity;
        cout << "\t\t\t\t" << setw(13) << ShoppingCart[i].quantity << setw(23) << ShoppingCart[i].name
            << "\t" << setw(13) << "Rs." << ShoppingCart[i].price << setw(15) << "Rs." << itemTotal << endl;
        stotal += itemTotal;
    }

    // Calculate discount and total price
    dis = stotal * 0.1;
    total = stotal - dis;

    cout << "\t\t\t\t-----------------------------------------------------------------------------------------------\n";
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\tSub Total Price: Rs." << stotal << endl;
    cout << "\t\t\t\t\t\t\t\t\tDiscound (10%) : Rs." << dis << endl;
    cout << "\t\t\t\t-----------------------------------------------------------------------------------------------\n";
    cout << endl;
    cout << "\t\t\t\t\t\t\t\t\tTotal Price    : Rs." << total << endl;
    cout << "\t\t\t\t\t\t\t\tThank you for shopping at BUN TALK BAKERY!\n";
    cout << "\t\t\t\t-----------------------------------------------------------------------------------------------\n";

    // Define billing history
    BillingHistory history;
    history.customerName = cnm;
    history.date = currentDate;
    history.time = currentTime;
    history.totalAmount = total;
    history.discb = dis;
    history.subth = stotal;

    // Update the billing history 
    cout << endl;
    updateBillingHistory(history);

    // Clear the shopping cart
    numCartItems = 0;
    cout << endl << "\t\t\t\t\t\t\tPress Enter to go back to the Cashier menu... ^^/ " << endl << endl;
    cin.ignore();
    cin.get(); // Wait for Enter key
    cout << endl << endl; cashierMenu();
}

// view bakery items
void viewBillingHistory() {
	ifstream inFile("billinghistory.txt");
	if (inFile.is_open()) {
		string line;
		cout << endl << endl;
		system("CLS");
		mainDisplay();
		cout << "\t\t\t\t\t\t\t\t   Bun Talk Bakery Billing History "<<endl;
		cout << "\t\t\t\t\t\t\t\t------------------------------------- " << endl<<endl;

		while (getline(inFile, line)) {
			cout << "\t\t\t\t\t\t\t\t"<<line << endl;
		}
		inFile.close();
	}
	else {
		cout << "Error opening billing history file." << endl;
	}

	// Wait for user input before returning to the menu
	cout <<endl<<endl<<endl <<"\t\t\t\t\t\t\tPress Enter to go back to the menu... ^^/ " << endl;
	cin.ignore();
	cin.get();
}


    
   //              //
  //      م"      //
 //              //
//              //

// Mohamed Maizan Munas ^^/
//  
