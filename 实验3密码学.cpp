#include<iostream>
#include<string.h>

using namespace std;
int main(){
	int k1, k2,ch;
	char s[100],m[100];
	int i, j, k;
	int t[26] = {};
	cout << "����任";
	cout << "��ѡ������ģʽ��\n";
	cout << "1.����\n";
	cout << "2.����\n";
	cout << "3.�����ƽ�\n";
	cin >> ch;
	if (ch == 1){
		cout << "���������������Կk1��k2:\n";
		cin >> k1 >> k2;
		if (k1 % 2 == 0 || k1 == 13){
			cout << "��������26���ص�k1\n";
		}
		else{
			cout << "����������:\n";
			cin >> m;
			cout << "���ܵõ�������Ϊ:";
			for (i = 0; i < strlen(m); i++){
				s[i] = ((((int)m[i] - 97 + 26) % 26)*k1 + k2) % 26 + 65;
				cout << s[i];
			}
			cout << "\n";
		}
	}
	else if (ch == 2){
		cout << "���������������Կk1,k2\n";
		cin >> k1 >> k2;
		if (k1 % 2 == 0 || k1 == 13){
			cout << "��������26���ص�k1\n";
		}
		else{
			for (i = 1; i <= 25; i++){
				if ((k1*i) % 26 == 1){
					k1 = i;
					break;
				}
			}
			cout << "������Կk1'=" << k1 << "\n" << "������Կk2'=" << k2 << "\n";
			cout << "����������:";
			cin >> s;
			cout << "���ܵõ�����:";
			for (i = 0; i < strlen(s); i++){
				m[i] = ((((int)s[i] - 65 + 26 - k2) % 26)*k1) % 26 + 97;
				cout << m[i];
			}
			cout << "\n";
		}
	}
	else{
		cout << "����������:";
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
				cout << "������Կk1=" << i << ",k2=" << j << ":";
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
