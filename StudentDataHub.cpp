#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Basic_Details
{
    string first_name, last_name, sex, dob, mob_no, email, hno, city1, state1, father_name, mother_name, father_mobno, mother_mobno, aadhar;
    int pin1;
    char gender;

public:
    // constructor to initialise the attributes
    Basic_Details()
    {
        first_name = "fname";
        last_name = "lname";
        sex = "male";
        dob = "01012000";
        mob_no = "9876543211";
        email = "someone@gmail.com";
        hno = "01";
        city1 = "Noida";
        state1 = "UP";
        father_name = "father";
        mother_name = "mother";
        father_mobno = "9876512345";
        mother_mobno = "6789123455";
        aadhar = "111122223333";
        pin1 = 201301;
        gender = 'm';
    }

    //function to register basic details in the BasicDetails.csv file
    void register_basic_details(int enroll)
    {
        int flag = 0;

        cout << "Enter student's first name : ";
        cin >> first_name;

        cout << "Enter student's last name : ";
        cin >> last_name;

        while (flag == 0)
        {
            cout << "Enter gender(M/F) : ";
            cin >> gender;

            if (gender != 'M' && gender != 'F' && gender != 'm' && gender != 'f')
            {
                flag = 0;
            }
            else
            {
                flag = 1;
                if (gender = 'M' || gender == 'm')
                    sex = "Male";
                else
                    sex = "Female";
            }
        }
        cout << "Enter DOB(DDMMYYYY):";
        cin >> dob;

        flag = 0;
        while (flag == 0)
        {
            cout << "enter mobile number(10 digits):";
            cin >> mob_no;

            //checking whether the mob no is 10 digit otherwise asking the user to reinput
            if (mob_no.length() == 10)
            {
                flag = 1;
            }
            else
            {
                cout << "enter valid Mobile Number" << endl;
                flag = 0;
            }
        }

        cout << "Enter email address:";
        cin >> email;

        cout << "Enter AADHAR number(12 digit):";
        cin >> aadhar;

        cout << "Permanent address -> " << endl;
        cout << "House no./Area/Locality:";
        fflush(stdin);
        getline(cin, hno);
        fflush(stdin);

        cout << "Enter the city : ";
        cin >> city1;

        cout << "Enter the state : ";
        cin >> state1;

        cout << "enter pin code:";
        cin >> pin1;

        cout << "Father's Name:";
        fflush(stdin);
        getline(cin, father_name);
        fflush(stdin);

        cout << "Father's Mobile number:";
        cin >> father_mobno;

        cout << "Mother's Name:";
        fflush(stdin);
        getline(cin, mother_name);
        fflush(stdin);

        cout << "Mother's Mobile number:";
        cin >> mother_mobno;

        fstream fp("BasicDetails.csv", ios::app);
        // opening a file

        //appending data in the file
        fp << enroll << "," << first_name << "," << last_name << "," << sex << "," << dob << "," << mob_no << "," << email << "," << aadhar << "," << hno << "," << city1 << "," << state1 << "," << pin1 << "," << father_name << "," << father_mobno
           << "," << mother_name << "," << mother_mobno << endl;
        
        fp.close();
        //closing a file

        cout << "\n";
        cout << "Basic Details Registered Successfully..." << endl;
    }

    //display basic details of all students from BasicDetails.csv file
    void display_basic_details()
    {
        fstream fp("BasicDetails.csv", ios::in);
        //opening a file in read mode

        string line, word;

        cout << "EnrNo\tFirstN\tLastN\tGender\tDateOfBirth\tMobile Number\tEmail ID\tAadhar Card No\tH.No/Area\tCity\tState\tPincode\tFather Name\tFather MobNo\tMother Name\tMother MobNo" << endl;
        while (getline(fp, line)) //reading a whole line from the csv file
        {
            //convert string to stringstream
            stringstream s(line);

            while (getline(s, word, ',')) //reading one field at a time
            {
                cout << word << "\t";
            }
            cout << endl;
        }

        fp.close();
        //closing a file
    }

    void search_basic_details(int enroll)
    {

        fstream fp("BasicDetails.csv", ios::in);
        //opening a file in read mode

        string line, word;
        int flag = 0;
        vector<string> v;

        while (getline(fp, line))
        {
            stringstream s(line);
            //convert string to stringstream

            while (getline(s, word, ',')) //reading one field at a time
            {
                v.push_back(word);
                //pushing each field into a vector for ease in searching and readability
            }

            if (stoi(v[0]) == enroll)
            {

                flag = 1;

                //retrieving from vector
                cout << " *************Student personal details*************" << endl;
                cout << " Enrollment Number:" << v[0] << endl;
                cout << " Name : " << v[1] << " " << v[2] << endl;
                cout << " Gender :  " << v[3] << endl;

                cout << " Date of birth : " << v[4] << endl;

                cout << " Mobile no : " << v[5] << endl;
                cout << " Email ID : " << v[6] << endl;
                cout << " Aadhar no : " << v[7] << endl;
                cout << endl;
                cout << "****************************************************" << endl;
                cout << endl;
                cout << " Permanent Address -> " << endl;
                cout << " House no./ Area/ Locality:" << v[8] << endl;
                cout << " City : " << v[9] << endl;
                cout << " State : " << v[10] << endl;
                cout << " Pincode : " << v[11] << endl;
                cout << "****************************************************" << endl;
                cout << " Father's name : " << v[12] << endl;
                cout << " Father's contact number : " << v[13] << endl;
                cout << "****************************************************" << endl;
                cout << " Mother's name : " << v[14] << endl;
                cout << " Mother's contact number : " << v[15] << endl;
                cout << "****************************************************" << endl;
            }

            v.clear();
            //clearing the vector for next input
        }

        //condition if enrolment number not found
        if (flag == 0)
        {
            cout << "No student with this enrollment number." << endl;
        }

        fp.close();
        //closing a file
    }
};

