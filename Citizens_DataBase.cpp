//#ifndef CITIZENSDB_H
//#define CITIZENSDB_H
//#include <string>

/* Name : Muhammad Huzaifa
   Roll No: 20I0604
   Assignment # 02
 */

#include <iostream>
#include<fstream>
#include <string>
#include<sstream>

using namespace std;
class crimenode;

template <class T>
struct Data {
	//Node structure for data pipeline, implementing data members as per requirement
	Data<T>* next;
	T data;
	Data() {//Default Constructor
		next = NULL;
	}
	Data(T data) {//Parameterize Constructor
		this->data = data;
	}
};

template <class T>
class DataPipeline {
	/*	A linkedlist based queue to implement databases
		Implementing additional functions as per requirement
	*/
	Data<T>* front;
	Data<T>* rear;			//front and rear for queues
public:
	DataPipeline() {
		front = rear = NULL;		//Default Constructor
	}
	Data<T>* frontval() {
		return front;			// Function returning front's value
	}
	T backval() {
		return rear->cnic;		// Function returning rear's value
	}

	void enqueue(T data) {		// Enqueueing data in queue

		Data<T>* newnode = new Data<T>(data);
		newnode->next = NULL;
		if (is_empty()) {
			front = newnode;		//front and rear pointing first node initially
			rear = newnode;
		}
		else {
			rear->next = newnode;
			rear = newnode;
		}
	}
	T dequeue() {
		T value;
		if (front == NULL) {
			cout << "The Queue is Empty" << endl;
		}
		else {
			Data<T>* temporary;
			temporary = front;
			value = front->data;			// Dequeueing 
			front = front->next;
			delete temporary;
		}
		return value;
	}

	bool is_empty() {
		if (front == NULL)
			return true;			//Empty Function Checking empty Queue
		else
			return false;
	}
	~DataPipeline() {
		while (!is_empty()) {			// Destructor for Data Pipeline Queue
			dequeue();
		}
	}
};

template<class a >
struct CBID_NODE {

	CBID_NODE* next, * previous;		//Pointers for CBID nodes
	a name, f_name, address, nationality;
	int cnic;							//Data of each member in cbid node
	a gender;

	CBID_NODE() {						//Default Constructor
		next = previous = NULL;
		a name = "";
		a f_name = "";
		a address = "";
		a nationality = "";
		int cnic = 0;
		a gender = " ";
	}
	//Parametrized constructor
	CBID_NODE(a n_name, a n_fname, a n_address, a n_nationality, int n_cnic, a n_gender) {
		next = previous = NULL;
		name = n_name;
		f_name = n_fname;
		address = n_address;
		nationality = n_nationality;
		cnic = n_cnic;
		gender = n_gender;
	}
};

template <class a>
class CBIDList {
public:
	CBID_NODE<a>* head;
	CBID_NODE<a>* tail;			//Head And Tail For Nodes
	CBIDList() {				//Default Constructor
		head = tail = NULL;
	}
	/*Inserting Data of a specific cnic in CBID list
	OR reading data from file and inserting in CBID LIST*/
	void insert(int cnic, a name, a f_name, a gender, a address, a nationality) {
		if (!head) {
			CBID_NODE<a>* newnode = new CBID_NODE<a>(name, f_name, address, nationality, cnic, gender);
			head = newnode;
			tail = head;				//Inserting 1st node

		}
		else {
			CBID_NODE<a>* curr = head;
			while (curr != tail) {
				curr = curr->next;			//Inserting Node At the End
			}
			curr->next = new CBID_NODE<a>(name, f_name, address, nationality, cnic, gender);
			curr->next->previous = tail;
			tail = tail->next;
		}
	}
	//Function For Searching A Specific Node in CBID List
	a& locate(int cnic) {
		CBID_NODE<a>* search = head;
		while (search->cnic != cnic) {
			search = search->next;			//Searching For Cnic
		}
		cout << "\nNode Found\n";
		cout << "Name: " << search->name << endl;
		cout << "Father Name: " << search->f_name << endl;
		cout << "Address: " << search->address << endl;
		cout << "Nationality: " << search->nationality << endl;			//Printing Cnic's Data If Exists
		cout << "Cnic: " << search->cnic << endl;
		cout << "Gender: " << search->gender << endl << endl;
		string s1 = search->name + " " + search->f_name + " " + search->address + " " + search->nationality + " " + search->gender;
		return s1;//Returning Data in a String
	}

