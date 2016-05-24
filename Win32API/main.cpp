#include <Windows.h>
#include "resource.h"
#include "CALCUL.h"
bool ERRORWITHNOLE;
HWND input;
HWND answer;
CHAR inputString[] = { "INPUT ¬€–¿∆≈Õ»≈" };
CHAR outputString[] = { 0 };
CHAR *ANS;
std::string primer;
HINSTANCE hInst;
BOOL CALLBACK Dlgproc(HWND, UINT, WPARAM, LPARAM);
int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, Dlgproc, 0);
	return 0;
}
void dfs()
{
	if (ANS != NULL)
		delete[]ANS;
	ANS = new CHAR[primer.size() + 1];
	for (size_t i = 0; i < primer.size(); i++)
		*(ANS + i) = primer[i];
	*(ANS + primer.size()) = '\0';
}
BOOL CALLBACK Dlgproc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG: 
	{
		HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon);
		input = GetDlgItem(hwnd, IDC_INPUT);
		answer = GetDlgItem(hwnd, IDC_OUTPUT);
		SendMessage(input, WM_SETTEXT, 0, (LPARAM)inputString);
		SetFocus(input);
		break;
	}
	case WM_CTLCOLORSTATIC:
	{
		if ((HWND)lParam == GetDlgItem(hwnd, IDC_STATIC1))
		{
			HDC hdc = (HDC)wParam;
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(255, 0, 0));
			return (int)GetStockObject(NULL_BRUSH);
		}
	}break;
	case WM_CTLCOLOREDIT:
	{

		HDC hdc = (HDC)wParam;
		SetBkMode(hdc, OPAQUE);
		SetBkColor(hdc, RGB(255, 255, 255));
		HBRUSH color = CreateSolidBrush(RGB(255, 255, 255));
		SetTextColor(hdc, RGB(0,189, 0));
		return (LRESULT)color;
		break;
	}
	case WM_COMMAND:
	{

		switch (LOWORD(wParam))
		{
		
		case IDOK:MessageBox(hwnd,ANS , "INFO", MB_OK | MB_ICONINFORMATION); break;
		case IDCANCEL:EndDialog(hwnd, 0);
			return FALSE;
		case IDC_ZHMIH:
		{
			//SendMessage(input, WM_GETTEXT, (WPARAM)255, (LPARAM)outputString);
		//	std::string a;
		//	for (size_t i = 0; i < strlen(outputString); i++)
		//		a += outputString[i];
			calcul::set(primer);
			calcul::DO_IT_NOW_CALCULE_PLS_NO_BUGS(primer, ERRORWITHNOLE);
			if (ERRORWITHNOLE)
			{
				ERRORWITHNOLE = false;
				return FALSE;

			}
			ANS = new CHAR[primer.size()+1];
			for (size_t i = 0; i < primer.size(); i++)
				*(ANS + i) = primer[i];
			*(ANS + primer.size()) = '\0';
			SendMessage(answer, WM_SETTEXT, 0, (LPARAM)ANS);
		}
		break;
		case IDC_CLEAR1:
		{
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)inputString);
			SendMessage(answer, WM_SETTEXT, 0, (LPARAM)" ");
			SetFocus(input);
			outputString[0] = '\0';
			delete[]ANS;
			ANS = NULL;
			primer.clear();
			break;
		}
		case IDC_CORRECT:
		{
			if (primer.size() != 0)
			{
				primer.erase(primer.size() - 1);
				ANS[primer.size()] = '\0';
				SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
			}
			break;
		}
		case IDC_N1:
		{
			primer += "1";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N2:
		{
			primer += "2";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N3:
		{
			primer += "3";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N4:
		{
			primer += "4";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N5:
		{
			primer += "5";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N6:
		{
			primer += "6";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N7:
		{
			primer += "7";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N8:
		{
			primer += "8";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N9:
		{
			primer += "9";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_N0:
		{
			primer += "0";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_PLUS:
		{
			primer += "+";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_MINUS:
		{
			primer += "-";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_DELENIE:
		{
			primer += "/";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_UMNOZHENIE:
		{
			primer += "*";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_SKOBKAOPEN:
		{
			primer += "(";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		case IDC_SKOBKACLOSE:
		{
			primer += ")";
			dfs();
			SendMessage(input, WM_SETTEXT, 0, (LPARAM)ANS);
		}break;
		default:break;
		}
		break;
	}
	case WM_CLOSE: 	delete[]ANS; EndDialog(hwnd, 0);
		return FALSE;
	default:return FALSE;

	}
	return FALSE;
}

//#include <windows.h>
//int WINAPI WinMain(HINSTANCE, HINSTANCE, PSTR, int) {
//	MessageBox(0, "Hello, World", "F*ck", 0);
//	return 0;
//}