class Medical_Details
{
    char hypertension, mellitus, asthma, bronchitis;
    char any_congenital_disease, any_surgery_or_accident, any_drug_intake;

public:
    // constructor to initialise the attributes
    Medical_Details()
    {
        hypertension = 'n';
        mellitus = 'n';
        asthma = 'n';
        bronchitis = 'n';
        any_congenital_disease = 'n';
        any_surgery_or_accident = 'n';
        any_drug_intake = 'n';
    }

    //function to ask the user whether he/she has hypertension
    char Hypertension()
    {
        char ch;
        cout << "Do you have Hypertension (Y/N) : ";
        cin >> ch;

        while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n')
        {
            cout << "invalid input.Try Again...";
            cin >> ch;
        }

        return ch;
    }

    //function to ask the user whether he/she has diabetes mellitus
    char Mellitus()
    {
        char ch;
        cout << "Do you have Diabetes Mellitus (Y/N) : ";
        cin >> ch;

        while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n')
        {
            cout << "invalid input.Try Again...";
            cin >> ch;
        }

        return ch;
    }

    //function to ask the user whether he/she has asthma
    char Asthma()
    {
        char ch;
        cout << "Do you have Asthma (Y/N) : ";
        cin >> ch;

        while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n')
        {
            cout << "invalid input.Try Again...";
            cin >> ch;
        }

        return ch;
    }

    //function to ask the user whether he/she has bronchitis
    char Bronchitis()
    {
        char ch;
        cout << "Do you have Bronchitis (Y/N) : ";
        cin >> ch;

        while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n')
        {
            cout << "invalid input.Try Again...";
            cin >> ch;
        }

        return ch;
    }

    //function to ask the user whether he/she has Any congenital disease
    char Any_congenital_disease()
    {
        char ch;
        cout << "Do you have any congenital disease (Y/N) : ";
        cin >> ch;

        while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n')
        {
            cout << "invalid input.Try Again...";
            cin >> ch;
        }

        return ch;
    }

    //function to ask the user whether he/she has any_surgery_or_accident
    char Any_surgery_or_accident()
    {
        char ch;
        cout << "Do you have any surgery or accident (Y/N) : ";
        cin >> ch;

        while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n')
        {
            cout << "invalid input.Try Again...";
            cin >> ch;
        }

        return ch;
    }

