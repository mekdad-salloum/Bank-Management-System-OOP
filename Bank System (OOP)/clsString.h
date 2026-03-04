#pragma once

#include <iostream>
#include <vector>

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


	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;


	static short Length(string S)
	{
		return S.length();
	}

	short Length()
	{
		return Length(_Value);
	}


	static short CountWords(string S)
	{
		short NumberOfWords = 0;
		size_t Pos = 0;
		string Word = "";
		string Delimiter = " ";

		while ((Pos = S.find(Delimiter)) != string::npos)
		{
			Word = S.substr(0, Pos);

			if (Word != "")
				NumberOfWords++;

			S.erase(0, Pos + Delimiter.length());
		}

		if (S != "")
			NumberOfWords++;

		return NumberOfWords;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}


	static string UpperFirstLetterOfEachWord(string S)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < S.length(); i++)
		{
			if ((S[i] != ' ') && IsFirstLetter)
			{
				S[i] = toupper(S[i]);
			}

			IsFirstLetter = (S[i] == ' ' ? true : false);

		}

		return S;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}


	static string LowerFirstLetterOfEachWord(string S)
	{
		bool IsFirstLetter = true;

		for (short i = 0; i < S.length(); i++)
		{
			if ((S[i] != ' ') && IsFirstLetter)
			{
				S[i] = tolower(S[i]);
			}

			IsFirstLetter = (S[i] == ' ' ? true : false);

		}

		return S;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}


	static string UpperAllString(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = toupper(S[i]);
		}

		return S;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}


	static string LowerAllString(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = tolower(S[i]);
		}

		return S;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}


	static char InvertLetterCase(char C)
	{
		return isupper(C) ? tolower(C) : toupper(C);
	}

	static string InvertAllLettersCase(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = InvertLetterCase(S[i]);
		}

		return S;
	}

	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}


	static short CountCapitalLetters(string S)
	{
		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (isupper(S[i]))
				Counter++;
		}

		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}


	static short CountSmallLetters(string S)
	{
		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (islower(S[i]))
				Counter++;
		}

		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}


	static short CountSpecificLetter(string S, char Letter, bool MatchCase = false)
	{
		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (MatchCase)
			{
				if (S[i] == Letter)
					Counter++;
			}

			else
			{
				if (tolower(S[i]) == tolower(Letter))
					Counter++;
			}
		}

		return Counter;
	}

	short CountSpecificLetter(char Letter, bool MatchCase = false)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}


	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		switch (WhatToCount)
		{
		case clsString::SmallLetters:
		{
			return CountSmallLetters(S);
			break;
		}

		case clsString::CapitalLetters:
		{
			return CountCapitalLetters(S);
			break;
		}

		case clsString::All:
		{
			return S.length();
			break;
		}

		default:
			break;
		}
	}

	short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
	{
		return CountLetters(_Value, WhatToCount);
	}


	static bool IsVowel(char C)
	{
		C = tolower(C);
		return (C == 'a' || C == 'e' || C == 'o' || C == 'u' || C == 'i');
	}

	static short CountVowels(string S)
	{
		short Counter = 0;

		for (short i = 0; i < S.length(); i++)
		{
			if (IsVowel(S[i]))
				Counter++;
		}

		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}


	static vector <string> Split(string S, string Delimiter = " ")
	{
		vector <string> vString;
		short Pos = 0;
		string Word = "";

		while ((Pos = S.find(Delimiter)) != string::npos)
		{
			Word = S.substr(0, Pos);

			if (Word != "")
				vString.push_back(Word);

			S.erase(0, Pos + Delimiter.length());
		}

		if (S != "")
			vString.push_back(S);

		return vString;
	}

	vector <string> Split(string Delimiter = " ")
	{
		return Split(_Value, Delimiter);
	}


	static string TrimLeft(string S)
	{
		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
				return S.substr(i, S.length());
		}

		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S)
	{
		for (short i = S.length() - 1; i >= 0; i--)
		{
			if (S[i] != ' ')
				return S.substr(0, i + 1);
		}

		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S)
	{
		return TrimLeft(TrimRight(S));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}


	static string Join(vector <string> vString, string Delimiter = " ")
	{
		string S = "";

		for (string& s : vString)
		{
			S += s + Delimiter;
		}

		S = S.substr(0, S.length() - Delimiter.length());

		return S;
	}

	static string Join(string ArrayString[], short Length, string Delimiter = " ")
	{
		string S = "";

		for (short i = 0; i < Length; i++)
		{
			S += ArrayString[i] + Delimiter;
		}

		S = S.substr(0, S.length() - Delimiter.length());

		return S;
	}


	static string ReverseWordsInString(string S)
	{
		string sReversed = "";
		vector <string> vString = Split(S, " ");

		vector <string>::iterator Iter = vString.end();

		while (Iter != vString.begin())
		{
			Iter--;
			sReversed += *Iter + " ";
		}

		sReversed = sReversed.substr(0, sReversed.length() - 1);

		return sReversed;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}


	static string ReplaceWord(string S, string sFrom, string sTo, bool MatchCase = true)
	{
		vector<string> vString = Split(S, " ");

		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == sFrom)
					s = sTo;
			}

			else
			{
				if (LowerAllString(s) == LowerAllString(sFrom))
				{
					s = sTo;
				}

			}

		}

		return Join(vString, " ");
	}

	void ReplaceWord(string sFrom, string sTo, bool MatchCase = true)
	{
		_Value = ReplaceWord(_Value, sFrom, sTo, MatchCase);
	}


	static string RemovePunctuations(string S)
	{
		string NewString = "";

		for (short i = 0; i < S.length(); i++)
		{
			if (!ispunct(S[i]))
			{
				NewString += S[i];
			}
		}
		return NewString;
	}

	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}
};

