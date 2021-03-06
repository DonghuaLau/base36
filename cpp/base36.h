#ifndef _BASE_36_H
#define _BASE_36_H

#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class CBase36
{
public:

	static map<char, int> initCharMap()
	{
		map<char, int> m;

		m['0'] = 0; m['1'] = 1; m['2'] = 2; m['3'] = 3; m['4'] = 4; 
		m['5'] = 5; m['6'] = 6; m['7'] = 7; m['8'] = 8; m['9'] = 9; 

		m['a'] = 10; m['b'] = 11; m['c'] = 12; m['d'] = 13; m['e'] = 14; m['f'] = 15; 
		m['g'] = 16; m['h'] = 17; m['i'] = 18; m['j'] = 19; m['k'] = 20; m['l'] = 21; 
		m['m'] = 22; m['n'] = 23; m['o'] = 24; m['p'] = 25; m['q'] = 26; m['r'] = 27; 
		m['s'] = 28; m['t'] = 29; m['u'] = 30; m['v'] = 31; m['w'] = 32; m['x'] = 33; 
		m['y'] = 34; m['z'] = 35;

		m['A'] = 10; m['B'] = 11; m['C'] = 12; m['D'] = 13; m['E'] = 14; m['F'] = 15;
		m['G'] = 16; m['H'] = 17; m['I'] = 18; m['J'] = 19; m['K'] = 20; m['L'] = 21;
		m['M'] = 22; m['N'] = 23; m['O'] = 24; m['P'] = 25; m['Q'] = 26; m['R'] = 27;
		m['S'] = 28; m['T'] = 29; m['U'] = 30; m['V'] = 31; m['W'] = 32; m['X'] = 33;
		m['Y'] = 34; m['Z'] = 35;

		return m;
	}

	static string encodeInt(long long n)
	{
		string result;
		long long v;

		do{
			v = n % CBase36::BASE36;
			n = n / CBase36::BASE36;
			result = CBase36::BASE36_MAP[v] + result;
		}while(n > 0);

		return result;
	}

	static long long decodeInt(string sSrc)
	{
		long long result = 0;
		long long base = 1;
		int len = sSrc.size();
		map<char, int>::const_iterator it;

		for(int i = len - 1; i >= 0; i--)
		{
			it = CBase36::BASE36_CHAR_MAP.find(sSrc[i]);
			if(it == CBase36::BASE36_CHAR_MAP.end())
			{
				break;
			}

			result += (long)(it->second) * base;
			base *= CBase36::BASE36;
		}

		return result;
	}

	static string encodeArray(int iArr[], int len)
	{
		string result;
		
		for(unsigned int i = 0; i < len; i++)
		{
			if(iArr[i] >= CBase36::BASE36 || iArr[i] < 0) 
			{
				result += BASE36_INVALID;
			}else{
				result += CBase36::BASE36_MAP[iArr[i]];
			}
		}

		return result; 
	}

	static string encodeArray(const vector<int> &vInt)
	{
		string result;
		
		for(unsigned int i = 0; i < vInt.size(); i++)
		{
			if(vInt[i] >= CBase36::BASE36 || vInt[i] < 0) 
			{
				result += BASE36_INVALID;
			}else{
				result += CBase36::BASE36_MAP[vInt[i]];
			}
		}

		return result; 
	}

	static void decodeArray(const string &sStr, vector<int> &vDst)
	{
		map<char, int>::const_iterator it;

		for(unsigned int i = 0; i < sStr.size(); i++)
		{
			it = CBase36::BASE36_CHAR_MAP.find(sStr[i]);
			if(it == CBase36::BASE36_CHAR_MAP.end())
			{
				vDst.push_back(-1);
			}else{
				vDst.push_back(it->second);
			}
		}
	}

	static string randomString(const int &length)
	{
		string result;
		int iRand;

		// ensure the seed different for every call
		srand(time(NULL) + length + (long long)&length);

		for(int i = 0; i < length; i++)
		{
			iRand = rand() % CBase36::BASE36;
			result += CBase36::BASE36_MAP[iRand];
		}

		return result; 
	}

	static const int BASE36 = 36;
	static const char BASE36_INVALID = '?';
	static const char BASE36_MAP[36];
	static const map<char, int> BASE36_CHAR_MAP;
};

const char CBase36::BASE36_MAP[36] = { 
				'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
				'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
				'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
				'u', 'v', 'w', 'x', 'y', 'z'
			};
const map<char, int> CBase36::BASE36_CHAR_MAP = CBase36::initCharMap();

#endif