    //function to ask the user whether he/she has Any_drug_intake
    char Any_drug_intake()
    {
        char ch;
        cout << "Do you have any drug intake (Y/N) : ";
        cin >> ch;

        while (ch != 'Y' && ch != 'N' && ch != 'y' && ch != 'n')
        {
            cout << "invalid input.Try Again...";
            cin >> ch;
        }

        return ch;
    }

    //function to register basic details in the MedicalDetails.csv file
    void register_medical_details(int enroll)
    {

        //asking the user for medical details
        cout << "Enter Medical Details : " << endl;
        hypertension = Hypertension();
        mellitus = Mellitus();
        asthma = Asthma();
        bronchitis = Bronchitis();
        any_congenital_disease = Any_congenital_disease();
        any_surgery_or_accident = Any_surgery_or_accident();
        any_drug_intake = Any_drug_intake();

        fstream fp("MedicalDetails.csv", ios::app);
        //opening a file in append mode

        fp << enroll << "," << hypertension << "," << mellitus << "," << asthma << "," << bronchitis << "," << any_congenital_disease << "," << any_surgery_or_accident << "," << any_drug_intake << endl;
        
        fp.close();
        //closing a file

        cout << "\n";
        cout << "Medical Details Registered Successfully..." << endl;
    }

    //to display medical details of all students from MedicalDetails.csv file
    void display_medical_details()
    {
        fstream fp("MedicalDetails.csv", ios::in);
        //opening a file in read mode

        string line, word;

        cout << "EnrNo\tHypertension\tMellitus\tAsthma\tBronchitis\tAnyCongenitalDisease\tAnySurgery\tAnyDrugIntake" << endl;
        while (getline(fp, line)) //retrieving a whole line from file
        {
            //convert string to stringstream
            stringstream s(line);

            //retrieving one field at a time from line
            while (getline(s, word, ','))
            {
                if (word.compare("y") == 0 || word.compare("Y") == 0)
                {
                    cout << "YES"
                         << "\t\t";
                }
                else if (word.compare("n") == 0 || word.compare("N") == 0)
                {
                    cout << "NO"
                         << "\t\t";
                }
                else
                {
                    cout << word << "\t";
                }
            }
            cout << endl;
        }

        fp.close();
        //closing a file
    }
    
    //to search medical details of a student using enrolment number
    void search_medical_details(int enroll)
    {
        fstream fp("MedicalDetails.csv", ios::in);
        //opening a file in read mode

        string line, word;
        int flag = 0;
        vector<string> v;

        //reading one line at a time from file
        while (getline(fp, line))
        {
            stringstream s(line);
            //converting string to stringstream

            //reading one field at a time from line
            while (getline(s, word, ','))
            {
                v.push_back(word);
                //pushing one field at a time in vector for ease in searching and readability
            }
            
            //checking whether the enrolment found or not
            if (stoi(v[0]) == enroll)
            {
                flag = 1;

                //displaying the details if the enrolment number mactches
                cout << "*********Student's Medical History******************" << endl;
                cout << "Enrollment Number:" << v[0] << endl;
                cout << "Hypertension = " << v[1] << endl;
                cout << "Diabetes Mellitus = " << v[2] << endl;
                cout << "Asthma = " << v[3] << endl;
                cout << "Bronchitis = " << v[4] << endl;
                cout << "Congenital Disease = " << v[5] << endl;
                cout << "Surgery OR Accident = " << v[6] << endl;
                cout << "Drug Intake = " << v[7] << endl;
                cout << "****************************************************" << endl;
            }

            v.clear();
            //clearing the vector for next lines of file
        }

        //condition if enrolment number not found
        if (flag == 0)
        {
            cout << "No student with this enrollment number." << endl;
        }

        fp.close();
        //closing a file
    }
};

