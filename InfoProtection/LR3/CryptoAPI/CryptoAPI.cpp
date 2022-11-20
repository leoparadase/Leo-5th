// CryptoAPI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "framework.h"
#include "CryptoAPI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#pragma comment(lib, "crypt32.lib")

CWinApp theApp;

class CryptoAPI
{
	HCRYPTPROV m_hCP = NULL;
	HCRYPTKEY m_hExchangeKey = NULL;
	HCRYPTKEY m_hSessionKey = NULL;
	HCRYPTKEY m_hExportKey = NULL;
public:

	HCRYPTKEY GetExchangeKey()
	{
		return m_hExchangeKey;
	}

	HCRYPTKEY GetSessionKey()
	{
		return m_hSessionKey;
	}

	HCRYPTKEY GetExportKey()
	{
		return m_hExportKey;
	}

	CryptoAPI()
	{
		if (!CryptAcquireContext(&m_hCP, NULL, MS_ENH_RSA_AES_PROV, PROV_RSA_AES, CRYPT_VERIFYCONTEXT))	// использование временных ключей, не сохраняющихся в контейнере
			PrintError();
//		if (!CryptAcquireContext(&m_hCP, "My Container", MS_ENH_RSA_AES_PROV, PROV_RSA_AES, 0))
//		{
//			if (GetLastError() == NTE_BAD_KEYSET)
//			{
//				if (!CryptAcquireContext(&m_hCP, "My Container", MS_ENH_RSA_AES_PROV, PROV_RSA_AES, CRYPT_NEWKEYSET))
//					PrintError();
//			}
//		}
	}
	
	~CryptoAPI()
	{
		DestroyKeys();
		if (m_hCP)
		{
			if (!CryptReleaseContext(m_hCP, 0))
				PrintError();
		}
	}

	void GenKeyPair()
	{
		if (!CryptGenKey(m_hCP, CALG_RSA_KEYX, CRYPT_EXPORTABLE, &m_hExchangeKey))
			PrintError();
	}

	void GenSessionKey()
	{
		if (!CryptGenKey(m_hCP, CALG_AES_256, CRYPT_EXPORTABLE, &m_hSessionKey))
			PrintError();
	}

	void GenExportKey(const string& sPassword)
	{
		HCRYPTHASH hHash;
		if (!CryptCreateHash(m_hCP, CALG_SHA_256, NULL, 0, &hHash))
		{
			PrintError();
			return;
		}
		if(!CryptHashData(hHash, (BYTE*)sPassword.c_str(), sPassword.length(), 0))
		{
			PrintError();
			return;
		}

		if (!CryptDeriveKey(m_hCP, CALG_AES_256, hHash, CRYPT_EXPORTABLE, &m_hExportKey))
			PrintError();

		CryptDestroyHash(hHash);
	}

	void DestroyKey(HCRYPTKEY& hKey)
	{
		if (hKey)
		{
			if (!CryptDestroyKey(hKey))
				PrintError();
			hKey = NULL;
		}
	}

	void DestroyKeys()
	{
		DestroyKey(m_hExchangeKey);
		DestroyKey(m_hSessionKey);
		DestroyKey(m_hExportKey);
	}

	void DoExportKey(vector<char>& v, HCRYPTKEY hKey, HCRYPTKEY hExpKey, DWORD dwType)
	{
		DWORD dwLen = 0;
		if (!CryptExportKey(hKey, hExpKey, dwType, 0, NULL, &dwLen))
		{
			PrintError();
			return; 
		}
		v.resize(dwLen);
		if (!CryptExportKey(hKey, hExpKey, dwType, 0, (BYTE*)v.data(), &dwLen))
			PrintError();
		v.resize(dwLen);		// поскольку для некоторых ключей реальный размер экспортированных данных 
								// может быть меньше размера, необходимого для экспорта
	}

	void DoImportKey(vector<char>& v, HCRYPTKEY& hKey, HCRYPTKEY hPubKey, DWORD dwType)
	{
		if (!CryptImportKey(m_hCP, (BYTE*)v.data(), v.size(), hPubKey, CRYPT_EXPORTABLE, &hKey))
			PrintError();
	}

