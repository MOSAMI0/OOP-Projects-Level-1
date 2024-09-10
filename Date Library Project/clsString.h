#pragma once
#include <iostream>
#include<vector>
using namespace std;


class clsString
{
private:
	string _Value;

public:
	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	};

	short Length()
	{
		return _Value.length();
	};

	static short CountWords(string S1)
	{

		string delim = " "; // delimiter  
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word   
			if (sWord != "")
			{
				Counter++;
			}

			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}

		return Counter;

	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintFirstLetterOfEachWord(string Name)
	{
		bool IsFirstLetter = true;
		cout << "\nThe First Letter in each String: \n";

		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ' && IsFirstLetter)
			{
				cout << Name[i] << endl;
			}
			IsFirstLetter = (Name[i] == ' ' ? true : false);

		}

	}

	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string Name)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ' && IsFirstLetter)
			{
				Name[i] = toupper(Name[i]);
			}
			IsFirstLetter = (Name[i] == ' ' ? true : false);

		}
		return Name;
	}

	void UpperFirstLetterOfEachWord()
	{
		// no need to return value , this function will directly update the object value 
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string Name)
	{
		bool IsFirstLetter = true;

		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ' && IsFirstLetter)
			{
				Name[i] = tolower(Name[i]);
			}
			IsFirstLetter = (Name[i] == ' ' ? true : false);

		}
		return Name;
	}

	void LowerFirstLetterOfEachWord()
	{
		// no need to return value , this function will directly update the object value  
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string Name)
	{

		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ')
			{
				Name[i] = toupper(Name[i]);
			}
		}
		return Name;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string Name)
	{

		for (int i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ')
			{
				Name[i] = tolower(Name[i]);
			}
		}
		return Name;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Name)
	{
		return isupper(Name) ? tolower(Name) : toupper(Name);
	}

	static string InvertAllStringLettersCase(string Name)
	{
		/*
			for (int i = 0; i < Name.length(); i++)

			   {
			   if (Name[i] == toupper(Name[i]))
						Name[i] = tolower(Name[i]);
				else
						Name[i] = toupper(Name[i]);

			   }
		*/

		for (int i = 0; i < Name.length(); i++)
		{
			Name[i] = InvertLetterCase(Name[i]);
		}
		return Name;
	}

	void InvertAllStringLettersCase()
	{
		_Value = InvertAllStringLettersCase(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 2 };

	static short CountLetters(string Name, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return Name.length();
		}

		int Counter = 0;

		for (int i = 0; i < Name.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Name[i]))
			{
				Counter++;
			}
			else if (WhatToCount == enWhatToCount::SmallLetters && islower(Name[i]))
			{
				Counter++;
			}

		}
		return Counter;

	}

	void CountLetters()
	{
		_Value = CountLetters(_Value);
	}

	static short CountCapitalLetters(string Name)
	{
		int Counter = 0;
		for (int i = 0; i < Name.length(); i++)
		{
			if (isupper(Name[i]))
			{
				Counter++;
			}


		}
		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetters(string Name)
	{
		int Counter = 0;
		for (int i = 0; i < Name.length(); i++)
		{
			if (islower(Name[i]))
			{
				Counter++;
			}

		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountSpecificLetter(string Name, char letter, bool MatchCase = true)
	{
		int Counter = 0;
		for (int i = 0; i < Name.length(); i++)
		{
			if (MatchCase)
			{
				if (Name[i] == letter)
				{
					Counter++;
				}
			}
			else
			{
				if (tolower(Name[i]) == tolower(letter))
				{
					Counter++;
				}

			}
		}

		return Counter;
	}

	short CountSpecificLetter(char letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, letter, MatchCase);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'u') || (Ch1 == 'o') || (Ch1 == 'i'));
	}

	static short CountVowels(string Name)
	{
		short Counter = 0;
		for (int i = 0; i < Name.length(); i++)
		{
			if (IsVowel(Name[i]))
			{
				Counter++;
			}
		}

		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintEachWordInString(string Name)
	{
		string delim = " "; // delimite
		cout << "\nYour string wrords are: \n\n";
		short pos = 0;
		string sWord; // define a string variable  

		// use find() function to get the position of the delimiters  
		while ((pos = Name.find(delim)) != std::string::npos)
		{
			sWord = Name.substr(0, pos); // store the word   
			if (sWord != "")
			{
				cout << sWord << endl;
			}

			Name.erase(0, pos + delim.length()); /* erase() until
			 positon and move to next word. */
		}

		if (Name != "")
		{
			cout << Name << endl;// it print last word of the string.
		}


	}

	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static vector <string> Split(string Name, string Delim)
	{
		vector<string>Vstring;

		short pos = 0;
		string sWord; // define a string variable 

		// use find() function to get the position of the delimiters  
		while ((pos = Name.find(Delim)) != std::string::npos)
		{
			sWord = Name.substr(0, pos); // store the word   
			if (sWord != "")
			{
				Vstring.push_back(sWord);
			}

			Name.erase(0, pos + Delim.length()); /* erase() until
			 positon and move to next word. */
		}

		if (Name != "")
		{
			Vstring.push_back(Name);

		}

		return Vstring;
	}

	vector <string> Split(string Delim)
	{
		return Split(_Value, Delim);
	}

	static string TrimLeft(string Name)
	{
		for (short i = 0; i < Name.length(); i++)
		{
			if (Name[i] != ' ')
			{
				return Name.substr(i, Name.length() - 1);
			}
		}
		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Name)
	{
		for (short i = Name.length() - 1; i >= 0; i--)
		{
			if (Name[i] != ' ')
			{
				return Name.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Name)
	{
		return TrimLeft(TrimRight(Name));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string> vString, string Delim)
	{
		string S1 = "";
		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string JoinString(string arrS[], short length, string Delim)
	{
		string S1 = "";
		for (short i = 0; i < length; i++)
		{
			S1 = S1 + arrS[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWordsInString(string S1)
	{
		vector<string> Vstring;
		string S2 = "";

		Vstring = Split(S1, " ");

		//declare iterator
		vector<string>::iterator itr = Vstring.end();
		while (itr != Vstring.begin())
		{
			itr--;

			S2 += *itr + " ";
		}
		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWordInStringUsingSplit(string S1, string StringToReplace, string sReplaceTo, bool MarchCase = true)
	{
		vector<string> Vstring = Split(S1, " ");

		for (string& s : Vstring)
		{
			if (MarchCase)
			{
				if (s == StringToReplace)
				{
					s = sReplaceTo;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sReplaceTo;
				}

			}
		}

		return JoinString(Vstring, " ");
	}

	string ReplaceWordInStringUsingSplit(string StringToReplace, string sReplaceTo)
	{
		return ReplaceWordInStringUsingSplit(_Value, StringToReplace, sReplaceTo);
	}

	static string RemovePunctuationsFromString(string S1)
	{
		string S2 = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];

			}
		}

		return S2;
	}

	void RemovePunctuationsFromString()
	{
		_Value = RemovePunctuationsFromString(_Value);
	}
};

