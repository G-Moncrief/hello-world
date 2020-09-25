#include <iostream>
#include <string>

void decrypt (std::string m, int k)
{
	for (int i = 0; i < m.length(); i++)
	{
		if (islower(m[i]))
		{
			m[i] = m[i]-97; //shift range to 0
			m[i] = (m[i]+(26-k))%26;
			m[i] = m[i]+65; //convert to uppercase per convention
		}
		
	}
	std::cout << "\nDecrypted Text: ";
	std::cout << m;
}

void encrypt(std::string m, int k)
{
	for (int i = 0; i < m.length(); i++)
	{
		if (isupper(m[i]))
		{
			m[i] = m[i]-65; //shift range to 0
			m[i] = (m[i]+k)%26; //(pi+k)mod 26
			m[i] = m[i]+97; //convert to lowercase per convention
		}	
	}
	std::cout << "\nEncrypted Text: ";
	std::cout << m;
	decrypt(m, k);
}

int statattack (std::string m)
{
	for (int i = 0; i < m.length(); i++)
	{
		m[i] = m[i]-97; //shift range to 0
	}
	
	double freq[26] = {0};
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < m.length(); j++)
		{
			if (m[j] == i)
			{
				freq[i] = freq[i]+1;
			}
		}
	}
	char c='a';
	for (int i = 0; i < 26; i++)
	{
		std::cout << "\n" << c << " -- ";
		std::cout << freq[i]/m.length();
		c++;
	}
	
	std::cout << "\n\nStatistical Attack 2b: \n";
	
	double G[]  = {0.080, 0.015, 0.030, 0.040, 0.130, 0.020, 0.015, 0.060,
		0.065, 0.005, 0.005, 0.035, 0.030, 0.070, 0.080, 0.020, 0.002, 0.065,
		0.060, 0.090, 0.030, 0.010, 0.015, 0.005, 0.020, 0.002};
	
	double closest_corr_val = 0;
	int closest_corr = 0;
	
	for (int i = 0; i < 26; i++) //iterates through keys
	{
		double temp = 0;
		for (int j = 0; j < 26; j++)
		{
			//freq of cipher letter vs freq plain text 
			temp += freq[j]/m.length() * (G[(j+(26-i))%26]); 
		}
		
		std::cout << "\nKey Value: " << i <<"\t" << temp;
		
		if (closest_corr_val < temp)
		{
			closest_corr = i;
			closest_corr_val = temp;
		}		
	}
	return closest_corr;
}

int main()
{
	std::string msg = "WELCOME TO HARDWARE SECURITY AT USF!";
	std::cout << "\nTEST ONE:";
	std::cout << "\nKey Value: 1";
	encrypt(msg, 1);
	
	std::cout << "\n\nTEST TWO:";
	std::cout << "\nKey Value: 24";
	encrypt(msg, 24);
	
	std::cout << "\n\nBRUTE FORCE ATTACK CHECK:";
	
	std::string jibberish = "kyzj kvok yrj svve vetipgkvu nzky kyv trvjri tzgyvi. "
		"rttfiuzex kf nzbzgvuzr, zk zj fev fw kyv jzdgcvjk reu "
		"dfjk nzuvcp befne vetipgkzfe kvtyezhlvj. zk zj r kpgv "
		"fw jlsjkzklkzfe tzgyvi ze nyzty vrty cvkkvi ze kyv "
		"gcrzekvok zj ivgcrtvu sp r cvkkvi jfdv wzovu eldsvi "
		"fw gfjzkzfej ufne kyv rcgyrsvk.";
	
	for (int i = 0; i < 25; i++)
	{
		std::cout << "\n";
		decrypt(jibberish,i);
	}
	
	std::cout << "\n\nStatistical Attack 2a: \n";
	int autok = statattack(jibberish); //returns key value for auto decryption
	decrypt(jibberish, autok);
	
	//note: the key is 17
}