	//Function For Updating Cnic's Name
	bool update_name(a n_name, int CNIC) {
		if (is_empty()) {
			return false;		//Checking for Empty list
		}
		else {
			CBID_NODE<a>* newnode = head;
			while (newnode->next != NULL && newnode->cnic != CNIC) {
				newnode = newnode->next;					//Searching For CNIC
			}
			newnode->name = n_name;
			cout << "Updated Name: " << newnode->name << endl;
			string s1 = newnode->name + " " + newnode->f_name + " " + newnode->gender + " " + newnode->address + " " + newnode->nationality;
			cout << s1 << endl;
			return true;
		}
		return false;
	}

	//Function For Updating Cnic's Name
	bool update_fname(a n_fname, int CNIC) {
		if (is_empty()) {
			return false;				//Checking for Empty list
		}
		else {
			CBID_NODE<a>* newnode = head;
			while (newnode->next != NULL && newnode->cnic != CNIC) {
				newnode = newnode->next;							//Searching For CNIC
			}
			newnode->f_name = n_fname;
			cout << "Updated Father Name: " << newnode->f_name << endl;
			string s1 = newnode->name + " " + newnode->f_name + " " + newnode->gender + " " + newnode->address + " " + newnode->nationality;
			cout << s1 << endl;
			return true;
		}
		return false;
	}

	//Function For Updating Cnic's Name
	bool update_address(a naddress, int CNIC) {
		if (is_empty()) {						//Checking for Empty list
			return false;
		}
		else {
			CBID_NODE<a>* newnode = head;
			while (newnode->next != NULL && newnode->cnic != CNIC) {
				newnode = newnode->next;								//Searching For CNIC
			}
			newnode->address = naddress;
			cout << "Updated address: " << newnode->address << endl;
			string s1 = newnode->name + " " + newnode->f_name + " " + newnode->gender + " " + newnode->address + " " + newnode->nationality;
			cout << s1 << endl;
			return true;
		}
		return false;
	}

	//Function For Updating Cnic's Name
	bool update_nationality(a n_nationality, int CNIC) {
		if (is_empty()) {							//Checking for Empty list
			return false;
		}
		else {
			CBID_NODE<a>* newnode = head;
			while (newnode->next != NULL && newnode->cnic != CNIC) {
				newnode = newnode->next;						//Searching For CNIC
			}
			newnode->nationality = n_nationality;
			cout << "Updated Nationality: " << newnode->nationality << endl;
			string s1 = newnode->name + " " + newnode->f_name + " " + newnode->gender + " " + newnode->address + " " + newnode->nationality;
			cout << s1 << endl;
			return true;
		}
		return false;
	}

	//Function For Displaying DAta Of CNIC given
	a& display(int CNIC) {
		string* temp = new string("\0");
		if (!head) {
			return *temp;			//Check for Empty List
		}
		CBID_NODE<a>* i = head;
		while (i) {
			if (i->cnic == CNIC) {
				*temp = i->name + " " + i->f_name + " " + i->gender + " " + i->address + " " + i->nationality;		//Storing Cnic's Data in a string
				return *temp;
			}
			i = i->next;
		}
		return *temp;			//Returning String Data To Bool Function
	}

	//Function For Printing All Data In List
	void print() {
		if (head == NULL) {
			cout << "list is empty" << endl;			// Checking For Empty List
		}
		else {
			CBID_NODE<a>* i = head;
			while (i) {
				cout << i->cnic << " " << i->name << " " << i->f_name << " " << i->gender << " " << i->address << " " << i->nationality << endl;		//Printing Data As a Single Line
				i = i->next;
			}
		}
	}

	bool is_empty() {
		if (head == NULL) {				//Empty Function For Chacking List
			return true;
		}
		else
			return false;
	}
};