	void ExportPublicKey(vector<char>& v)
	{
		DoExportKey(v, m_hExchangeKey, NULL, PUBLICKEYBLOB);
	}

	void ExportPrivateKey(vector<char>& v)
	{
		DoExportKey(v, m_hExchangeKey, m_hExportKey, PRIVATEKEYBLOB);
	}

	void ExportSessionKey(vector<char>& v)
	{
		DoExportKey(v, m_hSessionKey, m_hExchangeKey, SIMPLEBLOB);
	}

	void ImportPublicKey(vector<char>& v)
	{
		DoImportKey(v, m_hExchangeKey, NULL, PUBLICKEYBLOB);
	}

	void ImportPrivateKey(vector<char>& v)
	{
		DoImportKey(v, m_hExchangeKey, m_hExportKey, PRIVATEKEYBLOB);
	}

	void ImportSessionKey(vector<char>& v)
	{
		DoImportKey(v, m_hSessionKey, NULL, SIMPLEBLOB);
	}

	void EncryptData(ifstream& in, ofstream& out, DWORD dwSize, HCRYPTKEY hKey = NULL, bool bRSA = false)
		// CryptGetKeyParam с KP_BLOCKLEN возвращает размер блока в битах, 
		// для большинства алгоритмов можно использовать кратное значение,
		// но RSA требует точного соответствия длине блока в байтах,
		// причем 11 байт нужны для обязательного заполнителя (padding)
	{
		if (!hKey)
			hKey = m_hSessionKey;
		DWORD dwBlockLen = 0;
		DWORD dwDataLen = sizeof(DWORD);
		if (!CryptGetKeyParam(hKey, KP_BLOCKLEN, (BYTE*)&dwBlockLen, &dwDataLen, 0))
			PrintError();
		writeln("Block length: ", dwBlockLen);

		if (bRSA)
		{
			dwBlockLen >>= 3;
			dwBlockLen -= 11;
		}

		DWORD dwDone = 0;
		vector<char> v(dwBlockLen);

		bool bDone = false;
		while (!bDone)
		{
			in.read(v.data(), dwBlockLen);
			DWORD dwRead = (DWORD)in.gcount();
			dwDone += dwRead;
			bDone = (dwDone == dwSize);
			dwDataLen = dwRead;
			if (!CryptEncrypt(hKey, NULL, bDone, 0, NULL, &dwDataLen, 0))
				PrintError();
			if (dwDataLen > v.size())
				v.resize(dwDataLen);
			if (!CryptEncrypt(hKey, NULL, bDone, 0, (BYTE*)v.data(), &dwRead, v.size()))
				PrintError();
			out.write(v.data(), dwRead);
		}
	}

	void DecryptData(ifstream& in, ofstream& out, DWORD dwSize, HCRYPTKEY hKey = NULL, bool bRSA = false)
	{
		if (!hKey)
			hKey = m_hSessionKey;
		DWORD dwBlockLen = 0;
		DWORD dwDataLen = sizeof(DWORD);
		if (!CryptGetKeyParam(hKey, KP_BLOCKLEN, (BYTE*)&dwBlockLen, &dwDataLen, 0))
			PrintError();
		writeln("Block length: ", dwBlockLen);

		if (bRSA)
		{
			dwBlockLen >>= 3;
		}

		DWORD dwDone = 0;
		vector<char> v(dwBlockLen);

		bool bDone = false;
		while (!bDone)
		{
			in.read(v.data(), dwBlockLen);
			DWORD dwRead = (DWORD)in.gcount();
			dwDone += dwRead;
			bDone = (dwDone == dwSize);
			if (!CryptDecrypt(hKey, NULL, bDone, 0, (BYTE*)v.data(), &dwRead))
				PrintError();
			out.write(v.data(), dwRead);
		}
	}

