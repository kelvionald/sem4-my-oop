#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

using namespace std;

enum class Modes
{
	CRYPT,
	DECRYPT
};

struct Args
{
	Modes mode;
	string inputFilepath;
	string outputFilepath;
	byte key;
};

optional<Modes> ParseMode(string mode)
{
	if (mode == "crypt")
	{
		return Modes::CRYPT;
	}
	else if (mode == "decrypt")
	{
		return Modes::DECRYPT;
	}
	cout << "Invalid mode, expected 'crypt' or 'decrypt' \n";
	return nullopt;
}

optional<byte> ParseKey(string keyString)
{
	stringstream ss;
	int key;
	ss << keyString;
	if (ss >> key && 0 <= key && key <= 255)
	{
		return (byte)key;
	}
	cout << "Invalid key, expected number 0-255\n";
	return nullopt;
}

optional<Args> ParseArgs(int argc, char* argv[])
{
	Args args;
	auto mode = ParseMode(argv[1]);
	if (!mode)
	{
		return nullopt;
	}
	args.mode = mode.value();
	args.inputFilepath = argv[2];
	if (!args.inputFilepath.size())
	{
		cout << "Empty input file argument\n";
		return nullopt;
	}
	args.outputFilepath = argv[3];
	if (!args.outputFilepath.size())
	{
		cout << "Empty output file argument\n";
		return nullopt;
	}
	auto key = ParseKey(argv[4]);
	if (!key)
	{
		return nullopt;
	}
	args.key = key.value();
	return args;
}

const byte bit7 = (byte)128;
const byte bit6 = (byte)64;
const byte bit5 = (byte)32;
const byte bit4 = (byte)16;
const byte bit3 = (byte)8;
const byte bit2 = (byte)4;
const byte bit1 = (byte)2;
const byte bit0 = (byte)1;

string ToBinary(int n)
{
	string r;
	while (n != 0)
	{
		r = (n % 2 == 0 ? "0" : "1") + r;
		n /= 2;
	}
	while (8 - r.size())
	{
		r = "0" + r;
	}
	return r;
}

int ApplyShuffle(byte arr[])
{
	int ch = 0;
	for (int i = 0; i < 8; i++)
	{
		ch = ch << 1;
		if (static_cast<bool>(arr[i]))
		{
			ch |= 1;
		}
	}
	return ch;
}

char CryptByte(byte ch, byte key)
{
	ch ^= key;
	byte arr[]
	{
		bit4 & ch,
		bit3 & ch,
		bit7 & ch,
		bit2 & ch,
		bit1 & ch,
		bit0 & ch,
		bit6 & ch,
		bit5 & ch
	};
	return static_cast<char>(ApplyShuffle(arr));
}

char DecryptByte(byte ch, byte key)
{
	byte arr[]
	{
		bit5 & ch,
		bit1 & ch,
		bit0 & ch,
		bit7 & ch,
		bit6 & ch,
		bit4 & ch,
		bit3 & ch,
		bit2 & ch,
	};
	ch = static_cast<byte>(ApplyShuffle(arr));
	ch ^= key;
	return static_cast<char>(ch);
}

int main(int argc, char* argv[])
{
	optional<Args> args;
	if (argc == 5)
	{
		args = ParseArgs(argc, argv);
	}
	else
	{
		cout << "Invalid arguments count\n";
	}
	if (!args)
	{
		cout << "Usage: 1.3.invert.exe <mode> <input file> <output file> <key> \n";
		return 1;
	}

	ifstream input(args->inputFilepath, ios::binary);
	if (!input.is_open())
	{
		cout << "Failed to open '" << args->inputFilepath << "' for reading\n";
		return 1;
	}

	ofstream output(args->outputFilepath, ios::binary);
	if (!output.is_open())
	{
		cout << "Failed to open '" << args->inputFilepath << "' for writing\n";
		return 1;
	}

	char ch;
	while (input.get(ch))
	{
		if (args->mode == Modes::CRYPT)
		{
			output.put(CryptByte(static_cast<byte>(ch), args->key));
		}
		else if (args->mode == Modes::DECRYPT)
		{
			output.put(DecryptByte(static_cast<byte>(ch), args->key));
		}
		else
		{
			cout << "Undefined mode\n";
			break;
		}
	}

	if (!output.flush())
	{
		cout << "Filed to write data to output file\n";
		return 1;
	}

	return 0;
}
