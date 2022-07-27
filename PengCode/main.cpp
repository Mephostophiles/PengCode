#include"file.h"
int main(int argc, char* agrv[]) {
	cout << " @@@@@@@@\                                     " << endl;
	cout << " @@@    \@@                                    " << endl;
	cout << " @@@    =@@`  /@@@@@\   =@@/@@@@@`   */@@@@@@@@" << endl;
	cout << " @@@  */@@^ ,@@`   =@@  =@@^   =@@  ,@@^   *@@@" << endl;
	cout << " @@@@@@/[   @@@@@@@@@@^ =@@    =@@  /@@     =@@ " << endl;
	cout << " @@@        =@@         =@@    =@@   \@@     /@@" << endl;
	cout << " @@@         *@@@`  ,/^ =@@    =@@  ,@@@` ,/@@@" << endl;
	cout << " [[[          ,[@@@/[   ,[[    ,[[    ,\@@/`=@@" << endl;
	cout << "                                          ,@@^" << endl;
	cout << "                                    @@@@@@@@`" << endl;
	unsigned int argvSize = 0;
	while (true)
	{
		if (agrv[argvSize] == NULL) {
			break;
		}
		else {
			argvSize++;
		}
	}
	char* path = nullptr;
	char* opath = nullptr;
	for (int i = 0; i < argvSize; i++) {
		if (!strcmp(agrv[i], "-h")|| agrv[1]==nullptr) {   
			cout << "##################################################" << endl;
			cout << "# -32 32位ShellCode生成（需要转换程序本身为32位）#" << endl;
			cout << "# -64 64位ShellCode生成（需要转换程序本身为64位）#" << endl;
			cout << "# -e 需要转换的exe路径                           #" << endl;
			cout << "# -o 输出Shellcode的路径                         #" << endl;
			cout << "# 例子: PengCode.exe -64 -e code.exe -o code.bin #" << endl;
			cout << "# 需要管理员运行PengCode!                        #" << endl;
			cout << "##################################################" << endl;
		}
		if (!strcmp(agrv[i], "-e")) {
			path = agrv[i + 1];
		}
		if (!strcmp(agrv[i], "-o")) {
			opath = agrv[i + 1];
		}
	}

	for (int i = 0; i < argvSize; i++) {
		if (!strcmp(agrv[i], "-64")) {
			if (path != nullptr && opath != nullptr) {
				Write64FileShellCode(path, opath);
				cout << "64位ShellCode生成" << endl;
				return 0;
			}
		}
		if (!strcmp(agrv[i], "-32")) {
			Write32FileShellCode(path, opath);
			cout << "32位ShellCode生成" << endl;
			return 0;
		}
	}
}