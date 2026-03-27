#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h> // 윈도우 전용 기능을 위해 필요

void CreatePoopFiles() {
    // 1. 바탕화면 경로 가져오기
    const char* userProfile = std::getenv("USERPROFILE");
    if (!userProfile) return;

    std::string desktopPath = std::string(userProfile) + "\\Desktop\\_💩_EMERGENCY_💩_";

    // 2. 폴더 생성 (이미 있으면 무시)
    std::string mkdirCmd = "mkdir \"" + desktopPath + "\" 2>nul";
    std::system(mkdirCmd.c_str());

    // 3. 똥 파일 100개 생성 (광기 모드)
    for (int i = 1; i <= 100; ++i) {
        std::string filePath = desktopPath + "\\POOP_RAIN_" + std::to_string(i) + ".txt";
        std::ofstream poopFile(filePath);
        if (poopFile.is_open()) {
            poopFile << "당신은 똥의 저주에 걸렸습니다. " << i << "번째 똥입니다. 💩" << std::endl;
            poopFile.close();
        }
    }

    // 4. 사용자에게 경고 메시지 박스 띄우기 (윈도우 기본 기능)
    MessageBoxA(NULL, "바탕화면을 확인하십시오. 똥 비가 내렸습니다.", "⚠️ WARNING ⚠️", MB_OK | MB_ICONWARNING);
}

int main() {
    // 콘솔 창 숨기기 (몰래 실행되는 느낌)
    // HWND hWnd = GetConsoleWindow();
    // ShowWindow(hWnd, SW_HIDE);

    std::cout << "테러를 시작합니다... 3... 2... 1..." << std::endl;

    CreatePoopFiles();

    return 0;
}