	void EncryptData(vector<char>& vIn, vector<char>& vOut, HCRYPTKEY hKey = NULL, bool bRSA = false)
	{
		if (!hKey)
			hKey = m_hSessionKey;
		DWORD dwBlockLen = 0;
		DWORD dwDataLen = sizeof(DWORD);
		if (!CryptGetKeyParam(hKey, KP_BLOCKLEN, (BYTE*)&dwBlockLen, &dwDataLen, 0))
			PrintError();
		writeln("Block length: ", dwBlockLen);

		if (bRSA)
		{
			dwBlockLen >>= 3;
			dwBlockLen -= 11;
		}

		DWORD dwDone = 0;
		vector<char> v(dwBlockLen);

		bool bDone = false;
		while (!bDone)
		{
			DWORD dwRead = min(dwBlockLen, vIn.size() - dwDone);
			memcpy(v.data(), vIn.data() + dwDone, dwRead);
			dwDone += dwRead;
			bDone = (dwDone == vIn.size());
			dwDataLen = dwRead;
			if (!CryptEncrypt(hKey, NULL, bDone, 0, NULL, &dwDataLen, 0))
				PrintError();
			if (dwDataLen > v.size())
				v.resize(dwDataLen);
			if (!CryptEncrypt(hKey, NULL, bDone, 0, (BYTE*)v.data(), &dwRead, v.size()))
				PrintError();
			vOut.insert(vOut.end(), v.begin(), v.begin() + dwRead);
		}
	}

	void DecryptData(vector<char>& vIn, vector<char>& vOut, HCRYPTKEY hKey = NULL, bool bRSA = false)
	{
		if (!hKey)
			hKey = m_hSessionKey;
		DWORD dwBlockLen = 0;
		DWORD dwDataLen = sizeof(DWORD);
		if (!CryptGetKeyParam(hKey, KP_BLOCKLEN, (BYTE*)&dwBlockLen, &dwDataLen, 0))
			PrintError();
		writeln("Block length: ", dwBlockLen);

		if (bRSA)
		{
			dwBlockLen >>= 3;
		}

		DWORD dwDone = 0;
		vector<char> v(dwBlockLen);

		bool bDone = false;
		while (!bDone)
		{
			DWORD dwRead = min(dwBlockLen, vIn.size() - dwDone);
			memcpy(v.data(), vIn.data() + dwDone, dwRead);
			dwDone += dwRead;
			bDone = (dwDone == vIn.size());
			if (!CryptDecrypt(hKey, NULL, bDone, 0, (BYTE*)v.data(), &dwRead))
				PrintError();
			vOut.insert(vOut.end(), v.begin(), v.begin() + dwRead);
		}
	}
};

void KeyGen()
{
	CryptoAPI crypto;
	string public_key_name;
	string private_key_name;
	string password;

	cout << "Enter name for public key: ";
	cin >> public_key_name;

	cout << endl << "Enter name for private key: ";
	cin >> private_key_name;

	cout << endl << "Enter password: ";
	cin >> password;

	cout << endl;

	crypto.GenKeyPair();
	crypto.GenExportKey(password);

	{
		vector<char> v;
		crypto.ExportPrivateKey(v);
		ofstream out(private_key_name, ios::binary);
		out.write(v.data(), v.size());
	}

	{
		vector<char> v;
		crypto.ExportPublicKey(v);
		ofstream out(public_key_name, ios::binary);
		out.write(v.data(), v.size());
	}

	cout << "Keys generated." << endl;
}

void Encoding()
{
	{
		CryptoAPI crypto;

		string public_key_name;
		string private_key_name;
		string init_file;
		string encoded_file;
		string password;
		string session_enc_key;

		cout << "Enter name for public key: ";
		cin >> public_key_name;

		cout << endl << "Enter name for private key: ";
		cin >> private_key_name;

		cout << endl << "Enter password: ";
		cin >> password;

		cout << endl << "Enter name of initial file: ";
		cin >> init_file;

		cout << endl << "Enter name for encoded file: ";
		cin >> encoded_file;

		cout << endl;

		crypto.GenKeyPair();
		crypto.GenSessionKey();

		{
			ifstream in(private_key_name, ios::binary);

			if (in.good())
			{
				vector v(istreambuf_iterator<char>{in}, {});
				crypto.ImportPrivateKey(v);
			}
			else
			{
				cout << "No access to private key!" << endl;
			}
		}

		{
			ifstream in(public_key_name, ios::binary);

			if (in.good())
			{
				vector v(istreambuf_iterator<char>{in}, {});
				crypto.ImportPublicKey(v);
			}
			else
			{
				cout << "No access to public key!" << endl;
			}
		}

		{
			vector<char> v1;
			vector<char> v2;
			crypto.ExportSessionKey(v1);
			crypto.EncryptData(v1, v2, crypto.GetExchangeKey(), true);
			string temp(v2.begin(), v2.end());
			session_enc_key = temp;
		}

		{
			ifstream in(init_file, ios::binary);
			ofstream out(encoded_file, ios::binary);
			
			try
			{
				crypto.EncryptData(in, out, (DWORD)filesystem::file_size(init_file));
				out << '\n' << "SK" << '\n';
				for (auto& ch : session_enc_key)
				{
					out << ch;
				}
			}
			catch (...)
			{
				cout << endl << "Unattented exception." << endl << endl;
			}
			
			in.close();
			out.close();
		}
	}
}

