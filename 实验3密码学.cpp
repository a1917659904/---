#include<iostream>
#include<string.h>

using namespace std;
int main(){
	int k1, k2,ch;
	char s[100],m[100];
	int i, j, k;
	int t[26] = {};
	cout << "仿射变换";
	cout << "请选择运行模式：\n";
	cout << "1.加密\n";
	cout << "2.解密\n";
	cout << "3.暴力破解\n";
	cin >> ch;
	if (ch == 1){
		cout << "请依次输入加密密钥k1，k2:\n";
		cin >> k1 >> k2;
		if (k1 % 2 == 0 || k1 == 13){
			cout << "请输入与26互素的k1\n";
		}
		else{
			cout << "请输入明文:\n";
			cin >> m;
			cout << "加密得到的密文为:";
			for (i = 0; i < strlen(m); i++){
				s[i] = ((((int)m[i] - 97 + 26) % 26)*k1 + k2) % 26 + 65;
				cout << s[i];
			}
			cout << "\n";
		}
	}
	else if (ch == 2){
		cout << "请依次输入加密密钥k1,k2\n";
		cin >> k1 >> k2;
		if (k1 % 2 == 0 || k1 == 13){
			cout << "请输入与26互素的k1\n";
		}
		else{
			for (i = 1; i <= 25; i++){
				if ((k1*i) % 26 == 1){
					k1 = i;
					break;
				}
			}
			cout << "解密密钥k1'=" << k1 << "\n" << "解密密钥k2'=" << k2 << "\n";
			cout << "请输入密文:";
			cin >> s;
			cout << "解密得到明文:";
			for (i = 0; i < strlen(s); i++){
				m[i] = ((((int)s[i] - 65 + 26 - k2) % 26)*k1) % 26 + 97;
				cout << m[i];
			}
			cout << "\n";
		}
	}
	else{
		cout << "请输入密文:";
		cin >> s;
		int l;
		for (i = 1; i < 26; i+=2){
			k=0;
			if(i==13){
				continue;
			}
			for(l=1;l<25;l++){
				if((i*l)%26==1){
					k1=l;
				}
			}
			for (j = 1; j < 26; j++){
				cout << "加密密钥k1=" << i << ",k2=" << j << ":";
				for (k = 0; k < strlen(s); k++){
					m[k] = ((((int)s[k] - 65 + 26 - j) % 26)*k1)%26 + 97;
					cout << m[k];
				}
				cout << "\n";
			}
		}	
	}	
	system("pause");
}
