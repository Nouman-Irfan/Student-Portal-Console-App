#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    //Menu of Portal
    cout << "============================================" << endl;
    cout << "HELLO STUDENTS WELCOME TO THE STUDENT PORTAL" << endl;
    cout << "============================================" << endl;
    system("pause");
	cout << "********************************************" << endl;
    cout << "* 1 - Register\n* 2 - Log In\n* 3 - Calculate Result\n* 4 - Print Result\n* 5 - Print All" << endl;
    cout << "********************************************" << endl;
	//Taking User Choice from menu
    int choice = 0;
    cout << "Enter Your Choice: ";
    cin >> choice;
    cout << "********************************************" << endl;

	//Account Setup and Registration
    if (choice == 1)
    {
        cout << "Welcome to the Registration Page" << endl;
        cout << "Lets Setup Your Account" << endl;
        cout << "********************************************" << endl;

		//Variables for Registration
        char registration[20] = { '\0' };
        char password[20] = { '\0' };
        char total_registartions[20] = { '\0' };

		//fileing of registration and password
        ifstream read;
        ofstream write;

		//Counting Total Registrations to Assign Serial Number
        int count = 0;

        read.open("reg.txt");
        if (!read.is_open())
        {
            cout << "File Not Found!!!!" << endl; //if file is not found
            cout << "********************************************" << endl;
        }
        else
        {
            while (!read.eof())
            {
                read.getline(total_registartions, 20);
                if (read)
                {
                    count++; //couting total registrations
                }
            }
            read.close();

            bool registration_successful = true; //used to check if registration is successful or not
            //help to break while(true) loop
            while (true)
            {
                //taking registration input from user
                cout << "Enter Student ID For Registration: ";
                cin >> registration;
                cout << "********************************************" << endl;

                //write registration in file with serial number
                write.open("reg.txt", ios::app);
                write << count + 1 << ". " << registration << endl;
                write.close();

                //taking password input from user
                cout << "Enter Password for Your Account: ";
                cin >> password;
                cout << "********************************************" << endl;

                //write password in file with serial number
                write.open("pswd.txt", ios::app);
                write << count + 1 << ". " << password << endl;
                write.close();

                //checking if registration is successful or not
                if (!registration_successful)
                {
                    cout << "Registration is not Successful...\nRegister Again" << endl;
                    cout << "********************************************" << endl;
                }
                else
                {
                    cout << "Registration Successful!" << endl;
                    cout << "********************************************" << endl;
                    break;
                }
            }
        }
    }
	//Log In Verification
    else if (choice == 2)
    {

        cout << "WELCOME TO LOG IN PAGE" << endl;
        cout << "********************************************" << endl;

		//arrays to store registration and password from file
        char registration[20] = { '\0' };
        char password[20] = { '\0' };

		//arrays to store registration and password from user
        char login_registration[20] = { '\0' };
        char login_password[20] = { '\0' };

		//arrays to store serial numbers from file
        char serial_number[20] = { '\0' };
        char registartion_serial_number[20] = { '\0' };
        char password_serial_number[20] = { '\0' };

		//used to check if login is successful or not
        bool login_successful = false;

        while (true)
        {
			//taking registration input
            cout << "Enter Your Student ID: ";
            cin >> login_registration;
            cout << "********************************************" << endl;

			//reading registration file to verify registration
            ifstream read_registration;
            read_registration.open("reg.txt");
            if (!read_registration.is_open())
            {
                cout << "File Not Found!!!" << endl;
                cout << "********************************************" << endl;
            }
            else
            {
                bool registration_found = false;

				while (read_registration.getline(serial_number, 10, ' ') && //reading serial number and registration from file
                    read_registration.getline(registration, 20))
                {
                    if (read_registration.eof())
                    {
                        break;
                    }

                    int j = 0;
                    while (serial_number[j] != '\0')
                    {
						registartion_serial_number[j] = serial_number[j]; //store serial number in array 
						j++;                                              //to compare serial number of registration and password later
                    }

                    bool registration_match = true;

					//comparing registration input with registration from file
                    int i = 0;
                    while (login_registration[i] != '\0' && registration[i] != '\0')
                    {
                        if (login_registration[i] != registration[i])
                        {
                            registration_match = false;
                            break;
                        }
                        i++;
                    }
                    if (registration_match && login_registration[i] == '\0' && registration[i] == '\0')
                    {
                        cout << "Student ID Matched!" << endl;
                        cout << "********************************************" << endl;
                        registration_found = true;
                        break;
                    }
                }
				//if registration is not found in file
                if (!registration_found)
                {
                    cout << "ERROR!!!\nStudent ID Seems To Be Incorrect...Try Again" << endl;
                    cout << "********************************************" << endl;
                }
				//if registration is found then verify password
                else
                {
					//taking password input from user
                    cout << "Enter Your Password: ";
                    cin >> login_password;
                    cout << "********************************************" << endl;

					//reading password file to verify password
                    ifstream read_password;
                    read_password.open("pswd.txt");
                    if (!read_password.is_open())
                    {
                        cout << "File Not Found!!!" << endl;
                        cout << "********************************************" << endl;
                    }
                    else
                    {
                        bool password_found = false;

						while (read_password.getline(serial_number, 10, ' ') && //reading serial number and password from file
                            read_password.getline(password, 20))
                        {
                            if (read_password.eof())
                            {
                                break;
                            }

							//store serial number in array to compare with registration serial number
                            int j = 0;
                            while (serial_number[j] != '\0')
                            {
                                password_serial_number[j] = serial_number[j];
                                j++;
                            }

                            bool serial_number_match = true;

                            //match serial number of registration and password
                            int k = 0;
                            while (registartion_serial_number[k] != '\0' && password_serial_number[k] != '\0')
                            {
                                if (registartion_serial_number[k] != password_serial_number[k])
                                {
									serial_number_match = false;
                                    break;
                                }
                                k++;
                            }
                            if (!serial_number_match)
                            {
                                continue;
                            }

                            bool password_match = true;

							//comparing password input with password from file
                            int i = 0;
                            while (login_password[i] != '\0' && password[i] != '\0')
                            {
                                if (login_password[i] != password[i])
                                {
                                    password_match = false;
                                    break;
                                }
                                i++;
                            }
							//both c-strings should end at the same time for a match
                            if (password_match && login_password[i] == '\0' && password[i] == '\0')
                            {
                                cout << "Password Matched!" << endl;
                                password_found = true;
                                cout << "********************************************" << endl;
                                break;
                            }
                        }
						//if password is not found in file
                        if (!password_found)
                        {
                            cout << "You Entered an Incorrect Password!!!\nAccess Denied....Login Failed....Try Again" << endl;
                            cout << "********************************************" << endl;
                        }
						//if password is found then login is successful
                        else
                        {
                            cout << "Login Successful!" << endl;
                            login_successful = true;
                            cout << "********************************************" << endl;
                            cout << "Use Option 3 in Main Menu to Calculate Result" << endl;
                            cout << "Use Option 4 in Main Menu to Print Result" << endl;
                            cout << "********************************************" << endl;
                            break;
                        }
                        read_password.close();
                    }
                }
                read_registration.close();
            }
        }
    }
	//Calculate Result and Save in File
    else if (choice == 3)
    {
        cout << "It's time to Calculate your Result\nOops!!!" << endl;
        cout << "********************************************" << endl;
		cout << "Login Required To Calculate Result          " << endl;
        cout << "********************************************" << endl;
        cout << "To Log In ";
        system("pause");
        cout << "********************************************" << endl;
        cout << "WELCOME TO LOG IN PAGE" << endl;
        cout << "********************************************" << endl;

		//arrays to store registration and password from file
        char registration[20] = { '\0' };
        char password[20] = { '\0' };

		//arrays to store registration and password from user
        char login_registration[20] = { '\0' };
        char login_password[20] = { '\0' };

		//arrays to store serial numbers from file
        char serial_number[20] = { '\0' };
        char registartion_serial_number[20] = { '\0' };
        char password_serial_number[20] = { '\0' };

        bool login_successful = false;

		//same old logic of registration and password verification to log in the user before calculating result
		//if login is successful then calculate result and save in file
		//if login is not successful then keep asking for login until successful
        while (true)
        {
            cout << "Enter Your Student ID: ";
            cin >> login_registration;
            cout << "********************************************" << endl;

			//reading registration file to verify registration
            ifstream read_registration;
            read_registration.open("reg.txt");
            if (!read_registration.is_open())
            {
                cout << "File Not Found!!!" << endl;
                cout << "********************************************" << endl;
            }
            else
            {
                bool registration_found = false;

                while (read_registration.getline(serial_number, 10, ' ') && //reading serial number and registration from file
                    read_registration.getline(registration, 20))
                {
                    if (read_registration.eof())
                    {
                        break;
                    }

                    int j = 0;
                    while (serial_number[j] != '\0')
                    {
                        registartion_serial_number[j] = serial_number[j]; //store serial number in array 
						j++;                                              //to compare serial number of registration and password later
                    }

                    bool registration_match = true;

                    //comparing registration input with registration from file
                    int i = 0;
                    while (login_registration[i] != '\0' && registration[i] != '\0')
                    {
                        if (login_registration[i] != registration[i])
                        {
                            registration_match = false;
                            break;
                        }
                        i++;
                    }
                    if (registration_match && login_registration[i] == '\0' && registration[i] == '\0')
                    {
                        cout << "Student ID Matched!" << endl;
                        registration_found = true;
                        cout << "********************************************" << endl;
                        break;
                    }
                }
                if (!registration_found)
                {
                    cout << "ERROR!!!\nStudent ID Seems To Be Incorrect...Try Again" << endl;
                    cout << "********************************************" << endl;
                }
				//password verification logic is same as before
                else
                {
                    cout << "Enter Your Password: ";
                    cin >> login_password;
                    cout << "********************************************" << endl;

                    ifstream read_password;
                    read_password.open("pswd.txt");
                    if (!read_password.is_open())
                    {
                        cout << "File Not Found!!!" << endl;
                        cout << "********************************************" << endl;
                    }
                    else
                    {
                        bool password_found = false;

                        while (read_password.getline(serial_number, 10, ' ') &&
                            read_password.getline(password, 20))
                        {
                            if (read_password.eof())
                            {
                                break;
                            }

                            int j = 0;
                            while (serial_number[j] != '\0')
                            {
                                password_serial_number[j] = serial_number[j];
                                j++;
                            }

                            bool serial_number_match = true;

                            int k = 0;
                            while (registartion_serial_number[k] != '\0' && password_serial_number[k] != '\0')
                            {
                                if (registartion_serial_number[k] != password_serial_number[k])
                                {
                                    serial_number_match = false;
                                    break;
                                }
                                k++;
                            }

                            if (!serial_number_match)
                            {
                                continue;
                            }

                            bool password_match = true;

                            int i = 0;
                            while (login_password[i] != '\0' && password[i] != '\0')
                            {
                                if (login_password[i] != password[i])
                                {
                                    password_match = false;
                                    break;
                                }
                                i++;
                            }

                            if (password_match && login_password[i] == '\0' && password[i] == '\0')
                            {
                                cout << "Password Matched!" << endl;
                                password_found = true;
                                cout << "********************************************" << endl;
                                break;
                            }
                        }
                        if (!password_found)
                        {
                            cout << "You Entered an Incorrect Password!!!\nAccess Denied....Login Failed....Try Again" << endl;
                            cout << "********************************************" << endl;
                        }

                        else
                        {
                            cout << "Login Successful!" << endl;
							cout << "It's time to Calculate your Result" << endl;
                            cout << "********************************************" << endl;
                            login_successful = true;

							//Logic to Check if a student already has a result calculated and saved in the file or not
							//if result is already calculated then show message and break
							//if result is not calculated then take marks input and calculate result and save in file
							ifstream read_result;
							read_result.open("result.txt");
                            if (!read_result.is_open())
                            {
                                cout << "Unable to open the Result File..." << endl;
                                cout << "********************************************" << endl;
                            }

                            else
                            {
								//arrays to store serial 
								char result_serial_number[20] = { '\0' };
								char garbage[50] = { '\0' }; //garbage to store registeration and %age cuz it is not needed

								bool result_found = false;

								//reading result file to check if result is already calculated
                                while (read_result.getline(result_serial_number,20,' ') &&
                                        read_result.getline(garbage,50))
                                {
									bool match = true;

                                    if (read_result.eof())
                                    {
                                        break;
									}
                                    //match serial no. of both registeration and result
									//it will check if serial no. of registeration and result are same or not 
                                    // if same then it means result is already calculated for that student
                                    int i = 0;
                                    while (registartion_serial_number[i]!='\0' || result_serial_number[i]!='\0')
                                    {
                                         if (registartion_serial_number[i]!=result_serial_number[i])
                                        {
											match=false;
											break;
                                        }
                                        i++;
                                    }
                                    if (match)
                                    {
                                        result_found = true;
                                        break;
                                    }
                                }
								if (!result_found)
                                {
                                    cout << "No Previous Result Found for Your Account..." << endl;
                                    cout << "You can Calculate Your Result Now..." << endl;
                                    cout << "********************************************" << endl;
                                }
                                else
                                {
                                    cout << "Result Already Calculated" << endl;
                                    cout << "Use Print Result in Main Menu" << endl;
                                    cout << "***************************************************************" << endl;
                                    break;
                                }
								read_result.close();
                            }

							//variables to take marks input and calculate result
                            float PF = 0;
                            float DLD = 0;
							float Calculus = 0;
							float Expository_Writing = 0;
                            float Civics_and_Community = 0;
							float Total_marks = 0;
							float Total_subjects = 5;
							float Percentage = 0;

							//taking marks input from user of 5 subjects
                            cout << "Enter Your Marks for Programming Fundamentals (out of 100): ";
							cin >> PF;

							cout << "Enter Your Marks for Digital Logic Design (out of 100): ";
							cin >> DLD;

                            cout << "Enter Your Marks for Calculus & Analytical Geometry (out of 100): ";
                            cin >> Calculus;

                            cout << "Enter Your Marks for Expository Writing (out of 100): ";
                            cin >> Expository_Writing;

                            cout << "Enter Your Marks for Civics & Community Engagement (out of 100): ";
                            cin >> Civics_and_Community;
                            cout << "***************************************************************" << endl;

							//calculating total marks and percentage
							Total_marks = PF + DLD + Calculus + Expository_Writing + Civics_and_Community;
							Percentage = (Total_marks / (Total_subjects * 100)) * 100;

							//writing result in file with serial number
							ofstream write_result;
							write_result.open("result.txt", ios::app);
                            write_result << registartion_serial_number << " " << login_registration << "    " << Percentage << "%" << endl;
                            write_result.close();

							cout << "Your Result has been Calculated and Saved Successfully!" << endl;
                            cout << "----------------------------------------" << endl;
                            cout << "| Sr.    |        ID              %    |" << endl;
                            cout << "----------------------------------------" << endl;
                            cout << registartion_serial_number << "        " << login_registration << "        " << Percentage << "%" << endl;
                            cout << "----------------------------------------" << endl;
                            break;
                        }
						read_password.close(); //closing password file
                    }
                }
				read_registration.close(); //closing registration file
            }
        }
    }
	//Print Result Logic
    else if (choice == 4)
    {
        cout << "Now you can Print your Result" << endl;
		cout << "Log In First to Print Your Result" << endl;
        cout << "********************************************" << endl;
        cout << "Welcome to the Log In Page" << endl;
        cout << "********************************************" << endl;

		//arrays to store registration and password from file
        char registration[20] = { '\0' };
        char password[20] = { '\0' };

		//arrays to store registration and password from user
        char login_registration[20] = { '\0' };
        char login_password[20] = { '\0' };

		//arrays to store serial numbers from file
        char serial_number[20] = { '\0' };
        char registartion_serial_number[20] = { '\0' };
        char password_serial_number[20] = { '\0' };

        bool login_successful = false;
		//same old logic of registration and password verification to log in the user before printing result
		//if login is successful then print result
		//if login is not successful then keep asking for login until successful
		//if a user not calculated result then it will show message that no result found and 
        // you can calculate your result from calculate result option in main menu
        while (true)
        {
            cout << "Enter Your Student ID: ";
            cin >> login_registration;
            cout << "********************************************" << endl;

            ifstream read_registration;
            read_registration.open("reg.txt");
            if (!read_registration.is_open())
            {
                cout << "File Not Found!!!" << endl;
                cout << "********************************************" << endl;
            }
            else
            {
                bool registration_found = false;

                while (read_registration.getline(serial_number, 10, ' ') &&
                    read_registration.getline(registration, 20))
                {
                    if (read_registration.eof())
                    {
                        break;
                    }

                    int j = 0;
                    while (serial_number[j] != '\0')
                    {
                        registartion_serial_number[j] = serial_number[j];
                        j++;
                    }

                    bool registration_match = true;

                    int i = 0;
                    while (login_registration[i] != '\0' && registration[i] != '\0')
                    {
                        if (login_registration[i] != registration[i])
                        {
                            registration_match = false;
                            break;
                        }
                        i++;
                    }
                    if (registration_match && login_registration[i] == '\0' && registration[i] == '\0')
                    {
                        cout << "Student ID Matched!" << endl;
                        cout << "********************************************" << endl;
                        registration_found = true;
                        break;
                    }
                }
                if (!registration_found)
                {
                    cout << "ERROR!!!\nStudent ID Seems To Be Incorrect....Try Again" << endl;
                    cout << "********************************************" << endl;
                }
                else
                {
                    cout << "Enter Your Password: ";
                    cin >> login_password;
                    cout << "********************************************" << endl;

                    ifstream read_password;
                    read_password.open("pswd.txt");
                    if (!read_password.is_open())
                    {
                        cout << "File Not Found!!!" << endl;
                        cout << "********************************************" << endl;
                    }
                    else
                    {
						//Password verification logic is same as before
                        bool password_found = false;

                        while (read_password.getline(serial_number, 10, ' ') &&
                            read_password.getline(password, 20))
                        {
                            if (read_password.eof())
                            {
                                break;
                            }

                            int j = 0;
                            while (serial_number[j] != '\0')
                            {
                                password_serial_number[j] = serial_number[j];
                                j++;
                            }

                            bool serial_number_match = true;

                            int k = 0;
                            while (registartion_serial_number[k] != '\0' && password_serial_number[k] != '\0')
                            {
                                if (registartion_serial_number[k] != password_serial_number[k])
                                {
                                    serial_number_match = false;
                                    break;
                                }
                                k++;
                            }

                            if (!serial_number_match)
                            {
                                continue;
                            }

                            bool password_match = true;

                            int i = 0;
                            while (login_password[i] != '\0' && password[i] != '\0')
                            {
                                if (login_password[i] != password[i])
                                {
                                    password_match = false;
                                    break;
                                }
                                i++;
                            }

                            if (password_match && login_password[i] == '\0' && password[i] == '\0')
                            {
                                cout << "Password Matched!" << endl;
                                cout << "********************************************" << endl;
                                password_found = true;
                                break;
                            }
                        }
                        if (!password_found)
                        {
                            cout << "Entered an Incorrect Password!!!\nAccess Denied....Login Failed....Try Again" << endl;
                            cout << "********************************************" << endl;
                        }
                        else
                        {
                            cout << "Login Successful!" << endl;
                            cout << "********************************************" << endl;
                            login_successful = true;

							//this part is to read result file and find the result of the logged in 
                            // user by matching serial number of registration and result
                            ifstream read_result;
                            read_result.open("result.txt");
                            if (!read_result.is_open())
                            {
                                cout << "Unable to open the Result File..." << endl;
                                cout << "********************************************" << endl;
                            }
                            else
                            {
                                char result_serial_number[20] = { '\0' }; //array to capture result serial number of result 
                                char Result[30] = { '\0' };               //it will store result

                                bool result_found = false;

                                while (read_result.getline(result_serial_number, 20, ' ') && //reading serial no. then result 
                                    read_result.getline(Result, 30))
                                {
                                    bool match = true;
                                    if (read_result.eof())
                                    {
                                        break;
                                    }

                                    //matching seria number of registration and result
                                    //if it is matched with loggedin user then print result of logged in user 
                                    int i = 0;
                                    while (registartion_serial_number[i] != '\0' || result_serial_number[i] != '\0')
                                    {
                                        if (registartion_serial_number[i] != result_serial_number[i])
                                        {
                                            match = false;
                                            break;
                                        }
                                        i++;
                                    }
                                    if (match)
                                    {
                                        result_found = true;
                                        break;
                                    }
                                }
                                if (!result_found)
                                {
                                    cout << "No Result Found for Your Account..." << endl;
                                    cout << "Use Calculate Option in Main Menu" << endl;
                                    cout << "********************************************" << endl;
                                    break;
								}
                                else
                                {
                                    //print result
                                    cout << "YOUR RESULT IS AS FOLLOWS..." << endl;
                                    cout << "********************************************" << endl;
                                    cout << "------------------------------" << endl;
                                    cout << "|        ID              %   |" << endl;
                                    cout << "------------------------------" << endl;
                                    cout << "|   " << Result << " " << endl;
                                    cout << "------------------------------" << endl;
                                    break;
                                }
								read_result.close(); //close result file
                            }
                        }
                        read_password.close(); //close password file
                    }
                }
                read_registration.close(); //close registration file
            }
        }
    }
    //print all information 
    //odd serial result printing on console
    else if (choice == 5)
    {
        cout << "Print All Information" << endl;
        cout << "********************************************" << endl;
        cout << "Will Print All Results with Odd Serial no." << endl;
        cout << "********************************************" << endl;
        system("pause");
        //formatting of result on console
        cout << "----------------------------------------" << endl;
        cout << "| Sr.    |        ID              %    |" << endl;
        cout << "----------------------------------------" << endl;
       
        //array for result and serial number 
		char result[30] = { '\0' };
		char serial_number[20] = { '\0' };

        //file variable for reading
		ifstream read_result;
		read_result.open("result.txt"); //open result.txt from directory

        if (!read_result.is_open())
        {
            cout << "File Not Found!!!" << endl;
            cout << "********************************************" << endl;
        }
        else
        {
            if (!read_result.eof())
            {
				while (read_result.getline(serial_number, 20, ' ') && //read serial number in a separate array 
                    read_result.getline(result, 30))                  //and result in separate 
                {
                    //variable to store serial number when it will be converted from char to int
                    int num = 0;
                    //converting of serial number to integar 
                    int i = 0;
                    while (serial_number[i]!='.') //loop will run till "." is found cuz int only have digits 
                    {
                        num = num * 10 + (serial_number[i] - '0');
                        i++;
                    }
                   //check odd numbers(serial numbers) 
                    if (num%2!=0)
                    {
                        cout <<"|  " << num << ".    |   " << result << endl;
                        cout << "----------------------------------------" << endl;
                    }   //result only with odd serial number will be printed
                }
            }
        }
		read_result.close(); //close result file
       
    }
    //invalid case 
    else
    {
        cout << "Invalid Choice!!!\nPlease Enter a Valid Choice from the Main Menu" << endl;
    }
    system("pause");
    cout << "********************************************" << endl;
    return 0;
}
