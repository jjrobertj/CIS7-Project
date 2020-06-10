#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;


int main() {
  int lang_select; //Language selection
  int speciality;  //Specialization selection
  int preference; //Preferred Country selection
  const int LANGUAGES = 10; //Columns in 2-d array
  const int CON_PER_LANG = 7; //Rows in 2-d array
  const int SPECIALIZATION = 5; //Array for Specialization

  //2-D array to match and hold countries based on languages

   string countries [LANGUAGES][CON_PER_LANG]= {{"Austria", "Germany", "Hungary", "Italy", "Luxembourg", "Poland", "Liechtenstein"},{"Finland", "Kosovo", "Macedonia", "Norway", "Romania", "Sweden", "Slovenia"},{"Togo", "France", "Switzerland", "Benin", "Burkina Faso", "Guinea", "Haiti"},{"Brazil", "Portugal", "Angola", "Cape Verde", "Macau","Guinea-Bissau","Mozambique"}, {"Spain","Mexico", "Cueta", "Melilla", "Cuba", "Costa Rica", "El Salvador"}, {"Gambia", "United States", "Liberia", "Nigeria", "Namibia", "Sierra Leone", "Zambia"}, {"Algeria", "Egypt", "libya", "Mauritania", "Sudan", "Tunisia", "Bahrain"}, {"Netherlands", "Belgium","Indonesia","Aruba","Curacao","Sint Maarten", "Suriname"}, {"Armenia", "Russia","Azerbaijan","Belarus", "Kazakhstan","Tajikistan"}, {"India","Sri Lanka","Singapore","Canada","Fiji","South Africa", "Guyana"}};

    //String Array for languages
    string languages[LANGUAGES] = {"German", "Romani","French", "Portuguese", "Spanish", "English","Arabic","Dutch","Russian", "Tamil"};

    //String array for Specialization
    string Specialization[SPECIALIZATION] = {"Cardiology", "Bariatrics", "Neurology", "Ophthalmology","Radiology"};

    
    cout << "\n***************************************************\n\n";
    cout << "70 Countries that may be selected: \n\n";

    //Displays all countries in the array
    for(int i=0; i< LANGUAGES; i++)
      for(int j=0; j<CON_PER_LANG; j++)
      {
        cout << countries[i][j] << ", ";
      }
      cout << endl;

  

   cout << "\nChoose your Specialization:" << endl;
   cout << "-----------------------------" << endl;

   //Displays the specializations
   for(int i =0; i<SPECIALIZATION; i++)
    cout << i+1 << ". " << Specialization[i] << endl;

    //Added for space
    cout << endl;
    //User input specialization
    cin >> speciality;
   
   //Matches & displays user specializations
   for(int i =0; i<SPECIALIZATION; i++)
    if(speciality == i)
      cout << "You choose " << Specialization[i-1] << ". " << endl << endl;


   //Asks user for their preffered language
   cout << "\nWhich is your preferred Language?" << endl;
   cout << "------------------------------------" << endl;

   //Displays the languages
   for(int i=0;i<LANGUAGES;i++) 
    cout <<i+1 << ". " << languages[i] << endl;
  
    //Added for space
    cout << endl;

    //User selects their language
    cin >> lang_select;
   
   //Matches and displays the users selection of language
   for(int i=0;i<LANGUAGES;i++) 
    if(lang_select == i)
      cout << "You have choose " << languages[i-1]<< ". " << endl << endl;

  cout << "Which Country would you prefer to be assigned? " << endl;
  cout << "----------------------------------------------" << endl;

  //Displays the countries associated to their language selection
   for(int i =0; i<CON_PER_LANG;i++)
    cout << i+1 << ". " << countries[lang_select-1][i] << endl;
  
  //added for space
   cout << endl;
   
   //User selects their preferred country 
   cin >> preference;

 //incoporates the srand %time function
  srand(time(0));
 //Generates a random number between 1-7 for the countries for the language
  int rcount = (rand() % CON_PER_LANG);
  
  //Generates and displays a random country based on their language
  cout << "\nThe country chosen that matches your language choice is : " << countries[lang_select-1][rcount] << endl;

 //Holds the probability for the random country and their preffered
  float probability_1 = 1.0/70.0;
  float probability_2 = (1.0/7.0)/70.0;

  //Fixes the decimal places to two after
  cout << setprecision(2) << fixed;
  
  //Displays the probability of landing the random country generated
  cout << "\nThe probability of choosing this country is " << probability_1 * 100.00 << "%." << endl;

 //Checks is random country matches their preferred country
 //If not is displays the probability of being matched to their preferred country
 if(preference != rcount)
  { for(int i = 0; i<CON_PER_LANG;i++)
    {if(preference == i)
      cout << "\nYour preferred country is " << countries[lang_select-1][i-1] << endl;
    }
  
  cout << "\nThe probability of being assigned your country of prefernce is " << probability_2 * 100.00 << "%." <<  endl;
  }
  else if (preference == rcount)
  {
    //if matches it displays nothing as the probability is the same.
    cout << endl;
  }
}