void Decoding()
{
	{
		CryptoAPI crypto;

		string public_key_name;
		string private_key_name;
		string init_file;
		string decoded_file;
		string password;
		string session_enc_key;

		cout << "Enter name for public key: ";
		cin >> public_key_name;

		cout << endl << "Enter name for private key: ";
		cin >> private_key_name;

		cout << endl << "Enter password: ";
		cin >> password;

		cout << endl << "Enter name of initial file: ";
		cin >> init_file;

		cout << endl << "Enter name for decoded file: ";
		cin >> decoded_file;

		cout << endl;

		crypto.GenKeyPair();
		crypto.GenExportKey(password);
		{
			ifstream in(private_key_name, ios::binary);

			if (in.good())
			{
				vector v(istreambuf_iterator<char>{in}, {});
				crypto.ImportPrivateKey(v);
			}
			else
			{
				cout << "No access to private key!" << endl;
			}
		}

		{
			ifstream in(public_key_name, ios::binary);

			if (in.good())
			{
				vector v(istreambuf_iterator<char>{in}, {});
				crypto.ImportPublicKey(v);
			}
			else
			{
				cout << "No access to public key!" << endl;
			}
		}

		{
			ifstream in(init_file, ios::binary);
			string str;
			vector<char> data;
			vector<char> s_key;

			while (getline(in, str))
			{
				if (str != "SK")
				{
					copy(str.begin(), str.end(), back_inserter(data));
					data.push_back('\n');
				}
				else
				{
					data.pop_back();
					break;
				}
			}
			while (getline(in, str))
			{
				copy(str.begin(), str.end(), back_inserter(s_key));
				s_key.push_back('\n');
			}
			s_key.pop_back();
			in.close();

			ofstream temp(init_file + ".temp", ios::binary);
			for (auto& ch : data)
				temp << ch;
			temp.close();

			vector<char> v2;

			ifstream inN(init_file + ".temp", ios::binary);
			ofstream outN(decoded_file, ios::binary);

			try
			{
				crypto.DecryptData(s_key, v2, crypto.GetExchangeKey(), true);
				crypto.ImportSessionKey(v2);
				crypto.DecryptData(inN, outN, (DWORD)filesystem::file_size(init_file + ".temp"));
			}
			catch (...)
			{
				cout << endl << "Check password or file's accessibility." << endl << endl;
			}
			 

			inN.close();
			outN.close();
		}
	}
}

int main()
{     
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: code your application's behavior here.
			wprintf(L"Fatal Error: MFC initialization failed\n");
			nRetCode = 1;
		}
		else
		{
			// CryptoTest(); // Move to separate functions!

			while (1)
			{
				cout << "Choose the action:" << endl << endl
					<< "1. Encode file" << endl
					<< "2. Decode file" << endl
					<< "3. Generate keys" << endl
					<< "0. Exit" << endl << endl;

				int choose;
				cin >> choose;

				switch (choose)
				{
				case 1:
				{
					Encoding();
					break;
				}
				case 2:
				{
					Decoding();
					break;
				}
				case 3:
				{
					KeyGen();
					break;
				}
				default:
				{
					return 0;
					break;
				}
				}
			}
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		wprintf(L"Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}

	return nRetCode;
}