class Bank_Details
{
    string name_of_account_holder;
    long long int account_no;
    string name_of_bank;
    string branch;
    string IFSC_code;

public:
    // constructor to initialise the attributes
    Bank_Details()
    {
        name_of_account_holder = "name";
        account_no = 1234567812345678;
        name_of_bank = "ICICI bank";
        branch = "noida";
        IFSC_code = "ABCD1234560";
    }

    //function to append bank details in BankDetails.csv file
    void register_bank_details(int enroll)
    {

        cout << "Enter the student's bank details -> " << endl;
        cout << "Enter Account holder's name:";
        fflush(stdin);
        getline(cin, name_of_account_holder);
        fflush(stdin);

        cout << "Enter Account number:";
        fflush(stdin);
        cin >> account_no;
        fflush(stdin);

        cout << "Enter name of the bank:";
        fflush(stdin);
        getline(cin, name_of_bank);
        fflush(stdin);

        cout << "Enter branch name:";
        fflush(stdin);
        getline(cin, branch);
        fflush(stdin);

        cout << "Enter the IFSC code:";
        fflush(stdin);
        getline(cin, IFSC_code);
        fflush(stdin);

        fstream fp("BankDetails.csv", ios::app);
        //opening a file in append mode

        fp << enroll << "," << name_of_account_holder << "," << account_no << "," << name_of_bank << "," << branch << "," << IFSC_code << endl;
        //appending data into the file

        fp.close();
        //closing a file

        cout << "\n";
        cout << "Bank Details Registered Successfully..." << endl;
    }

    //function to display bank details of all students from BankDetails.csv file
    void display_bank_details()
    {
        fstream fp("BankDetails.csv", ios::in);
        //opening file in read mode

        string line, word;

        cout << "EnrNo\tNameOfHolder\tAccountNo\tBank\tBranch\tIFSC Code" << endl;

        //reading one line at a time from file
        while (getline(fp, line))
        {
            stringstream s(line);
            //converting string to string stream

            //reading one filed at a time from line
            while (getline(s, word, ','))
            {
                cout << word << "\t";
            }
            cout << endl;
        }

        fp.close();
        //closing a file
    }

    //function to search all bank details of a student using enrolment number
    void search_bank_details(int enroll)
    {
        fstream fp("BankDetails.csv", ios::in);
        //opening a file in read mode

        string line, word;
        int flag = 0;
        vector<string> v;

        //reading one line at a time from file
        while (getline(fp, line))
        {
            stringstream s(line);
            //converting string to string stream

            //reading one field at a time from file
            while (getline(s, word, ','))
            {
                v.push_back(word);
                //pushing field into vector for ease in searching and readability
            }
            //checking whether enrolment matches or not
            if (stoi(v[0]) == enroll)
            {
                flag = 1;

                //retriving fields from the vector and printing
                cout << "***************Student's Bank details***************" << endl;
                cout << "****************************************************" << endl;
                cout << "Enrollment Number:" << v[0] << endl;
                cout << "Name : " << v[1] << endl;
                cout << "Account No. : " << v[2] << endl;
                cout << "Name of the Bank : " << v[3] << endl;
                cout << "Branch:" << v[4] << endl;
                cout << "IFSC Code :  " << v[5] << endl;
                cout << "****************************************************" << endl;
            }

            v.clear();
            //clearing the vector for next lines of file
        }

        //condition runs if enrolment number not found in the file
        if (flag == 0)
        {
            cout << "No student with this enrollment number." << endl;
        }

        fp.close();
        //closing a file
    }
};

class Student : public Basic_Details, public Medical_Details, public Bank_Details
{
    int enroll, sem;

public:
    // constructor to initialise the attributes
    Student()
    {
        enroll = 1;
        sem = 1;
    }

    //to set enroll attribute
    void set_enroll()
    {
        cout << "\n";
        cout << "enter enrollment number:";
        cin >> enroll;
        cout << "\n";
    }

    //to return enroll
    int get_enroll()
    {
        return enroll;
    }