class crimenode {

public:
	crimenode* next;
	string crime;			// next pointer for next node
	string punishment;		// Data For Crime of A CNIC
	string fine;
	crimenode() {			// Default Constructor
		next = NULL;
	}
	//ParaMeterized Constructor
	crimenode(string ncrime, string npunish, string nfine) {
		crime = ncrime;
		punishment = npunish;
		fine = nfine;
	}
};

class crimelist {
public:
	crimenode* head;
	crimelist() {//Default Constructor
		head = NULL;
	}

	bool insert(string crime, string punishment, string fine) {//Inserting Crime 
		if (!head) {
			crimenode* newnode = new crimenode(crime, punishment, fine);
			head = newnode;//Inserting Crime For !st Node
			newnode->next = NULL;
			return true;
		}
		else {
			crimenode* curr = new crimenode(crime, punishment, fine);
			curr->next = head;
			head = curr;
			return true;
		}
		return false;
	}

	//Function For Displaying Or returning Data in crimeslist
	string display(int cnic) {
		string* temp = new string;
		if (!head) {			//Check For Empty List
			return *temp;
		}
		crimenode* i = head;
		while (i) {//Storing Data in a string
			*temp = *temp + " " + i->crime + " " + i->punishment + " " + i->fine;
			i = i->next;
		}
		return *temp;// Returning String Data of Given CNIC
	}

	//Function for printing all Data in the List 
	void print() {
		if (!head) {//Empty list check
			cout << "list is empty" << endl;
		}
		else {//Displaying Data
			crimenode* i = head;
			while (i) {
				cout << " " << i->crime << " " << i->punishment << " " << i->fine << "  ";
				i = i->next;
			}
		}
		cout << endl;
	}
};

template<class a>
struct CCID_NODE {
	CCID_NODE<a>* next;
	CCID_NODE<a>* previous;//Pointers For Nodes
	int cnic;
	crimelist c;//Data Members
	crimenode c1;
	CBID_NODE<a> link;
	CCID_NODE() {//Default Constructor
		next = previous = NULL;
	}
	CCID_NODE(int ncnic, a charges, a punishment, a fine) {//Parameterize Constructor
		next = previous = NULL;
		cnic = ncnic;
		c.insert(charges, punishment, fine);//Calling Insert Function From Crimelist to nest crime at each relative node
	}
};

template<class T>
class CCIDList {
	CCID_NODE<T>* head;
	CCID_NODE<T>* tail;
public:
	CBIDList<T> link;
	CCIDList() {//Default Constructor
		head = tail = NULL;
	}

	//Function For inserting read Data in Link List
	void insert(int cnic, T charges, T punishment, T fine) {
		if (!head) {
			CCID_NODE<T>* newnode = new CCID_NODE<T>(cnic, charges, punishment, fine);
			head = newnode;//Inserting First Data
			tail = head;
		}
		else {
			CCID_NODE<T>* temp = head;
			while (temp != tail) {
				temp = temp->next;
			}
			temp->next = new CCID_NODE<T>(cnic, charges, punishment, fine);
			temp->next->previous = tail;
			tail = tail->next;
			tail->next = head;
		}
	}

	//Function For Updating Crime
	bool addcrime(int cnic, T charges, T punishment, T fine){
		if (is_empty()) {
			
			return false;
		}
		else {
			CCID_NODE<T>* curr = head;
			while (curr->cnic != cnic) {
				curr = curr->next;
			}
			curr->c.insert(charges, punishment, fine);
			return true;
		}
		return false;
	}

	//Function For Adding Crime
	bool updatecrime(int CNIC, T charges, T punishment, T fine) {
		if (is_empty()) {
			return false;
		}
		else {
			CCID_NODE<T>* curr = head;
			while (curr->next!=head && curr->cnic != CNIC) {
				curr = curr->next;
			}
			curr->c.head->crime = charges;
			curr->c.head->punishment = punishment;
			curr->c.head->fine = fine;
			return true;
		}
		return false;
	}