    //to register all details of a student
    void register_Student()
    {
        set_enroll();

        cout << "REGISTER BASIC DETAILS->" << endl;
        register_basic_details(enroll);
        cout << "\n";

        cout << "REGISTER MEDICAL DETAILS->" << endl;
        register_medical_details(enroll);
        cout << "\n";

        cout << "REGISTER BANK DETAILS->" << endl;
        register_bank_details(enroll);
        cout << "\n";

        cout << "\n";
        cout << "Student Registered Successfully." << endl;
        cout << "\n";
    }

};

class LoginPage : public Student
{
    string id, password;
    string p, q;
    int ch;
    char n;

public:
    // constructor to initialise the attributes
    LoginPage()
    {
        id = "";
        password = "";
        p = "admin";
        q = "12345";
        ch = 0;
        n = 'y';
    }

    int welcome()
    {
        cout << "********************************************************************" << endl;
        cout << "*************JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY*************" << endl;
        cout << "**************************Sector-62, Noida**************************" << endl;
        cout << "********************************************************************" << endl;
        cout << endl;
        cout << "********************************************************************" << endl;
        cout << "************************* STUDENT DATA HUB *************************" << endl;
        cout << "********************************************************************" << endl;
        cout << endl;
    }

    void login()
    {
        int flag = 1;

        cout << endl;
        cout << "********************************************************************" << endl;
        cout << "**************************** LOGIN PAGE ****************************" << endl;
        cout << "********************************************************************" << endl;
        cout << endl;

        while (flag == 1)
        {
            cout << endl;
            cout << "Enter user ID and password:" << endl;
            cin >> id;
            cin >> password;

            // condition to check credentials entered by user
            if (password.compare(q) || id.compare(p))
            {
                cout << endl;
                cout << "Wrong id or Password. Please Try Again" << endl;
                flag = 1;
            }
            else
            {
                flag = 0;
                cout << endl;
                cout << "********************************************************************" << endl;
                cout << "************************** Access Granted! *************************" << endl;
                cout << "********************************************************************" << endl;
                cout << endl;
            }
        }
    }

    int menu()
    {
        while (n == 'y' || n == 'Y')
        {
            cout << "************************** MENU *************************" << endl;
            cout << endl;
            cout << "1. Register student details" << endl;
            cout << "2. View all students Basic Details" << endl;
            cout << "3. View all students Medical Details" << endl;
            cout << "4. View all students Bank Details" << endl;
            cout << "5. Search all details of a student using enrollment number" << endl;
            cout << "6. Display Basic Details of a student using enrollment number" << endl;
            cout << "7. Display Medical Details of a student using enrollment number" << endl;
            cout << "8. Display Bank Details of a student using enrollment number" << endl;
            cout << "\n";
            cout << "Enter operation you want to perform:";
            cin >> ch;
            cout << "\n";

            switch (ch)
            {
            case 1:
                register_Student();
                break;

            case 2:
                display_basic_details();
                break;

            case 3:
                display_medical_details();
                break;

            case 4:
                display_bank_details();
                break;

            case 5:
                set_enroll();

                cout << "Basic Details:" << endl;
                search_basic_details(get_enroll());
                cout << "\n\n";

                cout << "Medical Details:" << endl;
                search_medical_details(get_enroll());
                cout << "\n\n";

                cout << "Bank Details:" << endl;
                search_bank_details(get_enroll());
                cout << "\n\n";

                break;

            case 6:
                set_enroll();

                cout << "Basic Details:" << endl;
                search_basic_details(get_enroll());

                break;

            case 7:
                set_enroll();

                cout << "Medical Details:" << endl;
                search_medical_details(get_enroll());

                break;

            case 8:
                set_enroll();

                cout << "Bank Details:" << endl;
                search_bank_details(get_enroll());

                break;

            default:
                cout << "Wrong choice." << endl;
            }

            cout << endl;
            cout << "********************************************************************" << endl;
            cout << "***************************** THANK YOU ****************************" << endl;
            cout << "********************************************************************" << endl;
            cout << endl;

            cout << "\n";
            cout << "Do you want any more operation to be performed?(y/n)\n";
            fflush(stdin);
            cin >> n;
            fflush(stdin);
        }
    }
};

int main()
{
    LoginPage lp;
    lp.login();
    lp.welcome();
    lp.menu();
    return 0;
}