	//Function for deleting a crime
	bool deletecrime(int CNIC, T charges, T punishment, T fine) {
		if (is_empty())			//Check for empty list
			return false;
		else {//Checks given data in file, if matches function deletes the crime/node 
			CCID_NODE<T>* newnode = head;
			while (newnode->cnic != CNIC && newnode->c.head->crime != charges && newnode->c.head->punishment != punishment && newnode->c.head->fine != fine) {
				newnode = newnode->next;
			}
			newnode->previous->next = newnode->next;
			newnode->next->previous = newnode->previous;
			delete newnode;
			return true;
		}
		return false;
	}

	//Function  for displaying CCID DATA for given CNIC
	T& display(int CNIC) {
		string* temp = new string("\0");
		if (!head) {
			return *temp;//Check For Empty List
		}
		CCID_NODE<T>* i = head;

		while (i->next != head) {
			if (i->cnic == CNIC) {
				*temp = i->c.display(CNIC);//Storing Information in string
				return *temp;
			}
			i = i->next;
		}
		return *temp;//Returns a string data
	}

	//Function for checking if list is empty or not
	bool is_empty() {
		if (head == NULL)
			return true;
		else
			return false;
	}

	//Function for Printing Link list CCId
	void print() {
		if (head == NULL) {//Empty list check
			cout << "list is empty" << endl;
		}
		else {//Displaying Data
			CCID_NODE<T>* i = head;
			while (i->next != head) {
				cout << " " << i->cnic;
				i->c.print();
				i = i->next;
			}
			cout << " "<<i->cnic;
			i->c.print();
		}
	}
	//A freind Function for displaying output of CCID list containing Crimelist
	friend ostream& operator<<(ostream& out, CCIDList& obj) {
		obj.display();
		out << endl;
		return out;
	}
};

template <class T>
class Database {
public:
	CBIDList<T> CBID; //CBID Database
	CCIDList<T> CCID; //CCID Database
	CCID_NODE<T> cn;
	crimelist cl;
	DataPipeline<T> dataPipeline;


	//Parameterized Constructor
	Database(const T& filename, const T& filename1) {
		stringstream ss;
		ifstream file;
		file.open("CBID.txt", ios::in);//reading CBID Text File
		while (!file.eof()) {
			string str;
			getline(file, str);//Getting A line from CBID
			dataPipeline.enqueue(str);// And Enqueueing it in datapipeline Queue
		}
		while (!dataPipeline.is_empty()) {
			string temp = dataPipeline.dequeue();//returning value from function gets stored in string
			stringstream mine;
			int CNIC;
			T name, fname, gender, address, nationality;
			mine << temp;
			mine >> CNIC;
			mine << temp;						//spliting data of string into relative variable 
			mine >> name;						//with the help of stringstream
			mine << temp;
			mine >> fname;
			mine << temp;
			mine >> gender;
			for (int i = 0; i < 3; i++) {
				string temp2 = "\0";
				mine << temp;					//Address Has three words 
				mine >> temp2;					//So it is created by adding threee words after gender in CBID
				address = address + temp2 + " ";
			}
			address.pop_back();				//Poping garbage
			mine << temp;
			mine >> nationality;
			int i = 0;
			while (i < 4 && nationality.length()>0) {
				nationality.pop_back();			//Poping garbage value at the end if string
				i++;
			}
			//Inserting data collected withhelp of stringstream into CBID LIST
			CBID.insert(CNIC, name, fname, gender, address, nationality);
		}
		file.close();//CLosing CBID's File


		stringstream ss1;
		ifstream nfile;
		nfile.open("CCID.txt", ios::in);//Opening & Reading CCID's file
		while (!nfile.eof()) {
			string str1;
			getline(nfile, str1);//Getting input line by line from file
			dataPipeline.enqueue(str1);// and enqueueing it in Queue
		}
		while (!dataPipeline.is_empty()) {
			string temp1 = dataPipeline.dequeue();//returning value from function gets stored in string
			stringstream mine1;
			int cnic;
			T charges, punishment, fine;
			mine1 << temp1;
			mine1 >> cnic;						//spliting data of string into relative variable
			mine1 << temp1;						//with the help of stringstream
			mine1 >> charges;
			for (int i = 0; true; i++) {
				string temp2 = "\0";
				mine1 << temp1;					//Punishment Comprises of 3,4 words 
				mine1 >> temp2;					//but prison is a common word in every punishment
				punishment = punishment + temp2 + " ";//so punishment string adds until prison comes
				if (temp2 == "prison")
					break;
			}
			punishment.pop_back();				//Poping garbage
			mine1 << temp1;
			mine1 >> fine;
			int i = 0;
			while (i < 4 && fine.length()>0) {
				fine.pop_back();				//Poping Garbage at the end of string
				i++;
			}
			//Inserting data collected withhelp of stringstream into CBID LIST
			CCID.insert(cnic, charges, punishment, fine);
		}
		nfile.close();//Closing CCID file
		cout << "\t\tDisplaying CBID LIST\n\n";
		CBID.print();
		cout << endl;
		cout << "\n\t\tDisplaying CCID List\n\n";
		CCID.print();
		cout << endl;
		cout << "\nDisplaying cnic 8943\n";
		cout << CBID_Search_by_CNIC(8943);
		cout << endl;
		cout << "\nDisplaying cnic 9662\n";
		cout << CCID_Search_by_CNIC(9662);
		cout << endl;
		cout << "\n\n";
		addCrime(7098, "Thanday Jokes", "Umer Qaid", "100000");
		updateCrime(6480, "theeta", "Death Sentence", "5000");
		CCID.print();
		cout << "Deleting node 6480\n";
		deleteCrime(6480, "theeta", "Death Sentence", "5000");
		CCID.print();

	}

	/*Return a string in following format "Name FName Gender Address Nationality Crimes(if any) Charges punishment fine number network activation_date deactivation_date status"
	 Refer to test cases for further clerification*/
	
	T& CBID_Search_by_CNIC(int cnic) {
		//returning display function in CBID which shows the data of given CNIC
		cout<<CBID.display(cnic);
		cout<<CCID.display(cnic)<<endl;
		string *x = new string("");
		return *x;
	}

	T& CCID_Search_by_CNIC(int cnic) {
		//returning display function in CCID which shows the data of given CNIC
		cout<<CBID.display(cnic);
		cout<<CCID.display(cnic)<<endl;
		string *x = new string("");
		return *x;
	}

	bool updateCBIDName(T Name, int cnic) {
		/*update and return true when cnic found else return false
		update name function in Cbid gets called which updates the name of given cnic*/

		return CBID.update_name(Name, cnic);
	}

	bool updateCBIDFName(T Father_Name, int cnic) {
		/*update and return true when cnic found else return false
		* update father name function in Cbid gets called which updates the name of given cnic*/

		return CBID.update_fname(Father_Name, cnic);
	}

	bool updateCBIDAddress(T Address, int cnic) {
		/*update and return true when cnic found else return false
		update address function in Cbid gets called which updates the name of given cnic*/

		return CBID.update_address(Address, cnic);
	}

	bool updateCBIDNationality(T Nationality, int cnic) {
		/*update and return true when cnic found else return false
		update nationality function in Cbid gets called which updates the name of given cnic*/

		return CBID.update_nationality(Nationality, cnic);
	}
	bool addCrime(int cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false
		 add crime function in CCid gets called which add crimes according to the conditions
		For Details: See Add Crime Function in CCIDList*/

		return CCID.addcrime(cnic, charges, punishment, fine);
	}

	bool updateCrime(int cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false
		 update crime function in CCid gets called which updates crimes of the given cnic if exists
		For Details: See Update Crime Function in CCIDList*/

		return CCID.updatecrime(cnic, charges, punishment, fine);
	}

	bool deleteCrime(int cnic, T charges, T punishment, T fine) {
		/*update and return true when crime found else return false
		 Delete crime function in CCid gets called which deltes crimes according to the conditions
		For Details: See delete Crime Function in CCIDList*/
		
		return CCID.deletecrime(cnic, charges, punishment, fine);
	}

	~Database() {
		/* deallocate and cleanup */
	}
};

int main() {
	Database<string> db("CBID.txt", "CCID.txt");
	return 0;
}
//#endif
